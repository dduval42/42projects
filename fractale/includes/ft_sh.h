/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduval <dduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:08:33 by dduval            #+#    #+#             */
/*   Updated: 2015/02/13 11:52:33 by dduval           ###   ########.fr       */
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

int						ft_sh(char **env);
int						ft_check_path(char *path, char **cmd, char **env);
int						ft_check_func(char **env, char **cmd);
int						ft_check_my_func(char **cmd, char ***env);
void					ft_get_args(char ***env, char *arg);
int						ft_fork(char **arg, char **env, char *path);
int						ft_exit(char **cmd);
int						ft_env(char **env, char **cmd);
int						ft_env_error(char **cmd);
int						ft_alt_error_env(char *cmd);
void					ft_signal_handler(int signum);
void					ft_signal(void);
int						ft_cd(char ***env, char **cmd);
void					ft_get_home(char **env, char **path);
void					ft_absolute_path(char **path, char **env, char *cmd);
int						ft_setenv(char ***env, char **cmd);
char					**ft_setenv_check(char **env, char **cmd, int len);
int						ft_unsetenv(char ***env, char **cmd);
int						ft_check_alnum_error(char **cmd);
int						ft_count_spec(char *str, char *spe);
int						ft_strlen_cust(char *str, char *spe);
t_list					*ft_fill_list(char **cmd);
void					ft_aff_lst(t_list **lst);
int						ft_del_to_semicolon(t_list **lst, char ***env);
void					ft_del_to_redirect_left(t_list **lst);
void					ft_del_to_redirect_right(t_list **lst);
void					ft_del(void *content, size_t content_size);
void					ft_del_to_red_l_e(t_list **first, t_list **second);
void					ft_del_to_red_r_e(t_list **first, t_list **second);
int						ft_del_to_red_l_b(t_list **tmp, t_list *tmp2, int bol);
int						ft_del_to_red_r_b(t_list **tmp, t_list *tmp2, int bol);
int						ft_hub_exec(t_list **cmd, char ***env);
char					**ft_parse(char *cmd);
void					ft_pipe(char **cmd, int *save, t_list **tmp, char ***env);
void					ft_redirect_right(char **cmd, int *save, t_list **tmp, char **env);
int						ft_redirect(char **cmd, int *s, t_list **lst, int bol, t_list *tmp, char ***env);
int						ft_fill_bol(char **next);
char					**ft_fill_tab(char ***cmd, t_list *tmp);
int		toto(char *argv, char ***env);
int		ft_check_func_before_fork(char **cmd, char ***env);
void	ft_son(char **cmd, char ***env);


#endif
