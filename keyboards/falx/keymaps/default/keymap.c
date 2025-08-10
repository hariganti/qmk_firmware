// Copyright 2024 Hari Ganti
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/** TODO
 *  - Try asymmetric combos due to stagger, so RHS gets shifted rightward
 *  - See if the hyphen and underscore would be better swapped with quotes
 *  - See if Flow Tap can still be used to good effect
 *      Biggest issue is with things like ctrl + delete
 *      Ideally tapping term would be dynamic, extended while typing and shorter after a break
 *      Maybe send "0" for Flow Tap, but adjust an internal variable for a dynamic tapping term
 */

/*******************************************************************************
 ***                        Custom Keys and Keymaps                          ***
 ******************************************************************************/

// Custom Keys
enum user_keycodes {
  LTINHIB = SAFE_RANGE,
  TERMLOCK,
  DEFAULT_MODE,
  HYPHEN_MODE,
  UNDERSCORE_MODE,
  SLASH_MODE
};

// Tap Dances
enum {
  TD_BRKTOPEN,
  TD_BRKTCLOS
};

// Layers
enum layers {
  LAYER_DEFAULT,
  LAYER_NUMPAD,
  LAYER_SYMBOL,
  LAYER_FUNCTION,
  LAYER_NAVIGATION,
  LAYER_WINDOW,
  LAYER_NORM_ALPHA,
  LAYER_NORM_FN,
  LAYER_MEDIA
};

// Keymaps
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

