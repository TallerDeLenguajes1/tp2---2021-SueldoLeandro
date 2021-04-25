#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 5

int main(void){


int f,c;
double mt[N][M] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};


for(f = 0;f<N; f++)
{
        for(c = 0;c<M; c++)
        {
        printf("  %lf", mt[f][c]);

        }
    printf("\n");
}

getchar();
}