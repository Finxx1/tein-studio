GLOBAL constexpr const char* TB_INFO_BRUSH    = "Brush Tool: Allows for placing and erasing of single tiles.";
GLOBAL constexpr const char* TB_INFO_FILL     = "Fill Tool: Fills or erases a given region with tiles.";
GLOBAL constexpr const char* TB_INFO_SELECT   = "Select Tool: Click and drag to select tiles for copy, cut, delete, grouping, etc.";
GLOBAL constexpr const char* TB_INFO_GRID     = "Grid: Toggle the tile grid on and off.";
GLOBAL constexpr const char* TB_INFO_BOUNDS   = "Bounds: Toggle the shaded out-of-bounds region on and off.";
GLOBAL constexpr const char* TB_INFO_LAYERS   = "Layer Transparency: Toggles the transparency applied to layers above the active layer.";
GLOBAL constexpr const char* TB_INFO_CAMERA   = "Reset Camera: Return to the editor's default position and zoom.";
GLOBAL constexpr const char* TB_INFO_RESIZE   = "Resize: Resize the boundaries of the level.";
GLOBAL constexpr const char* TB_INFO_FLIP_H   = "Flip Horizontal: Flip the level's content horizontally.";
GLOBAL constexpr const char* TB_INFO_FLIP_V   = "Flip Vertical: Flip the level's content vertically.";
GLOBAL constexpr const char* TB_INFO_MIRROR_H = "Mirror Horizontal: Toggle horizontal symmetry on and off.";
GLOBAL constexpr const char* TB_INFO_MIRROR_V = "Mirror Vertical: Toggle vertical symmetry on and off.";
GLOBAL constexpr const char* TB_INFO_CUT      = "Cut: Copy and delete the currently selected region.";
GLOBAL constexpr const char* TB_INFO_COPY     = "Copy: Copy the currently selected region.";
GLOBAL constexpr const char* TB_INFO_DESELECT = "Deselect: Removes the current box selection.";
GLOBAL constexpr const char* TB_INFO_CLEAR    = "Clear Selection: Deletes everything inside the current selection.";
GLOBAL constexpr const char* TB_INFO_ENTITY   = "Large Entities: Toggles entity graphics to represent their in-game size.";
GLOBAL constexpr const char* TB_INFO_GUIDES   = "Entity Guides: Toggles guides to showcase entity placement and bounds.";
GLOBAL constexpr const char* TB_INFO_PALETTE  = "Palette: Toggles tile graphics to reflect their color in the palette.";

GLOBAL constexpr float TOTAL_TOOLBAR_LVL_BUTTONS = 18;
GLOBAL constexpr float TOTAL_TOOLBAR_MAP_BUTTONS =  1;
GLOBAL           float toolbar_width = TOOLBAR_WIDTH;

