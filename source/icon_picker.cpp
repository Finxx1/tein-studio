//GLOBAL bool icon_picker_mouse_pressed;

// When the color picker menu is opened we cache the current color value.
// This allows the color picker menu to modify the current color immediately
// for instant feedback. If the user then wants to cancel the changes made,
// we can just restore the cached version of the color to turn it back.

GLOBAL quad* current_icon_picker_icon;
GLOBAL quad  cached_icon_picker_icon;

FILDEF void internal__do_icon_picker (vec2& cursor, float w, float h)
{
    ASSERT(ui_texture);

    Texture& tex = *ui_texture;

    // We scissor the contents to avoid image overspill.
    begin_scissor(cursor.x, cursor.y, w, h);
    defer{ end_scissor(); };

    float x1 = cursor.x;
    float y1 = cursor.y;
    float x2 = cursor.x + w;
    float y2 = cursor.y + h;

    set_draw_color(ui_color_med_dark);
    fill_quad(x1, y1, x2, y2);

    // Selected quadrant.
    ASSERT(current_icon_picker_icon);
    quad& i = *current_icon_picker_icon;
    x1 = x1+i.x1;
    y1 = y1+i.y1;
    x2 = x1+i.x2;
    y2 = y1+i.y2;
    set_draw_color(ui_color_white);
    fill_quad(  x1,   y1,   x2,   y2);
    set_draw_color(ui_color_med_light);
    fill_quad(x1+1, y1+1, x2-1, y2-1);

    x1 = cursor.x + roundf(w / 2);
    y1 = cursor.y + roundf(h / 2);
    tex.color = ui_color_white;
    draw_texture(tex, x1, y1, &CLIP_MOD_ICONS);
}

FILDEF void internal__move_icon_marker (float x, float y)
{
    float new_x = current_icon_picker_icon->x + x;
    float new_y = current_icon_picker_icon->y + y;
    if (new_x != current_icon_picker_icon->x)
    {
        if (new_x >= 0 && new_x < CLIP_MOD_ICONS.w) current_icon_picker_icon->x = new_x;
    }
    else if (new_y != current_icon_picker_icon->y)
    {
        if (new_y >= 0 && new_y < CLIP_MOD_ICONS.h) current_icon_picker_icon->y = new_y;
    }
}

FILDEF void internal__okay_icon ()
{
    hide_window("IconPicker");
}

FILDEF void internal__cancel_icon ()
{
    ASSERT(current_icon_picker_icon);
    *current_icon_picker_icon = cached_icon_picker_icon;

    hide_window("IconPicker");
}

FILDEF void open_icon_picker (quad* icon)
{
    raise_window("IconPicker");

    ASSERT(icon);

    current_icon_picker_icon =  icon;
    cached_icon_picker_icon  = *icon;

    if (is_window_hidden("IconPicker"))
    {
        show_window("IconPicker");
    }
}

FILDEF void do_icon_picker ()
{
    if (is_window_hidden("IconPicker")) return;

    quad p1, p2;

    p1.x = WINDOW_BORDER;
    p1.y = WINDOW_BORDER;
    p1.w = get_viewport().w - (WINDOW_BORDER * 2);
    p1.h = get_viewport().h - (WINDOW_BORDER * 2);

    set_ui_font(&get_editor_regular_font());

    begin_panel(p1, UI_NONE, ui_color_ex_dark);

    // It says color picker, but we're using it here.
    float bb = COLOR_PICKER_BOTTOM_BORDER;

    float vw = get_viewport().w;
    float vh = get_viewport().h;

    float bw = roundf(vw / 2);
    float bh = bb - WINDOW_BORDER;

    // Bottom buttons for okaying or cancelling the icon picker.
    vec2 btn_cursor(0, WINDOW_BORDER);
    begin_panel(0, vh-bb, vw, bb, UI_NONE, ui_color_medium);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&btn_cursor);

    // Just to make sure that we always reach the end of the panel space.
    float bw2 = vw - bw;

    if (do_button_txt(NULL, bw ,bh, UI_NONE, "Okay"  )) internal__okay_icon();
    if (do_button_txt(NULL, bw2,bh, UI_NONE, "Cancel")) internal__cancel_icon();

    // Add a separator to the left for symmetry.
    btn_cursor.x = 1;
    do_separator(bh);

    end_panel();

    p2.x =                  1;
    p2.y =                  1;
    p2.w = vw             - 2;
    p2.h = vh - p2.y - bb - 1;

    begin_panel(p2, UI_NONE, ui_color_medium);
    vw = get_viewport().w;
    vh = get_viewport().h;

    vec2 cursor(0, 0);

    set_panel_cursor_dir(UI_DIR_RIGHT);
    set_panel_cursor(&cursor);

    // Draw the icon picker itself.
    set_ui_texture(&resource_mod_icons);
    internal__do_icon_picker(cursor, vw, vh);

    end_panel();
    end_panel();
}

FILDEF void cancel_icon_picker ()
{
    internal__cancel_icon();
}

FILDEF void handle_icon_picker_events ()
{
    if (!is_window_focused("IconPicker")) return;

    // Determine if the mouse was pressed this update/cycle.
    switch (main_event.type)
    {
        case (SDL_MOUSEBUTTONDOWN):
        {
            if (main_event.button.button == SDL_BUTTON_LEFT)
            {
                
            }
        } break;
        case (SDL_MOUSEBUTTONUP):
        {
            if (main_event.button.button == SDL_BUTTON_LEFT)
            {
                if (get_render_target()->mouse)
                {
                    vec2 mouse  = get_mouse_pos();
                    const float border = WINDOW_BORDER + 1;
                    bool inside = point_in_bounds_xywh(mouse, {border, border, CLIP_MOD_ICONS.w, CLIP_MOD_ICONS.h});
                    if (inside)
                    {
                        current_icon_picker_icon->x = floorf((mouse.x-border) / 24)*24;
                        current_icon_picker_icon->y = floorf((mouse.y-border) / 24)*24;
                    }
                }
            }
        } break;
        case (SDL_KEYDOWN):
        {
            switch (main_event.key.keysym.sym)
            {
                case (SDLK_RETURN): internal__okay_icon();              break;
                case (SDLK_ESCAPE): internal__cancel_icon();            break;
                case (SDLK_LEFT):   internal__move_icon_marker(-24,0);  break;
                case (SDLK_RIGHT):  internal__move_icon_marker( 24,0);  break;
                case (SDLK_UP):     internal__move_icon_marker(0,-24);  break;
                case (SDLK_DOWN):   internal__move_icon_marker(0, 24);  break;
            }
        } break;
    }
}