//[LAYER_TEMPLATE] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
//    KC_TRNS  ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS  ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
//     KC_TRNS   ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS     ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
//      KC_TRNS    ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
//  KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,    KC_TRNS    ,    KC_TRNS    ,    KC_TRNS    ,   KC_TRNS   ,KC_TRNS,KC_TRNS,KC_TRNS
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
//)

  #define HRMAS   LALT_T(KC_S)
  #define HRMCD   LCTL_T(KC_D)
  #define HRMSF   LSFT_T(KC_F)
  #define HRMGG   LGUI_T(KC_G)
  #define HRMGH   RGUI_T(KC_H)
  #define HRMSJ   RSFT_T(KC_J)
  #define HRMCK   RCTL_T(KC_K)
  #define HRMAL   RALT_T(KC_L)
  #define LTILFUN LT(LAYER_FUNCTION,    LTINHIB )
  #define PRTLWIN LT(LAYER_WINDOW,      KC_PSCR )
  #define SPCLNUM LT(LAYER_NUMPAD,      KC_NO   )
  #define SPCLNAV LT(LAYER_NAVIGATION,  KC_NO   )
  #define SPCLSYM LT(0,                 KC_NO   ) // To be updated with a symbols layer
  #define APPLMED LT(LAYER_MEDIA,       KC_APP  )
  #define THTL    LT(0,                 TERMLOCK)
  #define THED    LT(0,                 KC_ESC  )

  // Default layer - Basis for regular typing
  [LAYER_DEFAULT] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
       KC_TAB  ,  KC_Q ,  KC_W ,  KC_E ,  KC_R ,  KC_T ,  KC_Y ,  KC_U ,  KC_I ,  KC_O ,  KC_P ,KC_LBRC,KC_RBRC,  KC_BSPC  ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
         THED    ,  KC_A , HRMAS , HRMCD , HRMSF , HRMGG , HRMGH , HRMSJ , HRMCK , HRMAL ,KC_SCLN,KC_QUOT,     KC_ENT      ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        CW_TOGG    ,  KC_Z ,  KC_X ,  KC_C ,  KC_V ,  KC_B ,  KC_N ,  KC_M ,KC_COMM, KC_DOT,KC_SLSH,KC_BSLS, KC_UP , KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
      THTL ,G(KC_E),LTILFUN, PRTLWIN ,    SPCLNUM    ,    SPCLNAV    ,    SPCLSYM    ,   APPLMED   ,KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define ZROLSYM LT(0,  KC_0) // To be updated with a symbols layer
  #define DOTLMED LT(LAYER_MEDIA,   KC_PDOT)

  // Numpad layer - Puts a numpad on the RHS of the keyboard
  [LAYER_NUMPAD] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS  ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_NO ,  KC_7 ,  KC_8 ,  KC_9 ,KC_BSPC, KC_NO , KC_NO ,  KC_TRNS  ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS   ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_GRV,  KC_4 ,  KC_5 ,  KC_6 , KC_EQL, KC_NO ,    KC_ENT       ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS    ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_NO ,  KC_1 ,  KC_2 ,  KC_3 , KC_DEL, KC_NO , KC_UP ,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,    KC_TRNS    ,    KC_TRNS    ,    ZROLSYM    ,   DOTLMED   ,KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  // Function key layer - F-Keys
  [LAYER_FUNCTION] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS  , KC_F1 , KC_F4 , KC_F7 , KC_F10,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS  ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS   , KC_F2 , KC_F5 , KC_F8 , KC_F11,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS     ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS    , KC_F3 , KC_F6 , KC_F9 , KC_F12,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,    KC_TRNS    ,    KC_TRNS    ,    KC_TRNS    ,   KC_TRNS   ,KC_TRNS,KC_TRNS,KC_TRNS
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define RMRREDO RCTL_T(KC_Y)
  #define RGLUNDO RGUI_T(KC_Z)
  #define RSLCOPY RSFT_T(KC_C)
  #define RCLPSTE RCTL_T(KC_V)
  #define RALCUT  RALT_T(KC_X)

  // Navigation layer - Navigation keys near the home row
  [LAYER_NAVIGATION] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS  ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RMRREDO,KC_PGUP, KC_UP ,KC_PGDN,KC_BSPC, KC_NO , KC_NO ,  KC_TRNS  ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS   ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT, KC_END, KC_NO ,     KC_ENT      ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS    ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RGLUNDO,RSLCOPY,RCLPSTE, RALCUT, KC_DEL, KC_NO ,KC_PGUP,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,    KC_TRNS    ,    KC_TRNS    ,    KC_TRNS    ,   KC_TRNS   ,KC_HOME,KC_PGDN, KC_END
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define WKSPPRV G(S(KC_TAB))
  #define WKSPNXT G(KC_TAB)
  #define TABPRV  C(S(KC_TAB))
  #define TABNXT  C(KC_TAB)
  #define SECPRV  A(S(KC_TAB))
  #define SECNXT  A(KC_TAB)
  #define CONSRNK S(KC_F4)
  #define CONEQL  S(KC_F5)
  #define CONGROW S(KC_F6)
  #define ROTCCW  S(KC_F1)
  #define CONFLOT S(KC_F2)
  #define ROTCW   S(KC_F3)
  #define SPLITT  G(KC_SLSH)
  #define FOCUST  G(KC_A)
  #define BORDERT G(KC_F)

  // Window management layer - Move tHRMough workspaces and tabs, and adjust simple WM formatting
  [LAYER_WINDOW] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS  ,WKSPPRV,WKSPNXT,CONSRNK, CONEQL,CONGROW,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS  ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
       KC_TRNS   , TABPRV, TABNXT, ROTCCW,CONFLOT, ROTCW ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS     ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS    , SECPRV, SECNXT, SPLITT, FOCUST,BORDERT,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,    KC_TRNS    ,    KC_TRNS    ,    KC_TRNS    ,   KC_TRNS   ,KC_TRNS,KC_TRNS,KC_TRNS
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define LNORMFN MO(LAYER_NORM_FN)

  // Normal layout alphas - Basis for regular typing when a (mostly) typical layout is needed
  [LAYER_NORM_ALPHA] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
       KC_TAB  ,  KC_Q ,  KC_W ,  KC_E ,  KC_R ,  KC_T ,  KC_Y ,  KC_U ,  KC_I ,  KC_O ,  KC_P ,KC_LBRC,KC_RBRC,  KC_BSPC  ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
        KC_ESC   ,  KC_A ,  KC_S ,  KC_D ,  KC_F ,  KC_G ,  KC_H ,  KC_J ,  KC_K ,  KC_L ,KC_SCLN,KC_QUOT,     KC_ENT      ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_LSFT    ,  KC_Z ,  KC_X ,  KC_C ,  KC_V ,  KC_B ,  KC_N ,  KC_M ,KC_COMM, KC_DOT,KC_SLSH,KC_BSLS, KC_UP , KC_DEL,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_LCTL,KC_LGUI,KC_LALT, LNORMFN ,     KC_SPC    ,     KC_SPC    ,     KC_SPC    ,   APPLMED   ,KC_LEFT,KC_DOWN,KC_RGHT
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  // Normal layout fn - For the number and F-key rows
  [LAYER_NORM_FN] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
      KC_TRNS  , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12,  KC_TRNS  ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
        KC_GRV   ,  KC_1 ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,  KC_6 ,  KC_7 ,  KC_8 ,  KC_9 ,  KC_0 ,KC_MINS,      KC_EQL     ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
        KC_TRNS    ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,    KC_TRNS    ,    KC_TRNS    ,    KC_TRNS    ,   KC_TRNS   ,KC_TRNS,KC_TRNS,KC_TRNS
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  ),

  #define MIKM  S(KC_MUTE)
  #define MIKU  S(KC_VOLU)
  #define MIKD  S(KC_VOLD)
  #define LNORM TG(LAYER_NORM_ALPHA)

  // Media layer - Primarily volume and track actions
  [LAYER_MEDIA] = LAYOUT(
// ├───────┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───┬───┴───────┤
       KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,KC_MPLY,KC_MPRV,KC_MNXT,   KC_NO   ,
// ├───────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴───────────┤
        KC_NO    , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,      LNORM      ,
// ├─────────────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┬───────┬───────┤
         KC_NO     , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,KC_MUTE,KC_VOLU,  MIKM ,
// ├───────┬───────┼───────┼───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┴─┬─────┴───────┼───────┼───────┼───────┤
    KC_TRNS,KC_TRNS, KC_NO ,  KC_NO  ,    KC_TRNS    ,    KC_TRNS    ,    KC_TRNS    ,   KC_TRNS   ,  MIKD ,KC_VOLD,  MIKU
// ├───────┼───────┼───────┼───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┬─┴─────┬───────┼───────┼───────┼───────┤
  )
};

