GLOBAL const std::map<std::string, const char*> PREFERENCES_SETTINGS_NAMES
{
{ SETTING_UI_THEME,            "Theme"                         },
{ SETTING_FONT_FACE,           "Font"                          },
{ SETTING_TILE_GRAPHICS,       "Tile Graphics"                 },
{ SETTING_CUSTOM_CURSORS,      "Cursors"                       },
{ SETTING_SHOW_TOOLTIPS,       "Tooltips"                      },
{ SETTING_UNLIMITED_BACKUPS,   "Unlimited Backups"             },
{ SETTING_BACKUP_COUNT,        "Backups Per Level"             },
{ SETTING_AUTO_BACKUP,         "Automatic Backups"             },
{ SETTING_BACKUP_INTERVAL,     "Auto-Backup Time"              },
{ SETTING_BACKGROUND_COLOR,    "Background"                    },
{ SETTING_SELECT_COLOR,        "Select"                        },
{ SETTING_OUT_OF_BOUNDS_COLOR, "Out of Bounds"                 },
{ SETTING_CURSOR_COLOR,        "Cursor"                        },
{ SETTING_MIRROR_LINE_COLOR,   "Mirror Lines"                  },
{ SETTING_TILE_GRID_COLOR,     "Tile Grid"                     }
};

GLOBAL const std::map<std::string, const char*> PREFERENCES_HOTKEYS_NAMES
{
{ KB_LEVEL_NEW,                "New"                           },
{ KB_LEVEL_OPEN,               "Load"                          },
{ KB_LEVEL_SAVE,               "Save"                          },
{ KB_LEVEL_SAVE_AS,            "Save As"                       },
{ KB_REFRESH,                  "Refresh"                       },
{ KB_LEVEL_CLOSE,              "Close"                         },
{ KB_LEVEL_CLOSE_ALL,          "Close All"                     },
{ KB_LEVEL_RESIZE,             "Resize"                        },
{ KB_UNDO,                     "Undo"                          },
{ KB_REDO,                     "Redo"                          },
{ KB_HISTORY_BEGIN,            "History Begin"                 },
{ KB_HISTORY_END,              "History End"                   },
{ KB_CAMERA_ZOOM_OUT,          "Zoom Out"                      },
{ KB_CAMERA_ZOOM_IN,           "Zoom In"                       },
{ KB_RUN_GAME,                 "Run Game"                      },
{ KB_RUN_FOCUSED_MOD,          "Run Focused Mod"               },
{ KB_FOCUS_NEXT_MOD,           "Focus Next Mod"                },
{ KB_FOCUS_PREV_MOD,           "Focus Prev Mod"                },
{ KB_MODS_LIST,                "Mods List"                     },
{ KB_PREFERENCES,              "Preferences"                   },
{ KB_ABOUT,                    "About"                         },
{ KB_BUG_REPORT,               "Bug Report"                    },
{ KB_BACKUPS,                  "Open Backups Folder"           },
{ KB_HELP,                     "Help"                          },
{ KB_TOOL_BRUSH,               "Brush"                         },
{ KB_TOOL_FILL,                "Fill"                          },
{ KB_TOOL_SELECT,              "Select"                        },
{ KB_FLIP_H,                   "Flip Horizontal"               },
{ KB_FLIP_V,                   "Flip Vertical"                 },
{ KB_MIRROR_H_TOGGLE,          "Mirror Horizontal"             },
{ KB_MIRROR_V_TOGGLE,          "Mirror Vertical"               },
{ KB_GPAK_UNPACK,              "Unpack GPAK"                   },
{ KB_GPAK_PACK,                "Pack GPAK"                     },
{ KB_TOGGLE_ENTITY,            "Toggle Large Entities"         },
{ KB_TOGGLE_GUIDES,            "Toggle Entity Guides"          },
{ KB_TOGGLE_PALETTE,           "Toggle Palette"                },
{ KB_GRID_TOGGLE,              "Toggle Tile Grid"              },
{ KB_BOUNDS_TOGGLE,            "Toggle Out of Bounds"          },
{ KB_LAYERS_TOGGLE,            "Toggle Transparency"           },
{ KB_CAMERA_RESET,             "Reset Camera"                  },
{ KB_CLEAR_SELECT,             "Clear Selection"               },
{ KB_DESELECT,                 "Select Box Deselect"           },
{ KB_SELECT_ALL,               "Cursor Deselect"               },
{ KB_COPY,                     "Copy"                          },
{ KB_CUT,                      "Cut"                           },
{ KB_PASTE,                    "Paste"                         },
{ KB_INCREMENT_TILE,           "Next Selected Tile"            },
{ KB_DECREMENT_TILE,           "Prev Selected Tile"            },
{ KB_INCREMENT_GROUP,          "Next Selected Group"           },
{ KB_DECREMENT_GROUP,          "Prev Selected Group"           },
{ KB_INCREMENT_CATEGORY,       "Next Selected Category"        },
{ KB_DECREMENT_CATEGORY,       "Prev Selected Category"        },
{ KB_TOGGLE_LAYER_ACTIVE,      "Toggle Active Layer"           },
{ KB_TOGGLE_LAYER_TAG,         "Toggle Tag Layer"              },
{ KB_TOGGLE_LAYER_OVERLAY,     "Toggle Overlay Layer"          },
{ KB_TOGGLE_LAYER_BACK1,       "Toggle Back 1 Layer"           },
{ KB_TOGGLE_LAYER_BACK2,       "Toggle Back 2 Layer"           },
{ KB_CATEGORY_BASIC,           "Category Basic"                },
{ KB_CATEGORY_TAG,             "Category Tag"                  },
{ KB_CATEGORY_OVERLAY,         "Category Overlay"              },
{ KB_CATEGORY_ENTITY,          "Category Entity"               },
{ KB_CATEGORY_BACK1,           "Category Back 1"               },
{ KB_CATEGORY_BACK2,           "Category Back 2"               },
{ KB_INCREMENT_TAB,            "Next Tab"                      },
{ KB_DECREMENT_TAB,            "Prev Tab"                      },
{ KB_MOVE_TAB_LEFT,            "Move Tab Left"                 },
{ KB_MOVE_TAB_RIGHT,           "Move Tab Right"                },
{ KB_OPEN_RECENT_TAB,          "Open Recent Tab"               },
{ KB_LOAD_NEXT_LEVEL,          "Load Next Level"               },
{ KB_LOAD_PREV_LEVEL,          "Load Prev Level"               }
};

