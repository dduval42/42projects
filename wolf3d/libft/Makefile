# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dduval <dduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 12:22:40 by dduval            #+#    #+#              #
#    Updated: 2015/02/12 16:59:08 by dduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_O = ft_bzero.o ft_memset.o ft_memcpy.o ft_memccpy.o
SRC_O += ft_memmove.o ft_memchr.o ft_memcmp.o ft_memalloc.o
SRC_O += ft_memdel.o ft_strsplit.o
SRC_O += ft_strlen.o ft_strdup.o
SRC_O += ft_strcpy.o ft_strncpy.o
SRC_O += ft_strcat.o ft_strncat.o ft_strlcat.o
SRC_O += ft_strchr.o ft_strrchr.o
SRC_O += ft_strstr.o ft_strnstr.o
SRC_O += ft_strcmp.o ft_strncmp.o
SRC_O += ft_strnew.o ft_strdel.o ft_strclr.o
SRC_O += ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o
SRC_O += ft_strequ.o ft_strnequ.o ft_strsub.o ft_strtrim.o
SRC_O += ft_strjoin.o ft_strsplit.o
SRC_O += ft_toupper.o ft_tolower.o
SRC_O += ft_isalpha.o ft_isdigit.o ft_isdigit.o ft_isalnum.o
SRC_O += ft_isprint.o ft_isascii.o ft_lstadd.o ft_lstiter.o
SRC_O += ft_atoi.o ft_itoa.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o
SRC_O += ft_putchar.o ft_putchar_fd.o ft_putstr.o ft_putstr_fd.o
SRC_O += ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o
SRC_O += ft_lstmap.o ft_len_tab.o ft_free_tab.o ft_print_tab.o
SRC_O += ft_printtab_fd.o get_next_line.o	ft_cpy_tab.o ft_match.o
SRC_O += ft_realloc_tab.o ft_remove_intab.o ft_stop_str.o
SRC_O += ft_strlen_carac.o	ft_strschr.o ft_lstsize.o

SRC = ./src/

OBJ = ./obj/

INC = ../includes

CFLAGS = -Wall -Wextra -Werror

DFLAGS = -g

CC = gcc

.SILENT :

all: $(OBJ) $(NAME)

$(OBJ):
ifeq ($(wildcard $(OBJ)),)
		$(shell mkdir $(OBJ))
endif

$(NAME): $(addprefix $(OBJ), $(SRC_O))
	ar rc $(NAME) $(addprefix $(OBJ), $(SRC_O))
	ranlib $(NAME)
	echo "\033[35; 1m Creation Lib\033[0m"

$(addprefix $(OBJ), %.o): $(addprefix $(SRC), %.c)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	rm -f $(addprefix $(OBJ), $(SRC_O))

fclean: clean
	rm -f $(NAME)

re: fclean all
