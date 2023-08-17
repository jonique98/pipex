/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:37:24 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/18 07:43:26 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process2(t_var *var, char **env, int *pipe_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
	dup2(var->fd_close, STDOUT_FILENO);
	close(var->fd_close);
	if (execve(var->cmd2[0], var->cmd2, env) == -1)
	{
		perror("execve error2");
		exit(1);
	}
}

void	child_process(t_var *var, char **env, int pipe_fd[2])
{
	close(pipe_fd[0]);
	dup2(var->fd_open, STDIN_FILENO);
	close(var->fd_open);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (execve(var->cmd1[0], var->cmd1, env) == -1)
	{
		perror("execve error1");
		exit(1);
	}
}
