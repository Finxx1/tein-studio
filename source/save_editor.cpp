#include "save_editor.hpp"
FILDEF void init_save_editor ()
{
    save_editor.bounds   = { 0,0,0,0 };
    save_editor.viewport = { 0,0,0,0 };
}

GLOBAL std::string save_name;

FILDEF void do_save_editor ()
{
    set_cursor(Cursor::ARROW);

    quad p1;

    p1.x = get_toolbar_w() + 1;
    p1.y = TAB_BAR_HEIGHT + 1;
    p1.w = get_viewport().w - get_toolbar_w() - (get_control_panel_w()) - 2;
    p1.h = get_viewport().h - STATUS_BAR_HEIGHT - TAB_BAR_HEIGHT - 2;

    begin_panel(p1.x, p1.y, p1.w, p1.h, UI_NONE);

    // We cache the mouse position so that systems such as paste which can
    // potentially happen outside of this section of code (where the needed
    // transforms will be applied) can use the mouse position reliably as
    // prior to doing this there were bugs with the cursor's position being
    // slightly off during those operations + it's probably a bit faster.
    push_editor_camera_transform();
    save_editor.mouse_world = screen_to_world(get_mouse_pos());
    save_editor.mouse = get_mouse_pos();
    pop_editor_camera_transform();

    // We cache this just in case anyone else wants to use it (status bar).
    save_editor.viewport = get_viewport();

    Tab& tab = get_current_tab();

    push_editor_camera_transform();

    //Try to make it look like this:
    // _______________________
    //|       |#######|       |
    //|       |#######|       |
    //|       |#######|       |
    //|       |#######|       |
    //|       |#######|       |
    //|_______|#######|_______|
    //(extremely high detail graphic)

    float w = std::max(p1.w / 2.0, 400.0);

    begin_panel(p1.w / 2 - w / 2, 0, w, p1.h, UI_NONE, ui_color_med_dark);

    std::string frames  = std::to_string(tab.save.frames);
    std::string deaths  = std::to_string(tab.save.deaths);
    std::string reloads = std::to_string(tab.save.reloads);

    vec2 cursor = { 8, 8 };
    set_panel_cursor(&cursor);
    set_panel_cursor_dir(UI_DIR_DOWN);
    do_text_box_labeled(w - 16, SAVE_EDITOR_EDIT_HEIGHT, UI_NONE, tab.save.name, w / 2, "Save name:", "Empty", UI_ALIGN_LEFT);
    advance_panel_cursor(8);
    do_text_box_labeled(w - 16, SAVE_EDITOR_EDIT_HEIGHT, UI_NONE, tab.save.last_lvl, w / 2, "Current level:", "1-1", UI_ALIGN_LEFT);
    advance_panel_cursor(8);
    do_text_box_labeled(w - 16, SAVE_EDITOR_EDIT_HEIGHT, UI_NONE, tab.save.last_area, w / 2, "Current area:", "1-1", UI_ALIGN_LEFT);
    advance_panel_cursor(8);
    do_text_box_labeled(w - 16, SAVE_EDITOR_EDIT_HEIGHT, UI_NUMERIC, frames, w / 2, "Total time (in frames):", "0", UI_ALIGN_LEFT);
    advance_panel_cursor(8);
    do_text_box_labeled(w - 16, SAVE_EDITOR_EDIT_HEIGHT, UI_NUMERIC, deaths, w / 2, "Total deaths:", "0", UI_ALIGN_LEFT);
    advance_panel_cursor(8);
    do_text_box_labeled(w - 16, SAVE_EDITOR_EDIT_HEIGHT, UI_NUMERIC, reloads, w / 2, "Total reloads:", "0", UI_ALIGN_LEFT);

    tab.save.frames  = std::stoull(frames);
    tab.save.deaths  = std::stoull(deaths);
    tab.save.reloads = std::stoull(reloads);
    
    end_panel();

    pop_editor_camera_transform();

    end_panel();
}

FILDEF void save_drop_file (Tab* tab, std::string file_name)
{
    file_name = fix_path_slashes(file_name);

    // If there is just one tab and it is completely empty with no changes
    // then we close this tab before opening the new level(s) in editor.
    if (editor.tabs.size() == 1)
    {
        if (is_current_tab_empty() && !get_current_tab().unsaved_changes && get_current_tab().name.empty())
        {
            close_current_tab();
        }
    }

    size_t tab_index = get_tab_index_with_this_file_name(file_name);
    if (tab_index != INVALID_TAB) // This file is already open so just focus on it.
    {
        set_current_tab(tab_index);
    }
    else
    {
        create_new_save_tab_and_focus();
        tab = &get_current_tab();
        tab->name = file_name;
        set_main_window_subtitle_for_tab(tab->name);

        if (!load_save(tab->save, tab->name))
        {
            close_current_tab();
        }
    }

    need_to_scroll_next_update();
}

FILDEF bool is_current_save_empty()
{
    if (are_there_any_save_tabs())
    {
        const Tab& tab = get_current_tab();
        if (tab.type == Tab_Type::SAVE)
        {
            return tab.save.save_entries.size() == 0;
        }
    }
    return false;
}