GLOBAL const std::map<std::string, const char*> PREFERENCES_MODPATHS_NAMES
{
{ SETTING_MODS_LAYOUT,         "Mods Layout"                   },
{ SETTING_COLORED_TABS,        "Colored Tabs"                  },
{ SETTING_HIGHLIGHT_MOD,       "Highlight Focused Mod"         },
{ SETTING_FOCUS_TAB_MOD,       "Focus Mod On Tab Switch"       },
{ SETTING_SHOW_MOD_LIST,       "Show Mod List"                 }
};

GLOBAL constexpr float PREFERENCES_V_FRAME_H       = 26;
GLOBAL constexpr float PREFERENCES_SECTION_H       = 24;
GLOBAL constexpr float PREFERENCES_INNER_XPAD      = 10;
GLOBAL constexpr float PREFERENCES_INNER_YPAD      =  5;
GLOBAL constexpr float PREFERENCES_TEXT_BOX_INSET  =  2;
GLOBAL constexpr float PREFERENCES_SCROLLBAR_WIDTH = 12;
GLOBAL constexpr float PREFERENCES_COLOR_HEIGHT    = 18;

enum class Preferences_Tab { SETTINGS, HOTKEYS, MODPATHS };

GLOBAL Preferences_Tab preferences_tab = Preferences_Tab::SETTINGS;

GLOBAL float preferences_scroll_offset = 0;
GLOBAL float    modpaths_scroll_offset = 0;

// When the preferences menu is opened we cache the current settings and
// hotkey states. This allows the preferences menu to modify the current
// settings and hotkeys immediately for instant feedback. If the user
// then wants to cancel the changes made, we can just restore the cached
// versions of the settings and hotkeys to return to the original state.

GLOBAL Settings                           cached_editor_settings;
GLOBAL std::map<std::string, Key_Binding> cached_editor_hotkeys;
GLOBAL std::vector<ModPath>               cached_modpaths;
GLOBAL size_t                             cached_focused_mod;

FILDEF void internal__next_section (vec2& cursor)
{
    cursor.x  = 0;
    cursor.y += PREFERENCES_SECTION_H;
}

FILDEF void internal__do_settings_label (float w, const char* key)
{
    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, w,PREFERENCES_SECTION_H, PREFERENCES_SETTINGS_NAMES.at(key));

    advance_panel_cursor(PREFERENCES_INNER_XPAD/2);
    do_separator(PREFERENCES_SECTION_H);
    advance_panel_cursor(PREFERENCES_INNER_XPAD/2);
}

FILDEF void internal__do_half_settings_label (float w, const char* key)
{
    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, w,PREFERENCES_SECTION_H, PREFERENCES_SETTINGS_NAMES.at(key));
    advance_panel_cursor(PREFERENCES_INNER_XPAD/2);
}

FILDEF void internal__do_half_separator (vec2& cursor)
{
    advance_panel_cursor((PREFERENCES_INNER_XPAD/2)+1);
    do_separator(PREFERENCES_SECTION_H);
    cursor.x -= 1;
    advance_panel_cursor(PREFERENCES_INNER_XPAD/2);
}

FILDEF void internal__do_hotkeys_label (float w, const char* key)
{
    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, w,PREFERENCES_SECTION_H, PREFERENCES_HOTKEYS_NAMES.at(key));

    advance_panel_cursor(PREFERENCES_INNER_XPAD/2);
    do_separator(PREFERENCES_SECTION_H);
    advance_panel_cursor(PREFERENCES_INNER_XPAD/2);
}

FILDEF void internal__do_modpaths_label (float w, const char* key)
{
    do_label(UI_ALIGN_LEFT, UI_ALIGN_CENTER, w, PREFERENCES_SECTION_H, PREFERENCES_MODPATHS_NAMES.at(key));

    advance_panel_cursor(PREFERENCES_INNER_XPAD / 2);
    do_separator(PREFERENCES_SECTION_H);
    advance_panel_cursor(PREFERENCES_INNER_XPAD / 2);
}

FILDEF void internal__begin_settings_area (const char* title, vec2& cursor)
{
    float w = get_viewport().w;
    float h = PREFERENCES_SECTION_H;

    do_label(UI_ALIGN_CENTER,UI_ALIGN_CENTER, w,h, title);
    internal__next_section(cursor);

    set_panel_cursor_dir(UI_DIR_DOWN);

    advance_panel_cursor(PREFERENCES_INNER_YPAD);
    do_separator(w);
    advance_panel_cursor(PREFERENCES_INNER_YPAD);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    cursor.x = 0;
}

FILDEF void internal__end_settings_area ()
{
    set_panel_cursor_dir(UI_DIR_DOWN);
    advance_panel_cursor(PREFERENCES_INNER_YPAD);
    set_panel_cursor_dir(UI_DIR_RIGHT);
}

FILDEF void internal__do_color_setting_row (vec2& cursor, float w, const char* key1, const char* key2, vec4& c1, vec4& c2)
{
    float lw1 = w-1;
    float lw2 = w;

    float sw = w;
    float sh = PREFERENCES_COLOR_HEIGHT;

    internal__do_half_settings_label(lw1, key1);
    do_color_swatch(cursor, sw, sh, c1);
    internal__do_half_separator(cursor);
    internal__do_half_settings_label(lw2, key2);
    do_color_swatch(cursor, sw, sh, c2);
    internal__next_section(cursor);
}

FILDEF void internal__do_hotkey_label_titles (vec2& cursor)
{
    float vw = get_viewport().w-(PREFERENCES_SCROLLBAR_WIDTH-1);
    float sh = PREFERENCES_SECTION_H+(PREFERENCES_INNER_YPAD*2);

    // We use get_viewport().w so the labels are slightly larger and align.
    float lw1 = (roundf((get_viewport().w-(PREFERENCES_INNER_XPAD*2)) / 3) - (PREFERENCES_INNER_XPAD/2));
    float lw2 = roundf((vw-(lw1*2))-roundf((PREFERENCES_INNER_XPAD*2.5f)+2));

    do_quad(vw, sh, ui_color_medium);

    cursor.x  = PREFERENCES_INNER_XPAD;
    cursor.y += PREFERENCES_INNER_YPAD;

    do_label(UI_ALIGN_LEFT,UI_ALIGN_CENTER, lw1,PREFERENCES_SECTION_H, "Hotkey Action");

    advance_panel_cursor(PREFERENCES_INNER_XPAD/2);
    advance_panel_cursor(1);
    advance_panel_cursor(PREFERENCES_INNER_XPAD/2);

    do_label(UI_ALIGN_RIGHT,UI_ALIGN_CENTER, lw2,PREFERENCES_SECTION_H, "Main Binding");
    cursor.x += roundf(PREFERENCES_INNER_XPAD/3);
    do_label(UI_ALIGN_RIGHT,UI_ALIGN_CENTER, lw2,PREFERENCES_SECTION_H, "Alternate Binding");

    cursor.x = 0;

    cursor.y += PREFERENCES_SECTION_H;
    cursor.y += PREFERENCES_INNER_YPAD;

    // To add a separation between hotkey sections.
    ++cursor.y;
}