/*******************************************************************************
 ***                                 Combos                                  ***
 ******************************************************************************/

// Key Definition
const uint16_t PROGMEM CB_FJ[] = {HRMSF,  HRMSJ,    COMBO_END};
const uint16_t PROGMEM CB_DK[] = {HRMCD,  HRMCK,    COMBO_END};
const uint16_t PROGMEM CB_EI[] = {KC_E,   KC_I,     COMBO_END};
const uint16_t PROGMEM CB_CO[] = {KC_C,   KC_COMM,  COMBO_END};
const uint16_t PROGMEM CB_SL[] = {HRMAS,  HRMAL,    COMBO_END};

const uint16_t PROGMEM CB_JK[] = {HRMSJ,  HRMCK,    COMBO_END};
const uint16_t PROGMEM CB_HJ[] = {HRMGH,  HRMSJ,    COMBO_END};
const uint16_t PROGMEM CB_UI[] = {KC_U,   KC_I,     COMBO_END};
const uint16_t PROGMEM CB_YU[] = {KC_Y,   KC_U,     COMBO_END};
const uint16_t PROGMEM CB_MO[] = {KC_M,   KC_COMM,  COMBO_END};
const uint16_t PROGMEM CB_NM[] = {KC_N,   KC_M,     COMBO_END};
const uint16_t PROGMEM CB_DF[] = {HRMCD,  HRMSF,    COMBO_END};
const uint16_t PROGMEM CB_FG[] = {HRMSF,  HRMGG,    COMBO_END};
const uint16_t PROGMEM CB_ER[] = {KC_E,   KC_R,     COMBO_END};
const uint16_t PROGMEM CB_RT[] = {KC_R,   KC_T,     COMBO_END};
const uint16_t PROGMEM CB_CV[] = {KC_C,   KC_V,     COMBO_END};
const uint16_t PROGMEM CB_VB[] = {KC_V,   KC_B,     COMBO_END};
const uint16_t PROGMEM CB_GH[] = {HRMGG,  HRMGH,    COMBO_END};
const uint16_t PROGMEM CB_TY[] = {KC_T,   KC_Y,     COMBO_END};
const uint16_t PROGMEM CB_BN[] = {KC_B,   KC_N,     COMBO_END};

