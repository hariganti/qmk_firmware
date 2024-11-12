// Copyright 2024 Hari Ganti
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// TODO: Enter bug ticket for shifted media keys being out of sequence
// TODO: Add the normal layers for gaming
// TODO: Add user function for caps word to work with HRM and SPCL/R
//        Consider case modes for this (camelCase, snake_case, kebab-case, CAPS_SNAKE, path/to/file, PDFs/caps word)

// Custom Keys
enum user_keycodes {
  SFLK = SAFE_RANGE,
  TLCK,
  EDEF
};

// Layers
enum layers {
  LAYER_DEFAULT,
  LAYER_NUMPAD,
  LAYER_NAVIGATION,
  LAYER_WINDOW,
  LAYER_MEDIA,
  LAYER_HRM_LEFT,
  LAYER_HRM_RIGHT
};

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Spacing, positioning, and coordinates of all keys for use in formatting the keymap
 *
 * │.'.1.'.│.'.2.'.│.'.3.'.│.'.4.'.│.'.5.'.│.'.6.'.│.'.7.'.│.'.8.'.│.'.9.'.│.'10.'.│.'11.'.│.'12.'.│.'13.'.│.'14.'.│.'15.'.│
 * ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
 * │    0,0    │  0,1  │  0,2  │  0,3  │  0,4  │  0,5  │  0,6  │  0,7  │  0,8  │  0,9  │  0,10 │  0,11 │  0,12 │   3,12    │ 1
 * ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
 * │     1,0     │  1,1  │  1,2  │  1,3  │  1,4  │  1,5  │  1,6  │  1,7  │  1,8  │  1,9  │  1,10 │  1,11 │       1,12      │ 2
 * ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
 * │      2,0      │  2,1  │  2,2  │  2,3  │  2,4  │  2,5  │  2,6  │  2,7  │  2,8  │  2,9  │  2,10 │  2,11 │  2,12 │  3,11 │ 3
 * ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
 * │  3,0  │  3,1  │  3,2  │   3,3   │      3,4      │      3,5      │      3,6      │     3,7     │  3,8  │  3,9  │  3,10 │ 4
 * ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
 * │.'.1.'.│.'.2.'.│.'.3.'.│.'.4.'.│.'.5.'.│.'.6.'.│.'.7.'.│.'.8.'.│.'.9.'.│.'10.'.│.'11.'.│.'12.'.│.'13.'.│.'14.'.│.'15.'.│
 */

  #define TT_LNAV TT(LAYER_NAVIGATION)
  #define TT_LNUM TT(LAYER_NUMPAD)
  #define MO_LWIN LT(LAYER_WINDOW,    KC_PSCR)
  #define ESCLMED LT(LAYER_MEDIA,     KC_ESC)
  #define HRMLEFT LT(LAYER_HRM_LEFT,  SFLK)
  #define HRMRGHT LT(LAYER_HRM_RIGHT, KC_SPC)
  #define THTL    LT(0,               TLCK)
  #define THED    LT(0,               EDEF)
  #define HRAS    LALT_T(KC_S)
  #define HRCD    LCTL_T(KC_D)
  #define HRSF    LSFT_T(KC_F)
  #define HRGG    LGUI_T(KC_G)
  #define HRGH    RGUI_T(KC_H)
  #define HRSJ    RSFT_T(KC_J)
  #define HRCK    RCTL_T(KC_K)
  #define HRAL    RALT_T(KC_L)

  // Default layer - Basis for regular typing
  [LAYER_DEFAULT] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_LBRC,KC_RBRC,  KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       TT_LNAV,    KC_A,   HRAS,   HRCD,   HRSF,   HRGG,   HRGH,   HRSJ,   HRCK,   HRAL,  KC_SCLN,KC_QUOT,      KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,KC_SLSH,KC_BSLS, KC_UP,  KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
     THTL,   THED,   KC_NO,  MO_LWIN,     HRMLEFT,        HRMRGHT,        TT_LNUM,       ESCLMED,   KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define HRAF5   LALT_T(KC_F5)
  #define HRCF8   LCTL_T(KC_F8)
  #define HRSF11  LSFT_T(KC_F11)
  #define HRGNO   LGUI_T(KC_NO)
  #define HRGMNS  RGUI_T(KC_MINS)
  #define HRS4    RSFT_T(KC_4)
  #define HRC5    RCTL_T(KC_5)
  #define HRA6    RALT_T(KC_6)
  #define ZROLNUM LT(LAYER_NUMPAD,  KC_0)
  #define DOTLMED LT(LAYER_MEDIA,   KC_PDOT)

  // Numpad layer - Puts a numpad on the RHS of the keyboard
  //  Needs significant optimization of the relevant symbols' locations
  [LAYER_NUMPAD] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,   KC_F1,  KC_F4,  KC_F7,  KC_F10, KC_NO,  KC_GRV, KC_7,   KC_8,   KC_9,   KC_NO,  KC_NO,  KC_NO,   KC_BSPC,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS,    KC_F2,  HRAF5,  HRCF8, HRSF11,  HRGNO, HRGMNS,  HRS4,   HRC5,   HRA6,  KC_EQL,  KC_NO,      KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,     KC_F3,  KC_F6,  KC_F9,  KC_F12, KC_NO,  KC_0,   KC_1,   KC_2,   KC_3,  KC_SLSH, KC_NO,  KC_UP,  KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS, KC_NO,  KC_TRNS,     KC_TRNS,        KC_TRNS,        ZROLNUM,       DOTLMED,   KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  // Navigation layer - Navigation keys near the home row
  [LAYER_NAVIGATION] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_PGUP, KC_UP, KC_PGDN, KC_NO,  KC_NO,  KC_NO,   KC_TRNS,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS,    KC_NO, KC_LALT,KC_LCTL,KC_LSFT,KC_LGUI,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT, KC_END, KC_NO,      KC_ENT,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,    C(KC_Z),C(KC_X),C(KC_C),C(KC_V),C(KC_Y), KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_PGUP,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,     KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,   KC_HOME,KC_PGDN, KC_END
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define CONPRV  G(S(KC_TAB))
  #define CONNXT  G(KC_TAB)
  #define TABPRV  C(S(KC_TAB))
  #define TABNXT  C(KC_TAB)
  #define SECPRV  A(S(KC_TAB))
  #define SECNXT  A(KC_TAB)
  #define ROTL    S(KC_F2)
  #define FLOTT   S(KC_F1)
  #define ROTR    S(KC_F3)
  #define SHRINK  S(KC_F5)
  #define EQLDIST S(KC_F4)
  #define GROW    S(KC_F6)
  #define SPLITT  G(KC_SLSH)

  // Window Management layer - Growing, shrinking, switching, anything-to-do-with managing windows
  //  Caps (1,0) = container back and forth?
  [LAYER_WINDOW] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,  CONPRV, CONNXT, SHRINK, EQLDIST, GROW,   KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS,   TABPRV, TABNXT,  ROTL,   FLOTT,  ROTR,   KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,    SECPRV, SECNXT, SPLITT, G(KC_A),G(KC_F), KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,     KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,    KC_NO,  KC_NO,  KC_NO
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define MIKM S(KC_MUTE)
  #define MIKU S(KC_VOLU)
  #define MIKD S(KC_VOLD)

  // Media layer - Primarily volume and track actions
  [LAYER_MEDIA] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
       KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_MPLY,KC_MPRV,KC_MNXT,   KC_NO,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
         KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,     KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_MUTE,KC_VOLU, MIKM,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS, KC_NO,   KC_NO,      KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,    MIKD,  KC_VOLD, MIKU
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define OSLALT OSM(MOD_LALT)
  #define OSLCTL OSM(MOD_LCTL)
  #define OSLSFT OSM(MOD_LSFT)
  #define OSLGUI OSM(MOD_LGUI)

  // HRM Left layer - LHS Home Row Mods
  [LAYER_HRM_LEFT] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS,   KC_TRNS, OSLALT, OSLCTL, OSLSFT, OSLGUI,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,     KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define OSRALT OSM(MOD_RALT)
  #define OSRCTL OSM(MOD_RCTL)
  #define OSRSFT OSM(MOD_RSFT)
  #define OSRGUI OSM(MOD_RGUI)

  // HRM Right layer - RHS Home Row Mods
  [LAYER_HRM_RIGHT] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, OSRGUI, OSRSFT, OSRCTL, OSRALT,KC_TRNS, KC_TRNS,     KC_TRNS,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,     KC_TRNS,        KC_TRNS,        KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  )
};

