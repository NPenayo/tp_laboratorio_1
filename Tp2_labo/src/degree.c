/*
 * degree.c
 *
 *  Created on: 8 May 2021
 *      Author: npenayo
 */

#include "degree.h"
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>

int getId(Degree *degrees, int arrLength, char *description, int *output) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		if (!(strcmp(degrees[i].description, description))) {
			*output = degrees[i].id;
			resp = 1;
			break;
		}
	}
	return resp;
}

int getDescription(Degree *degrees, int arrLength, int id, char *output) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		if (degrees[i].id == id) {
			strcpy(output, degrees[i].description);
			resp = 1;
			break;
		}
	}
	return resp;
}

void indexDegrees(Degree *degrees, int arrLength) {
	printf("\n************ Carreras disponibles ************");
	printf("\n\n%-15s | %6s", "Codigo_Carrera", "Descripcion");
	printf("\n-----------------------------");
	for (int i = 0; i < arrLength; i++) {
		showDegree(degrees[i]);
	}
}


void showDegree(Degree degree) {
	printf("\n %6d%10s %-20s", degree.id,"",degree.description);
}

int validDegree(Degree *degrees, int arrLength, int *output, int max_attempts) {
	int resp = 0;
	int valid = 0;
	int attempts = 0;
	int isDegree;
	int aux;
	do {
		indexDegrees(degrees, arrLength);
		printf("\nCodigo de carrera: ");
		__fpurge(stdin);
		isDegree = scanf("%d", &aux);
		for (int i = 0; i < arrLength; i++) {
			if (isDegree && degrees[i].id == aux) {
				valid = 1;
				resp = 1;
				*output = aux;
				break;
			}
		}
		if (!valid) {
			printf("\nError. Carrera invalida");
		}
		attempts++;
	} while (!valid || attempts >= max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;

}
