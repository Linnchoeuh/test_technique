/**
 ** @file game_data.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__GAME_DATA_H__
#define 	__GAME_DATA_H__

#include	<stdlib.h>
#include	<stdbool.h>
#include	<time.h>

#include	"baselib.h"

#define P1_DEFAULT_CHAR 'X'
#define P2_DEFAULT_CHAR 'O'
#define VOID_DEFAULT_CHAR ' '
#define BOARD_DEFAULT_SIZE 3

typedef struct	s_game_data
{
	char p1_char;
	char p2_char;
	bool player_turn;
	char *game_board;
	size_t game_board_size;
}				t_game_data;

t_game_data *game_data_init(void);

void game_data_delete(t_game_data *gdata);

bool game_data_set_board(t_game_data *gdata);

#endif