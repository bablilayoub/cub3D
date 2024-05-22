/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:32:23 by abablil           #+#    #+#             */
/*   Updated: 2024/05/22 16:33:32 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../cub3D.h"

void exit_game(char *message, t_data *data)
{
	if (message)
	{
		printf("\033[91m\033[1mError\033[0m :\n");
		printf("%s\n", message);
	}
	free_data(data);
	exit(1);
}