FILDEF void internal__do_level_toolbar ()
{
    vec2 cursor(TOOLBAR_INNER_PAD, TOOLBAR_INNER_PAD);

    // Dimensions for the toolbar buttons.
    float bw = TOOLBAR_WIDTH - (TOOLBAR_INNER_PAD * 2);
    float bh = 25;

    set_ui_texture(&resource_icons);

    UI_Flag brush_flags    = UI_NONE;
    UI_Flag fill_flags     = UI_NONE;
    UI_Flag select_flags   = UI_NONE;
    UI_Flag grid_flags     = UI_NONE;
    UI_Flag bounds_flags   = UI_NONE;
    UI_Flag layer_flags    = UI_NONE;
    UI_Flag entity_flags   = UI_NONE;
    UI_Flag guide_flags    = UI_NONE;
    UI_Flag flip_h_flags   = UI_NONE;
    UI_Flag flip_v_flags   = UI_NONE;
    UI_Flag mirror_h_flags = UI_NONE;
    UI_Flag mirror_v_flags = UI_NONE;
    UI_Flag cut_flags      = UI_NONE;
    UI_Flag copy_flags     = UI_NONE;
    UI_Flag deselect_flags = UI_NONE;
    UI_Flag clear_flags    = UI_NONE;
    UI_Flag palette_flags  = UI_NONE;

    brush_flags    = (level_editor.tool_type == Tool_Type::BRUSH)  ? UI_NONE : UI_INACTIVE;
    fill_flags     = (level_editor.tool_type == Tool_Type::FILL)   ? UI_NONE : UI_INACTIVE;
    select_flags   = (level_editor.tool_type == Tool_Type::SELECT) ? UI_NONE : UI_INACTIVE;
    grid_flags     = (editor.grid_visible)                         ? UI_NONE : UI_INACTIVE;
    bounds_flags   = (level_editor.bounds_visible)                 ? UI_NONE : UI_INACTIVE;
    layer_flags    = (level_editor.layer_transparency)             ? UI_NONE : UI_INACTIVE;
    entity_flags   = (level_editor.large_tiles)                    ? UI_NONE : UI_INACTIVE;
    guide_flags    = (level_editor.entity_guides)                  ? UI_NONE : UI_INACTIVE;
    flip_h_flags   =                                                 UI_NONE;
    flip_v_flags   =                                                 UI_NONE;
    mirror_h_flags = (level_editor.mirror_h)                       ? UI_NONE : UI_INACTIVE;
    mirror_v_flags = (level_editor.mirror_v)                       ? UI_NONE : UI_INACTIVE;
    palette_flags  = (level_editor.palette)                        ? UI_NONE : UI_INACTIVE;

    guide_flags |= (level_editor.large_tiles) ? UI_NONE : UI_LOCKED;

    cut_flags      = (are_any_select_boxes_visible())              ? UI_NONE : UI_LOCKED;
    copy_flags     = (are_any_select_boxes_visible())              ? UI_NONE : UI_LOCKED;
    deselect_flags = (are_any_select_boxes_visible())              ? UI_NONE : UI_LOCKED;
    clear_flags    = (are_any_select_boxes_visible())              ? UI_NONE : UI_LOCKED;

    // If not all buttons will fit on the screen we will double the width of the
    // toolbar and then place the buttons side-to-side instead of straight down.
    float content_height = (bh*TOTAL_TOOLBAR_LVL_BUTTONS)+(TOOLBAR_INNER_PAD*2);
    toolbar_width = TOOLBAR_WIDTH;
    if (get_viewport().h < content_height)
    {
        toolbar_width *= 2;
        toolbar_width -= 1;
    }

    // The toolbar is a vertical list of available tools.
    begin_panel(0, 0, toolbar_width, get_viewport().h, UI_NONE, ui_color_medium);

    set_panel_cursor(&cursor);
    set_panel_cursor_dir(UI_DIR_DOWN);

    do_button_img(tb_set_tool_to_brush,  bw,bh, brush_flags,     &CLIP_BRUSH,           TB_INFO_BRUSH,           KB_TOOL_BRUSH,     "Brush");
    do_button_img(tb_set_tool_to_fill,   bw,bh, fill_flags,      &CLIP_FILL,            TB_INFO_FILL,            KB_TOOL_FILL,      "Fill");
    do_button_img(tb_set_tool_to_select, bw,bh, select_flags,    &CLIP_SELECT,          TB_INFO_SELECT,          KB_TOOL_SELECT,    "Select");
    do_button_img(tb_toggle_grid,        bw,bh, grid_flags,      &CLIP_GRID,            TB_INFO_GRID,            KB_GRID_TOGGLE,    "Grid");
    do_button_img(tb_toggle_bounds,      bw,bh, bounds_flags,    &CLIP_BOUNDS,          TB_INFO_BOUNDS,          KB_BOUNDS_TOGGLE,  "Bounds");
    do_button_img(tb_toggle_layer_trans, bw,bh, layer_flags,     &CLIP_LAYERS,          TB_INFO_LAYERS,          KB_LAYERS_TOGGLE,  "Layer Transparency");
    do_button_img(tb_reset_camera,       bw,bh, UI_NONE,         &CLIP_CAMERA,          TB_INFO_CAMERA,          KB_CAMERA_RESET,   "Reset Camera");
    do_button_img(tb_toggle_entity,      bw,bh, entity_flags,    &CLIP_ENTITY,          TB_INFO_ENTITY,          KB_TOGGLE_ENTITY,  "Toggle Large Entities");
    do_button_img(tb_toggle_guides,      bw,bh, guide_flags,     &CLIP_GUIDES,          TB_INFO_GUIDES,          KB_TOGGLE_GUIDES,  "Toggle Entity Guides");
    do_button_img(tb_toggle_palette,     bw,bh, palette_flags,   &CLIP_PALETTE,         TB_INFO_PALETTE,         KB_TOGGLE_PALETTE, "Toggle Palette Coloring");

    // If not all buttons will fit on the screen we will double the width of the
    // toolbar and then place the buttons side-to-side instead of straight down.
    if (get_viewport().h < content_height)
    {
        cursor.x += bw + 1;
        cursor.y = TOOLBAR_INNER_PAD;

        set_panel_cursor_dir(UI_DIR_RIGHT);
        do_separator((bh*ceilf(TOTAL_TOOLBAR_LVL_BUTTONS/2)));
        set_panel_cursor_dir(UI_DIR_DOWN);

        cursor.x -= 1;
        cursor.y = TOOLBAR_INNER_PAD;
    }

    do_button_img(tb_resize,             bw,bh, UI_NONE,         &CLIP_RESIZE,          TB_INFO_RESIZE,          KB_LEVEL_RESIZE,    "Resize");
    do_button_img(tb_flip_level_h,       bw,bh, flip_h_flags,    &CLIP_FLIP_H,          TB_INFO_FLIP_H,          KB_FLIP_H,          "Flip Horizontal");
    do_button_img(tb_flip_level_v,       bw,bh, flip_v_flags,    &CLIP_FLIP_V,          TB_INFO_FLIP_V,          KB_FLIP_V,          "Flip Vertical");
    do_button_img(tb_toggle_mirror_h,    bw,bh, mirror_h_flags,  &CLIP_MIRROR_H,        TB_INFO_MIRROR_H,        KB_MIRROR_H_TOGGLE, "Mirror Horizontal");
    do_button_img(tb_toggle_mirror_v,    bw,bh, mirror_v_flags,  &CLIP_MIRROR_V,        TB_INFO_MIRROR_V,        KB_MIRROR_V_TOGGLE, "Mirror Vertical");
    do_button_img(tb_cut,                bw,bh, cut_flags,       &CLIP_CUT,             TB_INFO_CUT,             KB_CUT,             "Cut");
    do_button_img(tb_copy,               bw,bh, copy_flags,      &CLIP_COPY,            TB_INFO_COPY,            KB_COPY,            "Copy");
    do_button_img(tb_deselect,           bw,bh, deselect_flags,  &CLIP_DESELECT,        TB_INFO_DESELECT,        KB_DESELECT,        "Deselect");
    do_button_img(tb_clear_select,       bw,bh, clear_flags,     &CLIP_CLEAR,           TB_INFO_CLEAR,           KB_CLEAR_SELECT,    "Clear Selection");

    end_panel();
}

