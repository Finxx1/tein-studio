// More GLOBALs! As a treat!
constexpr float MODSLIST_SECTION_H = 48;
constexpr float ICON_WIDTH = 31;
constexpr float BUTTON_WIDTH = 48;
GLOBAL    float mods_list_scroll_offset = 0;

FILDEF void internal__do_modname_label(float w, const char* name)
{
    do_label(UI_ALIGN_LEFT, UI_ALIGN_CENTER, w, MODSLIST_SECTION_H, name);

    advance_panel_cursor(PREFERENCES_INNER_XPAD / 2);
    do_separator(MODSLIST_SECTION_H);
    advance_panel_cursor(PREFERENCES_INNER_XPAD / 2);
}

FILDEF void internal__do_mod_icon(float x, float y, vec4 color, quad& icon) {
    // Make sure that the necessary components are assigned.
    set_ui_texture(&resource_mod_icons);
    ASSERT(ui_texture);

    vec4 shadow = (ui_is_light) ? vec4(.9f, .9f, .9f, 1) : vec4(.16f, .16f, .16f, 1);
    float offset = (ui_is_light) ? -1.0f : 1.0f;

    Texture& tex = *ui_texture;
    tex.color = shadow;
    draw_texture(tex, x, y-offset, &icon);
    tex.color = color;
    draw_texture(tex, x, y, &icon);

    set_ui_texture(&resource_icons);
}

FILDEF void internal__do_mod(vec2& cursor, ModPath& modpath, bool is_focused)
{
    const float scroll_y        = ui_panels.top().relative_offset.y;
    if ((cursor.y + MODSLIST_SECTION_H < -scroll_y) || (cursor.y > get_viewport().h-scroll_y))
    {
        // Makes sure this row is not out of screenview to prevent weird 
        // behaviour with off-screen highlighted buttons and scrollbars. 
        // ( Band-aid solution? Band-aid solution! )
        cursor.y += MODSLIST_SECTION_H + 1;
        return;
    }

    const bool  show_highlight  = (is_focused && editor_settings.highlight_mod);
    const float view_width      =  get_viewport().w - (PREFERENCES_SCROLLBAR_WIDTH - 1);
    const float text_width      =  view_width-BUTTON_WIDTH*2-ICON_WIDTH-PREFERENCES_INNER_XPAD*3;
    const float text_height     =  MODSLIST_SECTION_H - (PREFERENCES_TEXT_BOX_INSET * 2);
    const vec4  highlight_color =  ui_is_light    ? ui_color_white  : vec4(.37f, .37f, 0.37f, 1);
    const vec4  focus_color     =  show_highlight ? highlight_color : ui_color_medium;

    do_quad(view_width, MODSLIST_SECTION_H, modpath.exists ? focus_color : ui_color_med_dark);
    cursor.x = roundf(PREFERENCES_INNER_XPAD * 2.5f);

    cursor.y += PREFERENCES_TEXT_BOX_INSET;

    internal__do_mod_icon(cursor.x, cursor.y+scroll_y+roundf(text_height /2), modpath.color, modpath.icon);
    cursor.x += ICON_WIDTH;

    internal__do_modname_label(text_width, modpath.name.c_str());
    cursor.x -= roundf(PREFERENCES_INNER_XPAD / 1.5f) - 1;

    UI_Flag highlight_flags = show_highlight ? UI_HIGHLIGHT    : UI_NONE;
    UI_Flag exists_flags    = modpath.exists ? highlight_flags : UI_LOCKED;

    // Open Folder and Play Mod buttons.
    if (do_button_img(NULL, BUTTON_WIDTH, text_height, exists_flags, &CLIP_LOAD))
    {
        if (!does_path_exist(modpath.path)) { modpath.exists = false; }
        else { open_folder(modpath.path.c_str()); }
    }
    if (do_button_img(NULL, BUTTON_WIDTH, text_height, exists_flags, &CLIP_RUN))
    {
        if (!does_path_exist(modpath.path)) { modpath.exists = false; }
        else { run_game_with_params(modpath.path.c_str()); }
    }

    cursor.y -= PREFERENCES_TEXT_BOX_INSET;

    cursor.x  = 0;
    cursor.y += MODSLIST_SECTION_H + 1;
}

FILDEF void internal__do_mods_list()
{
    float vw = get_viewport().w;
    float vh = get_viewport().h;

    begin_panel(0, 0, vw, vh, UI_NONE);

    vec2 cursor(0, 0);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    float content_height = modpaths.size() * (MODSLIST_SECTION_H + 1) -2;

    do_scrollbar(vw - PREFERENCES_SCROLLBAR_WIDTH + 1, -1, PREFERENCES_SCROLLBAR_WIDTH, vh + 2, content_height, mods_list_scroll_offset);

    const size_t FOCUSED_MOD = editor.focused_mod;
    size_t counter = 0;
    for (auto& it : modpaths)
    {
        internal__do_mod(cursor, it, counter++==FOCUSED_MOD);
    }

    end_panel();
}

FILDEF void do_mods_list()
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

    p2.x = 1;
    p2.y = 1;
    p2.w = get_viewport().w - 2;
    p2.h = get_viewport().h - 2;

    begin_panel(p2, UI_NONE);
    internal__do_mods_list();

    end_panel();
    end_panel();
}

FILDEF void handle_mods_list_events()
{
    if (!is_window_focused("ModsList")) return;

    switch (main_event.type)
    {
        case (SDL_MOUSEWHEEL):
        {
            mods_list_scroll_offset -= (main_event.wheel.y / get_viewport().h) * 4;
            mods_list_scroll_offset = std::clamp(mods_list_scroll_offset, 0.0f, get_viewport().h);
        } break;
        case (SDL_KEYDOWN):
        {
            switch (main_event.key.keysym.sym)
            {
            case (SDLK_ESCAPE): hide_window("ModsList"); break;
            case (SDLK_RETURN): hb_run_focused_mod();    break;
            case (SDLK_UP):     focus_prev_mod();        break;
            case (SDLK_DOWN):   focus_next_mod();        break;
            }
        } break;
    }
}
