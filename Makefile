# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fxst1 <fxst1@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/12 10:57:23 by fxst1             #+#    #+#              #
#    Updated: 2018/04/25 12:37:29 by fxst1            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = scop
INC = -I inc/
LIBS = -lm -lGLU -lGLEW -lglfw -lGL
OBJDIR = ./obj/

SRC := $(filter %.c, $(shell find src -type f))
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))
all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(INC) -o $(NAME) $(OBJ) $(LIBS)

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJDIR)

fclean:
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)

install:
	apt-get install libglfw-dev libglm-dev libglew1.6-dev

re: fclean all

push: fclean
	git add --all
	git commit -am "make push"
	git push
