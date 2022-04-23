/**
 ** @file baselib.h
 ** @author Lenny Vigeon [lenny.vigeon@gmail.com]
 ** @brief
 **/

#ifndef		__BASELIB_H__
#define 	__BASELIB_H__

#include	<unistd.h>
#include	<stdbool.h>
#include	<stdlib.h>

#define	IS_CHAR_NUMBER(nbr) ((nbr) >= '0' && (nbr) <= '9')

#define POW_2(num) ((num) * (num))

size_t std_strlen(char *str);

size_t std_strnlen(const char *s,
				   size_t n);

ssize_t	std_atoi(const char	*str);

ssize_t std_fputs(int fd,
				  char *str);

bool std_str_is_number(const char *s);

int	std_strcmp(const char *str1,
			   const char *str2);

void *std_memset(void *ptr,
				 int value,
				 size_t	count);

int	print_base(int nbr,
			   int base);

char *std_strdup(char *s);

char *std_strndup(const char *s,
				  size_t n);

char **split_str(char *str,
				 char parser);

size_t split_len(char **split);

void split_free(char **splitted);

char *split_merge(char 	  **splitted,
				  char 	  *separation,
				  ssize_t merge_len);

#endif