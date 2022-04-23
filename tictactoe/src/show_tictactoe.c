/**
 ** @file show_tictactoe.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tictactoe.h"

static void draw_top_line(t_game_data *gdata)
{
	size_t i;

	write(STDOUT_FILENO, CORNER, 1);
	i = 0;
	while (i < gdata->game_board_size)
	{
		write(STDOUT_FILENO, HOR_LINE, 1);
		i++;
	}
	write(STDOUT_FILENO, CORNER, 1);
	write(STDOUT_FILENO, "\n", 1);
}

void show_tictactoe(t_game_data *gdata)
{
	size_t i;
	size_t k;

	write(STDOUT_FILENO, "\n", 1);
	draw_top_line(gdata);
	i = 0;
	while (i < gdata->game_board_size)
	{
		k = 0;
		write(STDOUT_FILENO, VER_LINE, 1);
		while (k < gdata->game_board_size)
		{
			write(STDOUT_FILENO, &gdata->game_board[i * gdata->game_board_size + k], 1);
			k++;
		}
		write(STDOUT_FILENO, VER_LINE, 1);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	draw_top_line(gdata);
	write(STDOUT_FILENO, "\n", 1);
}