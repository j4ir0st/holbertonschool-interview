#include "slide_line.h"

/**
 * slide_line - Entry point
 *
 * @line: pointer to an array of integers
 * @size: size of the array
 * @direction: dir to slide and merge the array
 *
 * Return: 1 on SUCCESS or 0 on FAILURE
 */

int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0, j = 0;

	if (direction == 0)
	{
		for (i = 0; i < size; i++)
		{
			for (j = i + 1; j < size; j++)
			{
				if (line[j] != 0)
				{
					if (line[i] == line[j])
					{
						line[i] += line[j];
						line[j] = 0;
						break;
					}
					if (line[i] == 0)
					{
                                                line[i] = line[j];
						line[j] = 0;
						i--;
						break;
					}
				}
			}
		}
	}
	if (direction == 1)
        {
                for (i = size; i > 0; i--)
                {
                        for (j = i - 1; j > 0; j--)
                        {
                                if (line[j - 1] != 0)
                                {
                                        if (line[i - 1] == line[j - 1])
                                        {
                                                line[i - 1] += line[j - 1];
                                                line[j - 1] = 0;
                                                break;
                                        }
                                        if (line[i - 1] == 0)
                                        {
                                                line[i - 1] = line[j - 1];
                                                line[j - 1] = 0;
                                                i++;
                                                break;
                                        }
				}
			}
		}
	}
	return (1);
}
