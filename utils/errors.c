/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:32:23 by abablil           #+#    #+#             */
/*   Updated: 2024/06/03 17:04:53 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../cub3D.h"

void	exit_game(char *message, t_data *data, int fd, int is_error)
{
	if (message)
	{
		if (is_error)
			printf("\033[91m\033[1mError\033[0m :\n");
		printf("%s\n", message);
	}
	if (fd != -1)
		close(fd);
	free_data(data);
	if (is_error)
		exit(1);
	exit(0);
}
