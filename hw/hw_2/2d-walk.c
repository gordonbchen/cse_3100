#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int within(int x, int low, int high) {
    return (x >= low) && (x < high);
}

double two_d_random(int n) {
	//Fill in code below
	//When deciding which way to go for the next step, generate a random number as follows.
	//r = rand() % 4;
	//Treat r = 0, 1, 2, 3 as up, right, down and left respectively.

	//The random walk should stop once the x coordinate or y coordinate reaches $-n$ or $n$. 
	//The function should return the fraction of the visited $(x, y)$ coordinates inside (not including) the square.
    int square_len = 2*n - 1;
    int visited[square_len][square_len];
    memset(visited, 0, sizeof(visited));
    int visited_sum = 0;

    int coord[] = {n-1, n-1};
    while (within(coord[0], 0, square_len) && within(coord[1], 0, square_len)) {
        if (visited[coord[0]][coord[1]] == 0) {
            ++visited[coord[0]][coord[1]];
            ++visited_sum;
        }

        int d = rand() % 4;
        if (d == 0) {
            --coord[0];
        }
        else if (d == 1) {
            ++coord[1];
        }
        else if (d == 2) {
            ++coord[0];
        }
        else {
            --coord[1];
        }
    }
    return ((double) visited_sum) / (square_len*square_len);
}

//Do not change the code below
int main(int argc, char *argv[])
{
	int trials = 1000;
	int i, n, seed;
	if (argc == 2) seed = atoi(argv[1]);
	else seed = 12345;

	srand(seed);
	for(n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}