#include "../include/fdf.h"
int main(int argc, char **argv)
{
	long int **grid;
	double ***positions;
	int x;
	int y;

	x = count_columns(get_line(argv[1]));
	y = count_rows(argv[1]);
    grid = parse(x, y, argv[1]);
    positions = iso(grid, x, y);
    
    printf("INPUT MAP: \n");
    print_grid(grid, x, y);
    printf("\n");
    printf("ISOMETRIC MAPPING : \n");
    print_iso(positions, x, y);
	free_grid(&grid, count_columns(get_line(argv[1])));
    return 0;
}
