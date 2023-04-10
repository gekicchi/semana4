#include<stdio.h>
#include<stdlib.h>
#define MAX 5
#define TEMP 3
int i=0;
int j=0;

typedef struct
{
	char name[50];
	int age;
	int room;
	float temperature[TEMP];
} Patient;

void AddPatients(Patient pa[], int *numPoi, int num)
{
	if (num < MAX)
	{
		printf("-----PACIENTE %d-----\n",num+1);
		printf("Nombre: ");
		scanf("%s", &pa[num].name);
		printf("Edad: ");
		scanf("%d", &pa[num].age);
		printf("Habitacion: ");
		scanf("%d", &pa[num].room);
		
		*numPoi = num+1; // cuenta la cantidad de pacientes
	}
	else
	{
		printf("No Puede Agregar Mas Pacientes.\n");
	}
}

void RecordTemperature(Patient pa[], int num)
{
	int numPaciente=0;
	if (num > 0)
	{
		printf("Paciente a Agregar Temperatura?\n");
		do{ 
			printf("Paciente: ");
			scanf("%d", &numPaciente);
			if (numPaciente < 1 || numPaciente > num)
				printf("INGRESO DE VALOR INVALIDO.\n");
		} while (numPaciente < 1 || numPaciente > num);
		
		for (i=0; i<TEMP; i++) // rellena arreglo de temperatura
		{
			printf("Temperatura Dia %d: ", i+1);
			scanf("%f", &pa[numPaciente-1].temperature[i]);
		}
	}
	else
	{
		printf("NO HAY PACIENTES REGISTRADOS.\n");
	}
}

void PrintPatients(Patient pa[], int num)
{
	if (num > 0)
	{
		for (i=0; i<num; i++)
		{
			printf("------PACIENTE %d------\n", i+1);
			printf("Nombre:      %s\n", pa[i].name);
			printf("Edad:        %d\n", pa[i].age);
			printf("Habitacion:  %d\n", pa[i].room);
			for (j=0; j<TEMP; j++)
				printf("Temperatura %d: %.2f\n", j+1, pa[i].temperature[j]);
		}
	}
	else
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
		printf("[1] Agregar Paciente\n[2] Registrar Temperatura\n[3] Ver Pacientes\n[4] Salir\n");
		printf("--------------------------\n");
		do{
			printf ("Eleccion: ");
			scanf("%d", &eleccion);
			if (eleccion < 1 || eleccion > 4)
				printf("INGRESO DE VALOR INVALIDO\n");
		} while (eleccion < 1 || eleccion > 4);
		
		printf("\n");
		
		switch (eleccion)
		{
			case 1: // agregar paciente
				do{
					AddPatients(patients, &numPatients, numPatients);
					printf("\n");
					
					if (numPatients < MAX)
					{
						printf("Quiere Seguir Agregando Pacientes?\n");
						printf("[1] Si\t[2] No\n");
						do{
							printf("Eleccion: ");
							scanf("%d", &eleccion);
							if (eleccion < 1 || eleccion > 2)
								printf("INGRESO DE VALOR INVALIDO\n");
						} while (eleccion < 1 || eleccion > 2);
						printf("\n");
					}
				} while (numPatients < MAX && eleccion != 2);
				
				printf("\n");
				break;
				
			case 2: // registrar temperatura
				RecordTemperature(patients, numPatients);
				break;
			
			case 3: // ver pacientes
				PrintPatients(patients, numPatients);
				
				printf("\n");
				break;
				
			case 4: // salir
				printf("ADIOS!\n");
				break;
		}
	} while (eleccion != 4);
	
	return 0;
}
