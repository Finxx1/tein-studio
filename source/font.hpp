#pragma once

GLOBAL constexpr int   DEFAULT_FONT_GLYPH_POINT_SIZE =    9;
GLOBAL constexpr float DEFAULT_FONT_GLYPH_CACHE_SIZE = 1024;

GLOBAL constexpr int TOTAL_GLYPH_COUNT = 128;

GLOBAL constexpr int SMALL_FONT_POINT_SIZE = DEFAULT_FONT_GLYPH_POINT_SIZE;
GLOBAL constexpr int LARGE_FONT_POINT_SIZE = 14;

GLOBAL FT_Library freetype;

struct Font_Glyph
{
    vec2  bearing;
    quad  bounds;
    float advance;
};

struct Font
{
    // This is an internal variable only used if the font is being loaded
    // from data. This is because FT_New_Memory_Face does not copy over
    // the data passed into it so the pointer provided must remain valid
    // until we are done with the font face and finally call FT_Done_Face.
    std::vector<u8> data;

    std::map<int, std::vector<Font_Glyph>> glyphs;

    FT_Face face;
    std::map<int, Texture> cache;

    bool has_kerning;
    vec4 color;

    std::map<int, float> line_gap;

    // Should only ever be set using the set_font_point_size function!
    int current_pt_size;
};

FILDEF bool load_font_from_data (Font& fnt, const std::vector<u8>& file_data, std::vector<int> pt = { DEFAULT_FONT_GLYPH_POINT_SIZE }, float csz = DEFAULT_FONT_GLYPH_CACHE_SIZE);
FILDEF bool load_font_from_file (Font& fnt, std::string            file_name, std::vector<int> pt = { DEFAULT_FONT_GLYPH_POINT_SIZE }, float csz = DEFAULT_FONT_GLYPH_CACHE_SIZE);
FILDEF void free_font           (Font& fnt);

FILDEF float get_font_kerning   (const Font& fnt, int c, int& i, int& p);
FILDEF float get_font_tab_width (const Font& fnt);
FILDEF float get_glyph_advance  (const Font& fnt, int c, int& i, int& p);

INLDEF float get_text_width  (const Font& fnt, std::string text);
INLDEF float get_text_height (const Font& fnt, std::string text);

FILDEF float get_text_width_scaled (const Font& fnt, std::string text);
FILDEF float get_text_width_scaled (const Font& fnt, std::string text);

FILDEF void set_font_point_size (Font& fnt, int pt);
