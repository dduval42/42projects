/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:55:29 by dduval            #+#    #+#             */
/*   Updated: 2015/03/03 15:52:13 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <libft.h>
# include <ncurses.h>

typedef	struct	s_effects
{

}				t_effects;

typedef	struct		s_trap
{
	int				id;
	char			*name;
	char			*desc;
	int				coast;
	t_effects		*effect;
	struct	s_trap	*next;
	struct	s_trap	*prev;
}					t_trap;

typedef	struct		s_magic
{
	int				id;
	char			*name;
	char			*desc;
	int				coast;
	t_effects		*effect;
	struct	s_magic	*next;
	struct	s_magic	*prev;
}					t_magic;

typedef	struct		s_beast
{
	int				id;
	char			*name;
	char			*desc;
	int				coast;
	int				life;
	t_effects		*effect;
	int				atk;
	struct	s_beast	*next;
	struct	s_beast	*prev;
}					t_beast;

typedef	struct		s_card
{
	int				type;
	int				id;
	t_trap			*trap;
	t_magic			*magic;
	t_beast			*beast;
}					t_card;

typedef	struct		s_player
{
	char			*name;
	char			*mdp;
	int				level;
	int				gold;
}					t_player;

typedef	struct		s_deck
{
	struct s_deck	*next;
	t_card			*current;
	struct	s_deck	*prev;
}					t_deck;

typedef	struct		s_databoard
{
	t_player		*player1;
	t_deck			*deck1;
	t_deck			*cim1;
	t_player		*player2;
	t_deck			*deck2;
	t_deck			*cim2;
}					t_databoard;
# endif
