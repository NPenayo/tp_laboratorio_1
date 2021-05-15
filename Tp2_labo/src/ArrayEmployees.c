/*
 * ArrayEmployees.c
 *
 *  Created on: 12 May 2021
 *      Author: npenayo
 */
#include "ArrayEmployees.h"
#include "Arrays.h"
#include "Validations.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#define MAX_ATTEMPTS 3

int initEmployees(Employee *list, int len) {
	int resp = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		resp = 0;
	}

	return resp;
}
int addEmployee(Employee *list, int len, Department *dplist, int dplen, int *id) {
	int resp;
	int auxIndex;
	Employee auxEmployee;
	if (getEmpty(list, len, &auxIndex) && list != NULL) {

		if (validString("Nombre del Empleado",
				"Error. El nombre no puede estar vacío o contener numeros",
				auxEmployee.name, 51, MAX_ATTEMPTS)
				&& validString("Apellido del Empleado",
						"Error. El apellido no puede estar vacío o contener numeros",
						auxEmployee.lastName, 51, MAX_ATTEMPTS)
				&& validFloat("Salario", "Error.Tipo de dato invalido",
						&auxEmployee.salary, 1, 1000000, MAX_ATTEMPTS)
				&& printDepartments(dplist, dplen)
				&& validInt("Codigo de sector", "Error.Codigo Invalido",
						&auxEmployee.sector, 1, 3, MAX_ATTEMPTS)) {
			auxEmployee.isEmpty = 0;
			auxEmployee.id = *id;
			list[auxIndex] = auxEmployee;
			(*id)++;
			resp = 0;

		} else {
			resp = -1;
		}
	}else{

	}
	return resp;
}
int findEmployeeById(Employee *list, int len, int id) {
int resp = -1;
if (list != NULL && len > 0) {
	for (int i = 0; i < len; i++) {
		if (list[i].id == id && !(list[id].isEmpty)) {
			resp = i;
			break;
		}
	}
}
return resp;
}
int removeEmployee(Employee *list, int len, int id) {
int resp;
if (list != NULL && len > 0) {
	for (int i = 0; i < len; i++) {
		if (list[i].id == id) {
			list[i].isEmpty = 1;
			resp = 0;
			break;
		}
	}
} else {
	resp = -1;
}
return resp;
}
int sortEmployees(Employee *list, int len, int order, Department *dplist,
	int dplens) {
int resp = -1;
char description_1[51];
char description_2[51];
Employee aux;
if (list != NULL && len > 0) {
	if (order) {
		for (int i = 0; i < len - 1; i++) {
			if (strcmp(list[i].lastName, list[i + 1].lastName) > 0) {
				aux = list[i];
				list[i] = list[i + 1];
				list[i + 1] = aux;

			} else if (!(strcmp(list[i].lastName, list[i + 1].lastName))) {
				getDepartmentbyId(dplist, dplens, list[i].sector,
						description_1);
				getDepartmentbyId(dplist, dplens, list[i + 1].sector,
						description_2);
				if (strcmp(description_1, description_2) > 0) {
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
				}
			}
		}
		resp = 0;
	} else {
		for (int i = 0; i < len - 1; i++) {
			if (strcmp(list[i].lastName, list[i + 1].lastName) < 0) {
				aux = list[i];
				list[i] = list[i + 1];
				list[i + 1] = aux;

			} else if (!(strcmp(list[i].lastName, list[i + 1].lastName))) {
				getDepartmentbyId(dplist, dplens, list[i].sector,
						description_1);
				getDepartmentbyId(dplist, dplens, list[i + 1].sector,
						description_2);
				if (strcmp(description_1, description_2) > 0) {
					aux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = aux;
				}
			}
		}
	}
	resp = 0;
}
return resp;
}
int printEmployees(Employee *list, int length, Department *departments,
	int dep_lens) {
int resp;
char auxDepartment[15];
initializeChar(auxDepartment, 15);
if (list != NULL && length > 0) {
	for (int i = 0; i < 83; i++) {
		if (!i) {
			printf("\n -");
		} else {
			printf("-");
		}

	}
	printf("\n %-2c %s %2c %10s %5c %14s %7c %11s %5c %10s %5c", '|', "ID", '|',
			"Nombre", '|', "Apellido", '|', "Salario", '|', "Sector", '|');
	for (int i = 0; i < 83; i++) {
		if (!i) {
			printf("\n -");
		} else {
			printf("-");
		}

	}
	for (int i = 0; i < length; i++) {
		if (!(list[i].isEmpty)) {

			getDepartmentbyId(departments, dep_lens, list[i].sector,
					auxDepartment);
			printf("\n%5d %3c %-14s %c %-20s %c %14.2f  %c %-13s", list[i].id,
					'|', list[i].name, '|', list[i].lastName, '|',
					list[i].salary, '|', auxDepartment);
		}

	}
	resp = 1;
} else {
	resp = 0;
}
return resp;
}

void printEmployee(Employee employee, Department *departments, int dep_lens) {
char auxDepartment[15];
initializeChar(auxDepartment, 15);
getDepartmentbyId(departments, dep_lens, employee.sector, auxDepartment);
printf("\n%5d %3c %-14s %c %-20s %c %14.2f  %c %-13s", employee.id, '|',
		employee.name, '|', employee.lastName, '|', employee.salary, '|',
		auxDepartment);
}
int getEmpty(Employee *employees, int length, int *emptyIndex) {
int resp = 0;
if (employees != NULL && length > 0) {
	for (int i = 0; i < length; i++) {
		if (employees[i].isEmpty == 1) {
			*emptyIndex = i;
			resp = 1;
			break;
		}
	}
}
return resp;
}
int isEmpty(Employee *employees, int length) {
int resp = 0;
int aux = 0;
if (employees != NULL && length > 0) {
	for (int i = 0; i < length; i++) {
		if (employees[i].isEmpty == 1) {
			aux++;
		}
	}
}
if (aux == length) {
	resp = 1;
}
return resp;
}
int getDepartmentbyId(Department *departments, int length, int id, char *name) {
int resp = 0;
if (departments != NULL && length > 0 && name != NULL) {
	for (int i = 0; i < length; i++) {
		if (departments[i].id == id) {
			strcpy(name, departments[i].name);
			resp = 1;
			break;
		}
	}
}
return resp;
}
int printDepartments(Department *departments, int length) {
int resp = 0;
if (departments != NULL && length > 0) {
	printf("\n%50s", "---------- Listado de sectores ----------");
	printf("\n\n%5s | %5s", "Codigo de sector", "Nombre");
	for (int i = 0; i < length; i++) {
		printDepartment(departments[i]);
		resp = 1;
	}
}
return resp;
}
void printDepartment(Department department) {
char name[51];
initializeChar(name, 51);
printf("\n%8d %9c %-10s", department.id, '|', department.name);
}
