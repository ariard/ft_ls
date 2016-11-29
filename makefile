# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 13:20:33 by ariard            #+#    #+#              #
#    Updated: 2016/11/29 19:22:23 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls

SRC= main.c parsing_option.c ./Libft/ft_memalloc.c ./Libft/ft_bzero.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c
OBJ= main.o parsing_option.o ft_memalloc.o ft_bzero.o ft_putchar.o ft_putstr.o
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

test-opt:
	@ echo "Test multi lines opt : "
	@ echo " "
	 ./ft_ls -l -a -R -t -r
	@ echo "LS original :"
	@ echo "1-1-1-1-1"
	@ echo " "
	@ echo "Test one line opt 1:"
	@ echo " "
	 ./ft_ls -latr
	@ echo "LS original :"
	@ echo "1-1-1-1"
	@ echo " " 
	@ echo "Test one line opt 2:"
	@ echo " "
	 ./ft_ls -rlta
	@ echo "LS original :"
	@ echo "1-1-1-1"
	@ echo " "	
	@ echo "Test --"
	@ echo " "
	 ./ft_ls --
	@ echo "LS original :"
	@ echo " "
	@ echo "Test pas d option"
	@ echo " "
	 ./ft_ls hello
	@ echo "LS original :"
	@ echo " "

test-illeglopt:
	@ echo "Test illegal options 1:"
	@ echo " "
	 ./ft_ls -aU
	@ echo "LS original :"
	@ echo "usage: ls [laRtr][- ...]"
	@ echo " "
	@ echo " "
	@ echo "Test illegal options 2:"
	@ echo " "
	 ./ft_ls -a -U 
	@ echo "LS original :"
	@ echo "usage: ls [laRtr][- ...]"
	@ echo " "
	@ echo " "
	@ echo "Test illegal options 3:"
	@ echo " "
	 ./ft_ls -a -- 
	@ echo "LS original :"
	@ echo "1"
	@ echo " "
	@ echo "Test illegal options 4:"
	@ echo " "
	 ./ft_ls -a --- 
	@ echo "LS original :"
	@ echo "usage: ls [laRtr][- ...]"
	@ echo " "
	@ echo " "
	@ echo "Test illegal options 5:"
	@ echo " "
	 ./ft_ls -y 
	@ echo "LS original :"
	@ echo "usage: ls [laRtr][- ...]"
	@ echo " "
	@ echo " "
	@ echo "Test illegal options 6:"
	@ echo " "
	 ./ft_ls -- 
	@ echo "LS original :"
	@ echo " "
	@ echo " "
	
test-conflit:
	@ echo "Test conflit de sort :"
	@ echo " "
	 ./ft_ls -ut 
	@ echo "LS original :"
	@ echo "0-1 "
	@ echo " "
	@ echo "Test activation parallele:"
	@ echo " "
	 ./ft_ls -n
	@ echo "LS original :"
	@ echo "1-1 "
	@ echo " "
	@ echo "Test priorite S"
	@ echo " "
	 ./ft_ls -St
	@ echo "LS original :"
	@ echo "1-0-0 "
	@ echo "Test activation impose negatif"
	@ echo " "
	 ./ft_ls -@
	@ echo "LS original :"
	@ echo "0"
	@ echo " "
	@ echo "Test activation impose positif"
	@ echo " "
	 ./ft_ls -@l
	@ echo "LS original :"
	@ echo "1-1"
	@ echo " "
	@ echo "Test conflit de mode"
	@ echo " "
	 ./ft_ls -l -1
	@ echo "LS original :"
	@ echo "0-1 "
	@ echo " "
	@ echo "Test conflit de mode et activation imposee"
	@ echo " "
	 ./ft_ls -l@ -1 -l
	@ echo "LS original :"
	@ echo "1-1-0"
	@ echo " "


	



