#include "sandpiles.h"

/**
 * sandpiles_sum - 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (!stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		copy_grid(grid2, grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid2[i][j] > 3)
				{
					grid1[i][j] = grid1[i][j] - 4;
					if (i - 1 >= 0)
						grid1[i - 1][j] += 1;
					if (j - 1 >= 0)
						grid1[i][j - 1] += 1;
					if (i + 1 < 3)
						grid1[i + 1][j] += 1;
					if (j + 1 < 3)
						grid1[i][j + 1] += 1;
				}
			}
		}
	}
}

/**
 * stable - 3x3 grids check if stable
 * @grid1: 3x3 grid
 * Return: True if grid is Stable, otherwise False
 */
bool stable(int grid1[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return (false);
			}
		}
	}
	return (true);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * copy_grid - copy grid1 into grid1 (3x3)
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void copy_grid(int grid2[3][3], int grid1[3][3])
{
	int i = 0, j = 0, n = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			n = grid1[i][j];
			grid2[i][j] = n;
		}
	}
}
