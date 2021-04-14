/*
 ============================================================================
 Name        : Tp1_labo.c
 Author      : Nicolas Alejandro Penayo
 Version     :
 Copyright   : Tp 1 de laboratorio 1 / Penayo Nicolas 1E
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "operaciones.h"

void mostrarMenu(void);
void mostarOperandos(int *op1, int *op2, int *flag1, int *flag2);
int validarInput(int input);

int main(void) {

	mostrarMenu();
}

/**
 *  Mostrar un menu con opciones
 *
 * @return 0 si se mostro correctamente y 1 si hubo un error
 */
void mostrarMenu(void) {
	int opcion;
	int checkOpcion;
	int operando1 = 0;
	int operando2 = 0;
	int resultSuma;
	int resultResta;
	int resultProd;
	float resultDiv;
	long resultFact1;
	long resultFact2;
	int flagOperando1 = 1;
	int flagOperando2 = 1;
	do {
		printf("\n****************** Menu TP 1 ****************");
		mostarOperandos(&operando1, &operando2, &flagOperando1, &flagOperando2);
		printf("\n\n1. Ingresar 1er operando");
		printf("\n2. Ingresar 2do operando");
		printf("\n3. Calcular todas las operaciones");
		printf("\n4. Informar resultados");
		printf("\n5. Salir");
		printf("\n\nElija una opcion: ");
		__fpurge(stdin);
		checkOpcion = scanf("%d", &opcion);
		if (checkOpcion != 1 || (opcion < 1 || opcion > 5)) {
			system("clear");
			printf(
					"\nOpcion invalida. Presione cualquier tecla para volver al menu");
			__fpurge(stdin);
			getchar();
		}
		switch (opcion) {
		int input;
	case 1:

		do {
			system("clear");
			printf("\nIngrese el primer operando: ");
			__fpurge(stdin);
			input = scanf("%d", &operando1);
			if (!validarInput(input)) {
				printf("\nError!. El dato ingresado debe ser un numero entero");
			}

		} while (!validarInput(input));
		flagOperando1 = 0;
		break;
	case 2:
		do {
			system("clear");
			printf("\nIngrese el segundo operando: ");
			__fpurge(stdin);
			input = scanf("%d", &operando2);
			if (!validarInput(input)) {
				printf("\nError!. El dato ingresado debe ser un numero entero");
			}
		} while (!validarInput(input));
		flagOperando2 = 0;
		break;
	case 3:
		if (flagOperando1 || flagOperando2) {
			system("clear");
			printf(
					"\nError!Debe ingresar ambos operandos. Presione cualquier tecla para volver al menú");
			__fpurge(stdin);
			getchar();
		} else {
			suma(&operando1, &operando2, &resultSuma);
			resta(&operando1, &operando2, &resultResta);
			producto(&operando1, &operando2, &resultProd);
			//Validamos que no se haga una division por 0
			if (operando2 == 0) {
				resultDiv = 0;
			} else {
				division(&operando1, &operando2, &resultDiv);
			}
			// Validamos que sean numeros positivos para hacer el factoreo o que no sean 0 o 1
			if (operando1 < 0) {
				resultFact1 = 0;
			} else if (operando1 == 0 || operando1 == 1) {
				resultFact1 = 1;
			} else {
				factoreo(operando1, &resultFact1);
			}
			if (operando2 < 0) {
				resultFact2 = 0;
			} else if (operando2 == 0 || operando2 == 1) {
				resultFact2 = 1;
			} else {
				factoreo(operando2, &resultFact2);
			}
			system("clear");
			printf(
					"\nOperaciones realizadas. Presione cualquier tecla para volver al menú");
			__fpurge(stdin);
			getchar();
		}

		break;
	case 4:
		if (flagOperando1 || flagOperando2) {
			system("clear");
			printf(
					"\nError!Debe ingresar ambos operandos. Presione cualquier tecla para volver al menú");
			__fpurge(stdin);
			getchar();
		} else {
			system("clear");
			printf("a) El resultado de A+B es: %d", resultSuma);
			printf("\nb) El resultado de A-B es: %d", resultResta);
			if (resultDiv == 0) {
				printf(
						"\nc) El resultado de A/B es: No es posible dividir por cero");
			} else {
				printf("\nc) El resultado de A/B es: %.2f", resultDiv);
			}
			printf("\nd) El resultado de A*B es: %d", resultProd);

			//Muestra un mensaje segun el valor de los operandos ingresados para el factorial
			if (resultFact1 == 0 && resultFact2 == 0) {
				printf(
						"\ne) Ambos operando son negativos y no se puede realizar el factorial");
			}
			if (resultFact1 == 0 && resultFact2) {
				printf(
						"\ne) El operando A es un numero negativo y El factorial de B es: %ld",
						resultFact2);
			}
			if (resultFact2 == 0 && resultFact1) {
				printf(
						"\ne) El operando B es un numero negativo y El factorial de A es: %ld",
						resultFact1);
			}
			if (resultFact1 && resultFact2) {
				printf(
						"\ne) El factorial de A es: %ld y El factorial de B es: %ld",
						resultFact1, resultFact2);
			}

		}
		break;

		}
		system("clear");

	} while (opcion != 5);
}

/**
 *  Imprime los operandos en el menu
 *@param opA Operando 1
 *@param opB Operando 2
 *@param flag1 Flag para saber si se ingreso el primer operando
 *@param flag2 Flag para saber si se ingreso el segundo operando
 *
 */
void mostarOperandos(int *opA, int *opB, int *flag1, int *flag2) {
	if (*flag1 && *opA == 0) {
		printf("\n\n Operando A: No se cargo el primer operando");
	} else {
		printf("\n\n Operando A: %d", *opA);
		*flag1 = 0;
	}
	if (*flag2 && *opB == 0) {
		printf("\n Operando B: No se cargo el segundo operando");
	} else {
		printf("\n Operando B: %d", *opB);
		*flag2 = 0;
	}
}
/**
 *  Validar si el input ingresado es del tipo correcto
 *
 * @return 0 si es incorrecto y 1 si es correcto
 */
int validarInput(int input) {
	if (input != 0) {
		return 1;
	}
	return 0;
}
