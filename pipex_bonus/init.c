/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:02:28 by sumjo             #+#    #+#             */
/*   Updated: 2023/12/30 04:42:01 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_struct(t_var *var, int ac, char **av, char **env)
{
	open_files(var, ac, av);
	get_path(var, env);
	check_commands(var, ac, av);
	var->ac = ac;
	var->av = av;
	var->env = env;
	var->prev_pipe = 0;
}
