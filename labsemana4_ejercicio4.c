#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TEMP 3
int i=0;
int j=0;

typedef struct patient
{
	char name[50];
	int age;
	int room;
	float temperature[TEMP];
	struct patient *next;
} Patient;

Patient* CreatePatient(char nombre[], int edad, int hab)
{
	Patient *nuevoPaciente = (Patient*)malloc(sizeof(Patient));
	strcpy(nuevoPaciente->name, nombre);
	nuevoPaciente->age = edad;
	nuevoPaciente->room = hab;
	nuevoPaciente->next = NULL;
	for (i=0; i<TEMP; i++)
		nuevoPaciente->temperature[i] = 0.0;
	
	return nuevoPaciente;
}

void AddPatient(Patient *pa, Patient **head, int *num) // añade paciente pre-creado a la lista
{
	if (*head == NULL)
	{
		*head = pa;
	}
	else
	{
		Patient *current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = pa;
	}
	*num += 1; // cuenta la cantidad de pacientes en lista
}

void RecordTemperature(Patient *head, int num)
{
	Patient *current = head;
	while(num > 1) // cuenta atras por cantidad de pacientes
	{
		current = current->next;
		num--;
	}
	
	for (i=0; i<TEMP; i++)
	{
		printf("Temperatura %d: ",i+1);
		scanf("%f", &current->temperature[i]);
	}
}

void DischargePatient(Patient *head, char nombre[], int *num)
{
	Patient *current = head;
	Patient *prev = head;
	
	while (strcmp(current->name, nombre) != 0  && current != NULL) // mientras que el nombre ingresado sea distinto al nombre del paciente actual
	{
		prev = current;
		current = current->next;
	}
	
	if (current != NULL)
	{
		if (prev == current) // 1er elemento
		{
			*head = *current->next;
		}
		else if (prev != current && current->next != NULL) // elemento en el medio
		{
			prev->next = current->next;
		}
		else if (prev != current && current->next == NULL) // ultimo elemento
		{
			prev->next = NULL;
		}
		
		printf("Dando de Alta a %s...\n", nombre);
		*num -= 1;
		free(current);
	}
	else
	{
		printf("No se pudo Encontrar Paciente.\n");
	}
}

void PrintPatients(Patient *head)
{
	if (head == NULL)
	{
		printf("No Hay Pacientes.\n");
	}
	else
	{
		printf("LISTA DE PACIENTES\n");
		Patient *current = head;
		int iteracion=1;
		while (current != NULL)
		{
			printf("-----PACIENTE %d-----\n", iteracion);
			printf("Nombre: %s\n", current->name);
			printf("Edad: %d\n", current->age);
			printf("Habitacion: %d\n", current->room);
			for (i=0; i<TEMP; i++)
			{
				if (current->temperature[i] != 0.0)
					printf("Temperatura %d: %.2f\n", i+1, current->temperature[i]);
				else
					printf("Temperatura %d: NO REGISTRADA.\n", i+1);
			}
				
			current = current->next;
			iteracion++;
		}
	}
}

void FreePatients(Patient *head)
{
	Patient *current = head;
	while (current != NULL)
	{
		Patient *next = current->next;
		free(current);
		current = next;
	}
}

int main()
{	
	int eleccion=0;
	int numPatients=0;
	Patient *head = NULL;
	Patient *nuevoPaciente;
	
	char nombre[50];
	int edad=0;
	int habitacion=0;
	
	do{
		printf("---------HOSPITAL---------\n");
		printf("[1] Agregar Paciente\n[2] Registrar Temperatura\n[3] Ver Pacientes\n[4] Dar de Alta a Paciente\n[5] Salir\n");
		printf("--------------------------\n");
		do{
			printf ("Eleccion: ");
			scanf("%d", &eleccion);
			if (eleccion < 1 || eleccion > 5)
				printf("INGRESO DE VALOR INVALIDO\n");
		} while (eleccion < 1 || eleccion > 5);
		
		printf("\n");
		
		switch (eleccion)
		{
			case 1:
				do{
					
					printf("Nombre: ");
					scanf("%s",&nombre);
					printf("Edad: ");
					scanf("%d",&edad);
					printf("Habitacion: ");
					scanf("%d",&habitacion);
					
					nuevoPaciente = CreatePatient(nombre, edad, habitacion);
					AddPatient(nuevoPaciente, &head, &numPatients);
					
					printf("Seguir Agregando Pacientes?\n");
					printf("[1] Si\t[2] No\n");
					printf("Eleccion: ");
					scanf("%d",&eleccion);
					
				} while (eleccion != 2);
				
				printf("\n");
				break;
				
			case 2:
				printf("A Que Paciente Registrara Temperatura?\n");
				do{
					printf("Numero Paciente: ");
					scanf("%d",&eleccion);
					if (eleccion < 1 || eleccion > numPatients)
						printf("Paciente Inexistente\n");
				} while (eleccion < 1 || eleccion > numPatients);
				
				RecordTemperature(head, eleccion);
				
				printf("\n");
				break;
			
			case 3:
				PrintPatients(head);
				
				printf("\n");
				break;
				
			case 4:
				printf("Nombre Paciente: ");
				scanf("%s", &nombre);
				
				DischargePatient(head, nombre, &numPatients);
				break;
				
			case 5:
				printf("ADIOS!\n");
				break;
		}
	} while (eleccion != 5);
	
	FreePatients(head);
	
	return 0;
}
