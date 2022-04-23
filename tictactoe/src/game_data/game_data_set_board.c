/**
 ** @file game_data_set_board.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "game_data.h"

bool game_data_set_board(t_game_data *gdata)
{
	size_t allocating_size;

	allocating_size = POW_2(gdata->game_board_size);
	if (gdata->game_board != NULL)
		free(gdata->game_board);
	gdata->game_board = malloc(allocating_size);
	if (gdata->game_board == NULL)
		return (false);
	std_memset(gdata->game_board, VOID_DEFAULT_CHAR, allocating_size);
	return (true);
}