/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmassy <anmassy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:09:48 by anmassy           #+#    #+#             */
/*   Updated: 2023/02/18 15:08:04 by anmassy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mlx/mlx.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	// void	*image;
// 	// int		*x;
// 	// int		*y

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	// image = mlx_xpm_file_to_image(mlx, "lien", x, y);
// 	mlx_loop(mlx);
// 	(void)mlx_win;
// }


// int		mlx_clear_window(void *mlx_ptr, void *win_ptr);
// int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
// void	*mlx_new_image(void *mlx_ptr,int width,int height);

// void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

#include "get_next_line/get_next_line.h"
#include "include/so_long.h"

int main(int ac, char **av)
{
	char	**map;
	int	fd;
	char	c;

	if (ac != 2)
		return (0);
	fd = open (av[1], O_RDONLY);
	if (fd < 0 || read (fd, &c, 1) == 0)
	{
		printf("error_null");
		return (0);
	}
	close(fd);
	map = convert_map(av[1]);
	if (!check_connecting(map) || !check_entry(map) || !check_exit(map)
		|| !map_is_rectangular(map) || !check_value(map) || !check_wall(map)
		|| !check_file(av[1]))
	{
		printf("error");
		return (0);
	}
	return (0);
}