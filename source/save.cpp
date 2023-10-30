#include "save.hpp"

FILDEF bool internal__read_string (FILE* file, std::string& str)
{
    u32 str_length;
    if (fread(&str_length, sizeof(u32), 1, file) != 1) return false;
    char* str_char = new char[str_length + 1];
    if (fread(str_char, sizeof(char), str_length, file) != str_length) return false;
    str_char[str_length] = 0;

    str = str_char;
    delete[] str_char;

    return true;
}

FILDEF bool internal__write_string (FILE* file, std::string& str)
{
    u32 str_length = str.length();
    if (fwrite(&str_length, sizeof(u32), 1, file) != 1) return false;
    if (fwrite(str.c_str(), sizeof(char), str_length, file) != str_length) return false;
    return true;
}

FILDEF bool internal__load_save (FILE* file, Save& save)
{
    fseek(file, 4, SEEK_CUR);
    internal__read_string(file, save.name);
    internal__read_string(file, save.last_lvl);
    fseek(file, 4, SEEK_CUR);
    internal__read_string(file, save.last_area);
    fseek(file, 1, SEEK_CUR);
    fread(&save.frames, sizeof(u64), 1, file);
    fread(&save.deaths, sizeof(u64), 1, file);
    fseek(file, 17, SEEK_CUR);
    fread(&save.reloads, sizeof(u64), 1, file);
    save.reloads -= save.deaths;
    save.reloads /= 500;

    u32 signature;
    fread(&signature, sizeof(u32), 1, file);

    if (signature != 999999 && signature != 999971)
    {
        std::string msg(format_string("Invalid save file signature '%d'!", signature));
        show_alert("Error", msg, ALERT_TYPE_ERROR, ALERT_BUTTON_OK, "Main");
        return false;
    }

    fseek(file, 133, SEEK_CUR);

    u32 entry_count;
    fread(&entry_count, sizeof(u32), 1, file);
    save.save_entries = std::vector<Save_Entry>(entry_count);
    for (int i=0; i<entry_count; ++i)
    {
        Save_Entry se;
        internal__read_string(file, se.lvl);
        fread(&se.flags, 1, 1, file);
    }

    return true;
}

STDDEF bool internal__save_save (FILE* file, Save& save)
{
    u32 buf;
    
    buf = 1;
    fwrite(&buf, 4, 1, file);
    internal__write_string(file, save.name);
    internal__write_string(file, save.last_lvl);
}

STDDEF bool load_save (Save& save, std::string file_name)
{
    // We don't make the path absolute or anything becuase if that is needed
    // then it should be handled by a higher-level than this internal system.

    LOG_DEBUG("Loading Save: %s", file_name.c_str());

    FILE* file = fopen(file_name.c_str(), "rb");
    if (!file)
    {
        LOG_ERROR(ERR_MED, "Failed to load save file '%s'!", file_name.c_str());
        return false;
    }
    defer { fclose(file); };

    // If the save is empty/blank we just create a blank default level.
    if (get_size_of_file(file) == 0) return create_blank_save(save);
    else                             return internal__load_save(file, save);
}

STDDEF bool save_save (Save& save, std::string file_name)
{
    // We don't make the path absolute or anything becuase if that is needed
    // then it should be handled by a higher-level than this internal system.

    LOG_DEBUG("Saving Save: %s", file_name.c_str());

    FILE* file = fopen(file_name.c_str(), "wb");
    if (!file)
    {
        LOG_ERROR(ERR_MED, "Failed to save file '%s'!", file_name.c_str());
        return false;
    }
    defer { fclose(file); };

    internal__save_save(file, save);
    return true;
}

STDDEF bool load_restore_save (Tab& tab, std::string file_name)
{
    LOG_DEBUG("Loading Restore Save: %s", file_name.c_str());

    FILE* file = fopen(file_name.c_str(), "rb");
    if (!file)
    {
        LOG_ERROR(ERR_MED, "Failed to load restore file '%s'!", file_name.c_str());
        return false;
    }
    defer { fclose(file); };

    // Read until the null-terminator to get the name of the save.
    std::string save_name;
    char c = 0;
    do
    {
        fread(&c, sizeof(char), 1, file);
        if (c) { save_name.push_back(c); }
    } while (c);

    // Set the name of the save for the tab we are loading into.
    tab.name = save_name;

    internal__load_save(file, tab.save);
    return true;
}

STDDEF bool save_restore_save(const Tab& tab, std::string file_name)
{
    LOG_DEBUG("Saving Restore Save: %s", file_name.c_str());

    FILE* file = fopen(file_name.c_str(), "wb");
    if (!file)
    {
        LOG_ERROR(ERR_MED, "Failed to save restore file '%s'!", file_name.c_str());
        return false;
    }
    defer { fclose(file); };

    // Write the name of the save + null-terminator for later restoration.
    if (tab.name.empty())
    {
        char null_terminator = '\0';
        fwrite(&null_terminator, sizeof(char), 1, file);
    }
    else
    {
        const char* name = tab.name.c_str();
        fwrite(name, sizeof(char), strlen(name) + 1, file);
    }

    internal__save_save(file, tab.save);
    return true;
}

FILDEF bool create_blank_save (Save& save, std::string start_level)
{
    save.name = "Empty";
    save.last_lvl = start_level;
    save.deaths = 0;
    save.last_area = "Nowhere";
    save.reloads = 1;
    save.frames = 60;
    save.save_entries.clear();

    return true;
}