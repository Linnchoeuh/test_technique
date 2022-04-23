/**
 ** @file run_tictactoe.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tictactoe.h"

static char **tictactoe_gui(t_game_data *gdata,
							bool display)
{
	char **content;

	if (display)
		show_tictactoe(gdata);
	write(STDOUT_FILENO, "Player ", 7);
	print_base(gdata->player_turn + 1, 10);
	content = get_entry("> \033[3m\033[1;33m");
	write(STDERR_FILENO, "\033[00m", 6);
	return (content);
}

static void print_win(t_game_data *gdata)
{
	show_tictactoe(gdata);
	write(STDOUT_FILENO, "Player ", 7);
	print_base(gdata->player_turn + 1, 10);
	write(STDOUT_FILENO, " won!\n", 6);
}

bool run_tictactoe(t_game_data *gdata)
{
	bool ok;
	bool display;
	char **content;
	size_t pos[2];

	ok = true;
	display = true;
	while (ok)
	{
		content = tictactoe_gui(gdata, display);
		if (content == NULL)
			return (false);
		if ((display = check_coords(gdata, content, pos)) &&
			(display = place_element(gdata, pos)))
		{
			if (is_player_winned(gdata))
				ok = false;
			else
				gdata->player_turn = !gdata->player_turn;
		}
		split_free(content);
	}
	print_win(gdata);
	return (true);
}