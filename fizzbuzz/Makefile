NAME = fizzbuzz
CC = gcc
SRC = $(shell find ./ -name "*.c")
OBJ = $(SRC:.c=.o)
INCLUDE = ./include

#FLAGS
CFLAG = -g3 -std=c11
ERRFLAG = -Wextra -Wall -Werror

#LIBRARY VARIABLE
LIBPATH =
LIBFLAG =

#DON'T TOUCH
ECHO = /bin/echo -e
LIBSDIRECTORIES = $(shell find $(LIBPATH)*/ -maxdepth 0 -type d -printf "$(LIBPATH)%f ")

DEFLT	=	"\033[00m"
PINK	=	"\033[0;36m"
GREEN	=	"\033[1;32m"
TEAL	=	"\033[1;36m"
RED		=	"\033[0;31m"
BLUE	=	"\033[34m"
BLINK 	= 	"\033[1;92m"
SBLINK	= 	"\033[0m"
INVERT  =	"\033[7m"

all:$(NAME)

%.o : %.c
	@ $(CC) -o $@ -c $< -I$(INCLUDE) $(CFLAG) $(ERRFLAG) $(LIBFLAG) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $< $(DEFLT) || \
	$(ECHO) $(RED) "[KO]" $(PINK) $< $(DEFLT);

$(NAME):$(OBJ)
	@ $(CC) $(shell find ./ -name "*.o") -o $(NAME) \
	-I$(INCLUDE) $(CFLAG) $(ERRFLAG) $(LIBFLAG) && \
	$(ECHO) $(BLINK) "[OK]"$(SBLINK) $(PINK) $(NAME) $(DEFLT) || \
	$(ECHO) $(RED) "[KO]" $(TEAL) $(NAME) $(DEFLT)

clean:
	@ find -name "*.o" -delete && find -name "*~" -delete && \
	$(ECHO) $(BLINK) "[CLEAN SUCCESS]" $(DEFLT)

fclean:
	@find . -name "*.o" -delete \
			-or -name "*.a" -delete \
			-or -name "*.exe" -delete \
        	-or -name "a.out" -delete \
			-or -name "*.so" -delete  \
        	-or -name "*~" -delete \
			-or -name "vgcore*" -delete
	@$(ECHO) $(GREEN) "All temporal file deleted!" $(DEFLT)
	@find -name $(NAME) -delete
	@$(ECHO) $(GREEN) "Executable deleted!" $(DEFLT)

re: 		fclean all

install:	all
	@sudo mv $(NAME) /usr/bin/
	@$(ECHO) $(GREEN) "Program installed!" $(DEFLT)

uninstall:
	@sudo rm -i /usr/bin/$(NAME)
	@$(ECHO) $(GREEN) "Program deleted!" $(DEFLT)