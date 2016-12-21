# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariard <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 13:20:33 by ariard            #+#    #+#              #
#    Updated: 2016/12/21 00:38:32 by ariard           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls

SRC= main.c parsing_option.c command.c sort.c read_dir.c read_dir_a.c read_dir_d.c get_info.c auxi_list.c auxi_info3.c error.c print.c print_files.c column.c auxi_info.c auxi_print.c ./Libft/ft_memalloc.c ./Libft/ft_bzero.c ./Libft/ft_putchar.c ./Libft/ft_putstr.c ./Libft/ft_strcmp.c ./Libft/ft_stack_push.c ./Libft/ft_list_push_front.c ./Libft/ft_create_elem.c ./Libft/ft_strlen.c ./Libft/ft_strdel.c ./Libft/ft_stack_pop.c ./Libft/ft_strjoin.c ./Libft/ft_strnew.c ./Libft/ft_list_rem_front.c ./Libft/ft_strcat.c ./Libft/ft_strcpy.c ./Libft/ft_memcpy.c ./Libft/ft_list_push_back.c ./Libft/ft_list_clear.c ./Libft/ft_memdel.c ./Libft/ft_list_ins.c ./Libft/ft_list_rem.c ./Libft/ft_list_swap.c ./Libft/ft_list_push_back_special.c ./Libft/ft_list_reverse.c ./Libft/ft_strrchr.c ./Libft/ft_itoa.c ./Libft/ft_strchr.c ./Libft/ft_strncat.c ./Libft/ft_strdup.c ./Libft/ft_list_size.c

OBJ= main.o parsing_option.o command.o sort.o read_dir.o read_dir_a.o read_dir_d.o get_info.o auxi_list.o auxi_info3.o error.o print.o column.o print_files.o auxi_info.o auxi_print.o ft_memalloc.o ft_bzero.o ft_putchar.o ft_putstr.o ft_strcmp.o ft_stack_push.o ft_list_push_front.o ft_create_elem.o ft_strlen.o ft_strdel.o ft_stack_pop.o ft_strjoin.o ft_strnew.o ft_list_rem_front.o ft_strcat.o ft_strcpy.o ft_memcpy.o ft_list_push_back.o ft_list_clear.o ft_memdel.o ft_list_ins.o ft_list_rem.o ft_list_swap.o ./ft_list_push_back_special.o ft_list_reverse.o ft_strrchr.o ft_itoa.o ft_strchr.o ft_strncat.o ft_strdup.o ft_list_size.o

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

#parsing-files
	
test-files-error:
	@ echo "->Test pas de permission"
	@ echo " "
	 ./ft_ls ../../../bocal/Desktop
	@ echo "LS original :"
	@ echo "ls : Permission Denied"
	@ echo " "
	@ echo " "
	@ echo "->Test pas de fichier existant"
	@ echo " "
	 ./ft_ls abcedf
	@ echo "LS original :"
	@ echo "ls : No such file or directory"
	@ echo " "
	@ echo " "
	@ echo "->Test pas un directory"
	@ echo " "
	 ./ft_ls fichier1;
	@ echo "LS original :"
	@ echo "ls : Not a directory"
	@ echo " "
	@ echo " "
	@ echo "->Test all directory"
	@ echo " "
	 ./ft_ls 
	@ echo "LS original :"
	@ echo "hello-bonjour-salut-aurevoir"
	@ echo " "
	@ echo " "
	@ echo "->Test directory and files"
	@ echo " "
	 ./ft_ls hello fichier1 bonjour fichier2 salut aurevoir
	@ echo "LS original :"
	@ echo "fichier1 : Not a directory"
	@ echo "fichier2 : Not a directory"
	@ echo "hello-bonjour-salut-aurevoir"
	@ echo " "
	@ echo " "


	



