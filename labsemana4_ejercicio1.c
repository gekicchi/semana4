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

void AddPatients(Patient pa[])
{
	for (i=0; i<MAX; i++)
	{
		printf("----PACIENTE %d----\n",i+1);
		printf("Nombre: ");
		scanf("%s", &pa[i].name);
		printf("Edad: ");
		scanf("%d",&pa[i].age);
		printf("Habitacion: ");
		scanf("%d",&pa[i].room);
		printf("Temperatura: ");
		scanf("%f",&pa[i].temperature);
	}
}

void PrintPatients(Patient pa[])
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
	Patient patients[MAX];

	AddPatients(patients);
	printf("\n----IMPRIMIENDO----\n\n");
	PrintPatients(patients);
	
	return 0;
}
