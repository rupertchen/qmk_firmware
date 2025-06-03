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