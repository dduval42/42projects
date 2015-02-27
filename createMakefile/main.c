#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_count_files(char *path)
{
	int i;
	DIR *rep;
	struct dirent *dir;
	i = 0;
	rep = opendir(path);

	while ((dir = readdir(rep)) != NULL)
		i++;
	if (i == 0)
	{
		printf("No source files\n");
		exit(EXIT_FAILURE);
	}
	return (i);
}

char	**ft_get_files(char *path, int len)
{
	DIR *rep;
	struct dirent *dir;
	char	**files;
	int i;

	i = 0;
	files = (char **)malloc(sizeof(char *) * len + 1);
	rep = opendir(path);

	while((dir = readdir(rep)) != NULL)
	{
		files[i] = strdup(dir->d_name);
		i++;
	}
	return (files);
}

char	**ft_object(char **files)
{
	int i;

	i = 0;
	while (files[i])
	{
		if(files[i][strlen(files[i]) - 2] == '.' && files[i][strlen(files[i]) - 1] == 'c')
			files[i][strlen(files[i]) - 1] = 'o';
		i++;
	}
	return(files);
}

int		create_make(char *path)
{
	int fd;
	char *name;

	name = (char *)malloc(strlen(path) + 12);
	name = strcat(name, path);
	name = strcat(name, "/");
	name = strcat(name, "Makefile");
	if (opendir(name) == NULL)
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (fd);
}

void	write_begin(int fd, char **files, char *path)
{
	int i;
	int j;
	int bol;

	bol = 0;
	i = 0;
	dprintf(fd,"NAME = %s\n", strrchr(path, '/') + 1);
	dprintf(fd,"\nSRC_O =	");
	while(files[i])
	{
		j = 0;
		if (bol == 1)
			dprintf(fd, "\nSRC_O +=");
		while(files[i] && j < 4)
		{
			if (files[i][strlen(files[i]) - 1] == 'o')
			{
				dprintf(fd,"	%s", files[i]);
				i++;
				j++;
				bol = 1;
			}
			else
				i++;
		}
	}
}

void	write_middle(int fd, char **argv)
{
	dprintf(fd,"\n\nSRC = ./proj/src/\n\n");
	dprintf(fd,"OBJ = ./proj/obj/\n\n");
	if (strcmp(argv[2], "flag") == 0)
		dprintf(fd,"CFLAGS = -Wall -Wextra -Werror\n\n");
	else
		dprintf(fd,"CFLAGS =\n\n");
	dprintf(fd,"INC = ./includes\n\n");
	if (strcmp(argv[3], "libft") == 0)
	{
		dprintf(fd,"LIB = libft\n\n");
		dprintf(fd,"LFLAGS = -lft\n\n");
	}
	else if (strcmp(argv[3], "mlx") == 0)
	{
		dprintf(fd,"LIB = /usr/X11/lib\n\n");
		dprintf(fd,"LFLAGS = -lmlx -lXext -lX11\n\n");
	}
	else
	{
		dprintf(fd,"LIB =\n\n");
		dprintf(fd,"LFLAGS =\n\n");
	}
	if (argv[4] && strcmp(argv[4], "mlx") == 0)
	{
		dprintf(fd,"LIB2 = /usr/X11/lib\n\n");
		dprintf(fd,"L2FLAGS = -lmlx -lXext -lX11\n\n");
	}
	else if (argv[4] && strcmp(argv[4], "libft") == 0)
	{
		dprintf(fd,"LIB2 = libft\n\n");
		dprintf(fd,"L2FLAGS = -lft\n\n");
	}
	else
	{
		dprintf(fd,"LIB2 =\n\n");
		dprintf(fd,"L2FLAGS =\n\n");
	}
	dprintf(fd,"CC = gcc\n\n");
	dprintf(fd,"OBJ_O = $(addprefix $(OBJ), $(SRC_O))\n\n");
	dprintf(fd,"DFLAGS = -g\n\n");
	dprintf(fd,".SILENT :\n\n");
	dprintf(fd,"all: $(OBJ) $(NAME)\n\n");
	dprintf(fd,"$(OBJ):\n");
	dprintf(fd,"ifeq ($(wildcard $(OBJ)),)\n");
	dprintf(fd,"	@$(shell mkdir $(OBJ))\n");
	dprintf(fd,"endif\n\n");
}

void	write_end(int fd, char **argv)
{
	dprintf(fd,"$(NAME): $(OBJ_O)\n");
	dprintf(fd,"	echo \"\033[33; 1m Creation objets\033[0m\"\n");
	dprintf(fd,"	make -C $(LIB)\n");
	if (argv[4] && strcmp(argv[4], "mlx") == 0)
		dprintf(fd,"	$(CC) -o $@ $(OBJ_O) -L $(LIB)  -L $(LIB2) $(L2FLAGS) $(LFLAGS) $(DFLAGS)\n");
	else
		dprintf(fd,"	$(CC) -o $@ $(OBJ_O) -L $(LIB) $(LFLAGS) $(DFLAGS)\n");
	dprintf(fd,"	echo \"\033[31; 1m Creation Exe\033[0m\"\n\n");
	dprintf(fd,"proper: $(NAME) clean\n\n");
	dprintf(fd,"clean:\n");
	dprintf(fd,"	rm -f $(addprefix $(OBJ), $(SRC_O))\n");
	dprintf(fd,"	make clean -C $(LIB)\n");
	dprintf(fd,"	echo \"\033[32; 1m Clean obj\033[0m\"\n\n");
	dprintf(fd,"fclean: clean\n");
	dprintf(fd,"	rm -f $(NAME)\n");
	dprintf(fd,"	rm -f $(LIB)/$(LIB).a\n");
	dprintf(fd,"	echo \"\033[34; 1m Clean exe\033[0m\"\n\n");
	dprintf(fd,"re: fclean all\n\n");
	dprintf(fd,"$(addprefix $(OBJ), %%.o): $(addprefix $(SRC), %%.c)\n");
	if (strcmp(argv[2], "flag") == 0)
		dprintf(fd,"	$(CC) $(CFLAGS) -c  $< -o $@ -I $(INC)\n");
	else
		dprintf(fd,"	$(CC) -c  $< -o $@ -I $(INC)\n");
}

int		main(int argc, char **argv)
{
	char **files;
	int i;
	int fd;

	i = 0;
	if (argc < 4 || argc > 5)
	{
		printf("Use: ./ft_create path flag lib lib\n");
		return (0);
	}
	files = ft_get_files(argv[1], ft_count_files(argv[1]));
	files = ft_object(files);
	fd = create_make(argv[1]);
	write_begin(fd, files, argv[1]);
	write_middle(fd, argv);
	write_end(fd, argv);
	return(0);
}
