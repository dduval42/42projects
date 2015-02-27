/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 15:54:12 by dduval            #+#    #+#             */
/*   Updated: 2015/02/13 12:14:29 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACT_H
# define FRACT_H
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <libft.h>
# define LARGEUR 1000.0
# define HAUTEUR 1000.0
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_PLUS 65451
# define K_MINUS 65453
# define K_CTRL  65507
# define K_ONE 65457
# define K_ZERO 65456
# define K_SPACE 32
# define K_ESCAPE 65307
# define K_PGUP 65365
# define K_PGDWN 65366

typedef struct	s_coord
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			x;
	int			y;
	int			a;
	float		rc;
	float		ic;
	float		rz;
	float		iz;
	float		r;
	float		i;
	int			iter;
	float		maxxm;
	float		minxm;
	float		minxj;
	float		maxxj;
	float		miny;
	float		maxy;
	char		**argv;
	double		h;
	float		hy;

}				t_coord;

int				key_hook(int key, t_coord *e);
t_coord			super_hub(t_coord *e);
int				expose(t_coord *e);
t_coord			ft_fractale( t_coord e);
void			ft_fractale2(t_coord e);
t_coord			ft_zoom(t_coord e);


#endif