const uint16_t PROGMEM CB_12[] = {KC_1,   KC_2,     COMBO_END};
const uint16_t PROGMEM CB_23[] = {KC_2,   KC_3,     COMBO_END};
const uint16_t PROGMEM CB_45[] = {KC_4,   KC_5,     COMBO_END};
const uint16_t PROGMEM CB_56[] = {KC_5,   KC_6,     COMBO_END};
const uint16_t PROGMEM CB_78[] = {KC_7,   KC_8,     COMBO_END};
const uint16_t PROGMEM CB_89[] = {KC_8,   KC_9,     COMBO_END};

// Combo Mapping
combo_t key_combos[] = {
  COMBO(CB_FJ, KC_INS         ),
  COMBO(CB_DK, DEFAULT_MODE   ),
  COMBO(CB_EI, HYPHEN_MODE    ),
  COMBO(CB_CO, UNDERSCORE_MODE),
  COMBO(CB_SL, SLASH_MODE     ),

  COMBO(CB_JK, KC_DOT         ),
  COMBO(CB_HJ, KC_COMM        ),
  COMBO(CB_UI, KC_EXLM        ),
  COMBO(CB_YU, KC_QUES        ),
  COMBO(CB_MO, KC_SCLN        ),
  COMBO(CB_NM, KC_COLN        ),
  COMBO(CB_DF, KC_QUOT        ),
  COMBO(CB_FG, KC_DQUO        ),
  COMBO(CB_ER, KC_MINS        ),
  COMBO(CB_RT, KC_UNDS        ),
  COMBO(CB_CV, TD(TD_BRKTOPEN)),
  COMBO(CB_VB, TD(TD_BRKTCLOS)),
  COMBO(CB_TY, KC_BSLS        ),
  COMBO(CB_GH, KC_PIPE        ),
  COMBO(CB_BN, KC_SLSH        ),

  COMBO(CB_12, KC_LPRN),
  COMBO(CB_23, KC_RPRN),
  COMBO(CB_45, KC_PPLS),
  COMBO(CB_56, KC_PMNS),
  COMBO(CB_78, KC_PAST),
  COMBO(CB_89, KC_PSLS)
};

/*******************************************************************************
 ***                       Custom Keycode Processing                         ***
 ******************************************************************************/

// Custom state variables
static uint16_t spaceKey    = KC_SPC;
static uint16_t td_brktcnt  = 0;
static bool     layerLock   = false;
static bool     rguiLock    = false;
static bool     rsftLock    = false;
static bool     rctlLock    = false;
static bool     raltLock    = false;

// Tap Dance
void td_brktopen_fn(tap_dance_state_t *state, void *user_data) {
  td_brktcnt = state->count;
  switch(td_brktcnt) {
    case 1:
      tap_code16(KC_LPRN);
      break;

    case 2:
      tap_code16(KC_LCBR);
      break;

    case 3:
      tap_code16(KC_LBRC);
      break;

    default:
      break;
  }

  return;
}

