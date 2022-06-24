/* Copyright 2021 Jonavin Eng
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

//#pragma once

//#define TAPPING_TOGGLE 2
// TT set to two taps

#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

// Mouse Keys
#ifdef MOUSEKEY_ENABLE
#    define MK_KINETIC_SPEED  // Use kinetic acceleration for mouse-keys
#    ifndef MK_KINETIC_SPEED
//       Delay between pressing a movement key and cursor movement
#        define MOUSEKEY_DELAY 5
//       Time between cursor movements in milliseconds
#        define MOUSEKEY_INTERVAL 10
//       Step size for accelerating from initial to base speed
#        define MOUSEKEY_MOVE_DELTA 5
//       Initial speed of the cursor in pixel per second
#        define MOUSEKEY_INITIAL_SPEED 100
//       Maximum cursor speed at which acceleration stops
#        define MOUSEKEY_BASE_SPEED 1000
//       Decelerated cursor speed
#        define MOUSEKEY_DECELERATED_SPEED 400
//       Accelerated cursor speed
#        define MOUSEKEY_ACCELERATED_SPEED 3000
#    else
//       Delay between pressing a movement key and cursor movement
#        define MOUSEKEY_DELAY 10
//       Time between cursor movements in milliseconds
#        define MOUSEKEY_INTERVAL 20
//       Step size for accelerating from initial to base speed
#        define MOUSEKEY_MOVE_DELTA 8
//       Maximum cursor speed at which acceleration stops
#        define MOUSEKEY_MAX_SPEED 8
//       Time until maximum cursor speed is reached
#        define MOUSEKEY_TIME_TO_MAX 100
//       Decelerated cursor speed
#        define MOUSEKEY_DECELERATED_SPEED 400
//       Accelerated cursor speed
#        define MOUSEKEY_ACCELERATED_SPEED 3000
#    endif  // MK_KINETIC_SPEED
#endif  // MOUSEKEY_ENABLE

/*
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif
*/
