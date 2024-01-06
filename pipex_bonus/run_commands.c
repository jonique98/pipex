/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 02:00:11 by sumjo             #+#    #+#             */
/*   Updated: 2023/12/30 04:44:29 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_commands(t_var *var)
{
	int		pipe_fd[2];
	int		i;
	char	**cmd;

	i = 1;
	while (++i < var->ac - 1)
	{
		cmd = return_commands(var, var->av[i]);
		if (i == var->ac - 2)
			last_process(var, cmd);
		else
		{
			init_pipe(pipe_fd);
			if (i == 2)
				first_process(var, pipe_fd, cmd);
			else
				middle_process(var, pipe_fd, cmd);
		}
	}
}