FILDEF void internal__do_hotkey_rebind (vec2& cursor, const char* key)
{
    float vw = get_viewport().w-(PREFERENCES_SCROLLBAR_WIDTH-1);
    float sh = PREFERENCES_SECTION_H;

    // We use get_viewport().w so the labels are slightly larger and align.
    float lw = (roundf((get_viewport().w-(PREFERENCES_INNER_XPAD*2)) / 3) - (PREFERENCES_INNER_XPAD/2));
    float tw = roundf((vw-(lw*2))-roundf((PREFERENCES_INNER_XPAD*2.5f)+2));

    do_quad(vw, sh, ui_color_medium);
    cursor.x = PREFERENCES_INNER_XPAD;

    internal__do_hotkeys_label(lw, key);

    // It says text box inset but we're using for the hotkey rebind as well...
    float th = sh-(PREFERENCES_TEXT_BOX_INSET*2);
    cursor.y += PREFERENCES_TEXT_BOX_INSET;
    do_hotkey_rebind_main(tw,th, UI_NONE, key_bindings.at(key));
    cursor.x += roundf(PREFERENCES_INNER_XPAD/3);
    do_hotkey_rebind_alt(tw,th, UI_NONE, key_bindings.at(key));
    cursor.y -= PREFERENCES_TEXT_BOX_INSET;

    internal__next_section(cursor);

    // To add a separation between hotkey sections.
    ++cursor.y;
}

FILDEF void internal__update_path (ModPath* modpath)
{
    std::vector<std::string> v = path_dialog(false);
    if (v.empty()) return;

    std::string path = fix_path_slashes(v[0]);
    if (!path.empty() && path != modpath->path)
    {
        modpath->path   = path;
        modpath->exists = does_path_exist(path);
    }
}

FILDEF void internal__do_reorder_arrow (vec2& cursor, ModPath* modpath, float w, float h, size_t index, bool is_up)
{
    cursor.x              = 0;
    const int sign        = is_up ? 1 : -1;
    const bool is_enabled = is_up ? index : (index < modpaths.size() - 1);
    if (do_button_img(NULL, w, h, is_enabled ? UI_NONE : UI_LOCKED, is_up ? &CLIP_MOVE_UP : &CLIP_MOVE_DOWN))
    {
        std::iter_swap(modpaths.begin()+index-is_up, modpaths.begin()+index+(!is_up));
        if      (editor.focused_mod == index)      { editor.focused_mod -= sign; }
        else if (editor.focused_mod == index-sign) { editor.focused_mod += sign; }
    }
    cursor.y += (h + 4) * sign;
}

FILDEF void internal__do_modpath (vec2& cursor, ModPath* modpath, size_t index)
{
    const float view_width   = get_viewport().w - (PREFERENCES_SCROLLBAR_WIDTH - 1);
    const float text_height  = PREFERENCES_SECTION_H - (PREFERENCES_TEXT_BOX_INSET * 2);
    const float arrow_height = roundf(text_height / 2) - 2;
    const float button_width = roundf((get_viewport().w - (PREFERENCES_INNER_XPAD * 2)) / 12) - roundf(PREFERENCES_INNER_XPAD / 2);
    const float text_width   = roundf((view_width - (button_width * 7)) - PREFERENCES_INNER_XPAD * 3 - 1);
    const float scroll_y     = ui_panels.top().relative_offset.y;

    do_quad(view_width, PREFERENCES_SECTION_H, ui_color_medium);
    cursor.y += PREFERENCES_TEXT_BOX_INSET;

    // Arrows to reorder mod paths.
    internal__do_reorder_arrow(cursor, modpath, PREFERENCES_INNER_XPAD, arrow_height, index, true);
    internal__do_reorder_arrow(cursor, modpath, PREFERENCES_INNER_XPAD, arrow_height, index, false);

    // Name text box.
    do_text_box(text_width, text_height, UI_NONE, modpath->name, "", UI_ALIGN_LEFT);
    cursor.x += PREFERENCES_INNER_XPAD;
    cursor.y -= PREFERENCES_TEXT_BOX_INSET;

    // Color swatch.
    vec2 color_cursor = { cursor.x, cursor.y + scroll_y };
    do_color_swatch(color_cursor, button_width*3, text_height, modpath->color);
    cursor.x += PREFERENCES_INNER_XPAD;
    cursor.y += PREFERENCES_TEXT_BOX_INSET;
    do_separator(PREFERENCES_SECTION_H);

    // Action buttons.
    set_ui_texture(&resource_mod_icons);
    if (do_button_img(NULL, button_width, text_height, UI_NONE, &modpath->icon))
    {
        open_icon_picker(&modpath->icon);
    }
    set_ui_texture(&resource_icons);
    if (do_button_img(NULL, button_width, text_height, UI_NONE, &CLIP_EDIT_FOLDER))
    {
        internal__update_path(modpath);
    }
    if (do_button_txt(NULL, button_width*2, text_height, UI_NONE, "Remove"))
    {
        modpaths.erase(modpaths.begin() + index);
        if (editor.focused_mod > index) editor.focused_mod--;
    }

    internal__next_section(cursor);
    cursor.y -= PREFERENCES_TEXT_BOX_INSET;
    ++cursor.y;
}

FILDEF void internal__refresh_tab_colors (bool is_replacing) {
    for (auto& tab : editor.tabs)
    {
        // Only change the color if we've made changes to modpaths or if tab has no color.
        if (is_replacing || tab.color == vec4(0, 0, 0, 0)) tab.color = infer_tab_color(tab.name);
    }
}

