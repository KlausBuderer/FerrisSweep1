#include QMK_KEYBOARD_H

/* ============================================================================
 *  Ferris sweep — 3_layer_problem keymap, with German Umlauts on US OS layout
 * ============================================================================
 *
 *  New keycodes available (just drop them into any layer below):
 *
 *      CK_AE   -> ä          CK_AE_U -> Ä
 *      CK_OE   -> ö          CK_OE_U -> Ö
 *      CK_UE   -> ü          CK_UE_U -> Ü
 *      CK_SS   -> ß
 *      KC_BSLS -> \
 *
 *  These work on **macOS with the standard "U.S." keyboard layout** —
 *  no input-source change needed. They use the built-in Option dead keys:
 *      Option+u, a   → ä        Option+s → ß
 *  No additional QMK Unicode plumbing required.
 * ============================================================================
 */

enum custom_keycodes {
    CK_AE = SAFE_RANGE,
    CK_OE,
    CK_UE,
    CK_SS,
    CK_AE_U,
    CK_OE_U,
    CK_UE_U,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case CK_AE:   SEND_STRING(SS_LALT("u") "a"); return false;
            case CK_OE:   SEND_STRING(SS_LALT("u") "o"); return false;
            case CK_UE:   SEND_STRING(SS_LALT("u") "u"); return false;
            case CK_SS:   SEND_STRING(SS_LALT("s"));     return false;
            case CK_AE_U: SEND_STRING(SS_LALT("u") SS_LSFT("a")); return false;
            case CK_OE_U: SEND_STRING(SS_LALT("u") SS_LSFT("o")); return false;
            case CK_UE_U: SEND_STRING(SS_LALT("u") SS_LSFT("u")); return false;
        }
    }
    return true;
}

/* ============================================================================
 *  Layout reference — LAYOUT_split_3x5_2 takes 34 keycodes in this order:
 *
 *      top-row   left 5 ,  right 5
 *      home-row  left 5 ,  right 5
 *      bot-row   left 5 ,  right 5
 *      thumbs    left 2 ,  right 2
 * ============================================================================
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0 — base */
    [0] = LAYOUT_split_3x5_2(
        KC_Q,           KC_W,         KC_E,         KC_R,         KC_T,
        KC_Z,           KC_U,         KC_I,         KC_O,         KC_P,

        LSFT_T(KC_A),   LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), LSG_T(KC_G),
        RSG_T(KC_H),    RGUI_T(KC_J), RALT_T(KC_K), LCTL_T(KC_L), RSFT_T(KC_SCLN),

        LT(3,KC_Y),     KC_X,         KC_C,         KC_V,         KC_B,
        KC_N,           KC_M,         KC_COMM,      KC_DOT,       LT(3,KC_MINS),

        LT(2,KC_TAB),   KC_BSPC,      KC_ENT,       LT(1,KC_SPC)
    ),

    /* Layer 1 — symbols */
    [1] = LAYOUT_split_3x5_2(
        KC_QUES,        KC_EXLM,      KC_PSLS,      KC_BSLS,      KC_DQUO,
        KC_CIRC,        KC_TILD,      KC_GRV,       KC_PSLS,      KC_PPLS,

        KC_GT,          KC_LCBR,      KC_LPRN,      KC_LBRC,      KC_QUOT,
        KC_INT1,        KC_PERC,      KC_ASTR,      KC_AMPR,      KC_PAST,

        KC_LT,          KC_RCBR,      KC_RPRN,      KC_RBRC,      KC_PIPE,
        KC_SLSH,        KC_HASH,      KC_AT,        KC_DLR,       KC_PEQL,

        KC_TAB,         KC_ESC,       RCG_T(KC_BSPC), LT(1,KC_RALT)
    ),

    /* Layer 2 — nav / media / F-keys */
    [2] = LAYOUT_split_3x5_2(
        KC_VOLU,        KC_F1,        KC_F2,        KC_F3,        KC_F4,
        KC_PSCR,        KC_BRIU,      KC_PGUP,      KC_CUT,       KC_COPY,

        KC_MPLY,        LCTL_T(KC_F5), LALT(KC_F6), LGUI(KC_F7),  KC_F8,
        KC_LEFT,        KC_DOWN,      KC_UP,        KC_RGHT,      KC_PSTE,

        KC_VOLD,        KC_F9,        KC_F10,       KC_F11,       KC_F12,
        KC_HOME,        KC_BRID,      KC_PGDN,      KC_END,       KC_UNDO,

        KC_TRNS,        KC_TRNS,      KC_ESC,       KC_TAB
    ),

    /* Layer 3 — numpad */
    [3] = LAYOUT_split_3x5_2(
        CK_AE,          CK_OE,        CK_UE,        CK_AE_U,        CK_UE_U,
        KC_PSLS,        KC_P7,        KC_P8,        KC_P9,        KC_PPLS,

        KC_LSFT,        KC_LCTL,      KC_LALT,      KC_LGUI,      KC_NO,
        KC_PAST,        KC_P4,        KC_P5,        KC_P6,        KC_PMNS,

        KC_QUOT,        KC_SCLN,      KC_LBRC,      KC_NO,        KC_NO,
        KC_P0,          KC_P1,        KC_P2,        KC_P3,        KC_PEQL,

        LCSG_T(KC_TRNS),KC_TRNS,      KC_TRNS,      OS_RCAG
    ),

    /* Layer 4 */
    [4] = LAYOUT_split_3x5_2(
        KC_TRNS,        KC_COLN,      KC_LT,        KC_GT,        KC_SCLN,
        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,

        KC_LCBR,        KC_RCBR,      KC_LPRN,      KC_RPRN,      KC_AT,
        KC_TRNS,        KC_NO,        KC_EQL,       KC_PLUS,      KC_PERC,

        KC_TRNS,        KC_EXLM,      KC_LBRC,      KC_RBRC,      KC_TRNS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,

        KC_VOLD,        KC_TRNS,      KC_TRNS,      KC_VOLU
    ),

    /* Layer 5 — F-keys */
    [5] = LAYOUT_split_3x5_2(
        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_TRNS,        KC_F7,        KC_F8,        KC_F9,        KC_F10,

        KC_TRNS,        KC_NO,        LCTL(KC_LALT),KC_TRNS,      KC_TRNS,
        KC_TRNS,        KC_F4,        KC_F5,        KC_F6,        KC_F11,

        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,
        KC_TRNS,        KC_F1,        KC_F2,        KC_F3,        KC_F12,

        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS
    ),

    /* Layer 6 — numbers */
    [6] = LAYOUT_split_3x5_2(
        KC_PSLS,        KC_7,         KC_8,         KC_9,         KC_PPLS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,

        KC_0,           KC_1,         KC_2,         KC_3,         KC_PMNS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_NO,        KC_TRNS,

        KC_PAST,        KC_4,         KC_5,         KC_6,         KC_PEQL,
        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,

        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS
    ),

    /* Layer 7 */
    [7] = LAYOUT_split_3x5_2(
        KC_TRNS,        KC_TRNS,      KC_COLN,      KC_ESC,       KC_TRNS,
        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_DEL,

        KC_TRNS,        KC_PERC,      KC_SLSH,      KC_ENT,       KC_TRNS,
        DF(1),          KC_LGUI,      KC_TRNS,      KC_TRNS,      KC_TRNS,

        KC_TRNS,        KC_TRNS,      KC_TRNS,      KC_EXLM,      KC_TRNS,
        DF(0),          KC_TRNS,      RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT,

        KC_TRNS,        KC_TAB,       KC_NO,        KC_TRNS
    ),
};
