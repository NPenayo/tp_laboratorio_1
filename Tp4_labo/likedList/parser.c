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
		ll_add(pArrayListEmployee, auxEmp);

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
	int registers = 0;
	Employee auxEmp;
	while (!feof(pFile)) {
		if (fread(&auxEmp, sizeof(Employee), 1, pFile) == 1) {
			Employee *temp = employee_new();
			employee_setId(temp, auxEmp.id);
			employee_setNombre(temp, auxEmp.nombre);
			employee_setHorasTrabajadas(temp, auxEmp.horasTrabajadas);
			employee_setSueldo(temp, auxEmp.sueldo);
			ll_add(pArrayListEmployee,(Employee*)temp);
		}
		registers++;
	}

	return registers;
}
