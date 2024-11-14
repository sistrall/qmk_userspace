// Kyria is a split keyboard and I connect it
// to an USB port on the left side of my laptop.
// Therefore, to lower the cable clutter on my desk,
// I define left half as the master one.
#define MASTER_LEFT

// The amount of tapping to trigger the toggle on layer tap-toggle keys:
// by setting 1, I say to toggle on a single tap and to activate the layer
// when the key is held down.
#define TAPPING_TOGGLE 1

// This is the global tapping term threshold for the
// tap-hold feature: keys with tap-hold enabled that are kept
// down more than the following amount ar considered hold and
// that triggers their hold behaviour.
#ifndef TAPPING_TERM
    #define TAPPING_TERM 240
#endif

#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8
#define RSPC_KEYS KC_RSFT, KC_RSFT, KC_9

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LAYERS

    #define RGBLIGHT_EFFECT_BREATHING

    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
    #define RGBLIGHT_DEFAULT_HUE 148
#endif

#ifdef OLED_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_OLED_ENABLE
#endif
