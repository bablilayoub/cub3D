/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:48:31 by abablil           #+#    #+#             */
/*   Updated: 2024/05/17 18:57:58 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"
#include "libft/libft.h"

// Errors
void	exit_game(char *message, int status_code, int is_error);

// Free
void	free_array(char **str);

// Tools
int		array_len(char **str);