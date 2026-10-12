#ifndef REMNANT_5x7_SPRITE_FONT_H
#define REMNANT_5x7_SPRITE_FONT_H

#include "bn_sprite_font.h"
#include "bn_utf8_characters_map.h"
#include "bn_sprite_items_remnant_5x7_pixel_font_shadow.h"

namespace common
{

constexpr bn::utf8_character remnant_5x7_sprite_font_utf8_characters[] = {
        "…","Á", "À", "Â", "Ã", "Ä", "Ç", "É", "È", "Ê", "Í", "Ì", "Î", "Ó", "Ò", "Ô", "à", "á", "â", "ç", "Æ"
};

/*constexpr int8_t remnant_5x7_sprite_font_character_widths[] = {
    6,  // 32
    6,  // 33 !
    6,  // 34 "
    6,  // 35 #
    6,  // 36 $
    6,  // 37 %
    6,  // 38 &
    6,  // 39 '
    6,  // 40 (
    6,  // 41 )
    6,  // 42 *
    6,  // 43 +
    6,  // 44 ,
    6,  // 45 -
    6,  // 46 .
    6,  // 47 /
    6,  // 48 0
    6,  // 49 1
    6,  // 50 2
    6,  // 51 3
    6,  // 52 4
    6,  // 53 5
    6,  // 54 6
    6,  // 55 7
    6,  // 56 8
    6,  // 57 9
    6,  // 58 :
    6,  // 59 ;
    6,  // 60 <
    6,  // 61 =
    6,  // 62 >
    6,  // 63 ?
    6,  // 64 @
    6,  // 65 A
    6,  // 66 B
    6,  // 67 C
    6,  // 68 D
    6,  // 69 E
    6,  // 70 F
    6,  // 71 G
    6,  // 72 H
    6,  // 73 I
    6,  // 74 J
    6,  // 75 K
    6,  // 76 L
    6,  // 77 M
    6,  // 78 N
    6,  // 79 O
    6,  // 80 P
    6,  // 81 Q
    6,  // 82 R
    6,  // 83 S
    6,  // 84 T
    6,  // 85 U
    6,  // 86 V
    6,  // 87 W
    6,  // 88 X
    6,  // 89 Y
    6,  // 90 Z
    6,  // 91 [
    6,  // 92 
    6,  // 93 ]
    6,  // 94 ^
    6,  // 95 _
    6,  // 96 `
    6,  // 97 a
    6,  // 98 b
    6,  // 99 c
    6,  // 100 d
    6,  // 101 e
    6,  // 102 f
    6,  // 103 g
    6,  // 104 h
    6,  // 105 i
    6,  // 106 j
    6,  // 107 k
    6,  // 108 l
    6,  // 109 m
    6,  // 110 n
    6,  // 111 o
    6,  // 112 p
    6,  // 113 q
    6,  // 114 r
    6,  // 115 s
    6,  // 116 t
    6,  // 117 u
    6,  // 118 v
    6,  // 119 w
    6,  // 120 x
    6,  // 121 y
    6,  // 122 z
    6,  // 123 {
    6,  // 124 |
    6,  // 125 }
    6,  // 126 ~
    6,  //"…"
    6,  //"Á"
    6,  // "À"
    6,  // "Â"
    6,  // "Ã"
    6,  // "Ä"
    6   // "Ç", "É", "È", "Ê", "Í", "Ì", "Î", "Ó", "Ò", "Ô", "à", "á", "â", "ç", "Æ"
};*/

constexpr bn::span<const bn::utf8_character> remnant_5x7_sprite_font_utf8_characters_span(
        remnant_5x7_sprite_font_utf8_characters);

constexpr auto remnant_5x7_sprite_font_utf8_characters_map =
        bn::utf8_characters_map<remnant_5x7_sprite_font_utf8_characters_span>();

constexpr bn::sprite_font remnant_5x7_sprite_font(
        bn::sprite_items::remnant_5x7_pixel_font_shadow, remnant_5x7_sprite_font_utf8_characters_map.reference(),
        bn::span<const int8_t>(), -2);

}

#endif
