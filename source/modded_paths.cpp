// Oops! All GLOBALs!
GLOBAL bool   modded_paths_loaded;

FILDEF bool operator== (const ModPath& a, const ModPath& b)
{
    return (a.name   == b.name  &&
            a.path   == b.path  &&
            a.color  == b.color &&
            a.icon   == b.icon  &&
            a.exists == b.exists );
}

FILDEF bool operator!= (const ModPath& a, const ModPath& b)
{
    return !(a == b);
}

FILDEF void run_game_with_params (const std::string param)
{
    constexpr const char* EXE_STEAM_X86 = "C:/Program Files (x86)/Steam/steamapps/common/theendisnigh/TheEndIsNigh.exe";
    constexpr const char* EXE_STEAM_X64 = "C:/Program Files/Steam/steamapps/common/theendisnigh/TheEndIsNigh.exe";
    constexpr const char* EXE_STEAM_APP = "TheEndIsNigh.exe";

    constexpr const char* EXE_EPIC_X86  = "C:/Program Files (x86)/Epic Games/theendisnigh/TheEnd.exe";
    constexpr const char* EXE_EPIC_X64  = "C:/Program Files)/Epic Games/theendisnigh/TheEnd.exe";
    constexpr const char* EXE_EPIC_APP  = "TheEnd.exe";
	
    const std::string MOD_PARAMS = !param.empty() ? "-modpaths 1 \"" + param + "\"" : "";

    const std::vector<std::string> EXECUTABLES
    {
        EXE_STEAM_X86, EXE_STEAM_X64, EXE_STEAM_APP,
        EXE_EPIC_X86, EXE_EPIC_X64, EXE_EPIC_APP
    };

    std::string executable;
    if (!editor_settings.game_path.empty())
    {
        executable = editor_settings.game_path;
        if (!does_file_exist(executable))
        {
            executable.clear();
        }
    }
    if (executable.empty())
    {
        for (auto exe: EXECUTABLES)
        {
            executable = exe;
            if (does_file_exist(executable))
            {
                break;
            }
        }
        if (!does_file_exist(executable))
        {
            executable.clear();
        }
    }

    // Executable couldn't be found so we will ask for the location.
    if (executable.empty())
    {
        open_path();
    }
    else if (!run_executable(executable, MOD_PARAMS))
	{
		LOG_ERROR(ERR_MED, "Failed to launch The End is Nigh executable!");
	}

    // Set current mod as last mod played.
    if (!param.empty()) 
    {
        auto it = std::find_if(modpaths.begin(), modpaths.end(), 
            [param](const ModPath& mp) -> bool { return mp.path == param.c_str(); });
        if (it != modpaths.end()) editor.focused_mod = it - modpaths.begin();
    }
}

FILDEF void load_new_modpath ()
{
    std::vector<std::string> paths = path_dialog();
    if (!paths.empty())
    {
        for (auto path : paths)
        {
            // New modded path
            ModPath modpath;
            modpath.path   = fix_path_slashes(path.c_str());
            modpath.color  = ui_color_white;
            modpath.icon   = { 0,  0, 24, 24 };
            modpath.exists = does_path_exist(modpath.path);
            // Calling "strip_file_path" despite sending a path as
            // an argument instead of a file. Don't worry about it.
            modpath.name = strip_file_path(modpath.path);

            modpaths.push_back(modpath);
        }
    }
}

FILDEF void focus_prev_mod ()
{
    if (editor.focused_mod > 0)
    {
        editor.focused_mod--;
    }
    else
    {
        editor.focused_mod = modpaths.size() - 1;
    }
}

FILDEF void focus_next_mod ()
{
    if (editor.focused_mod + 1 < modpaths.size())
    {
        editor.focused_mod++;
    }
    else
    {
        editor.focused_mod = 0;
    }
}

FILDEF void focus_modpath (std::string name)
{
    if (editor_settings.focus_tab_mod)
    {
        const auto& MODDED_PATH = std::find_if(modpaths.begin(), modpaths.end(),
            [name](const ModPath& mp) -> bool { return name.find(mp.path) == 0; });
        size_t index = MODDED_PATH - modpaths.begin();
        if (index < modpaths.size() && index != editor.focused_mod)
        {
            editor.focused_mod = index;
        }
    }
}

FILDEF void modpath_drop_file (std::string file_name)
{
    ModPath modpath;
    modpath.path = fix_path_slashes(file_name);
    modpath.color = ui_color_white;
    modpath.icon = { 0,  0, 24, 24 };
    modpath.exists = does_path_exist(modpath.path);
    modpath.name = strip_file_path(modpath.path);

    modpaths.push_back(modpath);

    // Select the dropped mod path.
    editor.focused_mod = modpaths.size() - 1;
}

FILDEF vec4 infer_tab_color (std::string name)
{
    // Check for tab's filename in modded paths to show tab color.
    try {
        const auto& MODDED_PATH = std::find_if(modpaths.begin(), modpaths.end(),
            [name](const ModPath& mp) -> bool { return name.find(mp.path) == 0; });
        const vec4 TAB_COLOR = MODDED_PATH != modpaths.end() ? MODDED_PATH->color : vec4(0, 0, 0, 0);
        return TAB_COLOR;
    }
    catch (const char* msg)
    {
        LOG_ERROR(ERR_MIN, "Failed to get a tab color based on existing modded paths: %s", msg);
        return vec4(0, 0, 0, 0);
    }
}

FILDEF void dump_modpaths ()
{
    #define EXPAND_VEC4(v) v.r, v.g, v.b, v.a
    LOG_DEBUG("");
    LOG_DEBUG("[[Mod Paths]]");
    for (auto& it : modpaths)
    {
        LOG_DEBUG("%s \"%s\" | %s (\"%s\") | %s (%.2f %.2f %.2f %.2f) | %s [%.0f %.0f]", MODPATH_NAME, it.name.c_str(), MODPATH_PATH, it.path.c_str(), MODPATH_COLOR, EXPAND_VEC4(it.color), MODPATH_ICON, it.icon.x, it.icon.y);
    }
    #undef EXPAND_VEC4
}
