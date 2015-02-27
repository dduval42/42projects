NAME = wolf3d

SRC_O =		loop.o	main.o	init_struct.o
SRC_O +=	recup_map.o	ray_cast.o
SRC_O +=	move.o	init_ray.o
SRC_O +=	pixel_put.o	check_step.o
SRC_O +=	check_hit.o	init_draw.o
SRC_O +=	get_fps.o	levels.o
SRC_O +=	init_pos.o	len_map.o
SRC_O +=	config.o	inter_levels.o
SRC_O +=	get_minute.o	init_tp.o
SRC_O +=	end_level.o	tp.o

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

all: lib $(OBJ) $(NAME)

lib:
	make -C libft

$(OBJ):
ifeq ($(wildcard $(OBJ)),)
	@$(shell mkdir $(OBJ))
endif

$(NAME): $(OBJ_O)
	echo "[33; 1m Creation objets[0m"
	$(CC) -o $@ $(OBJ_O) -L $(LIB)  -L $(LIB2) $(L2FLAGS) $(LFLAGS) $(DFLAGS)
	echo "[31; 1m Creation Exe[0m"


proper: $(NAME) clean

clean:
	rm -f $(addprefix $(OBJ), $(SRC_O))
	make clean -C $(LIB)
	echo "[32; 1m Clean obj[0m"

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)/$(LIB).a
	echo "[34; 1m Clean exe[0m"

del:
	rm -f $(NAME)

liball:del all

re: fclean all

$(addprefix $(OBJ), %.o): $(addprefix $(SRC), %.c)
	$(CC) -c $(CFLAGS) $< -o $@ -I $(INC)
