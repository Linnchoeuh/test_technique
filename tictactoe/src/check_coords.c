/**
 ** @file check_coords.c
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#include "tictactoe.h"

static bool check_extracted_data(t_game_data *gdata,
								 char **split,
								 size_t *pos)
{
	ssize_t x;
	ssize_t y;

	if (split_len(split) < 2 ||
		!std_str_is_number(split[0]) ||
		!std_str_is_number(split[1]))
	{
		write(STDOUT_FILENO, "Invalid syntax.\n", 16);
		return (false);
	}
	x = std_atoi(split[0]);
	y = std_atoi(split[1]);
	if (x >= 0 && (size_t) x < gdata->game_board_size &&
		y >= 0 && (size_t) y < gdata->game_board_size)
	{
		pos[X_POS] = (size_t) x;
		pos[Y_POS] = (size_t) y;
		return (true);
	}
	write(STDOUT_FILENO, "Coords out of bounds.\n", 22);
	return (false);

}

bool check_coords(t_game_data *gdata,
				  char **split,
				  size_t *pos)
{
	char **tmp_split;
	char *merged_split;
	bool ok;

	merged_split = split_merge(split, "", 3);
	if (merged_split == NULL)
		return (false);
	tmp_split = split_str(merged_split, ',');
	free(merged_split);
	if (tmp_split == NULL)
		return (false);
	ok = check_extracted_data(gdata, tmp_split, pos);
	split_free(tmp_split);
	return (ok);
}