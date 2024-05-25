/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:22:33 by abablil           #+#    #+#             */
/*   Updated: 2024/05/21 18:55:44 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
#include "includes.h"
#include "utils/utils.h"
#include "utils/get_next_line/get_next_line.h"

#define VALID_ITEMS "0:1:N:S:E:W"

typedef struct s_data
{
	char	*temp;
	char	*map_file;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor_color;
	char	*ceiling_color;
}	t_data;
#endif