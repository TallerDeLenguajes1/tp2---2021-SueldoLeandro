#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct compu {
int velocidad;//entre 1 y 3 Gherz
int anio;//entre 2000 y 2017
int cantidad;//entre 1 y 4
char *tipo_cpu;//valores del arreglo tipos
};



void MostrarPC(struct compu **PC);
void CargarPC(struct compu **PC,int x,char **tipo_cpu);
void ListaDePC(struct compu **PC,int CantidadDePC);
void PCMasVieja(struct compu **PC,int CantidadDePC);
void PCMasRapida(struct compu **PC,int CantidadDePC);

int main(void){

srand(time(NULL));

    int CantidadDePC=0,NoTeCerresPorfa=0;
    char *tipos[]={"Intel", "AMD","Celeron", "Athlon", "Core","Pentium"},**tipo_cpu;
    tipo_cpu=tipos;

    printf("Ingrese la cantidad de PC a guardar ( hasta 6 ): \n");
    scanf("%d",&CantidadDePC);

    struct compu compu[CantidadDePC],*punteroEstructura,**PunteroAEstructura;
    punteroEstructura = compu;

    punteroEstructura = (struct compu *) malloc(sizeof(struct compu)*CantidadDePC);
    *PunteroAEstructura = punteroEstructura;


    /*CargarPC(PunteroAEstructura,CantidadDePC,tipo_cpu);
    MostrarPC(PunteroAEstructura);
    ListaDePC(PunteroAEstructura,CantidadDePC);
    PCMasVieja(PunteroAEstructura,CantidadDePC);
    PCMasRapida(PunteroAEstructura,CantidadDePC);*/


    free(punteroEstructura);

    scanf("%d",&NoTeCerresPorfa);
    return 0;
}

void MostrarPC(struct compu **PC){
    int x=0,i=0;

    printf("Que PC quiere ver (del 0 al 5): \n");
    scanf("%d",&x);

    while ((int)*(PC+i) != x)
    {
        i++;
    }
    
    printf("La PC %d tiene las siguientes caracteristicas:\n",x);
    printf("Velocidad: %d Gherz\n",PC[i]->velocidad);
    printf("Anio: %d\n",PC[i]->anio);
    printf("Cantidad de nucleos: %d\n",PC[i]->cantidad);
    printf("Procesador: %s\n",PC[i]->tipo_cpu);
    return;
}

void CargarPC(struct compu **PC,int x,char **tipo_cpu){

    for (int i = 0; i < x; i++)
    {
        PC[i]->velocidad = 1+rand()%(3-1);
        PC[i]->anio = 2000+rand()%(2017-2000);
        PC[i]->cantidad = 1+rand()%(4-1);
        strcpy(PC[i]->tipo_cpu,tipo_cpu[i]);
    }
    return;
}


void ListaDePC(struct compu **PC,int CantidadDePC){
    int i=0;

    for (i = 0; i < CantidadDePC; i++)
    {
        printf("La PC %d tiene las siguientes caracteristicas:\n",i);
        printf("Velocidad: %d Gherz\n",PC[i]->velocidad);
        printf("Anio: %d\n",PC[i]->anio);
        printf("Cantidad de nucleos: %d\n",PC[i]->cantidad);
        printf("Procesador: %s\n\n\n",PC[i]->tipo_cpu);
    }

    return;
}


void PCMasVieja(struct compu **PC,int CantidadDePC){

    int i=0,aux=0,cont=0;

    for (i = 0; i < CantidadDePC; i++)
    {
        if (PC[i]->anio > aux)
        {   
            cont++;
            aux = aux + PC[i]->anio;
        }
    }

    printf("\n La Pc %d es la mas vieja: \nEs del anio: %d",cont,aux);

    return;
}

void PCMasRapida(struct compu **PC,int CantidadDePC){

    int i=0,aux=0,cont=0;

    for (i = 0; i < CantidadDePC; i++)
    {
        if (PC[i]->velocidad > aux)
        {   
            cont++;
            aux = aux + PC[i]->velocidad;
        }
    }

    printf("\n La Pc %d es la mas rapida con %d de velocidad\n",cont,aux);

    return;
}
