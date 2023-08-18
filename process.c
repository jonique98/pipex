/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:37:24 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/19 04:57:59 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process2(t_var *var, char **env, int *pipe_fd)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error");
	if (pid == 0)
	{
		close(var->fd_open);
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			perror_exit("dup2 error");
		close(pipe_fd[0]);
		if (dup2(var->fd_close, STDOUT_FILENO) == -1)
			perror_exit("dup2 error");
		close(var->fd_close);
		if (execve(var->cmd2[0], var->cmd2, env) == -1)
			perror_exit("execve error2");
	}
	else
		close(pipe_fd[0]);
}

void	child_process(t_var *var, char **env, int pipe_fd[2])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error");
	if (pid == 0)
	{
		close(var->fd_close);
		close(pipe_fd[0]);
		if (dup2(var->fd_open, STDIN_FILENO) == -1)
			perror_exit("dup2 error");
		close(var->fd_open);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			perror_exit("dup2 error");
		close(pipe_fd[1]);
		if (execve(var->cmd1[0], var->cmd1, env) == -1)
			perror_exit("execve error1");
	}
	else
		close(pipe_fd[1]);
}
