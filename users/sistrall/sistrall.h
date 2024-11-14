#pragma once

// See: https://docs.qmk.fm/feature_layouts#tips-for-making-layouts-keyboard-agnostic
#include QMK_KEYBOARD_H

// I will mostly use my keyboards with an Italian OS, so it's useful to have Italian keycodes defined.
#include "keymap_italian_mac_iso.h"

// Inventory of the layers:
//
// - base layer is the one containing letters
// - numbers layer contains numbers and some symbols
// - navigation layer contains arrow keys, media control keys and more
enum LAYERS {
    BASE_LAYER,
    NUMBERS_LAYER,
    SYMBOLS_LAYER,
    NAVIGATION_LAYER,
    ADJUST_LAYER,
};

// Keycodes

#define PAGE_UP KC_PAGE_UP
#define PAGE_DOWN KC_PAGE_DOWN

#define VL_ENT LT(NAVIGATION_LAYER, KC_ENT)
#define NL_SPC LT(NUMBERS_LAYER, KC_SPC)
#define SL_SPC LT(SYMBOLS_LAYER, KC_SPC)

#define MO_NUM MO(NUMBERS_LAYER)
#define MO_NAV MO(NAVIGATION_LAYER)

#define LT_NUM LT(NUMBERS_LAYER, KC_ESC)

#define NL_TAB LT(NUMBERS_LAYER, KC_TAB)
#define VL_BSP LT(NAVIGATION_LAYER, KC_BACKSPACE)

#define LG_ESC MT(MOD_LGUI, KC_ESC)
#define RG_ESC MT(MOD_RGUI, KC_ESC)
#define LG_TAB MT(MOD_LGUI, KC_TAB)

#define TT_BL TT(BASE_LAYER)
#define TT_NL TT(NUMBERS_LAYER)
#define TT_SL TT(SYMBOLS_LAYER)
#define TT_VL TT(NAVIGATION_LAYER)
#define TT_AL TT(ADJUST_LAYER)

#define LG_A LGUI_T(IT_A)
#define LA_R LALT_T(IT_R)
#define LC_S LCTL_T(IT_S)
#define LS_T LSFT_T(IT_T)

#define LS_A LSFT_T(IT_A)
#define LC_R LCTL_T(IT_R)
#define LA_S LALT_T(IT_S)
#define LG_T LGUI_T(IT_T)

#define LC_Z LCTL_T(IT_Z)
#define LA_X LALT_T(IT_X)

#define LC_E LCTL_T(KC_ESC)

#define RS_N RSFT_T(IT_N)
#define RC_E RCTL_T(IT_E)
#define RA_I RALT_T(IT_I)
#define RG_O RGUI_T(IT_O)

#define RG_N RGUI_T(IT_N)
#define RA_E RALT_T(IT_E)
#define RC_I RCTL_T(IT_I)
#define RS_O RSFT_T(IT_O)

#define RC_MINS RCTL_T(IT_MINS)
#define RA_DOT RALT_T(IT_DOT)

#define LA_TAB LALT_T(KC_TAB)
#define RA_BSPC RALT_T(KC_BSPC)

// Tap-dance

enum {
    TD_CQ,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_CQ] = ACTION_TAP_DANCE_DOUBLE(IT_COMM, IT_QUOT),
};

// Combos

enum combos {
    LEFT_HALF_TOGGLE_TAP_NUMBERS_LAYER,
    LEFT_HALF_TOGGLE_TAP_NAVIGATION_LAYER,

    LEFT_HALF_SQUARE_BRACKET_OPEN,
    LEFT_HALF_CURLY_BRACKET_OPEN,
    LEFT_HALF_LABK,

    RIGHT_HALF_TOGGLE_TAP_NUMBERS_LAYER,
    RIGHT_HALF_TOGGLE_TAP_NAVIGATION_LAYER,

