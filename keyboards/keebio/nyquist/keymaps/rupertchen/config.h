#pragma once

// The LED map is not intuitive.  The i-th entry of the map defines the
// position to read out of the LED buffer.  I.e., multiple entries may map to
// the same LED buffer position.

// Nyquist LED legend
//
// Left, 0-5
// 2 1 0
// 3 4 5
//
// Right, 6-B
// b a 9
// 6 7 8
//
#define RGBLIGHT_LED_MAP { 1, 2, 3, 4, 5, 0, 11, 6, 7, 8, 9, 10 }
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST

#define COMBO_TERM 80
