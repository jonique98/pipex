/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:41:08 by sumjo             #+#    #+#             */
/*   Updated: 2024/01/06 19:23:06 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_var *var, int ac, char **av)
{
	int		exit_status;

	exit_status = 0;
	var->fd_in = open(av[1], O_RDONLY);
	if (var->fd_in == -1)
	{
		perror("file1 error");
		exit_status = 1;
	}
	var->fd_out = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (var->fd_out == -1)
	{
		perror("file2 error");
		exit_status = 1;
	}
	if (exit_status)
		exit(exit_status);
}

void	init_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		perror_exit("pipe error", 128);
}