FILDEF void internal__save_settings ()
{
    std::string file_name(get_appdata_path() + SETTINGS_FILE_NAME);
    FILE* file = fopen(file_name.c_str(), "w");
    if (!file)
    {
        LOG_ERROR(ERR_MED, "Failed to save settings data!");
        return;
    }
    defer { fclose(file); };

    vec4 c;

    if (!editor_settings.game_path.empty())
    {
        fprintf(file, "%s \"%s\"\n", SETTING_GAME_PATH, editor_settings.game_path.c_str());
    }
    fprintf(file, "%s %s\n", SETTING_UI_THEME,           editor_settings.ui_theme     .c_str());
    fprintf(file, "%s %s\n", SETTING_FONT_FACE,          editor_settings.font_face    .c_str());
    fprintf(file, "%s %s\n", SETTING_TILE_GRAPHICS,      editor_settings.tile_graphics.c_str());
    fprintf(file, "%s %s\n", SETTING_CUSTOM_CURSORS,    (editor_settings.custom_cursors)    ? "true" : "false");
    fprintf(file, "%s %s\n", SETTING_SHOW_TOOLTIPS,     (editor_settings.show_tooltips)     ? "true" : "false");
    fprintf(file, "%s %s\n", SETTING_UNLIMITED_BACKUPS, (editor_settings.unlimited_backups) ? "true" : "false");
    fprintf(file, "%s %d\n", SETTING_BACKUP_COUNT,       editor_settings.backup_count);
    fprintf(file, "%s %s\n", SETTING_AUTO_BACKUP,       (editor_settings.auto_backup)       ? "true" : "false");
    fprintf(file, "%s %d\n", SETTING_BACKUP_INTERVAL,    editor_settings.backup_interval);
    if (!editor_settings.background_color_defaulted)
    {
        c = editor_settings.background_color;
        fprintf(file, "%s [%f %f %f %f]\n", SETTING_BACKGROUND_COLOR, c.r, c.g, c.b, c.a);
    }
    else
    {
        fprintf(file, "%s %s\n", SETTING_BACKGROUND_COLOR, "none");
    }
    c = editor_settings.select_color;
    fprintf(file, "%s [%f %f %f %f]\n", SETTING_SELECT_COLOR, c.r, c.g, c.b, c.a);
    c = editor_settings.out_of_bounds_color;
    fprintf(file, "%s [%f %f %f %f]\n", SETTING_OUT_OF_BOUNDS_COLOR, c.r, c.g, c.b, c.a);
    c = editor_settings.cursor_color;
    fprintf(file, "%s [%f %f %f %f]\n", SETTING_CURSOR_COLOR, c.r, c.g, c.b, c.a);
    c = editor_settings.mirror_line_color;
    fprintf(file, "%s [%f %f %f %f]\n", SETTING_MIRROR_LINE_COLOR, c.r, c.g, c.b, c.a);
    if (!editor_settings.tile_grid_color_defaulted)
    {
        c = editor_settings.tile_grid_color;
        fprintf(file, "%s [%f %f %f %f]\n", SETTING_TILE_GRID_COLOR, c.r, c.g, c.b, c.a);
    }
    else
    {
        fprintf(file, "%s %s\n", SETTING_TILE_GRID_COLOR, "none");
    }
    fprintf(file, "%s %s\n", SETTING_MODS_LAYOUT,    editor_settings.mods_layout.c_str());
    fprintf(file, "%s %s\n", SETTING_COLORED_TABS,  (editor_settings.colored_tabs ) ? "true" : "false");
    fprintf(file, "%s %s\n", SETTING_HIGHLIGHT_MOD, (editor_settings.highlight_mod) ? "true" : "false");
    fprintf(file, "%s %s\n", SETTING_FOCUS_TAB_MOD, (editor_settings.focus_tab_mod) ? "true" : "false");
    fprintf(file, "%s %s\n", SETTING_SHOW_MOD_LIST, (editor_settings.show_mod_list) ? "true" : "false");

    fprintf(file, "\n");

    // Save all of the hotkeys to GON format.
    for (auto& it: key_bindings)
    {
        const Key_Binding& kb = it.second;
        fprintf(file, "%s { ", it.first.c_str());
        fprintf(file, "main [");
        if (kb.mod)
        {
            if (kb.mod&KMOD_CTRL ) fprintf(file, "\"Ctrl\" " );
            if (kb.mod&KMOD_ALT  ) fprintf(file, "\"Alt\" "  );
            if (kb.mod&KMOD_MODE ) fprintf(file, "\"AltGr\" ");
            if (kb.mod&KMOD_SHIFT) fprintf(file, "\"Shift\" ");
            if (kb.mod&KMOD_GUI  ) fprintf(file, "\"Gui\" "  );
        }
        if (kb.code)
        {
            fprintf(file, "\"%s\"", SDL_GetKeyName(kb.code));
        }
        fprintf(file, "] ");
        if (kb.has_alt)
        {
            fprintf(file, "alt [");
            if (kb.alt_mod)
            {
                if (kb.alt_mod&KMOD_CTRL ) fprintf(file, "\"Ctrl\" " );
                if (kb.alt_mod&KMOD_ALT  ) fprintf(file, "\"Alt\" "  );
                if (kb.alt_mod&KMOD_MODE ) fprintf(file, "\"AltGr\" ");
                if (kb.alt_mod&KMOD_SHIFT) fprintf(file, "\"Shift\" ");
                if (kb.alt_mod&KMOD_GUI  ) fprintf(file, "\"Gui\" "  );
            }
            if (kb.alt_code)
            {
                fprintf(file, "\"%s\"", SDL_GetKeyName(kb.alt_code));
            }
            fprintf(file, "] ");
        }
        fprintf(file, "}\n");
    }
}

FILDEF void internal__save_modded_paths ()
{
    #define EXPAND_VEC4(v) v.r, v.g, v.b, v.a
    std::string file_name(get_appdata_path() + MODDED_PATHS_FILE_NAME);
    FILE* file = fopen(file_name.c_str(), "w");
    if (!file)
    {
        LOG_ERROR(ERR_MED, "Failed to save modded paths data!");
        return;
    }
    defer{ fclose(file); };

    vec4 c;

    // Save all of the modded paths to GON format.
    fprintf(file, "modded_paths\n");
    fprintf(file, "[\n");
    for (auto& it : modpaths)
    {
        fprintf(file,                  "\t{\n");
        fprintf(file,        "\t\t%s \"%s\"\n", MODPATH_NAME,  it.name.c_str()      );
        fprintf(file,        "\t\t%s \"%s\"\n", MODPATH_PATH,  it.path.c_str()      );
        fprintf(file, "\t\t%s [%f %f %f %f]\n", MODPATH_COLOR, EXPAND_VEC4(it.color));
        fprintf(file,   "\t\t%s [%.0f %.0f]\n", MODPATH_ICON,  it.icon.x, it.icon.y );
        fprintf(file,                  "\t}\n");
    }
    fprintf(file, "]\n");
    #undef EXPAND_VEC4
}

