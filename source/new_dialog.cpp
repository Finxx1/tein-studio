GLOBAL constexpr float NEW_V_FRAME_H = 26;

GLOBAL constexpr float NEW_XPAD = 8;
GLOBAL constexpr float NEW_YPAD = 8;

GLOBAL constexpr float NEW_TEXT_BOX_H = 20;

GLOBAL constexpr const char* NEW_WIDTH_LABEL = "Level Width:  ";
GLOBAL constexpr const char* NEW_HEIGHT_LABEL = "Level Height:  ";

GLOBAL int current_new_width  = CAST(int, DEFAULT_LEVEL_WIDTH);
GLOBAL int current_new_height = CAST(int, DEFAULT_LEVEL_HEIGHT);

GLOBAL Tab_Type current_tab_type = Tab_Type::LEVEL;

FILDEF void internal__okay_new ()
{
    if (current_new_width < MINIMUM_LEVEL_WIDTH || current_new_height < MINIMUM_LEVEL_HEIGHT)
    {
        show_alert("Warning", format_string("Minimum level size is %dx%d!", MINIMUM_LEVEL_WIDTH, MINIMUM_LEVEL_HEIGHT), ALERT_TYPE_WARNING, ALERT_BUTTON_OK, "New");
        return;
    }
    switch (current_tab_type)
    {
        case (Tab_Type::LEVEL):
        {
            LOG_DEBUG("Creating blank level of size %dx%d!", get_new_w(), get_new_h());
            create_new_level_tab_and_focus(get_new_w(), get_new_h());
        } break;
        case (Tab_Type::MAP):
        {
            LOG_DEBUG("Creating blank world map!");
            create_new_map_tab_and_focus();
        } break;
    }

    hide_window("New");
}

FILDEF void open_new ()
{
    current_new_width = CAST(int, DEFAULT_LEVEL_WIDTH);
    current_new_height = CAST(int, DEFAULT_LEVEL_HEIGHT);

    // Default to level because people make more levels than they do maps.
    current_tab_type = Tab_Type::LEVEL;

    show_window("New");
}

FILDEF void do_new ()
{
    quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2);

    set_ui_font(&get_editor_regular_font());

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    vec2 cursor;

    float nvfh = NEW_V_FRAME_H;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float bw = roundf(vw / 2);
    float bh = nvfh - WINDOW_BORDER;

    // Top tabs for switching type of file to create.
    cursor = vec2(0,0);
    begin_panel(0, 0, vw, nvfh, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    UI_Flag level_flags = (current_tab_type == Tab_Type::LEVEL) ? UI_HIGHLIGHT : UI_INACTIVE;
    UI_Flag map_flags   = (current_tab_type == Tab_Type::MAP  ) ? UI_HIGHLIGHT : UI_INACTIVE;

    if (do_button_txt(NULL, bw,bh, level_flags, "Level"    )) current_tab_type = Tab_Type::LEVEL;
    if (do_button_txt(NULL, bw,bh, map_flags,   "World Map")) current_tab_type = Tab_Type::MAP;

    // Just in case of weird rounding manually add the right separator.
    cursor.x = vw;
    do_separator(bh);

    // Add a separator to the left for symmetry.
    cursor.x = 1;
    do_separator(bh);

    end_panel();

    // Bottom buttons for okaying or cancelling the resize.
    cursor = vec2(0, WINDOW_BORDER);
    begin_panel(0, vh-nvfh, vw, nvfh, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - bw;

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Create")) internal__okay_new();
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel")) cancel_new();

    // Add a separator to the left for symmetry.
    cursor.x = 1;
    do_separator(bh);

    end_panel();

    p2.x =                    1;
    p2.y = nvfh             + 1;
    p2.w = vw               - 2;
    p2.h = vh - p2.y - nvfh - 1;

    UI_Flag panel_flags = (current_tab_type == Tab_Type::LEVEL) ? UI_NONE : UI_LOCKED;
    begin_panel(p2, panel_flags, ui_color_medium);

    cursor = vec2(NEW_XPAD, NEW_YPAD);

    set_panel_cursor_dir(UI_DIR_DOWN);
    set_panel_cursor(&cursor);

    float label_w_w = get_text_width_scaled(get_editor_regular_font(), NEW_WIDTH_LABEL);
    float label_h_w = get_text_width_scaled(get_editor_regular_font(), NEW_HEIGHT_LABEL);

    float text_box_w = (vw-(NEW_XPAD*2));
    float label_w = std::max(label_w_w, label_h_w);

    std::string w_str(std::to_string(current_new_width));
    std::string h_str(std::to_string(current_new_height));

    do_text_box_labeled(text_box_w, NEW_TEXT_BOX_H, UI_NUMERIC, w_str, label_w, NEW_WIDTH_LABEL, "0");
    advance_panel_cursor(NEW_YPAD);
    do_text_box_labeled(text_box_w, NEW_TEXT_BOX_H, UI_NUMERIC, h_str, label_w, NEW_HEIGHT_LABEL, "0");

    if (atoi(w_str.c_str()) > MAXIMUM_LEVEL_WIDTH)
    {
        w_str = std::to_string(MAXIMUM_LEVEL_WIDTH);
    }
    if (atoi(h_str.c_str()) > MAXIMUM_LEVEL_HEIGHT)
    {
        h_str = std::to_string(MAXIMUM_LEVEL_HEIGHT);
    }

    int old_new_width = current_new_width;
    int new_new_width = atoi(w_str.c_str());
    if (new_new_width != old_new_width)
    {
        current_new_width = new_new_width;
    }
    int old_new_height = current_new_height;
    int new_new_height = atoi(h_str.c_str());
    if (new_new_height != old_new_height)
    {
        current_new_height = new_new_height;
    }

    end_panel();

    end_panel();
}

FILDEF void cancel_new ()
{
    hide_window("New");
}

FILDEF void handle_new_events ()
{
    if (is_window_focused("New"))
    {
        if (!text_box_is_active())
        {
            if (main_event.type == SDL_KEYDOWN)
            {
                switch (main_event.key.keysym.sym)
                {
                    case (SDLK_RETURN): internal__okay_new(); break;
                    case (SDLK_ESCAPE): cancel_new();         break;
                }
            }
        }
    }
}

FILDEF int get_new_w ()
{
    return current_new_width;
}

FILDEF int get_new_h ()
{
    return current_new_height;
}
