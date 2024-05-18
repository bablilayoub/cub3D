/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:22:33 by abablil           #+#    #+#             */
/*   Updated: 2024/05/18 18:57:03 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "utils/utils.h"
#include "utils/get_next_line/get_next_line.h"

#define VALID_ITEMS "NO:SO:WE:EA:F:C"

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