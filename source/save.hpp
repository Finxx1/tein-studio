#pragma once

struct Save_Entry
{
	std::string lvl;
	u8 flags;
};

struct Save
{
	std::string name;
	std::string last_lvl;
	std::string last_area;
	u64 frames;
	u64 deaths;
	u64 reloads;

	std::vector<Save_Entry> save_entries;
};

STDDEF bool load_save         (      Save& save, std::string file_name);
STDDEF bool save_save         (const Save& save, std::string file_name);

// A custom file format. Exactly the same as the default save format except
// the first part of the file until zero is the name of the file. This is
// done so that the name of the file can also be restored when the editor
// is loaded again after a fatal failure occurs and restore files are saved.

struct Tab; // Defined in <editor.hpp>

STDDEF bool load_restore_save (      Tab&   tab, std::string file_name);
STDDEF bool save_restore_save (const Tab&   tab, std::string file_name);

FILDEF bool create_blank_save (      Save& save, std::string start_level = "1-1");