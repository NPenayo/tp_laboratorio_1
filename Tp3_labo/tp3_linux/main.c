#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Validations.h"
#define TXT_PATH "./data.csv"
#define BIN_PATH "./data.bin"
/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 5. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
 10. Salir
 *****************************************************/
void clearConsole();
void cleanBuffer();
int main() {
	int option = 0;

	// FILE *text;
	//FILE *bin;
	LinkedList *employeesList = ll_newLinkedList();
	do {
		clearConsole();
		printf("\n%50s", "Menu Principal");
		printf("\n\n*1- Cargar empleados desde texto");
		printf("\n*2- Cargar empleados desde binario");
		printf("\n*3- Alta de empleado");
		printf("\n*4- Modificar datos de empleado");
		printf("\n*5- Baja de empleado");
		printf("\n*6- Listar empleados");
		printf("\n*7- Ordenar empleados");
		printf("\n*8- Guardar datos de empleados en archivo (texto)");
		printf("\n*9- Guardar datos de empleados en archivo (binario)");
		printf("\n*10- Salir");
		printf("\n\nOpcion: ");
		scanf("%d", &option);
		switch (option) {
		case 1:
			clearConsole();
			ll_clear(employeesList);
			if (!controller_loadFromText(TXT_PATH, employeesList)) {
				printf("\nHubo un error al leer el archivo.");
			}
			break;
		case 2:
			clearConsole();
			ll_clear(employeesList);
			if (!controller_loadFromBinary(BIN_PATH, employeesList)) {
				printf("\nHubo un error al leer el archivo.");
			}
			break;
		case 3:
			if (!ll_isEmpty(employeesList)) {
				clearConsole();
				printf("\n%50s", "Alta de empleado");
				if (controller_addEmployee(employeesList)) {
					printf("\nAlta exitosa");
				} else {
					printf("\nHubo un error al dar el alta");
				}
			} else {
				printf("\nPrimero debe cargar los datos desde un archivo");
			}
			break;
		case 4:
			if (!ll_isEmpty(employeesList)) {
				clearConsole();
				printf("\n%50s", "Modificar empleado");
				if (!controller_editEmployee(employeesList)) {
					printf(
							"\nEl ID ingresado no corresponde a un empleado registrado");
				}
			} else {
				printf("\nPrimero debe cargar los datos desde un archivo");
			}

			break;
		case 5:
			if (!ll_isEmpty(employeesList)) {
				clearConsole();
				printf("\n%50s", "Eliminar empleado");
				if (!controller_removeEmployee(employeesList)) {
					printf(
							"\nEl ID ingresado no corresponde a un empleado registrado");
				} else {
					printf("\nSe elimino exitosamente");
				}
			} else {
				printf("\nPrimero debe cargar los datos desde un archivo");
			}
			break;
		case 6:
			clearConsole();
			if (!controller_ListEmployee(employeesList)) {
				printf("\nNo hay registros cargados");
			}
			break;
		case 7:
			clearConsole();
			if (!ll_isEmpty(employeesList)) {
				controller_sortEmployee(employeesList);
			} else {
				printf("\nPrimero debe cargar los datos desde un archivo");
			}

			break;
		}
	} while (option != 10);
	ll_deleteLinkedList(employeesList);
	return 0;
}
void clearConsole() {
#if defined( __linux__)
	system("clear");
#elif defined( __MINGW32__)
		system("cls");
#endif
}
void cleanBuffer() {
#if defined(__linux__)
	__fpurge(stdin);
#elif defined(__MINGW32__)
	fflush(stdin);
#endif
}

