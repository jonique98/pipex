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

void	open_files(t_var *var, char **av)
{
	var->fd_in = open(av[1], O_RDONLY);
	if (var->fd_in == -1)
		perror_exit("file1 error");
	var->fd_out = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (var->fd_out == -1)
		perror_exit("file2 error");
}

void	init_pipe(int pipe_fd[2])
{
	if (pipe(pipe_fd) == -1)
		perror_exit("pipe error");
}
