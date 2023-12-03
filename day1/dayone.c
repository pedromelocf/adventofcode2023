#include <stdio.h>
#include <stdlib.h>

int	ft_find_first_int(char **argv, int x);
int ft_find_last_int(char **argv, int x, int y);
int	ft_get_result(int **matrix, int argc);

int main (int argc, char **argv)
{
	int x = 1;
	int y = 0;
	int z = 0;
	int	**matrix;
	int value = 0;

	matrix = malloc(sizeof(int*) * (argc - 1));
	while (x < argc)
	{
		while(argv[x] != NULL)
		{
			y = 0;
			matrix[z] = malloc(sizeof(int) * 2);
			matrix[z][0] = ft_find_first_int(argv, x);
			while (argv[x][y] != '\0')
				y++;
			matrix[z][1] = ft_find_last_int(argv, x, y);
			x++;
			z++;
		}
	}
	value = ft_get_result(matrix, argc);
	return (value);
}

int	ft_find_first_int(char **argv, int z)
{
	int y = 0;
	int value;

	y = 0;
	value = 0;
	while (argv[z][y] != '\0')
	{
		if (argv[z][y] >= '1' && argv[z][y] <= '9')
		{
			value = argv[z][y] - '0';
			return (value);
		}
		y++;
	}
	return 0;
}

int ft_find_last_int(char **argv, int x, int y)
{
	int value;
	int i;

	i = 0;
	value = 0;
	while (y >= i)
	{
		if (argv[x][y] >= '0' && argv[x][y] <= '9')
		{
			value = argv[x][y] - '0';
			return(value);
		}
		y--;
	}
	return 0;
}

int	ft_get_result(int **matrix, int argc)
{
	int x = 0;
	int y = 0;
	int value = 0;

	while (x < argc - 1)
	{
		y = 0;
		value += matrix[x][y] * 10;
		y++;
		value += matrix[x][y];
		x++;
	}
	return (value);
}
