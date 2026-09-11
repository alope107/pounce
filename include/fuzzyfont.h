#pragma once

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"

#include "bn_sprite_items_alphabet.h"

// TODO: Looks like we need the full ASCII range butano expects of us
// Will come back to this once font graphics are finalized

// constexpr bn::utf8_character chars[] = {
//     'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
//     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
// };

// constexpr bn::span<const bn::utf8_character> char_span(chars);

// constexpr auto utf8_characters_map =
//         bn::utf8_characters_map<char_span>();

// constexpr bn::sprite_font fixed_8x8_sprite_font(
//     bn::sprite_items::alphabet, 
//     utf8_characters_map.reference()
// );
