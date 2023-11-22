#!/usr/bin/python3
"""5. Island Perimeter"""


def island_perimeter(grid):
    """
    input: grid is a list of list of integers
    return: the perimeter of the island described in grid
    """
    perimeter = 0
    row = len(grid)
    column = len(grid[0]) if row else 0
    for i in range(row):
        for j in range(column):
            if grid[i][j] == 1:
                if i > 0 and grid[i-1][j] != 1:
                    perimeter += 1
                if i < (row-1) and grid[i+1][j] != 1:
                    perimeter += 1
                if j > 0 and grid[i][j-1] != 1:
                    perimeter += 1
                if j < (column-1) and grid[i][j+1] != 1:
                    perimeter += 1
                if i == 0 or i == (row-1):
                    perimeter += 1
                if j == 0 or j == (column-1):
                    perimeter += 1
    return perimeter