void td_brktclos_fn(tap_dance_state_t *state, void *user_data) {
  switch(state->count) {
    case 1:
      // Enter matching bracket if open bracket was entered previously
      switch(td_brktcnt) {
        case 0: // Case of no opening bracket
        case 1:
          tap_code16(KC_RPRN);
          break;

        case 2:
          tap_code16(KC_RCBR);
          break;

        case 3:
          tap_code16(KC_RBRC);
          break;

        default:
          break;
      }

      break;

    case 2:
      tap_code16(KC_RCBR);
      break;

    case 3:
      tap_code16(KC_RBRC);
      break;

    default:
      break;
  }

  td_brktcnt = 0;
  return;
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_BRKTOPEN] = ACTION_TAP_DANCE_FN(td_brktopen_fn),
  [TD_BRKTCLOS] = ACTION_TAP_DANCE_FN(td_brktclos_fn)
};

// Record Processing
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case KC_UP:
    case KC_DOWN:
    case KC_LEFT:
    case KC_RGHT:
    case KC_HOME:
    case KC_END:
    case KC_PGUP:
    case KC_PGDN:
      if(rguiLock) add_weak_mods(MOD_BIT(KC_RGUI));
      if(rsftLock) add_weak_mods(MOD_BIT(KC_RSFT));
      if(rctlLock) add_weak_mods(MOD_BIT(KC_RCTL));
      if(raltLock) add_weak_mods(MOD_BIT(KC_RALT));
      break;

    default:
      break;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Process regular keycodes
  switch(keycode) {
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      // Handle special cases of LT
      switch(keycode) {
        case LTILFUN:
          if(record->tap.count && record->event.pressed) {
            layerLock = !layerLock;
            return false;
          }

          break;

        case SPCLNUM:
        case SPCLNAV:
        case SPCLSYM:
          if(record->tap.count && record->event.pressed) {
            register_code16(spaceKey);
          } else if(record->tap.count && !record->event.pressed) {
            unregister_code16(spaceKey);
          }

          break;

        case THTL:
          if(record->tap.count && record->event.pressed) {
            tap_code16(G(KC_SPC));
          } else if(record->event.pressed) {
            tap_code16(G(KC_L));
          }

          return false;

        case THED:
          if(record->tap.count && record->event.pressed) {
            tap_code(KC_ESC);
          } else if(record->event.pressed) {
            layer_clear();
            spaceKey = KC_SPC;
          }

          return false;
      }

      // Disable hold action on LT when layer lock is active
      if(layerLock && !record->tap.count) {
        layerLock = false; // Essentially works as a one-time disable on the LT keyup
        return false;
      }

      break;

    case DEFAULT_MODE:
      if(record->event.pressed) spaceKey = KC_SPC;
      return false;

    case HYPHEN_MODE:
      if(record->event.pressed) spaceKey = KC_MINS;
      return false;

    case UNDERSCORE_MODE:
      if(record->event.pressed) spaceKey = KC_UNDS;
      return false;

    case SLASH_MODE:
      if(record->event.pressed) spaceKey = KC_SLSH;
      return false;

    case RMRREDO:
      if(record->tap.count && record->event.pressed) {
        tap_code16(C(KC_Y));
      } else if(record->event.pressed) {
        rguiLock = false;
        rsftLock = false;
        rctlLock = false;
        raltLock = false;
      }

      return false;

    case RGLUNDO:
      if(record->tap.count && record->event.pressed) {
        tap_code16(C(KC_Z));
      } else if(record->event.pressed) {
        rguiLock = !rguiLock;
      }

      return false;

    case RSLCOPY:
      if(record->tap.count && record->event.pressed) {
        tap_code16(C(KC_C));
        tap_code(KC_RGHT);
        rguiLock = false;
        rsftLock = false;
        rctlLock = false;
        raltLock = false;
      } else if(record->event.pressed) {
        rsftLock = !rsftLock;
      }

      return false;

    case RCLPSTE:
      if(record->tap.count && record->event.pressed) {
        tap_code16(C(KC_V));
        rguiLock = false;
        rsftLock = false;
        rctlLock = false;
        raltLock = false;
      } else if(record->event.pressed) {
        rctlLock = !rctlLock;
      }

      return false;

    case RALCUT:
      if(record->tap.count && record->event.pressed) {
        tap_code16(C(KC_X));
        rguiLock = false;
        rsftLock = false;
        rctlLock = false;
        raltLock = false;
      } else if(record->event.pressed) {
        raltLock = !raltLock;
      }

      return false;

    // The following are needed as workarounds due to the timing of the keycodes when sent
    case MIKM:
      if(record->event.pressed) {
        register_code(KC_LSFT);
        wait_ms(5);
        register_code(KC_MUTE);
      } else {
        unregister_code(KC_MUTE);
        unregister_code(KC_LSFT);
      }
      return false;

    case MIKU:
      if(record->event.pressed) {
        register_code(KC_LSFT);
        wait_ms(5);
        register_code(KC_VOLU);
      } else {
        unregister_code(KC_VOLU);
        unregister_code(KC_LSFT);
      }
      return false;

    case MIKD:
      if(record->event.pressed) {
        register_code(KC_LSFT);
        wait_ms(5);
        register_code(KC_VOLD);
      } else {
        unregister_code(KC_VOLD);
        unregister_code(KC_LSFT);
      }
      return false;
    }

  return true;
}

