#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3
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
	if (num < MAX)
	{
		printf("Nombre: ");
		scanf("%s", &pa[num].name);
		printf("Edad: ");
		scanf("%d",&pa[num].age);
		printf("Habitacion: ");
		scanf("%d",&pa[num].room);
		printf("Temperatura: ");
		scanf("%f",&pa[num].temperature);
		*numPoi = num++;
	}
	else
	{
		printf("No puede agregar mas pacientes.");
	}
}

void PrintPatients(Patient pa[], int num)
{
	for (i=0; i<MAX; i++)
	{
		printf("----PACIENTE %d----\n",i+1);
		printf("Nombre:      %s\n",pa[i].name);
		printf("Edad:        %d\n",pa[i].age);
		printf("Habitacion:  %d\n",pa[i].room);
		printf("Temperatura: %.2f\n",pa[i].temperature);
	}
}

int main()
{	
	int numPatients=0;
	int numPatientsTemp=0;
	int eleccion=0;
	Patient patients[MAX];
	
	do{
		printf("---------HOSPITAL---------\n");
		printf("[1] Agregar Paciente\n[2] Ver Pacientes\n[3] Salir\n");
		printf("--------------------------\n");
		do{
			printf ("Eleccion: ");
			scanf("%d",&eleccion);
		} while (eleccion < 1 || eleccion > 3);
		
		switch (eleccion)
		{
			case 1:
				do{
					AddPatients(patients, &numPatients, numPatients);
				} while (numPatients < MAX || numPatientsTemp < MAX);
				break;
			
			case 2:
				PrintPatients(patients, numPatients);
				break;
				
			case 3:
				printf("ADIOS!\n");
				break;
		}
	} while (eleccion != 3);
	
	return 0;
}
