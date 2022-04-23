/**
 ** @file entry_reader.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__ENTRY_READER_H__
#define 	__ENTRY_READER_H__

#include	<stdlib.h>

#include	"baselib.h"

char **get_entry(char *entry_header);

char *read_entry(void);

#endif