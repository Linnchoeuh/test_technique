/**
 ** @file check_win.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tictactoe.h"

static bool check_diag1(t_game_data *gdata)
{
	size_t i;
	size_t pos;
	bool win;
	char check_char;

	check_char = (gdata->player_turn) ? gdata->p2_char :
										gdata->p1_char;
	win = true;
	i = 0;
	while (i < gdata->game_board_size)
	{
		pos = i * gdata->game_board_size + i;
		if (check_char != gdata->game_board[pos])
			win = false;
		i++;
	}
	return (win);
}

static bool check_diag2(t_game_data *gdata)
{
	size_t i;
	size_t k;
	size_t pos;
	bool win;
	char check_char;

	check_char = (gdata->player_turn) ? gdata->p2_char :
										gdata->p1_char;
	win = true;
	i = 0;
	k = gdata->game_board_size - 1;
	while (i < gdata->game_board_size)
	{
		pos = i * gdata->game_board_size + k;
		if (check_char != gdata->game_board[pos])
			win = false;
		i++;
		k--;
	}
	return (win);
}

static bool check_ver(t_game_data *gdata)
{
	size_t i;
	size_t k;
	size_t pos;
	bool win;
	char check_char;

	i = 0;
	check_char = (gdata->player_turn) ? gdata->p2_char :
										gdata->p1_char;
	while (i < gdata->game_board_size)
	{
		k = 0;
		win = true;
		while (k < gdata->game_board_size)
		{
			pos = k * gdata->game_board_size + i;
			if (check_char != gdata->game_board[pos])
				win = false;
			k++;
		}
		if (win)
			return (true);
		i++;
	}
	return (false);
}

static bool check_hor(t_game_data *gdata)
{
	size_t i;
	size_t k;
	size_t pos;
	bool win;
	char check_char;

	i = 0;
	check_char = (gdata->player_turn) ? gdata->p2_char :
										gdata->p1_char;
	while (i < gdata->game_board_size)
	{
		k = 0;
		win = true;
		pos = i * gdata->game_board_size;
		while (k < gdata->game_board_size)
		{
			if (check_char != gdata->game_board[pos + k])
				win = false;
			k++;
		}
		if (win)
			return (true);
		i++;
	}
	return (false);
}

bool is_player_winned(t_game_data *gdata)
{
	return (check_hor(gdata) ||
			check_ver(gdata) ||
			check_diag1(gdata) ||
			check_diag2(gdata));
}