/*******************************************************************************
 *                           Behavioral Controls                               *
 ******************************************************************************/

// Layer State
layer_state_t layer_state_set_user(layer_state_t state) {
  // Backlight indicator of layer status
  if(get_highest_layer(state)) {
    backlight_enable();
  } else {
    backlight_disable();
    layerLock = false;
  }

  // Cleanup of nav/edit mod locks
  if(!IS_LAYER_ON_STATE(state, LAYER_NAVIGATION)) {
    rguiLock = false;
    raltLock = false;
    rsftLock = false;
    rctlLock = false;
  }

  return state;
}

// Tap-Hold Logic
#define DEFAULT_TAPPING_TERM 175

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    // Shift needs to be quicker to type quickly
    case HRMSF:
    case HRMSJ:
      return 100;

    // Alt and GUI both have non-chord use, so they need a moderate timeout
    case HRMGG:
    case HRMGH:
      return 200;

    case HRMAS:
    case HRMAL:
      return 250;

    // More relaxed timing for successive taps
    case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
      return 250;

    default:
      break;
  }

  return DEFAULT_TAPPING_TERM;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case HRMSF:
    case HRMSJ:
    case HRMCD:
    case HRMCK:
      return true;

    default:
      break;
  }

  return false;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case LTILFUN:
    case PRTLWIN:
    case ZROLSYM:
    case APPLMED:
    case DOTLMED:
    // case SPCLNUM:
    // case SPCLNAV:
    // case SPCLSYM:
      return true;

    default:
      break;
  }

  return false;
}

// Chordal Hold Logic
// bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
//   switch(tap_hold_keycode) {
//     case HRMCD:
//     case HRMCK:
//     case HRMAS:
//     case HRMAL:
//     case HRMGG:
//     case HRMGH:
//       return true;

//     default:
//       break;
//   }

//   return get_chordal_hold_default(tap_hold_record, other_record);
// }

// Caps Word Logic
bool caps_word_press_user(uint16_t keycode) {
  switch(keycode) {
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));

    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_MINS:
    case KC_UNDS:
    case KC_SLSH:
    case KC_BSLS:
      return true;

    case QK_LAYER_TAP_GET_TAP_KEYCODE(SPCLNUM):
      if(spaceKey != KC_SPC) return true;

    default:
      break;
  }

  return false;
}
