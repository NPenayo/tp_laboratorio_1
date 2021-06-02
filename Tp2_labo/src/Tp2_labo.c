/*
 ============================================================================
 Name        : Tp2_labo.c
 Author      : Penayo Nicolas 1E
 Version     :
 Description : Tp 2 Laboratorio | ABM Empleados
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <stddef.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Menu.h"
#include "Arrays.h"
#include "Validations.h"
#define MAX_EMPLOYEES 5
#define OPT_AMOUNT 5
#define REP_AMOUNT 3
#define UPD_AMOUNT 5
#define MAX_ATTEMPTS 3
#define MAX_DEPARTMENTS 3

void clearConsole();
void cleanBuffer();
int main(void) {
	char opt;
	int id_employee = 0;
	int auxDepartmentId;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	char confim_values[2];
	char mainOpts[5];
	int auxId;
	int totalEmployees;
	float avgSalary;
	float totalSalaries;
	int auxInt;
	initializeChar(mainOpts, 5);
	initializeChar(confim_values, 2);
	mainOpts[0] = '1';
	mainOpts[1] = '2';
	mainOpts[2] = '3';
	mainOpts[3] = '4';
	mainOpts[4] = 'x';
	confim_values[0] = 's';
	confim_values[1] = 'n';
	Employee employees[MAX_EMPLOYEES];
	Department departments[MAX_DEPARTMENTS] = { { 1, "RRHH", 1 }, { 2,
			"Desarollo", 1 }, { 3, "Soporte", 1 } };
	//Initialize employees array
	if (initEmployees(employees, MAX_EMPLOYEES)) {
		printf(
				"\nError al inicializar el array de empleados. Verifique los parametros");
	}
	//Settings menues
	Option menu[OPT_AMOUNT];
	Option reports[REP_AMOUNT];
	Option update[UPD_AMOUNT];
	//Create main menu
	setOption('1', "Alta Empleado", menu, 0);
	setOption('2', "Modificar Empleado", menu, 1);
	setOption('3', "Baja Empleado", menu, 2);
	setOption('4', "Informes", menu, 3);
	setOption('x', "Salir", menu, 4);
	//Create reports menu
	setOption('a', "Listar Empleados", reports, 0);
	setOption('b', "Listar Salarios", reports, 1);
	setOption('x', "Volver atras", reports, 2);
	//Create update menu
	setOption('a', "Cambiar nombre", update, 0);
	setOption('b', "Cambiar apellido", update, 1);
	setOption('c', "Cambiar salario", update, 2);
	setOption('d', "Cambiar sector", update, 3);
	setOption('x', "Volver al menu", update, 4);
	if (menu != NULL) {
		do { //Set variables

			clearConsole();
			printf("\n%50s",
					"-----------------Menu Empleados-----------------");
			printf(
					"\n 1 - Alta Empleado \n 2 - Modificar Empleado¸\n 3 - Baja Empleado\n 4 - Informes\n x - Salir");
			if (validChar("\n Elija una opcion", "Error.Opcion incorrecta",
					&opt, mainOpts, 5, MAX_ATTEMPTS)) {
				switch (opt) {
				case '1':
					do {
						clearConsole();
						printf("\n%50s", "---------- Alta empleado ----------");
						if ((!addEmployee(employees, MAX_EMPLOYEES, departments,
								MAX_DEPARTMENTS, &id_employee))) {
							validChar(
									"\nCarga exitosa. Desea cargar otro empleado? s/n",
									"Error.Opcion invalida", &opt,
									confim_values, 2, MAX_ATTEMPTS);
						} else {
							clearConsole();
							printf(
									"\nError. Base de datos completa, debe eliminar un registro antes de cargar uno nuevo");
							printf(
									"\n\nPresione una tecla para volver al menu");
							cleanBuffer();
							getchar();
							break;
						}
					} while (!(opt == 'n'));

					break;
				case '2':
					if (!(isEmpty(employees, MAX_EMPLOYEES))) {

						do {
							printEmployees(employees, MAX_EMPLOYEES,
									departments, MAX_DEPARTMENTS);
							if (validInt("Ingrese ID del empleado",
									"Error.El ID ingresado es invalido.",
									&auxId, 0, MAX_EMPLOYEES, MAX_ATTEMPTS)) {
								if (findEmployeeById(employees, MAX_EMPLOYEES,
										auxId) != -1) {
									do {
										printf("\n%50s",
												"---------- Modificar empleado ----------");
										printMenu(update, UPD_AMOUNT);
										printf("\n\n Elija una opcion: ");
										cleanBuffer();
										scanf("%c", &opt);
										if (getOption(opt, update,
										UPD_AMOUNT)) {
											switch (opt) {
											case 'a':
												clearConsole();
												if (validString("Nuevo nombre",
														"Error. El nombre no puede estar vacío o contener numeros",
														auxName, 51,
														MAX_ATTEMPTS)) {
													strcpy(
															employees[auxId].name,
															auxName);
													validChar(
															"\nSe modifico el nombre!. Desea modificar otro empleado? s/n",
															"Error.Opcion invalida",
															&opt, confim_values,
															2, MAX_ATTEMPTS);
												}
												break;
											case 'b':
												clearConsole();
												if (validString(
														"Nuevo apellido",
														"Error. El apellido no puede estar vacío o contener numeros",
														auxLastName, 51,
														MAX_ATTEMPTS)) {
													strcpy(
															employees[auxId].lastName,
															auxLastName);
													validChar(
															"\nSe modifico el apellido!. Desea modificar otro empleado? s/n",
															"Error.Opcion invalida",
															&opt, confim_values,
															2, MAX_ATTEMPTS);
												}
												break;
											case 'c':
												clearConsole();
												if (validFloat("Nuevo salario",
														"Error.Tipo de dato invalido",
														&auxSalary, 1, 1000000,
														MAX_ATTEMPTS)) {

													employees[auxId].salary =
															auxSalary;
													validChar(
															"\nSe modifico el salario!. Desea modificar otro empleado? s/n",
															"Error.Opcion invalida",
															&opt, confim_values,
															2, MAX_ATTEMPTS);
												}
												break;
											case 'd':
												clearConsole();
												printDepartments(departments,
												MAX_DEPARTMENTS);
												if (validInt("Nuevo sector",
														"Error.Codigo Invalido",
														&auxDepartmentId, 1,
														MAX_DEPARTMENTS,
														MAX_ATTEMPTS)) {
													employees[auxId].sector =
															auxDepartmentId;
													validChar(
															"\nSe modifico el sector!. Desea modificar otro empleado? s/n",
															"Error.Opcion invalida",
															&opt, confim_values,
															2, MAX_ATTEMPTS);
												}
												break;

											}
										}
									} while (!(opt == 'n' || opt == 'x'));

								} else {
									clearConsole();
									printf(
											"\nError no se encuentra el ID indicado.");
									printf(
											"\nIngrese (m) para volver al menu. O pulse una tecla para reintentar");
									cleanBuffer();
									scanf("%c", &opt);
								}
							} else {
								break;
							}
						} while (!(opt == 'n' || opt == 'm'));
					} else {
						clearConsole();
						printf("\nError. No hay registros cargados");
						printf("\n\nPresione una tecla para volver al menu");
						cleanBuffer();
						getchar();
						break;
					}
					break;
				case '3':
					do {
						if (!(isEmpty(employees, MAX_EMPLOYEES))) {
							printf("\n%50s",
									"---------- Eliminar empleado ----------");

							printf(
									"\n Ingrese ID del empleado que desea eliminar");
							cleanBuffer();
							scanf("%d", &auxId);
							if (findEmployeeById(employees,
							MAX_EMPLOYEES, auxId) != -1) {
								if (!removeEmployee(employees, MAX_EMPLOYEES,
										auxId)) {
									printf("Se elimino registro");
								}

							} else {
								printf("\nNo se encontro el ID del empleado.");
								break;
							}

						} else {
							clearConsole();
							printf("\nError. No hay registros cargados");
							printf(
									"\n\nPresione una tecla para volver al menu");
							cleanBuffer();
							getchar();
							break;
						}
					} while (!(opt == 'n'));
					break;
				case '4':
					totalEmployees = 0;
					totalSalaries = 0;
					if (!(isEmpty(employees, MAX_EMPLOYEES))) {
						printf("\n%50s", "---------- Informes ----------");
						if (validInt(
								"Como desea ordenar los registros? (ASCENDENTE 1 | DESCENDENTE 0)",
								"Eror.Opcion incorrecta", &auxInt, 0, 1,
								MAX_ATTEMPTS)) {
							if (!(sortEmployees(employees, MAX_EMPLOYEES,
									auxInt, departments, MAX_DEPARTMENTS))) {
								for (int i = 0; i < MAX_EMPLOYEES; i++) {
									if (!employees[i].isEmpty) {
										totalEmployees++;
										totalSalaries += employees[i].salary;

									}

								}
								printEmployees(employees, MAX_EMPLOYEES,
										departments, MAX_DEPARTMENTS);
								printf("\nTotal de salarios: %.2f",
										totalSalaries);
								avgSalary = totalSalaries / totalEmployees;
								printf("\nSalario promedio: %.2f", avgSalary);
								printf("\nEmpleados que superan el promedio");
								for (int i = 0; i < MAX_EMPLOYEES; i++) {
									if (!(employees[i].isEmpty)
											&& (employees[i].salary > avgSalary)) {

										printEmployee(employees[i], departments,
										MAX_DEPARTMENTS);
									}

								}
								printf(
										"\n\nPresione una tecla para volver al menu");
								cleanBuffer();
								getchar();

							}
						}
					} else {
						clearConsole();
						printf("\nNo hay registros cargados");
						printf("\n\nPresione una tecla para volver al menu");
						cleanBuffer();
						getchar();
						break;
					}
					break;
				}
			} else {
				clearConsole();
				printf(
						"\n Error.Opcion ivalida. Presione una tecla para volver al menu.");
				cleanBuffer();
				getchar();
			}
		} while (!(opt == 'x'));
	}

	return EXIT_SUCCESS;
}
void clearConsole() {
#if defined( __linux__)
	system("clear");
#elif defined( __MINGW32__)
		sytem("cls");
#endif
}
void cleanBuffer() {
#if defined(__linux__)
	__fpurge(stdin);
#elif defined(__MINGW32__)
	fflush(stdin);
#endif
}
