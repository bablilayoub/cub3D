/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:21:59 by abablil           #+#    #+#             */
/*   Updated: 2024/05/24 18:45:45 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_ESC 53

void	f(void)
{
	system("leaks cub3D");
}


void	init_game(t_data *data)
{
	void	*mlx;
	void	*win;
	void	*img;
	
	mlx = mlx_init();
	if (!mlx)
		exit_game("Failed to init mlx.", data, -1);
	win = mlx_new_window(mlx, 1920, 1080, "cub3D");
	if (!win)
		exit_game("Failed to create window.", data, -1);
	img = mlx_new_image(mlx, 1920, 1080);
	if (!img)
		exit_game("Failed to create image.", data, -1);
	mlx_loop(mlx);
}

int	main(int total, char **args)
{
	t_data	data;

	// atexit(f);
	if (total != 2)
	{
		printf("\033[30m\033[102m Usage \033[0m : ./cub3D [map path]\n");
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	parsing(args[1], &data);
	init_game(&data);
	free_data(&data);
}
