/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:35:31 by sumjo             #+#    #+#             */
/*   Updated: 2024/01/06 19:23:06 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_var
{
	int		ac;
	char	**av;
	char	**env;
	char	**path;
	int		cmd_num;
	int		prev_pipe;
	int		fd_in;
	int		fd_out;
}t_var;

char	**return_commands(t_var *var, char *av);
void	init_struct(t_var *var, int ac, char **av, char **env);
void	run_commands(t_var *var);
char	*ft_strdup(char *s1);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_commands(t_var *var, int ac, char **av);

void	open_files(t_var *var, int ac, char **av);
void	get_path(t_var *var, char **env);
void	get_cmd(t_var *var, char **av);
void	init_pipe(int *pipe_fd);
void	wait_childs(t_var *var);

int		ft_word_len(char const *s, char c);
char	*ft_inside(char const *s, char c);
int		ft_word_num(char const *s, char c);
void	make_arr(char const *s, char c, char **arr);
char	**ft_split(char const *s, char c);
void	ft_free(t_var *var);

void	perror_exit(char *message, int status);
void	child_process2(t_var *var, char **env, int *pipe_fd);
void	child_process(t_var *var, char **cmd, char **env, int pipe_fd[2]);
char	*return_path(char **envp);
void	get_path(t_var *var, char **envp);
void	get_cmd(t_var *var, char **av);
char	*ft_strdup(char *s1);

void	first_process(t_var *var, int pipe_fd[2], char **cmd);
void	last_process(t_var *var, char **cmd);
void	middle_process(t_var *var, int pipe_fd[2], char **cmd);

#endif
