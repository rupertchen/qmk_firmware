#pragma once

// The LED map is not intuitive.  The i-th entry of the map defines the
// position to read out of the LED buffer.  I.e., multiple entries may map to
// the same LED buffer position.
#define RGBLIGHT_LED_MAP { 5, 0, 1, 2, 3, 4, 7, 8, 9, 10, 11, 6 }
