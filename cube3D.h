/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:22:33 by abablil           #+#    #+#             */
/*   Updated: 2024/05/17 15:32:52 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "utils/utils.h"
#include "utils/get_next_line/get_next_line.h"

typedef struct s_data {
	char	*temp;
	char	*map_file;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
} t_data;