FILDEF void internal__do_map_toolbar ()
{
    vec2 cursor(TOOLBAR_INNER_PAD, TOOLBAR_INNER_PAD);

    // Dimensions for the toolbar buttons.
    float bw = TOOLBAR_WIDTH - (TOOLBAR_INNER_PAD * 2);
    float bh = 25;

    set_ui_texture(&resource_icons);

    Tab& tab = get_current_tab();

    // @Incomplete: Want to check if the active node's LVL text is a properly formatted as tileset-level!!!
    // @Incomplete: Want to check if the active node's LVL text is a properly formatted as tileset-level!!!
    // @Incomplete: Want to check if the active node's LVL text is a properly formatted as tileset-level!!!
    // @Incomplete: Want to check if the active node's LVL text is a properly formatted as tileset-level!!!
    UI_Flag add_left       = (tab.map_node_info.active && !tab.map_node_info.active->lvl.empty()) ? UI_NONE : UI_LOCKED;
    UI_Flag add_right      = (tab.map_node_info.active && !tab.map_node_info.active->lvl.empty()) ? UI_NONE : UI_LOCKED;
    UI_Flag add_up         = (tab.map_node_info.active && !tab.map_node_info.active->lvl.empty()) ? UI_NONE : UI_LOCKED;
    UI_Flag add_down       = (tab.map_node_info.active && !tab.map_node_info.active->lvl.empty()) ? UI_NONE : UI_LOCKED;
    UI_Flag cut_flags      = (map_select_box_present()) ? UI_NONE : UI_LOCKED;
    UI_Flag copy_flags     = (map_select_box_present()) ? UI_NONE : UI_LOCKED;
    UI_Flag deselect_flags = (map_select_box_present()) ? UI_NONE : UI_LOCKED;
    UI_Flag clear_flags    = (map_select_box_present()) ? UI_NONE : UI_LOCKED;

    toolbar_width = TOOLBAR_WIDTH;
    begin_panel(0, 0, toolbar_width, get_viewport().h, UI_NONE, ui_color_medium);

    set_panel_cursor(&cursor);
    set_panel_cursor_dir(UI_DIR_DOWN);

    do_button_img(tb_reset_camera, bw,bh, UI_NONE,        &CLIP_CAMERA,   TB_INFO_CAMERA,   KB_CAMERA_RESET, "Reset Camera"   );
    do_button_img(tb_cut,          bw,bh, cut_flags,      &CLIP_CUT,      TB_INFO_CUT,      KB_CUT,          "Cut"            );
    do_button_img(tb_copy,         bw,bh, copy_flags,     &CLIP_COPY,     TB_INFO_COPY,     KB_COPY,         "Copy"           );
    do_button_img(tb_deselect,     bw,bh, deselect_flags, &CLIP_DESELECT, TB_INFO_DESELECT, KB_DESELECT,     "Deselect"       );
    do_button_img(tb_clear_select, bw,bh, clear_flags,    &CLIP_CLEAR,    TB_INFO_CLEAR,    KB_CLEAR_SELECT, "Clear Selection");

    end_panel();
}

