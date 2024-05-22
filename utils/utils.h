/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:48:31 by abablil           #+#    #+#             */
/*   Updated: 2024/05/22 16:15:44 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "../includes.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

// Errors
void	exit_game(char *message, t_data *data);

// Free
void	free_array(char **str);
void	free_data(t_data *data);

// Tools
int		array_len(char **str);

#endif