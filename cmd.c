/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:40:16 by sumjo             #+#    #+#             */
/*   Updated: 2023/09/03 20:47:12 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_cmd(t_var *var, char **av)
{
	var->cmd1 = ft_split(av[2], ' ');
	var->cmd2 = ft_split(av[3], ' ');
}

void	check_cmd1(t_var *var, char *cmd)
{
	int		i;
	char	*arr;

	i = 0;
	while (var->env[i])
	{
		arr = ft_strdup(var->env[i]);
		arr = ft_strjoin(arr, cmd);
		if (access(arr, F_OK) == 0)
		{
			free(var->cmd1[0]);
			var->cmd1[0] = arr;
			return ;
		}
		free(arr);
		i++;
	}
}

void	check_cmd2(t_var *var, char *cmd)
{
	int		i;
	char	*arr;

	i = 0;
	while (var->env[i])
	{
		arr = ft_strdup(var->env[i]);
		arr = ft_strjoin(arr, cmd);
		if (access(arr, F_OK) == 0)
		{
			free(var->cmd2[0]);
			var->cmd2[0] = arr;
			return ;
		}
		free(arr);
		i++;
	}
}

void	check_cmds(t_var *var)
{
	if (var->cmd1[0][0] != '/')
		check_cmd1(var, var->cmd1[0]);
	if (var->cmd2[0][0] != '/')
		check_cmd2(var, var->cmd2[0]);
}
