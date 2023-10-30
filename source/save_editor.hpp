#pragma once

GLOBAL constexpr float SAVE_EDITOR_EDIT_HEIGHT = 22;

struct Tab; // Defined in <editor.hpp>

struct Save_History_State
{

};

struct Save_History
{
	int current_position;
	std::vector<Save_History_State> state;
};

struct Save_Editor
{
	vec2 mouse_world;
	vec2 mouse;

	quad bounds;
	quad viewport;
};

GLOBAL Save_Editor save_editor;

FILDEF void init_save_editor ();
FILDEF void do_save_editor   ();

FILDEF void handle_save_editor_events ();

FILDEF bool mouse_inside_save_editor_viewport ();

FILDEF void load_save_tab (std::string file_name);

FILDEF bool se_save            (Tab& level);
FILDEF bool se_save_as         ();
FILDEF void se_clear_select    ();
FILDEF void se_deselect        ();
FILDEF void se_cursor_deselect ();

FILDEF void save_has_unsaved_changes ();

FILDEF void se_undo ();
FILDEF void se_redo ();

FILDEF void se_history_begin ();
FILDEF void se_history_end   ();

FILDEF void save_drop_file (Tab* tab, std::string file_name);

FILDEF void backup_save_tab (const Save& save, const std::string& file_name);

FILDEF bool is_current_save_empty ();