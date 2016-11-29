# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 13:20:33 by ariard            #+#    #+#              #
#    Updated: 2016/11/29 15:14:23 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls

SRC= main.c parsing-option.c ./Libft/ft_memalloc.c ./Libft/ft_bzero.c
OBJ= main.o parsing-option.o ft_memalloc.o ft_bzero.o
HEADER= ft_ls.h
FLAGS= -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@ make -C ./Libft fclean && make -C ./libft
	@ make -C ./libft clean
	@ gcc -c $(FLAGS) $(SRC)
	@ gcc $(OBJ) -o $(NAME) -I $(HEADER)

clean:
	@ rm -rf $(OBJ)

fclean: clean
	@ rm -f $(NAME)
	@ rm -f Libft/libft.a

re: fclean all 

#parsing options

test-multiopt:
	@ echo "Votre LS :"
	 ./ft_ls -l -a -R -t -r
	@ echo "Ls original :"
	@ echo "1"
	@ echo "1"
	@ echo "1"
	@ echo "1"
	@ echo "1"

test-oneopt:
	@ echo "Votre LS :"
	 ./ft_ls -latr
	@ echo "Ls original :"
	@ echo "1"
	@ echo "1"
	@ echo "1"
	@ echo "1"
	@ echo "1"
