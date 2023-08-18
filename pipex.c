/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:35:46 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/19 05:37:45 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_var	var;
	int		pipe_fd[2];

	if (ac != 5)
		perror_exit(0);
	open_files(&var, av);
	get_path(&var, env);
	get_cmd(&var, av);
	check_cmds(&var);
	init_pipe(pipe_fd);
	child_process(&var, env, pipe_fd);
	child_process2(&var, env, pipe_fd);
	wait_childs(&var);
	ft_free(&var);
}
