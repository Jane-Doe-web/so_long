#include "mlx.h"

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*mlx_win;

	void	*img_walls;

	char	*relative_path = "./textures/floor.xpm";
	char	*relative_path1 = "./textures/walls.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// Initialize y and x
	int y = 0;
	while (y < 600)  // Loop over window height
	{
		int x = 0;
		while (x < 800)  // Loop over window width
		{
			mlx_put_image_to_window(mlx, mlx_win, img, x, y);
			x += img_width;  // Move to the next tile horizontally
		}
		y += img_height;  // Move to the next row vertically
	}
	img_walls = mlx_xpm_file_to_image(mlx, relative_path1, &img_width, &img_height);
	mlx_loop(mlx);
}