    RIGHT_HALF_SQUARE_BRACKET_CLOSE,
    RIGHT_HALF_CURLY_BRACKET_CLOSE,
    RIGHT_HALF_RABK,

    LAST_COMBO_POSITION_PLUS_ONE,
};

uint16_t COMBO_LEN = LAST_COMBO_POSITION_PLUS_ONE;

const uint16_t PROGMEM left_half_square_bracket_open[] = {LC_Z, LA_X, COMBO_END};
const uint16_t PROGMEM left_half_curly_bracket_open[] = {LA_X, IT_C, COMBO_END};
const uint16_t PROGMEM left_half_labk[] = {IT_C, IT_D, COMBO_END};

const uint16_t PROGMEM right_half_square_bracket_close[] = {RA_DOT, RC_MINS, COMBO_END};
const uint16_t PROGMEM right_half_curly_bracket_close[] = {TD(TD_CQ), RA_DOT, COMBO_END};
const uint16_t PROGMEM right_half_rabk[] = {IT_H, TD(TD_CQ), COMBO_END};

combo_t key_combos[] = {
    COMBO(left_half_square_bracket_open, IT_LBRC),
    COMBO(left_half_curly_bracket_open, IT_LCBR),
    COMBO(left_half_labk, IT_LABK),

    COMBO(right_half_square_bracket_close, IT_RBRC),
    COMBO(right_half_curly_bracket_close, IT_RCBR),
    COMBO(right_half_rabk, IT_RABK),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_LAYER] = SISTRALL_layout(
        KC_ESC,     IT_1,       IT_2,       IT_3,       IT_4,       IT_5,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    IT_6,       IT_7,       IT_8,       IT_9,       IT_0,       KC_BSPC,
        KC_TAB,     IT_Q,       IT_W,       IT_F,       IT_P,       IT_B,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    IT_J,       IT_L,       IT_U,       IT_Y,       IT_SLSH,    RA_BSPC,
        IT_AT,      LS_A,       LC_R,       LA_S,       LG_T,       IT_G,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    IT_M,       RG_N,       RA_E,       RC_I,       RS_O,       IT_HASH,
        SC_LSPO,    LC_Z,       LA_X,       IT_C,       IT_D,       IT_V,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    IT_K,       IT_H,       TD(TD_CQ),  RA_DOT,     RC_MINS,    SC_RSPC,
        KC_NO,      KC_NO,      KC_NO,      LC_E,       KC_LALT,    LG_ESC,     SL_SPC,     NL_TAB,     VL_BSP,     KC_ENT,     KC_RGUI,    KC_RALT,    KC_RCTL,    KC_NO,      KC_NO,      KC_NO
    ),

    [NUMBERS_LAYER] = SISTRALL_layout(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    IT_EXLM,    IT_DQUO,    IT_CIRC,    IT_DLR,     IT_PERC,    _______,    _______,    _______,    _______,    IT_EQL,     IT_7,       IT_8,       IT_9,       IT_0,       _______,
        _______,    IT_QUES,    IT_QUOT,    IT_SECT,    IT_EURO,    IT_PIPE,    _______,    _______,    _______,    _______,    IT_ASTR,    IT_4,       IT_5,       IT_6,       IT_PLUS,    _______,
        _______,    IT_DGRV,    IT_ACUT,    IT_CIRC,    IT_AMPR,    IT_BSLS,    _______,    _______,    _______,    _______,    IT_SLSH,    IT_1,       IT_2,       IT_3,       IT_MINS,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [SYMBOLS_LAYER] = SISTRALL_layout(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_TAB,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    RA_BSPC,    _______,
        _______,    IT_AT,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    IT_HASH,    _______,
        _______,    SC_LSPO,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    SC_RSPC,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [NAVIGATION_LAYER] = SISTRALL_layout(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    PAGE_UP,    KC_HOME,    KC_UP,      KC_END,     _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    PAGE_DOWN,  KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),

    [ADJUST_LAYER] = SISTRALL_layout(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    ),
};
