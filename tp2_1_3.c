#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

srand(time(NULL));

int filas=15,columnas=0,aleatorio=0,*puntero_matriz;
columnas = 5 + rand()%11;
puntero_matriz=(int *) malloc(sizeof(int) * filas * columnas);

for (int i = 0; i < filas; i++)
{
    for (int j = 0; j < columnas; j++)
    {   
        
        aleatorio = 100 + rand()%(999-100);
        *(puntero_matriz + i * filas + j)=aleatorio;
        printf(" %d ",*(puntero_matriz + i * filas + j));

    }
    printf("\n");
}

free(puntero_matriz);
getchar();
    return 0;
}