/**
 * validations.c
 *
 *  Author: Nicolas Alejandro Penayo
 *  Description: Validaciones de datos
 */
#include "Validations.h"
#include "Arrays.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define attempts_MSG "Cantidad de intentos supereda. Vuelva a intentar mas tarde."

int validChar(char *requestMsg, char *errorMsg, char *output,
		char *valid_values, int arrLength, int max_attempts) {
	char aux;
	int isChar = 0;
	int valid = 0;
	int attempts = 0;
	int resp = 0;
	do {
		printf("\n%s ", requestMsg);
		__fpurge(stdin);
		isChar = scanf("%c", &aux);
		for (int i = 0; i < arrLength; i++) {
			if (aux == valid_values[i] && isChar) {
				valid = 1;
				resp = 1;
				*output = aux;
				break;
			}
		}
		if (!valid) {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}

int validInt(char *requestMsg, char *errorMsg, int *output, int min_value,
		int max_value, int max_attempts) {
	int aux;
	int resp = 0;
	int isInt;
	int valid = 0;
	int attempts = 0;
	do {
		printf("\n%s ", requestMsg);
		__fpurge(stdin);
		isInt = scanf("%d", &aux);
		if (isInt && (aux >= min_value && aux <= max_value)) {
			valid = 1;
			resp = 1;
			*output = aux;
			break;
		} else {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}

int validFloat(char *requestMsg, char *errorMsg, float *output, float min_value,
		float max_value, int max_attempts) {
	float aux;
	int resp = 0;
	float isFloat = 0;
	int valid = 0;
	int attempts = 0;
	do {
		printf("\n%s: ", requestMsg);
		__fpurge(stdin);
		isFloat = scanf("%f", &aux);
		if (isFloat && (aux >= min_value || aux <= max_value)) {
			valid = 1;
			resp = 1;
			*output = aux;
			break;
		} else {
			printf("\n%s ", errorMsg);
		}
		attempts++;
	} while (!valid && attempts < max_attempts);
	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nCantidad de intentos superada. Presione una tecla para volver al menu");
		__fpurge(stdin);
		getchar();
	}
	return resp;
}
int validString(char *message, char *errMessage, char *output, int strLenght,
		int max_attempts) {
	int resp = 0;
	int attempts = 0;
	char aux[strLenght];
	if (strcmp(message, "\0") && strcmp(errMessage, "\0") && strLenght > 0) {
		do {
			printf("\n%s: ", message);
			__fpurge(stdin);
			fgets(aux, sizeof(aux), stdin);
			if (strcmp(&aux[0], "\n") && strcmp(&aux[0], "\0")) {
				resp = 1;
				for (int i = 0; i < strlen(aux); i++) {
					if (isdigit(aux[i])) {
						resp = 0;
						break;
					}
				}
				if (!resp) {
					printf("\n%s", errMessage);
					attempts++;
				} else {
					for (int i = 0; i < strlen(aux); i++) {
						aux[i] = tolower(aux[i]);
					}
					aux[0] = toupper(aux[0]);
					for(int i = 0; i<strlen(aux);i++){
						if(aux[i] == ' '){
							aux[i+1] = toupper(aux[i+1]);
						}
					}
					aux[strcspn(aux, "\n")] = 0;
					strcpy(output, aux);

				}

			} else {
				printf("\n%s", errMessage);
				attempts++;
			}
		} while (!resp && attempts < max_attempts);
	} else {
		system("clear");
		printf("\nError.Parametro de validString() invalido.");
	}

	if (attempts == max_attempts) {
		system("clear");
		printf(
				"\nMaxima cantidad de intentos superada. Presione una tecla para volver atras.");
		__fpurge(stdin);
		getchar();
	}

	return resp;
}
