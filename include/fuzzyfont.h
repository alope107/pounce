#pragma once
/*
 * Adapted from:

 * Copyright (c) 2020-2026 Gustavo Valiente gustavo.valiente@protonmail.com
 * zlib License, see LICENSE file.
 */


#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"
#include "bn_sprite_items_fuzzyfont.h"

constexpr bn::utf8_character fixed_8x16_sprite_font_utf8_characters[] = {
    "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿"
};

constexpr bn::span<const bn::utf8_character> fixed_8x16_sprite_font_utf8_characters_span(
        fixed_8x16_sprite_font_utf8_characters);

constexpr auto fixed_8x16_sprite_font_utf8_characters_map =
        bn::utf8_characters_map<fixed_8x16_sprite_font_utf8_characters_span>();

constexpr bn::sprite_font fuzzyfont(
        bn::sprite_items::fuzzyfont, fixed_8x16_sprite_font_utf8_characters_map.reference());


