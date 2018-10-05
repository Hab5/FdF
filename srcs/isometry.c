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
            
            positions[i][j][0] = (0.50 + ((i-(j))/sqrt(2))
                    *0.50)*(800) / 50;
                //(550/sqrt(x*x + y*y))*(j - i + y - 0.5);  
                //(((i-grid[i][j]) * cos(30)));
            
            positions[i][j][1] = (0.50 + ((i + -(grid[i][j]*2) + (j))/sqrt(6)
                        *0.50)*700) / 50;
                //50 + (600/sqrt(x*x+y*y))*(-0.11*grid[i][j] + 0.5*i + -0.5*j); 
                //(((j + (i + grid[i][j])) * sin(30))); 
        }
        i = -1;
    }
    return(positions);
}

void print_iso(double ***positions, int x, int y)
{
    int i,j,k;
    i=0;j=0;k=0;

    while(j != y)
    {
        while(i != x)
        {
            printf("[%G",positions[i][j][0]);
            printf("||%G] ",positions[i][j][1]);
            i++;
        }
        j++;
        i=0;
        printf("\n");
    }
}
