NAME = fractale

SRC_O =		hook.o	iter.o	main.o	move.o
SRC_O +=	zoom.o

SRC = ./proj/src/

OBJ = ./proj/obj/

CFLAGS = -Wall -Wextra -Werror

INC = ./includes

LIB = libft

LFLAGS = -lft

LIB2 = /usr/X11/lib

L2FLAGS = -lmlx -lXext -lX11

CC = gcc

OBJ_O = $(addprefix $(OBJ), $(SRC_O))

DFLAGS = -g

.SILENT :

all: $(OBJ) $(NAME)

$(OBJ):
ifeq ($(wildcard $(OBJ)),)
	@$(shell mkdir $(OBJ))
endif

$(NAME): $(OBJ_O)
	echo "[33; 1m Creation objets[0m"
	make -C $(LIB)
	$(CC) -o $@ $(OBJ_O) -L $(LIB)  -L $(LIB2) $(L2FLAGS) $(LFLAGS) $(DFLAGS)
	echo "[31; 1m Creation Exe[0m"

proper: $(NAME) clean

clean:
	rm -f $(addprefix $(OBJ), %.o)
	make clean -C $(LIB)
	echo "[32; 1m Clean obj[0m"

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)/$(LIB).a
	echo "[34; 1m Clean exe[0m"

re: fclean all

$(addprefix $(OBJ), %.o): $(addprefix $(SRC), %.c)
	$(CC) $(CFLAGS) -c  $< -o $@ -I $(INC)
