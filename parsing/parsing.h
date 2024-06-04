/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:17:27 by abablil           #+#    #+#             */
/*   Updated: 2024/06/04 21:48:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../includes.h"
# include "../utils/utils.h"

// Parsing
void	parsing(char *map_path, t_data *data);

// Checking
void	check_textures_path(t_data *data);
void	check_rgb(char *color, t_data *data);
void	check_colors_format(t_data *data);
void	check_textures(t_data *data);
void	check_invalid_chars(t_data *data);

// Converting
char	*expand_line(char *line, size_t size);
void	convert_tabs(t_data *data);
int		get_biggest_line(char **map);

// Map
int		map_start(t_data *data);
void	is_empty_map(t_data *data);
void	check_map(t_data *data);
int		check_if_map_closed(t_data *data, char *line, int i);
void	polish_map(t_data *data);

// More checking
void	check_first_six_lines(t_data *data);
void	check_border(char *line, t_data *data);
int		check_line(char *line);
int		check_player(t_data *data);
void	check_duplicated_keys(t_data *data);

// Reading
char	*get_line(char *str, int *i);
void	read_map_file(int fd, t_data *data);
void	get_file_data(char *map_path, t_data *data);
void	get_first_line(t_data *data, int *i, char **line);
void	get_map(t_data *data);

// Textures
char	*get_texture(t_data *data, int *i, char *texture_data);
void	get_textures(t_data *data);
void	get_xpms(t_data *data);

// Colors
void	check_rgb(char *color, t_data *data);
int		*create_rgb(int r, int g, int b);
void	set_colors(t_data *data);
void	check_colors_format(t_data *data);

#endif
