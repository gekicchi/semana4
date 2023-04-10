#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0;

typedef struct patient
{
	char name[50];
	int age;
	int room;
	float temperature;
	struct patient *next;
} Patient;

Patient* CreatePatient(char nombre[], int edad, int hab, float temp)
{
	Patient *nuevoPaciente = (Patient*)malloc(sizeof(Patient));
	strcpy(nuevoPaciente->name, nombre);
	nuevoPaciente->age = edad;
	nuevoPaciente->room = hab;
	nuevoPaciente->temperature = temp;
	nuevoPaciente->next = NULL;
	
	return nuevoPaciente;
}

void Enqueue(Patient *pa, Patient **head) // añade paciente a cola
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
}

void Dequeue(Patient *head, Patient **next) // libera al primer paciente
{
	if (head != NULL)
	{
		Patient *current = head;
		*next = current->next;
		free(current);
	}
}

void GetNextPatient(Patient *head) // datos del proximo paciente
{
	if (head != NULL)
	{
		printf("Nombre:      %s\n", head->name);
		printf("Edad:        %d\n", head->age);
		printf("Temperatura: %.2f\n", head->temperature);
		printf("Habitacion:  %d\n", head->room);
	}
	else
	{
		printf("No Hay Pacientes en la Cola.\n");
	}
}

void GetQueueSize(Patient *head, int *tam) // tamaño total de la cola
{
	*tam = 0;
	Patient *current = head;
	while (current != NULL)
	{
		*tam += 1;
		current = current->next;
	}
}

void GetLeftPatients(Patient *head, char nombre[]) // cantidad de pacientes hasta deseado
{
	Patient *current = head;
	int faltan=0;
	
	while (strcmp(current->name, nombre) != 0 && current->next != NULL) // busca paciente por su nombre
	{
		faltan++;
		current = current->next;
	}
	
	if (current != NULL) // se encontro
	{
		printf("Faltan %d Pacientes para %s\n", faltan, nombre);
	}
	else // no se encontro
	{
		printf("Paciente No se Encuentra en Cola.\n");
	}
}

void PrintPatients(Patient *head)
{
	if (head == NULL)
	{
		printf("No Hay Pacientes en la Cola.\n");
	}
	else
	{
		printf("PACIENTES EN COLA\n");
		Patient *current = head;
		int iteracion=1;
		while (current != NULL)
		{
			printf("--------------------\n", iteracion);
			printf("Nombre: %s\n", current->name);
			printf("Edad: %d\n", current->age);
			printf("Habitacion: %d\n", current->room);
			printf("Temperatura: %.2f\n", current->temperature);
				
			current = current->next;
			iteracion++;
		}
		printf("--------------------\n");
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
	Patient *head = NULL;
	Patient *Paciente1 = CreatePatient("nana", 20, 1, 37.60);
	Enqueue(Paciente1, &head);
	Patient *Paciente2 = CreatePatient("nene", 12, 2, 37.89);
	Enqueue(Paciente2, &head);
	Patient *Paciente3 = CreatePatient("nini", 15, 3, 37.37);
	Enqueue(Paciente3, &head);
	Patient *Paciente4 = CreatePatient("nono", 35, 4, 36.90);
	Enqueue(Paciente4, &head);
	Patient *Paciente5 = CreatePatient("nunu", 40, 5, 37.51);
	Enqueue(Paciente5, &head);
	
	int eleccion = 0;
	int tamanoCola = 0;
	char nombre[50];
	
	do{
		printf("---------HOSPITAL---------\n");
		printf("[1] Ver Siguiente Paciente\n[2] Dar de Alta a Paciente\n[3] Ver Cola\n[4] Buscar Paciente\n[5] Salir\n");
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
			case 1: // ver siguiente paciente
				printf("--PROXIMO PACIENTE--\n");
				GetNextPatient(head);
				
				printf("\n");
				break;
				
			case 2: // dar de alta a paciente
				printf("Datos De Paciente:\n");
				GetNextPatient(head);
				printf("Dando de Alta...");
				sleep(1);
				Dequeue(head, &head);
			
				printf("\n");
				break;
			
			case 3: // ver cola
				PrintPatients(head);
				GetQueueSize(head, &tamanoCola);
				printf("Pacientes en Cola: %d\n", tamanoCola);
				
				printf("\n");
				break;
				
			case 4: // buscar paciente
				printf("Nombre Paciente: ");
				scanf("%s", &nombre);
				
				GetLeftPatients(head, nombre);
				printf("\n");
				break;
				
			case 5: // salir
				FreePatients(head);
				printf("ADIOS!\n");
				break;
		}
	} while (eleccion != 5);
	
	return 0;
}
