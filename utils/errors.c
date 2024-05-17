/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:32:23 by abablil           #+#    #+#             */
/*   Updated: 2024/05/16 19:59:41 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../cube3D.h"

void exit_game(char *message, int status_code, int is_error)
{
	if (message)
	{
		if (is_error)
			printf("\033[91m\033[1mError\033[0m :\n");
		printf("%s\n", message);
	}
	exit(status_code);
}