FILDEF void internal__do_preferences_settings ()
{
    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float xpad = PREFERENCES_INNER_XPAD;
    float ypad = PREFERENCES_INNER_YPAD;

    begin_panel(0, 0, vw, vh, UI_NONE, ui_color_medium);
    begin_panel(xpad, ypad, vw-(xpad*2), vh-(ypad*2), UI_NONE);

    // We redefine as these will now be different.
    vw = get_viewport().w;
    vh = get_viewport().h;

    float sw = roundf(vw / 2) - (xpad/2);
    float sh = PREFERENCES_SECTION_H;

    float bw = roundf(sw / 2);
    float th = sh-(PREFERENCES_TEXT_BOX_INSET*2);

    vec2 cursor(0,0);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    internal__begin_settings_area("User Interface", cursor);

    internal__do_settings_label(sw, SETTING_UI_THEME);
    UI_Flag dark_flags  = (is_ui_light()) ? UI_INACTIVE : UI_NONE;
    UI_Flag light_flags = (is_ui_light()) ? UI_NONE : UI_INACTIVE;
    if (do_button_txt(NULL, bw,sh, dark_flags,  "Dark"))
    {
        editor_settings.ui_theme = "dark";
        load_ui_theme();
    }
    if (do_button_txt(NULL, bw,sh, light_flags, "Light"))
    {
        editor_settings.ui_theme = "light";
        load_ui_theme();
    }
    internal__next_section(cursor);

    internal__do_settings_label(sw, SETTING_FONT_FACE);
    UI_Flag sans_flags = (is_editor_font_opensans()) ? UI_NONE : UI_INACTIVE;
    UI_Flag dysl_flags = (is_editor_font_opensans()) ? UI_INACTIVE : UI_NONE;
    set_ui_font(&resource_font_regular_sans);
    if (do_button_txt(NULL, bw,sh, sans_flags, "OpenSans"))
    {
        editor_settings.font_face = "OpenSans";
        update_editor_font();
    }
    set_ui_font(&resource_font_regular_dyslexic);
    if (do_button_txt(NULL, bw,sh, dysl_flags, "OpenDyslexic"))
    {
        editor_settings.font_face = "OpenDyslexic";
        update_editor_font();
    }
    internal__next_section(cursor);

    // Reset the font to being the default for the editor.
    set_ui_font(&get_editor_regular_font());

    internal__do_settings_label(sw, SETTING_TILE_GRAPHICS);
    UI_Flag tile_graphics_new_flags = (editor_settings.tile_graphics == "new") ? UI_NONE : UI_INACTIVE;
    UI_Flag tile_graphics_old_flags = (editor_settings.tile_graphics == "new") ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, bw,sh, tile_graphics_new_flags, "New"))
    {
        if (editor_settings.tile_graphics != "new")
        {
            editor_settings.tile_graphics = "new";
            reload_tile_graphics();
        }
    }
    if (do_button_txt(NULL, bw,sh, tile_graphics_old_flags, "Old"))
    {
        if (editor_settings.tile_graphics != "old")
        {
            editor_settings.tile_graphics = "old";
            reload_tile_graphics();
        }
    }
    internal__next_section(cursor);

    internal__do_settings_label(sw, SETTING_CUSTOM_CURSORS);
    UI_Flag cursor_enabled_flags  = (custom_cursors_enabled()) ? UI_NONE : UI_INACTIVE;
    UI_Flag cursor_disabled_flags = (custom_cursors_enabled()) ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, bw,sh, cursor_enabled_flags,  "Enabled"))
    {
        editor_settings.custom_cursors = true;
        load_editor_cursors();
    }
    if (do_button_txt(NULL, bw,sh, cursor_disabled_flags, "Disabled"))
    {
        editor_settings.custom_cursors = false;
        load_editor_cursors();
    }
    internal__next_section(cursor);

    UI_Flag tooltips_enabled_flags  = (editor_settings.show_tooltips) ? UI_NONE : UI_INACTIVE;
    UI_Flag tooltips_disabled_flags = (editor_settings.show_tooltips) ? UI_INACTIVE : UI_NONE;
    internal__do_settings_label(sw, SETTING_SHOW_TOOLTIPS);
    if (do_button_txt(NULL, bw,sh, tooltips_enabled_flags,  "Enabled"))
    {
        editor_settings.show_tooltips = true;
    }
    if (do_button_txt(NULL, bw,sh, tooltips_disabled_flags, "Disabled"))
    {
        editor_settings.show_tooltips = false;
    }
    internal__next_section(cursor);

    internal__end_settings_area();

    internal__begin_settings_area("Level Backups", cursor);

    internal__do_settings_label(sw, SETTING_AUTO_BACKUP);
    UI_Flag backup_enabled_flags  = (editor_settings.auto_backup) ? UI_NONE : UI_INACTIVE;
    UI_Flag backup_disabled_flags = (editor_settings.auto_backup) ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, bw,sh, backup_enabled_flags,  "Enabled"))
    {
        editor_settings.auto_backup = true;
        update_backup_timer();
    }
    if (do_button_txt(NULL, bw,sh, backup_disabled_flags, "Disabled"))
    {
        editor_settings.auto_backup = false;
        update_backup_timer();
    }
    internal__next_section(cursor);

    internal__do_settings_label(sw, SETTING_UNLIMITED_BACKUPS);
    UI_Flag unlimited_enabled_flags  = (editor_settings.unlimited_backups) ? UI_NONE : UI_INACTIVE;
    UI_Flag unlimited_disabled_flags = (editor_settings.unlimited_backups) ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, bw,sh, unlimited_enabled_flags,  "Enabled"))
    {
        editor_settings.unlimited_backups = true;
    }
    if (do_button_txt(NULL, bw,sh, unlimited_disabled_flags, "Disabled"))
    {
        editor_settings.unlimited_backups = false;
    }
    internal__next_section(cursor);

    internal__do_settings_label(sw, SETTING_BACKUP_INTERVAL);
    if (!editor_settings.auto_backup) set_panel_flags(UI_LOCKED);
    cursor.y += PREFERENCES_TEXT_BOX_INSET;
    std::string backup_interval_str(std::to_string(editor_settings.backup_interval));
    do_text_box(vw-cursor.x,th, UI_NUMERIC, backup_interval_str, "0");
    cursor.y -= PREFERENCES_TEXT_BOX_INSET;
    if (!editor_settings.auto_backup) set_panel_flags(UI_NONE);
    if (atoll(backup_interval_str.c_str()) > INT_MAX)
    {
        backup_interval_str = std::to_string(INT_MAX);
    }
    int backup_interval = atoi(backup_interval_str.c_str());
    if (backup_interval != editor_settings.backup_interval)
    {
        editor_settings.backup_interval = backup_interval;
        update_backup_timer();
    }
    internal__next_section(cursor);

    internal__do_settings_label(sw, SETTING_BACKUP_COUNT);
    if (editor_settings.unlimited_backups) set_panel_flags(UI_LOCKED);
    cursor.y += PREFERENCES_TEXT_BOX_INSET;
    std::string backup_count_str(std::to_string(editor_settings.backup_count));
    do_text_box(vw-cursor.x,th, UI_NUMERIC, backup_count_str, "0");
    cursor.y -= PREFERENCES_TEXT_BOX_INSET;
    if (editor_settings.unlimited_backups) set_panel_flags(UI_NONE);
    if (atoll(backup_count_str.c_str()) > INT_MAX)
    {
        backup_count_str = std::to_string(INT_MAX);
    }
    int backup_count = atoi(backup_count_str.c_str());
    if (backup_count != editor_settings.backup_count)
    {
        editor_settings.backup_count = backup_count;
    }
    internal__next_section(cursor);

    internal__end_settings_area();

    internal__begin_settings_area("Custom Colors", cursor);

    float hw = roundf(vw/4) - (xpad/2);

    internal__do_color_setting_row(cursor, hw, SETTING_BACKGROUND_COLOR, SETTING_TILE_GRID_COLOR    , editor_settings.background_color, editor_settings.tile_grid_color    );
    internal__do_color_setting_row(cursor, hw, SETTING_SELECT_COLOR    , SETTING_OUT_OF_BOUNDS_COLOR, editor_settings.select_color    , editor_settings.out_of_bounds_color);
    internal__do_color_setting_row(cursor, hw, SETTING_CURSOR_COLOR    , SETTING_MIRROR_LINE_COLOR  , editor_settings.cursor_color    , editor_settings.mirror_line_color  );

    internal__end_settings_area();

    end_panel();
    end_panel();
}

