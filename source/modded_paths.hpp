#pragma once

GLOBAL constexpr const char* MODDED_PATHS_FILE_NAME = "modded_paths.dat";

// The names for all of the mod paths in the modded paths file.

GLOBAL constexpr const char* MODDED_PATHS  = "modded_paths";
GLOBAL constexpr const char* MODPATH_NAME  = "name";
GLOBAL constexpr const char* MODPATH_PATH  = "path";
GLOBAL constexpr const char* MODPATH_COLOR = "color";
GLOBAL constexpr const char* MODPATH_ICON  = "icon";

// Modded paths.
struct ModPath
{
    // Mod's name, path, color for launch button and tabs,
    // boolean to check if modded path actually exists.
    std::string  name;
    std::string  path;
    vec4        color;
    quad         icon;
    bool       exists;
};

FILDEF bool operator== (const ModPath& a, const ModPath& b);
FILDEF bool operator!= (const ModPath& a, const ModPath& b);

// Global variables, my behated.
GLOBAL std::vector<ModPath> modpaths;

FILDEF void     run_game_with_params(const std::string param);
FILDEF void     load_new_modpath();
FILDEF void     focus_prev_mod();
FILDEF void     focus_next_mod();
FILDEF void     focus_modpath(std::string name);
FILDEF void     modpath_drop_file(std::string file_name);
FILDEF vec4     infer_tab_color(std::string name);
FILDEF void     dump_modpaths();