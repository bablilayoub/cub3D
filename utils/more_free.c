/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:05:28 by abablil           #+#    #+#             */
/*   Updated: 2024/06/03 00:00:17 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "../cub3D.h"

void	free_torch(t_data *data)
{
	destory_texture(data, data->torch_1_texture);
	destory_texture(data, data->torch_2_texture);
	destory_texture(data, data->torch_3_texture);
	destory_texture(data, data->torch_4_texture);
	destory_texture(data, data->torch_5_texture);
	destory_texture(data, data->torch_6_texture);
	destory_texture(data, data->torch_7_texture);
	destory_texture(data, data->torch_8_texture);
}

void	free_doors(t_data *data)
{
	t_doors	*tmp;
	t_doors	*next;

	if (!data->doors)
		return ;
	tmp = data->doors;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
