#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
bool stable(int grid1[3][3]);
static void print_grid(int grid[3][3]);
void copy_grid(int grid2[3][3], int grid1[3][3]);

#endif
