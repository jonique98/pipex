/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:37:24 by sumjo             #+#    #+#             */
/*   Updated: 2024/01/06 19:23:06 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	last_process(t_var *var, char **cmd)
{
	int		pid;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error", 128);
	if (pid == 0)
	{
		if (dup2(var->prev_pipe, STDIN_FILENO) == -1)
			perror_exit("dup2 error", 128);
		close(var->prev_pipe);
		if (dup2(var->fd_out, STDOUT_FILENO) == -1)
			perror_exit("dup2 error", 128);
		close(var->fd_out);
		if (execve(cmd[0], cmd, var->env) == -1)
			perror_exit("execve error1", 128);
	}
	else
	{
		close(var->prev_pipe);
		close(var->fd_out);
		wait(NULL);
	}
}

void	middle_process(t_var *var, int pipe_fd[2], char **cmd)
{
	int			pid;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error", 128);
	if (pid == 0)
	{
		close(var->fd_out);
		if (dup2(var->prev_pipe, STDIN_FILENO) == -1)
			perror_exit("dup2 error", 128);
		close(var->prev_pipe);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			perror_exit("dup2 error", 128);
		close(pipe_fd[1]);
		if (execve(cmd[0], cmd, var->env) == -1)
			perror_exit("execve error1", 128);
	}
	else
	{
		close(var->prev_pipe);
		var->prev_pipe = pipe_fd[0];
		close(pipe_fd[1]);
		wait(NULL);
	}
}

void	first_process(t_var *var, int pipe_fd[2], char **cmd)
{
	int			pid;

	pid = fork();
	if (pid == -1)
		perror_exit("fork error", 128);
	if (pid == 0)
	{
		close(var->fd_out);
		close(pipe_fd[0]);
		if (dup2(var->fd_in, STDIN_FILENO) == -1)
			perror_exit("dup2 error", 128);
		close(var->fd_in);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			perror_exit("dup2 error", 128);
		close(pipe_fd[1]);
		if (execve(cmd[0], cmd, var->env) == -1)
			perror_exit("execve error1", 128);
	}
	else
	{
		var->prev_pipe = pipe_fd[0];
		close(pipe_fd[1]);
		wait(NULL);
	}
}
