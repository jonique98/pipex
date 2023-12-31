/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:38:38 by sumjo             #+#    #+#             */
/*   Updated: 2023/08/19 05:38:44 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_env(t_var *var)
{
	int	i;

	i = 0;
	while (var->env[i])
	{
		free(var->env[i]);
		i++;
	}
	free(var->env);
}

void	free_cmd(t_var *var)
{
	int	i;

	i = 0;
	while (var->cmd1[i])
	{
		free(var->cmd1[i]);
		i++;
	}
	free(var->cmd1);
	i = 0;
	while (var->cmd2[i])
	{
		free(var->cmd2[i]);
		i++;
	}
	free(var->cmd2);
}

void	ft_free(t_var *var)
{
	free_env(var);
	free_cmd(var);
}

void	perror_exit(char *message)
{
	if (message == 0)
		write(2, "ac error: 0\n", 12);
	else
		perror(message);
	exit(1);
}
