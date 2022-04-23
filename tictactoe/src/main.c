/**
 ** @file main.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tictactoe.h"

int main(int argc,
		 char **argv)
{
	t_game_data *gdata;
	bool ok;

	gdata = get_args(argc, argv);
	if (gdata == NULL)
		return (84);
	ok = run_tictactoe(gdata);
	game_data_delete(gdata);
	if (!ok)
		return (84);
	return (0);
}