FILDEF void internal__do_preferences_hotkeys ()
{
    float vw = get_viewport().w;
    float vh = get_viewport().h;

    begin_panel(0, 0, vw, vh, UI_NONE);

    vec2 cursor(0,0);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    float content_height = (PREFERENCES_HOTKEYS_NAMES.size() * (PREFERENCES_SECTION_H+1)) + (PREFERENCES_SECTION_H+(PREFERENCES_INNER_YPAD*2));
    do_scrollbar(vw-PREFERENCES_SCROLLBAR_WIDTH+1, -1, PREFERENCES_SCROLLBAR_WIDTH, vh+2, content_height, preferences_scroll_offset);

    internal__do_hotkey_label_titles(cursor);

    internal__do_hotkey_rebind(cursor, KB_LEVEL_NEW            );
    internal__do_hotkey_rebind(cursor, KB_LEVEL_OPEN           );
    internal__do_hotkey_rebind(cursor, KB_LEVEL_SAVE           );
    internal__do_hotkey_rebind(cursor, KB_LEVEL_SAVE_AS        );
    internal__do_hotkey_rebind(cursor, KB_REFRESH              );
    internal__do_hotkey_rebind(cursor, KB_LEVEL_CLOSE          );
    internal__do_hotkey_rebind(cursor, KB_LEVEL_CLOSE_ALL      );
    internal__do_hotkey_rebind(cursor, KB_LEVEL_RESIZE         );
    internal__do_hotkey_rebind(cursor, KB_UNDO                 );
    internal__do_hotkey_rebind(cursor, KB_REDO                 );
    internal__do_hotkey_rebind(cursor, KB_HISTORY_BEGIN        );
    internal__do_hotkey_rebind(cursor, KB_HISTORY_END          );
    internal__do_hotkey_rebind(cursor, KB_CAMERA_ZOOM_OUT      );
    internal__do_hotkey_rebind(cursor, KB_CAMERA_ZOOM_IN       );
    internal__do_hotkey_rebind(cursor, KB_RUN_GAME             );
    internal__do_hotkey_rebind(cursor, KB_RUN_FOCUSED_MOD      );
    internal__do_hotkey_rebind(cursor, KB_FOCUS_NEXT_MOD       );
    internal__do_hotkey_rebind(cursor, KB_FOCUS_PREV_MOD       );
    internal__do_hotkey_rebind(cursor, KB_MODS_LIST            );
    internal__do_hotkey_rebind(cursor, KB_PREFERENCES          );
    internal__do_hotkey_rebind(cursor, KB_ABOUT                );
    internal__do_hotkey_rebind(cursor, KB_BUG_REPORT           );
    internal__do_hotkey_rebind(cursor, KB_BACKUPS              );
    internal__do_hotkey_rebind(cursor, KB_HELP                 );
    internal__do_hotkey_rebind(cursor, KB_TOOL_BRUSH           );
    internal__do_hotkey_rebind(cursor, KB_TOOL_FILL            );
    internal__do_hotkey_rebind(cursor, KB_TOOL_SELECT          );
    internal__do_hotkey_rebind(cursor, KB_FLIP_H               );
    internal__do_hotkey_rebind(cursor, KB_FLIP_V               );
    internal__do_hotkey_rebind(cursor, KB_MIRROR_H_TOGGLE      );
    internal__do_hotkey_rebind(cursor, KB_MIRROR_V_TOGGLE      );
    internal__do_hotkey_rebind(cursor, KB_GPAK_UNPACK          );
    internal__do_hotkey_rebind(cursor, KB_GPAK_PACK            );
    internal__do_hotkey_rebind(cursor, KB_TOGGLE_ENTITY        );
    internal__do_hotkey_rebind(cursor, KB_TOGGLE_GUIDES        );
    internal__do_hotkey_rebind(cursor, KB_TOGGLE_PALETTE       );
    internal__do_hotkey_rebind(cursor, KB_GRID_TOGGLE          );
    internal__do_hotkey_rebind(cursor, KB_BOUNDS_TOGGLE        );
    internal__do_hotkey_rebind(cursor, KB_LAYERS_TOGGLE        );
    internal__do_hotkey_rebind(cursor, KB_CAMERA_RESET         );
    internal__do_hotkey_rebind(cursor, KB_CLEAR_SELECT         );
    internal__do_hotkey_rebind(cursor, KB_DESELECT             );
    internal__do_hotkey_rebind(cursor, KB_SELECT_ALL           );
    internal__do_hotkey_rebind(cursor, KB_COPY                 );
    internal__do_hotkey_rebind(cursor, KB_CUT                  );
    internal__do_hotkey_rebind(cursor, KB_PASTE                );
    internal__do_hotkey_rebind(cursor, KB_INCREMENT_TILE       );
    internal__do_hotkey_rebind(cursor, KB_DECREMENT_TILE       );
    internal__do_hotkey_rebind(cursor, KB_INCREMENT_GROUP      );
    internal__do_hotkey_rebind(cursor, KB_DECREMENT_GROUP      );
    internal__do_hotkey_rebind(cursor, KB_INCREMENT_CATEGORY   );
    internal__do_hotkey_rebind(cursor, KB_DECREMENT_CATEGORY   );
    internal__do_hotkey_rebind(cursor, KB_TOGGLE_LAYER_ACTIVE  );
    internal__do_hotkey_rebind(cursor, KB_TOGGLE_LAYER_TAG     );
    internal__do_hotkey_rebind(cursor, KB_TOGGLE_LAYER_OVERLAY );
    internal__do_hotkey_rebind(cursor, KB_TOGGLE_LAYER_BACK1   );
    internal__do_hotkey_rebind(cursor, KB_TOGGLE_LAYER_BACK2   );
    internal__do_hotkey_rebind(cursor, KB_CATEGORY_BASIC       );
    internal__do_hotkey_rebind(cursor, KB_CATEGORY_TAG         );
    internal__do_hotkey_rebind(cursor, KB_CATEGORY_OVERLAY     );
    internal__do_hotkey_rebind(cursor, KB_CATEGORY_ENTITY      );
    internal__do_hotkey_rebind(cursor, KB_CATEGORY_BACK1       );
    internal__do_hotkey_rebind(cursor, KB_CATEGORY_BACK2       );
    internal__do_hotkey_rebind(cursor, KB_INCREMENT_TAB        );
    internal__do_hotkey_rebind(cursor, KB_DECREMENT_TAB        );
    internal__do_hotkey_rebind(cursor, KB_OPEN_RECENT_TAB      );
    internal__do_hotkey_rebind(cursor, KB_MOVE_TAB_LEFT        );
    internal__do_hotkey_rebind(cursor, KB_MOVE_TAB_RIGHT       );
    internal__do_hotkey_rebind(cursor, KB_LOAD_NEXT_LEVEL      );
    internal__do_hotkey_rebind(cursor, KB_LOAD_PREV_LEVEL      );

    end_panel();
}

