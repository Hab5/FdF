#include "../include/fdf.h"

double ***allocate_xyz(const int x, const int y, const int z)
{
    int i;
    int j;
    i=-1;
    j=-1;
    
    double ***xyz = (double ***)malloc(x * sizeof(double**));

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


double ***iso_x(double ***positions, long **grid, const int x, const int y)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while(++j != y)
    {
        while(++i != x)
        {
            positions[i][j][0] = (i-grid[i][j])/sqrt(2);
        }
        i = -1;
    }
    return(positions);
}

double ***iso_y(double ***positions, long **grid, const int x, const int y)
{
    int i;
    int j;

    i = -1;
    j = -1;
    while(++j != y)
    {
        while(++i != x)
        {
            positions[i][j][1] = (i + (j*2) + grid[i][j])/sqrt(6);
        }
        i = -1;
    }
    return(positions);
}

double ***iso(long **grid, const int x, const int y)
{
    double ***positions;
    
    positions = allocate_xyz(x, y, 2);
    positions = iso_x(positions, grid, x, y);
    positions = iso_y(positions, grid, x, y);
    
    return(positions);
}

void print_iso(double ***positions, int x, int y)
{
    int i,j,k;
    i=0;j=0;k=0;

    while(j != y)
    {
        i = 0;
        while(i != x)
        {
            while(k != 2)
            {
                if(k==0)
                    printf("[%.1f",positions[i][j][0]);
                if(k==1)
                    printf("||%.1f] ",positions[i][j][1]);
                k++;
            }
            i++;
            k=0;
        }
        i=0;
        j++;
        printf("\n");
    }
}
