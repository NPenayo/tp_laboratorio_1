/*
 * operaciones.c
 *
 *  Created on: Apr 13, 2021
 *	Author: Nicolás Alejandro Penayo
 */

#include <stdio.h>

/**
 * Realiza una suma entre dos operandos
 * @param numA Primer operando
 * @param numB Segundo operando
 * @param resSuma Direccion de memoria donde se guarda el resultado
 * @return 0 Si se realizó correctamente o 1 si hubo un error
 */
int suma(int *numA, int *numB, int *resSuma) {
	if (resSuma != NULL) {
		*resSuma = *numA + *numB;
		return 0;
	}
	return 1;
}
/**
 * Realiza una resta entre dos operandos
 * @param numA Primer operando
 * @param numB Segundo operando
 * @param resResta Direccion de memoria donde se guarda el resultado
 * @return 0 Si se realizó correctamente o 1 si hubo un error
 */
int resta(int *numA, int *numB, int *resResta) {
	if (resResta != NULL) {
		*resResta = *numA - *numB;
		return 0;
	}
	return 1;
}
/**
 * Realiza una multiplicacion entre dos operandos
 * @param numA Primer operando
 * @param numB Segundo operando
 * @param resProd Direccion de memoria donde se guarda el resultado
 * @return 0 Si se realizó correctamente o 1 si hubo un error
 */
int producto(int *numA, int *numB, int *resProd) {
	if (resProd != NULL) {
		*resProd = *numA * *numB;
		return 0;
	}
	return 1;
}
/**
 * Realiza una division entre dos operandos
 * @param numA Primer operando
 * @param numB Segundo operando
 * @param resDiv Direccion de memoria donde se guarda el resultado
 * @return 0 Si se realizó correctamente o 1 si hubo un error
 */
int division(int *numA, int *numB, float *resDiv) {
	if (resDiv != NULL) {
		*resDiv = (float) *numA / (float) *numB;
		return 0;
	}
	return 1;
}
/**
 * Realiza un factoreo entre dos operandos
 * @param num Numero al que se le calcula el factorial
 * @param resFact Direccion de memoria donde se guarda el resultado
 * @return 0 Si se realizó correctamente o 1 si hubo un error
 */
int factoreo(int num, long *resFact) {
	long resParcial = num;
	if (resFact != NULL) {
		while (num > 1) {
			resParcial *= num - 1;
			num--;
		}
		*resFact = resParcial;
		return 0;
	}
	return 1;
}
