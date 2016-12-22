# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 13:20:33 by ariard            #+#    #+#              #
#    Updated: 2016/12/22 18:00:51 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls

SRC= main.c parsing_option.c command.c sort.c read_dir.c read_dir_a.c read_dir_d.c get_info.c auxi_list.c auxi_info3.c auxi_info2.c auxi_info4.c auxi_print2.c error.c print.c print_files.c column.c auxi_info.c auxi_print.c auxi_option.c auxi_option2.c auxi_print3.c ./Libft/ft_memalloc.c ./Libft/ft_bzero.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c ./Libft/ft_strcmp.c ./Libft/ft_stack_push.c ./Libft/ft_list_push_front.c ./Libft/ft_create_elem.c ./Libft/ft_strlen.c ./Libft/ft_strdel.c ./Libft/ft_stack_pop.c ./Libft/ft_strjoin.c ./Libft/ft_strnew.c ./Libft/ft_list_rem_front.c ./Libft/ft_strcat.c ./Libft/ft_strcpy.c ./Libft/ft_memcpy.c ./Libft/ft_list_push_back.c ./Libft/ft_list_clear.c ./Libft/ft_memdel.c ./Libft/ft_list_ins.c ./Libft/ft_list_rem.c ./Libft/ft_list_swap.c ./Libft/ft_list_push_back_special.c ./Libft/ft_list_reverse.c ./Libft/ft_strrchr.c ./Libft/ft_itoa.c ./Libft/ft_strchr.c ./Libft/ft_strncat.c ./Libft/ft_strdup.c ./Libft/ft_list_size.c ./Libft/ft_putstr_fd.c

OBJ= main.o parsing_option.o command.o sort.o read_dir.o read_dir_a.o read_dir_d.o get_info.o auxi_list.o auxi_info3.o auxi_info2.o auxi_info4.o auxi_print2.o error.o print.o column.o print_files.o auxi_info.o auxi_print.o auxi_option.o auxi_option2.o auxi_print3.o ft_memalloc.o ft_bzero.o ft_putchar.o ft_putstr.o ft_strcmp.o ft_stack_push.o ft_list_push_front.o ft_create_elem.o ft_strlen.o ft_strdel.o ft_stack_pop.o ft_strjoin.o ft_strnew.o ft_list_rem_front.o ft_strcat.o ft_strcpy.o ft_memcpy.o ft_list_push_back.o ft_list_clear.o ft_memdel.o ft_list_ins.o ft_list_rem.o ft_list_swap.o ./ft_list_push_back_special.o ft_list_reverse.o ft_strrchr.o ft_itoa.o ft_strchr.o ft_strncat.o ft_strdup.o ft_list_size.o ft_putstr_fd.o

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
	@ rm -rf $(NAME)
	@ rm -f Libft/libft.a

re: fclean all 
