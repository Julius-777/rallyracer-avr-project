/*
 * game.h
 *
 * Author: Peter Sutton
 *
 * The game has 16 rows, numbered 0 to 15 from the bottom. 
 * The car is always in rows 1 and 2 (two pixels in size).
 * The background scrolls down. There are 8 columns, numbered
 * 0 to 7 from the left.
 *
 * The functions in this module will update the LED matrix
 * display as required. Note that the LED matrix display has
 * a different understanding of rows and columns. See the comment
 * at the top of game.c for details.
 */ 

#ifndef GAME_H_
#define GAME_H_

#include <stdint.h>

// Reset the game. Get the background ready and place the car in the 
// initial position. Output this to the LED matrix.
void init_game(void);

void draw_power_ups(void);
void set_power(void);
uint8_t activate_power(void);
void Car_Powered(void);
uint8_t postionx;
uint8_t postiony;
uint8_t setting;
// Put a car at the starting position. (This would typically be called after
// a restart.)
void put_car_at_start(void);

/////////////////////////////////// MOVE FUNCTIONS /////////////////////////
// has_car_crashed() should be checked after calling one of these to see
// if the move succeeded or not

// Move the car one column left
// This function must NOT be called if the car is in column 0.
// Failure may occur if the car collides with the background.
void move_car_left(void);

// Move the car one column right
// This function must NOT be called if the car is in column 7.
// Failure may occur if the car collides with the background.
void move_car_right(void);



/////////////////////// CAR / GAME STATUS ///////////////////////////////////
// Get the column that the car is currently in (will return a number
// between 0 and 7 inclusive)
uint8_t get_car_column(void);

// Return true if the car has crashed, false otherwise
uint8_t has_car_crashed(void);

// Return true if the car has finished the lap, false otherwise
uint8_t has_lap_finished(void);

/////////////////////// UPDATE FUNCTIONS /////////////////////////////////////
// Scroll the background by one row and update the display. Note that this
// may cause the car to crash.
void scroll_background(void);

#endif /* GAME_H_ */