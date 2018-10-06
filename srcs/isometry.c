#include "../include/fdf.h"

double ***allocate_xyz(const int x, const int y, const int z)
{
    int i;
    int j;
    i=-1;
    j=-1;

    double ***xyz = malloc(x * sizeof(double**));

    while(++i < x)
    {
        xyz[i] = malloc(y * sizeof(double *));
        while(++j < y)
        {
            xyz[i][j] = malloc(z * sizeof(double));
        }
        j=-1;
    }

    return (xyz);
}

double ***iso_xy(long **grid, const int x, const int y)
{
    int i;
    int j;
    double ***positions;

    positions = allocate_xyz(x, y, 2);
    i = -1;
    j = -1;

    while(++j != y)
    {
        while(++i != x)
        {

            positions[i][j][0] = (0.5 + ((i-j)/sqrt(2)) * 0.5)
                                    *WIDTH / sqrt(x*y/1.5) + 600;
            positions[i][j][1] = (0.5 + ((i + -(grid[i][j]*RATIO) + j)/sqrt(6)
                                * 0.5)*HEIGHT) / sqrt(x*y/1.5) + 150;
        }
        i = -1;
    }
    return(positions);
}
