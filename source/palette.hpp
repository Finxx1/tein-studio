#pragma once

typedef std::vector<vec4> Palette;

FILDEF void init_palette_lookup    ();
FILDEF vec4 get_tileset_main_color (std::string tileset);