FILDEF void internal__do_preferences_modpaths ()
{
    float view_width  = get_viewport().w;
    float view_height = get_viewport().h;

    begin_panel(0, 0, view_width, view_height, UI_NONE, ui_color_medium);
    begin_panel(PREFERENCES_INNER_XPAD, PREFERENCES_INNER_YPAD, view_width - (PREFERENCES_INNER_XPAD * 2), view_height - (PREFERENCES_INNER_YPAD * 2), UI_NONE);

    // We redefine as these will now be different.
    view_width  = get_viewport().w;
    view_height = get_viewport().h;

    const float section_width = roundf(view_width    / 2) - (PREFERENCES_INNER_XPAD / 2);
    const float button_width  = roundf(section_width / 2);

    vec2 cursor(0, 0);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    internal__begin_settings_area("Mod Preferences", cursor);

    internal__do_modpaths_label(section_width, SETTING_MODS_LAYOUT);
    UI_Flag separate_flags = (editor_settings.mods_layout == "separate") ? UI_NONE : UI_INACTIVE; // Figure out why other settings are stored as global variables and called here instead of just referring to editor_settings.
    UI_Flag single_flags   = (editor_settings.mods_layout == "separate") ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, separate_flags, "Separate"))
    {
        if (editor_settings.mods_layout != "separate")
        {
            editor_settings.mods_layout = "separate";
        }
    }
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, single_flags, "Single"))
    {
        if (editor_settings.mods_layout != "single")
        {
            editor_settings.mods_layout = "single";
        }
    }
    internal__next_section(cursor);

    internal__do_modpaths_label(section_width, SETTING_COLORED_TABS);
    UI_Flag tabs_colored_flags = (editor_settings.colored_tabs) ? UI_NONE : UI_INACTIVE;
    UI_Flag tabs_regular_flags = (editor_settings.colored_tabs) ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, tabs_colored_flags, "Enabled"))
    {
        if (!editor_settings.colored_tabs)
        {
            editor_settings.colored_tabs = true;
            internal__refresh_tab_colors(false);
        }
    }
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, tabs_regular_flags, "Disabled"))
    {
        editor_settings.colored_tabs = false;
    }
    internal__next_section(cursor);

    internal__do_modpaths_label(section_width, SETTING_HIGHLIGHT_MOD);
    UI_Flag highlight_mod_enabled_flags  = (editor_settings.highlight_mod) ? UI_NONE : UI_INACTIVE;
    UI_Flag highlight_mod_disabled_flags = (editor_settings.highlight_mod) ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, highlight_mod_enabled_flags, "Enabled"))
    {
        editor_settings.highlight_mod = true;
    }
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, highlight_mod_disabled_flags, "Disabled"))
    {
        editor_settings.highlight_mod = false;
    }
    internal__next_section(cursor);

    internal__do_modpaths_label(section_width, SETTING_FOCUS_TAB_MOD);
    UI_Flag focus_tab_mod_enabled_flags = (editor_settings.focus_tab_mod) ? UI_NONE : UI_INACTIVE;
    UI_Flag focus_tab_mod_disabled_flags = (editor_settings.focus_tab_mod) ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, focus_tab_mod_enabled_flags, "Enabled"))
    {
        editor_settings.focus_tab_mod = true;
    }
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, focus_tab_mod_disabled_flags, "Disabled"))
    {
        editor_settings.focus_tab_mod = false;
    }
    internal__next_section(cursor);

    internal__do_modpaths_label(section_width, SETTING_SHOW_MOD_LIST);
    UI_Flag hide_modlist_enabled_flags = (editor_settings.show_mod_list) ? UI_NONE : UI_INACTIVE;
    UI_Flag hide_modlist_disabled_flags = (editor_settings.show_mod_list) ? UI_INACTIVE : UI_NONE;
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, hide_modlist_enabled_flags, "Enabled"))
    {
        editor_settings.show_mod_list = true;
    }
    if (do_button_txt(NULL, button_width, PREFERENCES_SECTION_H, hide_modlist_disabled_flags, "Disabled"))
    {
        editor_settings.show_mod_list = false;
    }
    internal__next_section(cursor);

    internal__end_settings_area();

    internal__begin_settings_area("Modded Paths", cursor);
    cursor.y -= PREFERENCES_TEXT_BOX_INSET * 3;

    // List of modded paths.
    begin_panel(0, cursor.y, view_width, view_height-cursor.y-PREFERENCES_V_FRAME_H, UI_NONE, ui_color_med_dark);
    set_panel_cursor_dir(UI_DIR_RIGHT);
    cursor.y = 0;
    set_panel_cursor(&cursor);
    view_width  = get_viewport().w;
    view_height = get_viewport().h;

    const float content_height = modpaths.size() * (PREFERENCES_SECTION_H + 1);
    do_scrollbar(view_width - PREFERENCES_SCROLLBAR_WIDTH + 1, -1, PREFERENCES_SCROLLBAR_WIDTH, view_height+1, content_height, modpaths_scroll_offset);

    size_t counter = 0;
    for (auto& it : modpaths) 
    { 
        internal__do_modpath(cursor, &it, counter++);
    }

    end_panel();

    internal__end_settings_area();

    view_width  = get_viewport().w;
    view_height = get_viewport().h;

    cursor = { view_width-button_width-1, view_height-PREFERENCES_V_FRAME_H+4 };
    do_separator(PREFERENCES_SECTION_H);
    if (do_button_txt(NULL, button_width+1, PREFERENCES_SECTION_H, UI_NONE, "Load New Folder")) load_new_modpath();

    end_panel();
    end_panel();
}