FILDEF void do_toolbar ()
{
    if (are_there_any_tabs())
    {
        if (current_tab_is_level()) internal__do_level_toolbar();
        else                        internal__do_map_toolbar();
    }
}

FILDEF float get_toolbar_w ()
{
    return ((are_there_any_tabs()) ? toolbar_width : 0);
}

FILDEF void tb_set_tool_to_brush ()
{
    if (!current_tab_is_level()) return;

    if (level_editor.tool_type == Tool_Type::SELECT && level_editor.tool_state == Tool_State::PLACE)
    {
        Tab& tab = get_current_tab();
        if (!tab.tool_info.select.bounds.empty())
        {
            new_level_history_state(Level_History_Action::SELECT_STATE);
        }
    }

    if (level_editor.tool_type != Tool_Type::BRUSH && level_editor.tool_state != Tool_State::IDLE)
    {
        new_level_history_state(Level_History_Action::NORMAL);
    }

    level_editor.tool_type = Tool_Type::BRUSH;
}

FILDEF void tb_set_tool_to_fill ()
{
    if (!current_tab_is_level()) return;

    if (level_editor.tool_type == Tool_Type::SELECT && level_editor.tool_state == Tool_State::PLACE)
    {
        Tab& tab = get_current_tab();
        if (!tab.tool_info.select.bounds.empty())
        {
            new_level_history_state(Level_History_Action::SELECT_STATE);
        }
    }

    if (level_editor.tool_type != Tool_Type::FILL && level_editor.tool_state != Tool_State::IDLE)
    {
        new_level_history_state(Level_History_Action::NORMAL);
    }

    level_editor.tool_type = Tool_Type::FILL;
}

