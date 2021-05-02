GLOBAL constexpr const char* PALETTE_FILE = "textures/palette.png";
GLOBAL constexpr const char* TILESET_FILE = "data/tilesets.txt";
GLOBAL constexpr const char* GAME_GPAK    = "game.gpak";

// The columns in the palette file to pull the colors from.
GLOBAL constexpr int PALETTE_MAIN_COLUMN = 5;

GLOBAL std::map<std::string, vec4> palette_main_lookup;

FILDEF void init_palette_lookup ()
{
    LOG_DEBUG("Looking for palette information...");

    constexpr const char* PATH_STEAM_X86 = ":/Program Files (x86)/Steam/steamapps/common/theendisnigh/";
    constexpr const char* PATH_STEAM_X64 = ":/Program Files/Steam/steamapps/common/theendisnigh/";
    constexpr const char* PATH_EPIC_X86  = ":/Program Files (x86)/Epic Games/theendisnigh/";
    constexpr const char* PATH_EPIC_X64  = ":/Program Files)/Epic Games/theendisnigh/";

    std::string drives = get_drive_names();

    // In order of priority of where we want to search.
    std::vector<std::string> paths;
    paths.push_back(make_path_absolute(""));
    for (auto& drive: drives)
    {
        std::string drive_letter(1, drive);
        paths.push_back(drive_letter + PATH_STEAM_X86);
        paths.push_back(drive_letter + PATH_STEAM_X64);
        paths.push_back(drive_letter + PATH_EPIC_X86);
        paths.push_back(drive_letter + PATH_EPIC_X64);
    }

    std::vector<u8> palette_data;
    std::vector<u8> tileset_data;

    for (auto& path: paths)
    {
        LOG_DEBUG("Looking at: %s", path.c_str());

        std::string pname(path + PALETTE_FILE);
        if (palette_data.empty() && does_file_exist(pname))
        {
            LOG_DEBUG("Palette file found!");
            palette_data = read_binary_file(pname);
        }
        std::string tname(path + TILESET_FILE);
        if (tileset_data.empty() && does_file_exist(tname))
        {
            LOG_DEBUG("Tileset file found!");
            tileset_data = read_binary_file(tname);
        }

        // If either data does not exist then we will attempt to load from the GPAK.
        if (palette_data.empty() || tileset_data.empty())
        {
            std::string file_name(path + "game.gpak");
            std::vector<GPAK_Entry> entries;
            if (does_file_exist(file_name))
            {
                LOG_DEBUG("GPAK file found!");

                FILE* file = fopen(file_name.c_str(), "rb");
                if (file)
                {
                    defer { fclose(file); };

                    u32 entry_count;
                    fread(&entry_count, sizeof(u32), 1, file);
                    entries.resize(entry_count);

                    for (auto& e: entries)
                    {
                        fread(&e.name_length, sizeof(u16),  1,             file);
                        e.name.resize(e.name_length);
                        fread(&e.name[0],     sizeof(char), e.name_length, file);
                        fread(&e.file_size,   sizeof(u32),  1,             file);
                    }

                    std::vector<u8> file_buffer;
                    for (auto& e: entries)
                    {
                        file_buffer.resize(e.file_size);
                        fread(&file_buffer[0], sizeof(u8), e.file_size, file);
                        if (palette_data.empty() && e.name == PALETTE_FILE)
                        {
                            LOG_DEBUG("Palette file loaded from GPAK!");
                            palette_data = file_buffer;
                        }
                        if (tileset_data.empty() && e.name == TILESET_FILE)
                        {
                            LOG_DEBUG("Tileset file loaded from GPAK!");
                            tileset_data = file_buffer;
                        }
                    }
                }
            }
        }
        // We can leave early because we have found both files we want!
        if (!palette_data.empty() && !tileset_data.empty())
        {
            break;
        }
    }

    // If they still aren't present then we can't load the palette.
    if (palette_data.empty() || tileset_data.empty())
    {
        LOG_DEBUG("Could not find both a tileset or palette file!");
        return;
    }

    constexpr int BPP = 4;

    LOG_DEBUG("Loading palette data...");
    int w, h, bpp;
    u8* palette = stbi_load_from_memory(&palette_data[0], CAST(int, palette_data.size()), &w, &h, &bpp, BPP);
    if (!palette)
    {
        LOG_ERROR(ERR_MIN, "Failed to load palette data for the map editor!");
        return;
    }
    defer { stbi_image_free(palette); };

    LOG_DEBUG("Loading tilset data...");
    try
    {
        std::string buffer(tileset_data.begin(), tileset_data.end());
        GonObject gon = GonObject::LoadFromBuffer(buffer);
        for (auto it: gon.children_map)
        {
            std::string name = it.first;
            if (gon.children_array[it.second].type == GonObject::g_object &&
                gon.children_array[it.second].Contains("palette"))
            {
                int palette_row = CAST(int, gon.children_array[it.second]["palette"].Number(0));
                int pitch = w*BPP;
                int index = (palette_row * pitch + (PALETTE_MAIN_COLUMN * BPP));
                if (index+3 < (pitch*h)) // Make sure we aren't referencing out of the palette bounds.
                {
                    float r = CAST(float, palette[index+0]) / 255;
                    float g = CAST(float, palette[index+1]) / 255;
                    float b = CAST(float, palette[index+2]) / 255;
                    float a = CAST(float, palette[index+3]) / 255;

                    palette_main_lookup.insert(std::pair<std::string, vec4>(name, vec4(r,g,b,a)));
                }
            }
        }
    }
    catch (const char* msg)
    {
        LOG_ERROR(ERR_MIN, "Failed to load tileset data for the map editor!");
        palette_main_lookup.clear();
    }
}

FILDEF vec4 get_tileset_main_color (std::string tileset)
{
    if (tileset != "..")
    {
        if (palette_main_lookup.find(tileset) != palette_main_lookup.end())
        {
            return palette_main_lookup[tileset];
        }
        return ((is_ui_light()) ? ui_color_ex_dark : ui_color_ex_dark);
    }
    return vec4(0,0,0,1);
}
