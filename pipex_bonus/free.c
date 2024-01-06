/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumjo <sumjo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 07:38:38 by sumjo             #+#    #+#             */
/*   Updated: 2023/12/30 04:42:16 by sumjo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(t_var *var)
{
	int	i;

	i = 0;
	while (var->path[i])
	{
		free(var->path[i]);
		i++;
	}
	free(var->path);
}

void	ft_free(t_var *var)
{
	free_path(var);
}

void	perror_exit(char *message, int status)
{
	if (message == 0)
		write(2, "ac error: 0\n", 12);
	else
		perror(message);
	exit(status);
}