FILDEF void init_preferences_menu ()
{
    cached_editor_settings = editor_settings;
    cached_editor_hotkeys  = key_bindings;
    cached_modpaths        = modpaths;
    cached_focused_mod     = editor.focused_mod;

    color_picker_mouse_pressed = false;
}

FILDEF void do_preferences_menu ()
{
    quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2);

    set_ui_font(&get_editor_regular_font());

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    vec2 cursor;

    float pvfh = PREFERENCES_V_FRAME_H;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float tw = roundf(vw / 3);
    float th = pvfh - WINDOW_BORDER;

    float bw = roundf(vw / 3);
    float bh = pvfh - WINDOW_BORDER;

    // Top tabs for switching from the settings and key bindings menu.
    cursor = vec2(0,0);
    begin_panel(0, 0, vw, pvfh, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    UI_Flag settings_flags = (preferences_tab == Preferences_Tab::SETTINGS) ? UI_HIGHLIGHT : UI_INACTIVE;
    UI_Flag hotkeys_flags  = (preferences_tab == Preferences_Tab::HOTKEYS)  ? UI_HIGHLIGHT : UI_INACTIVE;
    UI_Flag modpaths_flags = (preferences_tab == Preferences_Tab::MODPATHS) ? UI_HIGHLIGHT : UI_INACTIVE;

    if (do_button_txt(NULL,   tw,th, settings_flags, "Settings"))  preferences_tab = Preferences_Tab::SETTINGS;
    if (do_button_txt(NULL,   tw,th, hotkeys_flags,  "Hotkeys"))   preferences_tab = Preferences_Tab::HOTKEYS;
    if (do_button_txt(NULL, tw+1,th, modpaths_flags, "Mod Paths")) preferences_tab = Preferences_Tab::MODPATHS;

    // Just in case of weird rounding manually add the right separator.
    cursor.x = vw;
    do_separator(bh);

    // Add a separator to the left for symmetry.
    cursor.x = 1;
    do_separator(bh);

    end_panel();

    // Bottom buttons for saving and exiting or cancelling changes.
    cursor = vec2(0, WINDOW_BORDER);
    begin_panel(0, vh-pvfh, vw, pvfh, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    std::string restore_message;
    switch (preferences_tab)
    {
        case (Preferences_Tab::SETTINGS): restore_message = "Restore Settings";      break;
        case (Preferences_Tab::HOTKEYS):  restore_message = "Restore Hotkeys";       break;
        case (Preferences_Tab::MODPATHS): restore_message = "Restore Mods Settings"; break;
    }

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - (bw*2);

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Save and Exit"  )) save_preferences   ();
    if (do_button_txt(NULL, bw ,bh, UI_NONE, restore_message  )) restore_preferences();
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel and Exit")) cancel_preferences ();

    // Add a separator to the left for symmetry.
    cursor.x = 1;
    do_separator(bh);

    end_panel();

    p2.x =                                  1;
    p2.y = pvfh                           + 1;
    p2.w = get_viewport().w               - 2;
    p2.h = get_viewport().h - p2.y - pvfh - 1;

    begin_panel(p2, UI_NONE);
    switch (preferences_tab)
    {
        case (Preferences_Tab::SETTINGS): internal__do_preferences_settings(); break;
        case (Preferences_Tab::HOTKEYS):  internal__do_preferences_hotkeys();  break;
        case (Preferences_Tab::MODPATHS): internal__do_preferences_modpaths(); break;
    }
    end_panel();

    end_panel();
}

FILDEF void handle_preferences_menu_events ()
{
    if (!is_window_focused("Preferences")) return;

    switch (main_event.type)
    {
        case (SDL_MOUSEWHEEL):
        {
            if (preferences_tab == Preferences_Tab::HOTKEYS)
            {
                preferences_scroll_offset -= (main_event.wheel.y / get_viewport().h) * 4;
                preferences_scroll_offset = std::clamp(preferences_scroll_offset, 0.0f, get_viewport().h);
            }
            else if (preferences_tab == Preferences_Tab::MODPATHS)
            {
                modpaths_scroll_offset -= (main_event.wheel.y / get_viewport().h) * 8;
                modpaths_scroll_offset = std::clamp(modpaths_scroll_offset, 0.0f, get_viewport().h);
            }
        } break;
        case (SDL_KEYDOWN):
        {
            if (!text_box_is_active() && !hotkey_is_active())
            {
                switch (main_event.key.keysym.sym)
                {
                    case (SDLK_RETURN): save_preferences();   break;
                    case (SDLK_ESCAPE): cancel_preferences(); break;
                }
            }
        } break;
    }
}

FILDEF void restore_preferences ()
{
    switch (preferences_tab)
    {
        case (Preferences_Tab::SETTINGS): restore_editor_settings();     break;
        case (Preferences_Tab::HOTKEYS):  restore_editor_key_bindings(); break;
        case (Preferences_Tab::MODPATHS): restore_modpath_settings();    break;
    }
}

FILDEF void cancel_preferences ()
{
    // We only want to shot this prompt if the user actually made any changes to preferences.
    if (editor_settings != cached_editor_settings 
        || key_bindings != cached_editor_hotkeys 
        || modpaths != cached_modpaths)
    {
        // Make sure the user is certain about what they are doing and cancel the
        // action if they decide that they do not actually want to discard changes.
        if (show_alert("Discard Changes", "Are you sure you want to discard changes?", ALERT_TYPE_WARNING, ALERT_BUTTON_YES_NO, "Preferences") == ALERT_RESULT_NO)
        {
            return;
        }
    }

    bool tile_graphics_changed = (editor_settings.tile_graphics != cached_editor_settings.tile_graphics);

    // Restore the settings/hotkeys states from before modifying preferences.
    editor_settings    = cached_editor_settings;
    key_bindings       = cached_editor_hotkeys;
    modpaths           = cached_modpaths;
    editor.focused_mod = cached_focused_mod;

    update_systems_that_rely_on_settings(tile_graphics_changed);

    hide_window("ColorPicker");
    hide_window("IconPicker");
    hide_window("Preferences");
}

FILDEF void save_preferences ()
{
    // No point saving unless there were changes.
    if (editor_settings != cached_editor_settings || 
        key_bindings != cached_editor_hotkeys)
    {
        internal__save_settings();
    }
    if (modpaths != cached_modpaths)
    {
        internal__save_modded_paths();
        internal__refresh_tab_colors(true);
        if (editor.focused_mod >= modpaths.size()) editor.focused_mod = 0;
    }

    hide_window("ColorPicker");
    hide_window("IconPicker");
    hide_window("Preferences");
}
