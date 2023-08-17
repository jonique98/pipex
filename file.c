/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:41:08 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/18 07:43:04 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_files(t_var *var, char **av)
{
	var->fd_open = open(av[1], O_RDONLY);
	if (var->fd_open == -1)
	{
		perror("file1 error");
		exit(1);
	}
	var->fd_close = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (var->fd_close == -1)
	{
		perror("file2 error");
		exit(1);
	}
}

void	init_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
}
