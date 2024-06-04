/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:48:31 by abablil           #+#    #+#             */
/*   Updated: 2024/06/04 21:50:23 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../includes.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

// Errors
void	exit_game(char *message, t_data *data, int fd, int is_error);
void	exit_game_clean(t_data *data);

// Free
void	free_array(char **str);
void	free_data(t_data *data);
void	destory_texture(t_data *data, t_texture *texture);
void	free_torch(t_data *data);
void	free_doors(t_data *data);

// Tools
int		array_len(char **str);
int		is_number(char *str);
int		count_commas(char *str);

#endif