#include "Employee.h"
#include "string.h"
#include "stdlib.h"
Employee* employee_new() {
	Employee *auxEmp = (Employee*) malloc(sizeof(Employee));
	return auxEmp;
}
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *auxEmp = (Employee*) malloc(sizeof(Employee));
	if (auxEmp != NULL) {
		employee_setId(auxEmp, atoi(idStr));
		employee_setNombre(auxEmp, nombreStr);
		employee_setHorasTrabajadas(auxEmp, atoi(horasTrabajadasStr));
		employee_setSueldo(auxEmp, atoi(sueldoStr));
	}
	return auxEmp;
}
void employee_delete(Employee *this) {
	free(this);
}

int employee_setId(Employee *this, int id) {
	this->id = id;
	return 1;
}
int employee_getId(Employee *this, int *id) {
	*id = this->id;
	return 1;
}

int employee_setNombre(Employee *this, char *nombre) {
	strcpy(this->nombre, nombre);
	return 1;
}
int employee_getNombre(Employee *this, char *nombre) {
	strcpy(nombre, this->nombre);
	return 1;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	this->horasTrabajadas = horasTrabajadas;
	return 1;
}
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	*horasTrabajadas = this->horasTrabajadas;
	return 1;
}

int employee_setSueldo(Employee *this, int sueldo) {
	this->sueldo = sueldo;
	return 1;
}
int employee_getSueldo(Employee *this, int *sueldo) {
	*sueldo = this->sueldo;
	return 1;
}
void employee_increaseSalary(void *this) {
	if (this != NULL) {
		if ((*(Employee*) this).sueldo > 20000) {
			employee_setSueldo(this, (*(Employee*) this).sueldo * 1.20);
		}
	}
}
