/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:35:31 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/18 07:35:51 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_split.c"


typedef struct s_var
{
	int fd_open;
	int fd_close;
	char **env;
	char **cmd1;
	char **cmd2;
}				t_var;


char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void child_process2(t_var *var, char **env, int *pipe_fd);
void child_process(t_var *var, char **env, int pipe_fd[2]);
char	*ft_strdup(char *s1);
char *return_path(char **envp);
void get_path(t_var *var, char **envp);
void	get_cmd(t_var *var, char **av);
void	check_cmd1(t_var *var, char *cmd);
void	check_cmd2(t_var *var, char *cmd);

void	ft_free_split(char **arr, int i);
char	*ft_inside(char const *s, char c);
int	ft_word_num(char const *s, char c);
int	ft_word_len(char const *s, char c);
void	make_arr(char const *s, char c, char **arr);


#endif
