/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:35:31 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/19 04:53:28 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_var
{
	int		fd_open;
	int		fd_close;
	char	**env;
	char	**cmd1;
	char	**cmd2;
}t_var;

char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	open_files(t_var *var, char **av);
void	get_path(t_var *var, char **env);
void	get_cmd(t_var *var, char **av);
void	check_cmds(t_var *var);
void	init_pipe(int *pipe_fd);
void	wait_childs(t_var *var);

int		ft_word_len(char const *s, char c);
char	*ft_inside(char const *s, char c);
int		ft_word_num(char const *s, char c);
void	make_arr(char const *s, char c, char **arr);
char	**ft_split(char const *s, char c);
void	ft_free(t_var *var);

void	child_process2(t_var *var, char **env, int *pipe_fd);
void	child_process(t_var *var, char **env, int pipe_fd[2]);
char	*return_path(char **envp);
void	get_path(t_var *var, char **envp);
void	get_cmd(t_var *var, char **av);
void	check_cmd1(t_var *var, char *cmd);
void	check_cmd2(t_var *var, char *cmd);
char	*ft_strdup(char *s1);
void	perror_exit(char *message);

#endif
