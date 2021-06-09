#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	char buffer[4][128];
	int registers = 0;
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer + 0), *(buffer + 1),
			*(buffer + 2), *(buffer + 3));
	while (!feof(pFile)) {
		Employee *auxEmp = NULL;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer + 0),
				*(buffer + 1), *(buffer + 2), *(buffer + 3));
		registers++;
		auxEmp = employee_newParametros(*(buffer + 0), *(buffer + 1),
				*(buffer + 2), *(buffer + 3));
		ll_add(pArrayListEmployee, (Employee*) auxEmp);

	}

	return registers;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	char buffer[4][128];
	int registers = 0;
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer + 0), *(buffer + 1),
			*(buffer + 2), *(buffer + 3));

	while (!feof(pFile)) {
		Employee *auxEmp = NULL;
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", *(buffer + 0),
				*(buffer + 1), *(buffer + 2), *(buffer + 3));
		registers++;
		auxEmp = employee_newParametros(*(buffer + 0), *(buffer + 1),
				*(buffer + 2), *(buffer + 3));
		ll_add(pArrayListEmployee, (Employee*) auxEmp);

	}

	return registers;
}
