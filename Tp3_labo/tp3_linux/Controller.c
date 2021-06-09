#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Validations.h"
#define MAX_ATTEMPTS 3
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	int resp = 0;
	int registers;
	FILE *file;
	file = fopen(path, "r");
	if (file != NULL) {
		registers = parser_EmployeeFromText(file, pArrayListEmployee);
		if (registers) {
			printf("\nSe cargaron %d registros del archivo", registers);
			resp = 1;
		}

	}
	fclose(file);
	return resp;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	int resp = 0;
	int registers;
	FILE *file;
	file = fopen(path, "rb");
	if (file != NULL) {
		registers = parser_EmployeeFromBinary(file, pArrayListEmployee);
		if (registers) {
			printf("\nSe cargaron %d registros del archivo", registers);
			resp = 1;
		}

	}
	fclose(file);
	return resp;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee) {
	int resp = 0;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	int lastId = 0;
	for (int i = 0; i < ll_len(pArrayListEmployee); i++) {
		Employee *tmp = ll_get(pArrayListEmployee, i);
		if ((*tmp).id > lastId) {
			lastId = (*tmp).id;
		}
	}
	lastId++;
	Employee *newEmp = employee_new();
	if (newEmp != NULL) {
		if (validString("Nombre del empleado",
				"Error.El nombre no puede estar vacio o contener numeros",
				auxNombre, 128, MAX_ATTEMPTS)
				&& validInt("Horas trabajadas(MAX:325)",
						"Error.Cantidad de horas invalidas", &auxHoras, 1, 325,
						MAX_ATTEMPTS)
				&& validInt("Sueldo del empleado", "Error.Sueldo invalido",
						&auxSueldo, 10000, 50000, MAX_ATTEMPTS)) {
			employee_setId(newEmp, lastId);
			employee_setNombre(newEmp, auxNombre);
			employee_setHorasTrabajadas(newEmp, auxHoras);
			employee_setSueldo(newEmp, auxSueldo);
			ll_add(pArrayListEmployee, (Employee*) newEmp);
			resp = 1;
		}
	}
	return resp;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int resp = 0;
	int auxId;
	int option;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	printf("\nID del empleado: ");
	__fpurge(stdin);
	scanf("%d", &auxId);
	Employee *temp = ll_get(pArrayListEmployee, auxId);
	if (temp != NULL) {
		do {
			printf("\n%50s", "Modificar");
			printf("\n*1- Nombre: %s", (*temp).nombre);
			printf("\n*2- Horas trabajadas: %d", (*temp).horasTrabajadas);
			printf("\n*3- Sueldo: %d", (*temp).sueldo);
			printf("\n*4- Salir");
			__fpurge(stdin);
			if (validInt("Opcion", "Error.Opcion incorrecta", &option, 1, 4,
			MAX_ATTEMPTS)) {
				switch (option) {
				case 1:
					if (validString("Nuevo nombre",
							"Error.El nombre no puede estar vacio o contener numeros.",
							auxNombre, 128, MAX_ATTEMPTS)) {
						employee_setNombre(temp, auxNombre);
						resp = 1;
					}
					break;
				case 2:
					if (validInt("Nuevas horas",
							"Error.Cantidad de horas invalidas", &auxHoras, 1,
							325,
							MAX_ATTEMPTS)) {
						employee_setHorasTrabajadas(temp, auxHoras);
						resp = 1;
					}
					break;
				case 3:
					if (validInt("Sueldo del empleado", "Error.Sueldo invalido",
							&auxSueldo, 10000, 50000, MAX_ATTEMPTS)) {
						employee_setSueldo(temp, auxSueldo);
						resp = 1;
					}
					break;
				}
			}
		} while (!(option == 4));
	}
	return resp;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int resp = 0;
	int auxId;
	char confirm;
	printf("\nID del empleado: ");
	__fpurge(stdin);
	scanf("%d", &auxId);
	Employee *temp = ll_get(pArrayListEmployee, auxId - 1);
	if (temp != NULL) {
		printf("\n¿Seguro que desea eliminar el siguiente empleado?");
		printf("\n*Nombre: %s", (*temp).nombre);
		printf("\n*Horas trabajadas: %d", (*temp).horasTrabajadas);
		printf("\n*Sueldo: %d", (*temp).sueldo);
		printf("\n\nConfirmar(s/n): ");
		__fpurge(stdin);
		scanf("%c", &confirm);
		if (confirm == 's') {
			ll_remove(pArrayListEmployee, auxId - 1);
			employee_delete(temp);
			resp = 1;
		}
	}
	return resp;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int resp = 0;
	int auxId;
	char auxNombre[128];
	int auxHoras;
	int auxSueldo;
	if (!ll_isEmpty(pArrayListEmployee)) {
		int llLens = ll_len(pArrayListEmployee);
		printf("\n%50s", "Listado de empleados");
		printf("\n\n%5s %2c %-10s %2c %18s %3c %14s", "ID", '|', "Nombre", '|',
				"Horas Trabajadas", '|', "Sueldo");
		printf(
				"\n ------------------------------------------------------------------------");
		for (int i = 0; i < llLens; i++) {

			Employee *tmp = ll_get(pArrayListEmployee, i);

			if (tmp != NULL) {
				employee_getId(tmp, &auxId);
				employee_getNombre(tmp, auxNombre);
				employee_getHorasTrabajadas(tmp, &auxHoras);
				employee_getSueldo(tmp, &auxSueldo);
				printf("\n%7d %-16s %14d %19d", auxId, auxNombre, auxHoras,
						auxSueldo);
			}

		}
		printf("\n\nPresione una tecla para volver al menu...");
		__fpurge(stdin);
		getchar();
		resp = 1;
	}

	return resp;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int resp = 0;
	int option;
	do {
		printf("\n%50s", "Ordenar empleados");
		printf("\n\n*1- Nombre ASC");
		printf("\n*2- Nombre DESC");
		printf("\n*3- ID ASC");
		printf("\n*4- ID DESC");
		printf("\n*5- Horas ASC");
		printf("\n*6- Horas DESC");
		printf("\n*7- Sueldo ASC");
		printf("\n*8- Sueldo Desc");
		printf("\n*9- Salir");
		if (validInt("Opcion", "Error.Opcion invalida", &option, 1, 9,
		MAX_ATTEMPTS)) {
			switch (option) {
			case 1:
				for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++) {
					for (int j = i + 1; j < ll_len(pArrayListEmployee); j++) {
						char nameA[128];
						char nameB[128];
						Employee *empA = ll_get(pArrayListEmployee, i);
						Employee *empB = ll_get(pArrayListEmployee, j);
						employee_getNombre(empA, nameA);
						employee_getNombre(empB, nameB);
						if (strcmp(nameA, nameB) > 0) {
							ll_set(pArrayListEmployee, i, empB);
							ll_set(pArrayListEmployee, j, empA);
						}

					}

				}
				resp = 1;
				printf("\nOrdenamiento exitoso!!!");
				break;
			case 2:
				for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++) {
					for (int j = i + 1; j < ll_len(pArrayListEmployee); j++) {
						char nameA[128];
						char nameB[128];
						Employee *empA = ll_get(pArrayListEmployee, i);
						Employee *empB = ll_get(pArrayListEmployee, j);
						employee_getNombre(empA, nameA);
						employee_getNombre(empB, nameB);
						if (strcmp(nameA, nameB) < 0) {
							ll_set(pArrayListEmployee, i, empB);
							ll_set(pArrayListEmployee, j, empA);
						}

					}

				}
				resp = 1;
				printf("\nOrdenamiento exitoso!!!");
				break;
			case 3:
				for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++) {
					for (int j = i + 1; j < ll_len(pArrayListEmployee); j++) {
						int idA;
						int idB;
						Employee *empA = ll_get(pArrayListEmployee, i);
						Employee *empB = ll_get(pArrayListEmployee, j);
						employee_getId(empA, &idA);
						employee_getId(empB, &idB);
						if (idA > idB) {
							ll_set(pArrayListEmployee, i, empB);
							ll_set(pArrayListEmployee, j, empA);
						}

					}

				}
				resp = 1;
				printf("\nOrdenamiento exitoso!!!");
				break;
			case 4:
				for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++) {
					for (int j = i + 1; j < ll_len(pArrayListEmployee); j++) {
						int idA;
						int idB;
						Employee *empA = ll_get(pArrayListEmployee, i);
						Employee *empB = ll_get(pArrayListEmployee, j);
						employee_getId(empA, &idA);
						employee_getId(empB, &idB);
						if (idA < idB) {
							ll_set(pArrayListEmployee, i, empB);
							ll_set(pArrayListEmployee, j, empA);
						}

					}

				}
				resp = 1;
				printf("\nOrdenamiento exitoso!!!");
				break;
			case 5:
				for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++) {
					for (int j = i + 1; j < ll_len(pArrayListEmployee); j++) {
						int hourA;
						int hourB;
						Employee *empA = ll_get(pArrayListEmployee, i);
						Employee *empB = ll_get(pArrayListEmployee, j);
						employee_getHorasTrabajadas(empA, &hourA);
						employee_getHorasTrabajadas(empB, &hourB);
						if (hourA > hourB) {
							ll_set(pArrayListEmployee, i, empB);
							ll_set(pArrayListEmployee, j, empA);
						}

					}

				}
				resp = 1;
				printf("\nOrdenamiento exitoso!!!");
				break;
			case 6:
				for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++) {
					for (int j = i + 1; j < ll_len(pArrayListEmployee); j++) {
						int hourA;
						int hourB;
						Employee *empA = ll_get(pArrayListEmployee, i);
						Employee *empB = ll_get(pArrayListEmployee, j);
						employee_getHorasTrabajadas(empA, &hourA);
						employee_getHorasTrabajadas(empB, &hourB);
						if (hourA < hourB) {
							ll_set(pArrayListEmployee, i, empB);
							ll_set(pArrayListEmployee, j, empA);
						}

					}

				}
				resp = 1;
				printf("\nOrdenamiento exitoso!!!");
				break;
			case 7:
				for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++) {
					for (int j = i + 1; j < ll_len(pArrayListEmployee); j++) {
						int sallaryA;
						int sallaryB;
						Employee *empA = ll_get(pArrayListEmployee, i);
						Employee *empB = ll_get(pArrayListEmployee, j);
						employee_getSueldo(empA, &sallaryA);
						employee_getSueldo(empB, &sallaryB);
						if (sallaryA > sallaryB) {
							ll_set(pArrayListEmployee, i, empB);
							ll_set(pArrayListEmployee, j, empA);
						}

					}

				}
				resp = 1;
				printf("\nOrdenamiento exitoso!!!");
				break;
			case 8:
				for (int i = 0; i < ll_len(pArrayListEmployee) - 1; i++) {
					for (int j = i + 1; j < ll_len(pArrayListEmployee); j++) {
						int sallaryA;
						int sallaryB;
						Employee *empA = ll_get(pArrayListEmployee, i);
						Employee *empB = ll_get(pArrayListEmployee, j);
						employee_getSueldo(empA, &sallaryA);
						employee_getSueldo(empB, &sallaryB);
						if (sallaryA < sallaryB) {
							ll_set(pArrayListEmployee, i, empB);
							ll_set(pArrayListEmployee, j, empA);
						}

					}

				}
				resp = 1;
				printf("\nOrdenamiento exitoso!!!");
				break;
			}
			resp = 1;
		} else {
			break;
		}
	} while (!(option == 9));

	return resp;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	int resp = 0;
	char opt;
	printf("\n¿Desea guardar los cambios realizados?(s/n): ");
	__fpurge(stdin);
	scanf("%c", &opt);
	if (opt == 's') {
		FILE *file;
		file = fopen(path, "w");
		if (file != NULL) {
			fprintf(file, "id,nombre,horasTrabajads,sueldo\n");
			for (int i = 0; i < ll_len(pArrayListEmployee); i++) {
				Employee *tmp = ll_get(pArrayListEmployee, i);
				int auxid;
				char auxName[128];
				int auxHours;
				int auxSallary;
				employee_getId(tmp, &auxid);
				employee_getNombre(tmp, auxName);
				employee_getHorasTrabajadas(tmp, &auxHours);
				employee_getSueldo(tmp, &auxSallary);
				fprintf(file, "%d,%s,%d,%d\n", auxid, auxName, auxHours,
						auxSallary);
			}
			resp = 1;
		}
		fclose(file);
	}
	return resp;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	int resp = 0;
	char opt;
	printf("\n¿Desea guardar los cambios realizados?(s/n): ");
	__fpurge(stdin);
	scanf("%c", &opt);
	if (opt == 's') {
		FILE *file;
		file = fopen(path, "wb");
		if (file != NULL) {
			fprintf(file, "id,nombre,horasTrabajads,sueldo\n");
			for (int i = 0; i < ll_len(pArrayListEmployee); i++) {
				Employee *tmp = ll_get(pArrayListEmployee, i);
				int auxid;
				char auxName[128];
				int auxHours;
				int auxSallary;
				employee_getId(tmp, &auxid);
				employee_getNombre(tmp, auxName);
				employee_getHorasTrabajadas(tmp, &auxHours);
				employee_getSueldo(tmp, &auxSallary);
				fprintf(file, "%d,%s,%d,%d\n", auxid, auxName, auxHours,
						auxSallary);
			}
			resp = 1;
		}
		fclose(file);
	}
	return resp;
}

