# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obibby <obibby@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 22:29:03 by libacchu          #+#    #+#              #
#    Updated: 2023/02/01 10:25:26 by obibby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	webserv

SRC_DIR	=	src/
SRC		=	main.cpp Config.cpp Response.cpp Server.cpp

SRCS	=	$(addprefix $(SRC_DIR), $(SRC))

INC		=	inc/WebServ.hpp inc/Config.hpp inc/Server.hpp inc/Response.hpp 

OBJ_DIR	=	obj/
OBJ		=	$(SRCS:%.cpp=$(OBJ_DIR)%.o)

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g

GREY	=	\33[1;30m
BLUE	=	\33[0;34m
RESET	=	\33[0m

all : $(NAME)

$(OBJ_DIR)%.o : %.cpp
	@mkdir -p $(@D)
	@printf "\33[2K\r$(GREY)Compiling $(BLUE)$<"
	@$(CC) $(CFLAGS) -c -g $< -o $@

$(NAME) : $(OBJ) $(INC)
	@printf "\33[2K\r$(GREY)Compiling $(BLUE)$(NAME)$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@printf "$(GREY)Removing $(BLUE)$(OBJ)$(RESET)\n"
	@rm -fr $(OBJ_DIR)

fclean : clean
	@printf "$(GREY)Removing $(BLUE)$(NAME)$(RESET)\n"
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
