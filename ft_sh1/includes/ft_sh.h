/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 15:05:10 by dduval            #+#    #+#             */
/*   Updated: 2015/02/19 18:20:12 by dduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H
# include <libft.h>
# include <dirent.h>
# include <stdio.h>
# include <signal.h>
# include <limits.h>
# include <fcntl.h>

pid_t					g_father;
typedef struct dirent	t_dir;
typedef		struct		s_lstsh
{
	void				*content;
	struct s_lstsh		*prev;
	struct s_lstsh		*next;
}						t_lstsh;

int						ft_count_word(char *s, char *sp);
int						ft_check(char c, char *sp);
char					**ft_parse(char *str, char *sp);
t_lstsh					*ft_fill_list(char **arg);
void					ft_aff_list(t_lstsh *lst);
#endif