FILDEF void tb_set_tool_to_select ()
{
    if (!current_tab_is_level()) return;

    if (level_editor.tool_type != Tool_Type::SELECT && level_editor.tool_state != Tool_State::IDLE)
    {
        new_level_history_state(Level_History_Action::NORMAL);
    }

    if (level_editor.tool_state == Tool_State::PLACE)
    {
        Tab& tab = get_current_tab();
        tab.tool_info.select.start = true;
    }

    level_editor.tool_type = Tool_Type::SELECT;
}

FILDEF void tb_toggle_grid ()
{
    if (current_tab_is_level()) editor.grid_visible = !editor.grid_visible;
}

FILDEF void tb_toggle_bounds ()
{
    if (current_tab_is_level()) level_editor.bounds_visible = !level_editor.bounds_visible;
}

FILDEF void tb_toggle_layer_trans ()
{
    if (current_tab_is_level()) level_editor.layer_transparency = !level_editor.layer_transparency;
}

FILDEF void tb_reset_camera ()
{
    if (!are_there_any_tabs()) return;

    Tab& tab = get_current_tab();
    tab.camera.zoom = 1;

    if (tab.type == Tab_Type::MAP)
    {
        tab.camera.x = -get_min_map_bounds_x();
        tab.camera.y = -get_min_map_bounds_y();
    }
    else
    {
        tab.camera.x = 0;
        tab.camera.y = 0;
    }
}

FILDEF void tb_flip_level_h ()
{
    if (current_tab_is_level()) flip_level_h();
}

FILDEF void tb_flip_level_v ()
{
    if (current_tab_is_level()) flip_level_v();
}

FILDEF void tb_toggle_mirror_h ()
{
    if (current_tab_is_level()) level_editor.mirror_h = !level_editor.mirror_h;
}

FILDEF void tb_toggle_mirror_v ()
{
    if (current_tab_is_level()) level_editor.mirror_v = !level_editor.mirror_v;
}

FILDEF void tb_cut ()
{
    if (!are_there_any_tabs()) return;

    Tab& tab = get_current_tab();
    switch (tab.type)
    {
        case (Tab_Type::LEVEL): le_cut(); break;
        case (Tab_Type::MAP  ): me_cut(); break;
    }
}

FILDEF void tb_copy ()
{
    if (!are_there_any_tabs()) return;

    Tab& tab = get_current_tab();
    switch (tab.type)
    {
        case (Tab_Type::LEVEL): le_copy(); break;
        case (Tab_Type::MAP  ): me_copy(); break;
    }
}

FILDEF void tb_deselect ()
{
    if (!are_there_any_tabs()) return;

    Tab& tab = get_current_tab();
    switch (tab.type)
    {
        case (Tab_Type::LEVEL): le_deselect(); break;
        case (Tab_Type::MAP  ): me_deselect(); break;
    }
}

FILDEF void tb_clear_select ()
{
    if (!are_there_any_tabs()) return;

    Tab& tab = get_current_tab();
    switch (tab.type)
    {
        case (Tab_Type::LEVEL): le_clear_select(); break;
        case (Tab_Type::MAP  ): me_clear_select(); break;
    }
}

FILDEF void tb_resize ()
{
    if (current_tab_is_level()) le_resize();
}

FILDEF void tb_toggle_entity ()
{
    if (current_tab_is_level()) level_editor.large_tiles = !level_editor.large_tiles;
}

FILDEF void tb_toggle_guides ()
{
    if (current_tab_is_level()) level_editor.entity_guides = !level_editor.entity_guides;
}

FILDEF void tb_toggle_palette ()
{
    if (current_tab_is_level()) level_editor.palette = !level_editor.palette;
}
