#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int get_idx(int x, int y, int z, int n) {
    x += n;
    y += n;
    z += n;
    int dim = (2*n) + 1;
    return x + (y*dim) + (z*dim*dim);
}

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n) {
    int x = 0;
    int y = 0;
    int z = 0;
    int dir;
    for (int i = 0; i < n; ++i) {
        dir = rand() % 6;
        switch (dir) {
            case 0: --x; break;
            case 1: ++x; break;
            case 2: --y; break;
            case 3: ++y; break;
            case 4: --z; break;
            case 5: ++z; break;
        }
    }
    ++grid[get_idx(x, y, z, n)];
}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r) {
    double max_dist = (n*r) * (n*r);
    double dist;
    int idx;

    int inside = 0;
    int outside = 0;
    for (int x = -n; x <= n; ++x) {
        for (int y = -n; y <= n; ++y) {
            for (int z = -n; z <= n; ++z) {
                dist = (x*x) + (y*y) + (z*z);
                idx = get_idx(x, y, z, n);
                if (dist <= max_dist) {
                    inside += grid[idx];
                }
                else {
                    outside += grid[idx];
                }
            }
        }
    }
    return ((double) inside) / (inside + outside);
}

//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m) {
	//fill in a few line of code below
    int dim = (2*n) + 1;
    int* grid = (int*) calloc(dim * dim * dim, sizeof(int));
    if (grid == NULL) {
        printf("Failed to alloc grid.\n");
        exit(1);
    }

	for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);
	//fill in some code below

    free(grid);
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}
