/**
 ** @file tictactoe.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__TICTACTOE_H__
#define 	__TICTACTOE_H__

#include	<unistd.h>
#include	<stdbool.h>

#include	"baselib.h"
#include	"game_data.h"
#include	"entry_reader.h"

#define CORNER "+"
#define HOR_LINE "-"
#define VER_LINE "|"

typedef enum	e_coords
{
	X_POS,
	Y_POS
}				t_coords;

t_game_data *get_args(int argc,
					  char **argv);

bool run_tictactoe(t_game_data *gdata);

void show_tictactoe(t_game_data *gdata);

bool check_coords(t_game_data *gdata,
				  char **split,
				  size_t *pos);

bool place_element(t_game_data *gdata,
				   size_t *pos);

bool is_player_winned(t_game_data *gdata);

#endif