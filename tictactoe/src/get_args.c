/**
 ** @file check_arg.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tictactoe.h"

#define USAGE_INFO \
	"Usage: ./tictactoe [-p1 CHAR1] [-p2 CHAR2] [-s GRID_SIZE]\n"

#define WRONG_CHAR \
	": The character have to be a 1 byte len char.\n"

#define INVALID_BOARD_SIZE \
	"Error: The size have to be a number higher than 1.\n"


bool update_player_char(t_game_data *gdata,
						char *new_char,
						int player_id)
{
	if (std_strlen(new_char) > 1)
	{
		write(STDERR_FILENO, "Error: Player ", 14);
		print_base(player_id, 10);
		write(STDERR_FILENO, WRONG_CHAR, 46);
		return (false);
	}
	if (player_id == 1)
		gdata->p1_char = new_char[0];
	else
		gdata->p2_char = new_char[0];
	return (true);
}

bool update_board_size(t_game_data *gdata,
					   char *new_size)
{
	if (!std_str_is_number(new_size) ||
		std_atoi(new_size) < 1)
	{
		write(STDERR_FILENO, INVALID_BOARD_SIZE, 51);
		return (false);
	}
	gdata->game_board_size = (size_t) std_atoi(new_size);
	return(true);
}

bool extract_data(t_game_data *gdata,
				  int argc,
				  char **argv)
{
	int i;

	if (std_strcmp(argv[1], "-h") == 0)
	{
		write(STDOUT_FILENO, USAGE_INFO, 58);
		return (true);
	}
	i = 1;
	while (i < argc - 1)
	{
		if (std_strcmp(argv[i], "-p1") == 0 &&
			!update_player_char(gdata, argv[i + 1], 1))
			return (false);
		else if (std_strcmp(argv[i], "-p2") == 0 &&
			!update_player_char(gdata, argv[i + 1], 2))
			return (false);
		else if (std_strcmp(argv[i], "-s") == 0 &&
			!update_board_size(gdata, argv[i + 1]))
			return (false);
		i++;
	}
	return (true);
}

t_game_data *get_args(int argc,
					  char **argv)
{
	t_game_data *gdata;

	if ((gdata = game_data_init()) == NULL ||
		(argc > 1 && !extract_data(gdata, argc, argv)) ||
		!game_data_set_board(gdata))
	{
		game_data_delete(gdata);
		return (NULL);
	}
	return (gdata);
}