// Custom state variables
static bool shiftLock     = false;
static bool interrupted   = false;
static bool interruptable = false;

// Combos
const   uint16_t PROGMEM CB_INS[]   = {HRSF,  HRSJ, COMBO_END};
const   uint16_t PROGMEM CB_OLSFT[] = {HRCD,  HRSF, COMBO_END};
const   uint16_t PROGMEM CB_ORSFT[] = {HRSJ,  HRCK, COMBO_END};
combo_t key_combos[]                = {
  COMBO(CB_INS,   KC_INS        ),
  COMBO(CB_OLSFT, OSM(MOD_LSFT) ),
  COMBO(CB_ORSFT, OSM(MOD_RSFT) )
};

// Set layer status LED
layer_state_t layer_state_set_user(layer_state_t state) {
  if(get_highest_layer(state)) {
    backlight_enable();
  } else {
    backlight_disable();
  }

  return state;
}

// Define the tapping term
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//   return TAPPING_TERM;
// }

// Implement custom keycode functions

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case THTL:
      if(record->event.pressed) interruptable = true;
      break;

    default:
      if(interruptable && record->event.pressed) interrupted = true;
      break;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Process regular keycodes
  switch(keycode) {
    case THTL:
      if(record->tap.count && record->event.pressed) {          // Tap
        tap_code16(G(KC_SPC));
      } else if(record->event.pressed) {                        // Hold
        register_code(KC_LCTL);
      } else if(!record->tap.count && !record->event.pressed) { // Hold release
        unregister_code(KC_LCTL);
        interruptable = false;
        if(interrupted) {                                       // Chord
          interrupted = false;
        } else {
          tap_code16(G(KC_L));                                  // No chord
        }
      }

      return false;

    case THED:
      if(record->tap.count && record->event.pressed) {
        tap_code16(G(KC_E));
      } else if(record->event.pressed) {
        layer_clear();
      }

      return false;

    case HRMLEFT:
      if(record->tap.count && record->event.pressed) { // Only register actions on press
        shiftLock = !shiftLock;
        if(shiftLock) {
          register_code(KC_LSFT);
        } else {
          unregister_code(KC_LSFT);
        }

        return false;
      }

      break;

    // The following are needed as workarounds due to the timing of the keycodes when sent
    case MIKM:
      if(record->event.pressed) {
        register_code(KC_LSFT);
      } else {
        register_code(KC_MUTE);
        unregister_code(KC_MUTE);
        unregister_code(KC_LSFT);
      }
      return false;

    case MIKU:
      if(record->event.pressed) {
        register_code(KC_LSFT);
      } else {
        register_code(KC_VOLU);
        unregister_code(KC_VOLU);
        unregister_code(KC_LSFT);
      }
      return false;

    case MIKD:
      if(record->event.pressed) {
        register_code(KC_LSFT);
      } else {
        register_code(KC_VOLD);
        unregister_code(KC_VOLD);
        unregister_code(KC_LSFT);
      }
      return false;
    }

  return true;
}

// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return;
// }
