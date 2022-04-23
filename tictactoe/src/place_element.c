/**
 ** @file place_element.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tictactoe.h"

bool place_element(t_game_data *gdata,
				   size_t *pos)
{
	size_t coord_1d;

	coord_1d = pos[Y_POS] * gdata->game_board_size + pos[X_POS];
	if (gdata->game_board[coord_1d] != VOID_DEFAULT_CHAR)
	{
		write(STDOUT_FILENO, "Place already taken.\n", 21);
		return (false);
	}
	if (gdata->player_turn)
		gdata->game_board[coord_1d] = gdata->p2_char;
	else
		gdata->game_board[coord_1d] = gdata->p1_char;
	return (true);
}