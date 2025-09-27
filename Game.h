#ifndef GAME_H
#define GAME_H

void print_board( char grid[3][3] );

void zero_board( char grid[3][3] );

void start_game( char grid[3][3] );

int valid_move( int row, int col, char grid[3][3] );

int Win_check( char grid[3][3] );

#endif