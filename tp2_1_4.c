#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct compu {
int velocidad;//entre 1 y 3 Gherz
int anio;//entre 2000 y 2017
int cantidad;//entre 1 y 4
//char *tipo_cpu;//valores del arreglo tipos
struct compu* siguiente;
};

typedef struct compu* Lista;

Lista crearPC();
void MostrarPC(Lista cabecera);
Lista CargarPC(Lista cabecera,int CantidadDePC);
void PCMasVieja(Lista cabecera);
void PCMasRapida(Lista cabecera);
void Borrar(Lista cabecera);

int main(void){

srand(time(NULL));

    int NoTeCerresPorfa=0,CantidadDePC=0;

    printf("Ingrese la cantidad de PC a guardar ( hasta 6 ): \n");
    scanf("%d",&CantidadDePC);

    Lista cabecera;

    cabecera = crearPC();
    cabecera = CargarPC(cabecera,CantidadDePC);
    MostrarPC(cabecera);
    PCMasVieja(cabecera);
    PCMasRapida(cabecera);
    


    //Borrar(cabecera);

    scanf("%d",&NoTeCerresPorfa);
    return 0;
}


Lista crearPC(){
    Lista L;
    L = NULL;
    return L;
}


Lista CargarPC(Lista cabecera,int CantidadDePC){

for (int i = 0; i < CantidadDePC; i++)
{
    struct compu*nuevo;
    nuevo = malloc(sizeof(*nuevo)*50);
    nuevo->velocidad = 1 + rand()%(3-1);
    nuevo->anio = 2000 + rand()%(2017-2000);
    nuevo->cantidad = 1 + rand()%(4-1);;
    nuevo->siguiente = cabecera;
    cabecera = nuevo;
    
}

    
    return cabecera;
}


void MostrarPC(Lista cabecera){
    int i=1;char procesador[10];

    while (cabecera != NULL)
    {
        
        printf("La PC %d tiene las siguientes caracteristicas:\n",i);
        printf("Velocidad: %d Gherz\n",cabecera->velocidad);
        printf("Anio: %d\n",cabecera->anio);
        printf("Cantidad de nucleos: %d\n",cabecera->cantidad);
        
        switch (i)
            {
            case 1:
                strcpy(procesador,"Intel");
                break;
            case 2:
                strcpy(procesador,"AMD");
                break;
            case 3:
                strcpy(procesador,"Celeron");
                break;
            case 4:
                strcpy(procesador,"Athlon");
                break;
            case 5:
                strcpy(procesador,"Core");
                break;
            case 6:
                strcpy(procesador,"Pentium");
                break;

            default:
                break;
            }
        printf("Procesador: %s\n\n",procesador);
       cabecera = cabecera->siguiente;
       i++;
    }
    
    
    return;
}

void PCMasVieja(Lista cabecera){

    int anio=2020,velocidad=0,cantidad=0,i=1;
    char procesador[10];
    while (cabecera != NULL)
    {
        if (cabecera->anio < anio)
        {   
            
            velocidad = cabecera->velocidad;
            cantidad = cabecera->cantidad;
            anio = cabecera->anio;
            switch (i)
            {
            case 1:
                strcpy(procesador,"Intel");
                break;
            case 2:
                strcpy(procesador,"AMD");
                break;
            case 3:
                strcpy(procesador,"Celeron");
                break;
            case 4:
                strcpy(procesador,"Athlon");
                break;
            case 5:
                strcpy(procesador,"Core");
                break;
            case 6:
                strcpy(procesador,"Pentium");
                break;

            default:
                break;
            }
        }
        cabecera = cabecera->siguiente;
        i++;
    }

    printf("\n La Pc mas vieja es del anio: %d y tiene las siguientes caracteristicas\n\n",anio);

    printf("Velocidad: %d Gherz\n",velocidad);
    printf("Anio: %d\n",anio);
    printf("Cantidad de nucleos: %d\n",cantidad);
    printf("Procesador: %s\n\n",procesador);

    return;
}

void PCMasRapida(Lista cabecera){

    
    int anio=2020,velocidad=0,cantidad=0,i=1;
    char procesador[10];
    while (cabecera != NULL)
    {
        if (cabecera->velocidad > velocidad)
        {   
            
            velocidad = cabecera->velocidad;
            cantidad = cabecera->cantidad;
            anio = cabecera->anio;
            switch (i)
            {
            case 1:
                strcpy(procesador,"Intel");
                break;
            case 2:
                strcpy(procesador,"AMD");
                break;
            case 3:
                strcpy(procesador,"Celeron");
                break;
            case 4:
                strcpy(procesador,"Athlon");
                break;
            case 5:
                strcpy(procesador,"Core");
                break;
            case 6:
                strcpy(procesador,"Pentium");
                break;

            default:
                break;
            }
        }
        cabecera = cabecera->siguiente;
        
    }

    printf("\n La Pc mas rapida es la siguiente\n\n");

    printf("Velocidad: %d Gherz\n",velocidad);
    printf("Anio: %d\n",anio);
    printf("Cantidad de nucleos: %d\n",cantidad);
    printf("Procesador: %s\n\n",procesador);

    return;
}

void Borrar(Lista cabecera){

    while (cabecera != NULL)
    {
       free(cabecera);
    }
    return;
}