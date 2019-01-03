#include "keymap_common.h"
#include "action.h"
#include "action_code.h"
#include "action_layer.h"
#include "led.h"
#include "adb.h"


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Standard ANSI layer */
    KEYMAP_EXT_ISO(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,PAUS,                   NO,
    NUBS, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NLCK,FN11, PSLS,PAST,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,ENT,      DEL, END, PGDN,    P7,  P8,  P9,  PMNS,
    FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NUHS,                             P4,  P5,  P6,  PPLS,
    LSFT,GRV,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,          UP,           P1,  P2,  P3,
    LCTL,LALT,LGUI,          SPC,                               RALT,RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ), 
    /* Layer 1: programming layer 1*/
    KEYMAP_EXT_ISO(
    ESC, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,                   TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,SLSH,FN11,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, 
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN12,FN13,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,      
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN14,FN15,FN16,                           TRNS,TRNS,TRNS,TRNS, 
    FN26,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN17,     TRNS,        TRNS,         TRNS,TRNS,TRNS,      
    TRNS,TRNS,TRNS,               TRNS,                         TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS),
    /* Layer 2: programming layer 2*/
    KEYMAP_EXT_ISO(
    ESC, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,                   TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN18,RBRC,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS, 
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN19,FN20,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,      
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN21,FN22,FN23,                           TRNS,TRNS,TRNS,TRNS, 
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,NUBS,FN24,FN25,     TRNS,        TRNS,         TRNS,TRNS,TRNS,      
    TRNS,TRNS,TRNS,               TRNS,                         TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS)
};

enum macro_id {
    UNDERSCORE,
    EQUAL,
    RBRACE_L,
    CBRACE_L,
    RBRACE_R,
    CBRACE_R,
    SEMICOLON,
    COLON,
    APOSTROPHE,
    QUOTE,
    BACKSLASH,
    PIPE,
    GREATERTHAN,
    SLASH,
    QUESTION
};

const action_t PROGMEM fn_actions[] = {
   [0] = ACTION_LAYER_TOGGLE(1),
    [11] = ACTION_MACRO(EQUAL),
    [12] = ACTION_MACRO(RBRACE_L),
    [13] = ACTION_MACRO(RBRACE_R),
    [14] = ACTION_MACRO(SEMICOLON),
    [15] = ACTION_MACRO(APOSTROPHE),
    [16] = ACTION_MACRO(BACKSLASH),
    [17] = ACTION_MACRO(SLASH),
    [18] = ACTION_MACRO(UNDERSCORE),
    [19] = ACTION_MACRO(CBRACE_L),
    [20] = ACTION_MACRO(CBRACE_R),
    [21] = ACTION_MACRO(COLON),
    [22] = ACTION_MACRO(QUOTE),
    [23] = ACTION_MACRO(PIPE),
    [24] = ACTION_MACRO(GREATERTHAN),
    [25] = ACTION_MACRO(QUESTION),
    [26] = ACTION_LAYER_MOMENTARY(2)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    switch (id) {
        case EQUAL:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(0), U(LSHIFT), END ) :
                    MACRO( END ) );
        case RBRACE_L:
            return (event.pressed ?
                    MACRO( D(RALT), T(8), U(RALT), END ) :
                    MACRO( END ) );
        case RBRACE_R:
            return (event.pressed ?
                    MACRO( D(RALT), T(9), U(RALT), END ) :
                    MACRO( END ) );
        case SEMICOLON:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(COMM), U(LSHIFT), END ):
                    MACRO( END ) );
        case APOSTROPHE:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(BSLS), U(LSHIFT), END ):
                    MACRO( END ) );
        case BACKSLASH:
            return (event.pressed ?
                    MACRO( D(RALT), T(MINS), U(RALT), END ):
                    MACRO( END ) );
        case SLASH:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(7), U(LSHIFT), END ) :
                    MACRO( END ) );
        case UNDERSCORE:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(SLSH), U(LSHIFT), END ) :
                    MACRO( END ) );
        case CBRACE_L:
            return (event.pressed ?
                    MACRO( D(RALT), T(7), U(RALT), END ) :
                    MACRO( END ) );
        case CBRACE_R:
            return (event.pressed ?
                    MACRO( D(RALT), T(0), U(RALT), END ) :
                    MACRO( END ) );
        case COLON:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(DOT), U(LSHIFT), END ) :
                    MACRO( END ) );
        case QUOTE:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(2), U(LSHIFT), END ) :
                    MACRO( END ) );
        case PIPE:
            return (event.pressed ?
                    MACRO( D(RALT), T(NUBS), U(RALT), END ) :
                    MACRO( END ) );
        case GREATERTHAN:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(NUBS), U(LSHIFT), END ) :
                    MACRO( END ) );
        case QUESTION:
            return (event.pressed ?
                    MACRO( D(LSHIFT), T(MINS), U(LSHIFT), END ) :
                    MACRO( END ) );
    }
    return MACRO_NONE;
}


static uint8_t num_led_state = 0;
static uint8_t kbd_led_state = 0;
static uint8_t scrl_led_state = 0;

void hook_keyboard_leds_change(uint8_t led_status) {
  if (led_status & (1<<USB_LED_NUM_LOCK)) {
    num_led_state = 1<<USB_LED_NUM_LOCK;
  } else {
    num_led_state = 0;
  }
  if (led_status & (1<<USB_LED_SCROLL_LOCK)) {
    scrl_led_state = 1<<USB_LED_SCROLL_LOCK;
  } else {
    scrl_led_state = 0;
  }
  adb_host_kbd_led(ADB_ADDR_KEYBOARD, ~(num_led_state | kbd_led_state | scrl_led_state));
}


void hook_layer_change(uint32_t layer_state) {
  if (layer_state & 2) {
    kbd_led_state = kbd_led_state | (1<<USB_LED_CAPS_LOCK);
  } else {
    kbd_led_state = kbd_led_state  & ~(1<<USB_LED_CAPS_LOCK);
  }
  /*
  if (layer_state & 4) {
    kbd_led_state = kbd_led_state | (1<<USB_LED_SCROLL_LOCK);
  } else {
    kbd_led_state = kbd_led_state & ~(1<<USB_LED_SCROLL_LOCK);
  }
  */
  adb_host_kbd_led(ADB_ADDR_KEYBOARD, ~(num_led_state | kbd_led_state | scrl_led_state));
}
