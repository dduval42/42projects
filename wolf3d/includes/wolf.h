/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 20:02:25 by dduval            #+#    #+#             */
/*   Updated: 2015/02/26 19:23:58 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <mlx.h>
# include <libft.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

# define LARGEUR 1500
# define HAUTEUR 1000
# define CUBE 64
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT  65361
# define PLUS 65451
# define MINUS 65453
# define ONE 65457
# define ZERO 65456
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00

typedef	struct	s_cam
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		ms;
	double		rs;
	double		planex;
	double		planey;
}				t_cam;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
}				t_mlx;

typedef	struct	s_ress
{
	char		*argv;
	int			levels;
	char		**map;
	int			**tp;
}				t_ress;

typedef	struct	s_draw
{
	int	lineheight;
	int drawstart;
	int drawend;
	int color;
}				t_draw;

typedef	struct	s_event
{
	t_cam		*c;
	t_mlx		*m;
	t_ress		*s;
	t_draw		*draw;
	int			wintime;
}				t_event;

typedef	struct	s_ray
{
	double		rayposy;
	double		rayposx;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		walldist;
	double		deltadistx;
	double		deltadisty;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
}				t_ray;

void			ft_loop(void);
t_event			*ft_init_struct(void);
char			**ft_recup_map(t_event *e);
t_event			*ft_ray_cast(t_event *e);
void			ft_move_up_down(int key, t_event *e);
void			ft_move_left_right(int key, t_event *e);
void			mlx_pixel_put_to_image(unsigned long img_color,
				t_event *e, int x, int y);
t_draw			*ft_init_ray(t_cam	*c, double cam, t_event *e);
t_ray			*ft_check_step(t_ray *ray);
t_ray			*ft_check_hit(int hit, t_ray *ray, t_event *e, int *side);
t_draw			*ft_init_draw(t_ray *ray, int side);
void			ft_get_fps(t_event *e);
void			ft_levels(t_event *e);
void			ft_init_pos(t_event *e);
int				ft_len_map(t_event *e);
void			ft_config_move_speed(int key, t_event *e);
void			ft_config_rotate_speed(int key, t_event *e);
void			ft_inter_levels(t_event *e);
int				ft_get_minute(int *sec);
int				**ft_init_tp(t_event *e);
void			ft_end_levels(t_event *e);
void			ft_tp(t_event *e);

#endif
