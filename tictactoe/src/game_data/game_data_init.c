/**
 ** @file game_data_init.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "game_data.h"

t_game_data *game_data_init(void)
{
	t_game_data *gdata;

	gdata = malloc(sizeof(t_game_data));
	if (gdata == NULL)
		return (NULL);
	gdata->game_board = NULL;
	gdata->p1_char = P1_DEFAULT_CHAR;
	gdata->p2_char = P2_DEFAULT_CHAR;
	gdata->game_board_size = BOARD_DEFAULT_SIZE;
	srand(time(NULL));
	gdata->player_turn = rand() % 2;
	return (gdata);
}