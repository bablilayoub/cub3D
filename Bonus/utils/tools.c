/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:27:55 by abablil           #+#    #+#             */
/*   Updated: 2024/06/06 13:54:12 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../../cub3D.h"

int	array_len(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	is_number(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		if (ft_isdigit(str[i]))
			result = result * 10 + str[i] - '0';
		if (result > 255)
			return (0);
		i++;
	}
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (ft_strlen(str) == (size_t)i)
		return (0);
	return (1);
}

int	count_commas(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

void	exit_game_clean(t_data *data)
{
	printf("Exit game\n");
	system("killall afplay");
	free_data(data);
	exit(0);
}
