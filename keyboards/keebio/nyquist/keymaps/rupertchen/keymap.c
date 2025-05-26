// Copyright 2023 Danny Nguyen (danny@keeb.io)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _MAC,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  MAC,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |L-Ctrl|   `  | Caps | Alt  |Backsp|  Del |Ent/Low|Space| R-Gui|   [  |   ]  |Raise |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_ortho_5x12(
  KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
  KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
  KC_LCTL, KC_GRV, KC_CAPS, KC_LALT, KC_BSPC, MT(MOD_LCTL,KC_DEL), LT(_LOWER,KC_ENT), KC_SPC, KC_RGUI, KC_LBRC, KC_RBRC, MO(_RAISE)
),

/* Mac
 */
[_MAC] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,
  KC_LGUI, _______, _______, _______, _______, MT(MOD_LGUI,KC_DEL), _______, _______, KC_RCTL, _______, _______, _______
),

/* Lower
 */
[_LOWER] = LAYOUT_ortho_5x12(
  KC_F1,   KC_F2,       KC_F3,      KC_F4,         KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,      KC_F10,  KC_F11, KC_F12,
  KC_NO,   KC_MS_WH_UP, KC_MS_UP,   KC_MS_WH_DOWN, KC_NO,   KC_NO,   KC_HOME, KC_PGDN,    KC_PGUP,    KC_END,  KC_NO,  KC_PSCR,
  _______, KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN,    KC_UP,      KC_RGHT, KC_NO,  KC_NO,
  _______, KC_NO,       KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_MS_BTN1, KC_MS_BTN2, KC_NO,   KC_NO,  _______,
  _______, KC_NO,       KC_NO,      _______,       _______, _______, _______, _______,    _______,    KC_NO,   KC_NO,  _______
),

/* Raise
 */
[_RAISE] = LAYOUT_ortho_5x12(
  _______, QK_RBT,  DB_TOGG,      RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI,  RGB_SAD, RGB_VAI, RGB_VAD, _______,
  _______, _______, QK_DEF_LAYER, _______, _______, _______, _______, _______,  _______, _______, _______, _______,
  _______, _______, _______,      _______, _______, _______, _______, _______,  _______, _______, _______, _______,
  _______, _______, _______,      _______, _______, _______, _______, DF(_MAC), _______, _______, _______, _______,
  _______, _______, _______,      _______, _______, _______, _______, _______,  _______, _______, _______, _______
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case MAC:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_colemak);
        #endif
        set_single_persistent_default_layer(_MAC);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
