/**
 ** @file game_data_delete.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "game_data.h"

void game_data_delete(t_game_data *gdata)
{
	if (gdata == NULL)
		return;
	if (gdata->game_board != NULL)
		free(gdata->game_board);
	free(gdata);
}