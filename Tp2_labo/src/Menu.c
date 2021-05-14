/**
 * menu.c
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *      Description: Mostrar un menu y funciones relacionadas
 */

#include "Menu.h"

#include <stdio.h>
#include <string.h>
#include "Arrays.h"

/**
 * @brief Setea una opcion tipo numerica para el menu
 *
 * @param option El indicador correspondiente a la opcion para agregar al menu
 * @param opt_desciption Texto que se muestra en el menu para la opcion
 * @param menu Menu donde se va a agregar la opcion
 * @param position Posicion del array del menu donde se va a cargar la opcion
 *
 */
void setOption(char option, char description[], Option menu[], int position) {
	Option newOpt;
	initializeChar(newOpt.opt_description,DESC_LENGTH);
	newOpt.index = option;
	strcpy(newOpt.opt_description, description);
	menu[position] = newOpt;
}
/**
 *@brief Imprime el menu en la consola
 *
 * @param menu Menu a imprimir
 * @param length Cantidad de opciones que tiene el menu
 */
void printMenu(Option menu[], int lenght) {
	for (int i = 0; i < lenght; i++) {
		if (i == 0) {
			printf("\n\n%c - %s", menu[i].index, menu[i].opt_description);
		} else {
			printf("\n%c - %s", menu[i].index, menu[i].opt_description);
		}
	}
}
/**
 * @brief Validar si la opcion elegida es correcta
 *
 * @param char input Opcion elegida
 * @param Option valid_chars Array con los caracteres validos
 * @param int arrLength Tamanio del array
 * @return 1 si es inválido 0 si es válido
 */
int getOption(char input, Option menu[], int arrLength) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		if (input == menu[i].index) {
			resp = 1;
			break;
		}
	}
	return resp;
}
