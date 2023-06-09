#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
int i=0;

typedef struct
{
	char name[50];
	int age;
	int room;
	float temperature;
} Patient;

void AddPatients(Patient pa[], int *numPoi, int num)
{
	if (num < MAX) // aun hay espacio en arreglo
	{
		printf("-----PACIENTE %d-----\n",num+1);
		printf("Nombre: ");
		scanf("%s", &pa[num].name);
		printf("Edad: ");
		scanf("%d",&pa[num].age);
		printf("Habitacion: ");
		scanf("%d",&pa[num].room);
		printf("Temperatura: ");
		scanf("%f",&pa[num].temperature);
		
		*numPoi = num+1; // cuenta la cantidad de pacientes
	}
	else // no hay espacio en arreglo
	{
		printf("No Puede Agregar Mas Pacientes.\n");
	}
}

void PrintPatients(Patient pa[], int num)
{
	if (num > 0)
	{
		for (i=0; i<num; i++)
		{
			printf("------PACIENTE %d------\n",i+1);
			printf("Nombre:      %s\n",pa[i].name);
			printf("Edad:        %d\n",pa[i].age);
			printf("Habitacion:  %d\n",pa[i].room);
			printf("Temperatura: %.2f\n",pa[i].temperature);
		}
	}
	else // se avisa en caso que no hayan pacientes registrados
	{
		printf("NO HAY PACIENTES REGISTRADOS.\n");
	}
}

int main()
{	
	int numPatients=0;
	int eleccion=0;
	Patient patients[MAX];
	
	do{
		printf("---------HOSPITAL---------\n");
		printf("[1] Agregar Paciente\n[2] Ver Pacientes\n[3] Salir\n");
		printf("--------------------------\n");
		do{
			printf ("Eleccion: ");
			scanf("%d",&eleccion);
			if (eleccion < 1 || eleccion > 3)
				printf("INGRESO DE VALOR INCALIDO\n");
		} while (eleccion < 1 || eleccion > 3);
		
		printf("\n");
		
		switch (eleccion)
		{
			case 1: // agregar paciente
				do{
					AddPatients(patients, &numPatients, numPatients);
					printf("\n");
					
					if (numPatients < MAX) // si todavia hay espacio se pregunta si se quiere seguir agregando pacientes
					{
						printf("Quiere Seguir Agregando Pacientes?\n");
						printf("[1] Si\t[2] No\n");
						do{
							printf("Eleccion: ");
							scanf("%d",&eleccion);
							if (eleccion < 1 || eleccion > 2)
								printf("INGRESO DE VALOR INVALIDO\n");
						} while (eleccion < 1 || eleccion > 2);
						printf("\n");
					}
				} while (numPatients < MAX && eleccion != 2);
				
				printf("\n");
				break;
			
			case 2: // ver pacientes
				PrintPatients(patients, numPatients);
				
				printf("\n");
				break;
				
			case 3: // salir
				printf("ADIOS!\n");
				break;
		}
	} while (eleccion != 3);
	
	return 0;
}
