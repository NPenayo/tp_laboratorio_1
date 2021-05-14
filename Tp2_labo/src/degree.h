/*
 * degree.h
 *
 *  Created on: 8 May 2021
 *      Author: npenayo
 */

#ifndef DEGREE_H_
#define DEGREE_H_
typedef struct {
	int id;
	char description[20];
	int assigned;
} Degree;
/**
 * @fn int getId(Degree*, int, char*, int*)
 * @brief Obtener el id de una carrera mediante descripcion
 *
 * @param degrees Array de carreras
 * @param arrLength Tamanio del array de carreras
 * @param description Descripcion de la carrera a buscar
 * @param output Variable donde se guarda el id obtenido
 * @return 1 si se encontro el ID | 0 si no se encontro
 */
int getId(Degree *degrees, int arrLength, char *description, int *output);
/**
 * @fn void getDescription(Degree*, int, int, char*)
 * @brief Obtener descripcion de una carrera mediante un id
 *

 * @param degrees Array de carreras
 * @param arrLength Tamanio del array de carreras
 * @param id ID de la carrera a buscar
 * @param output Variable donde se guarda la descripcion obtenida
 * @return 1 si se encontro el ID | 0 si no se encontro
 */
int getDescription(Degree *degrees, int arrLength, int id, char *output);
// Mostrar carreras y atributos
/**
 * @fn void indexDegrees(Degree*, int)
 * @brief Mostrar todas las carreras
 * @param degrees Array de carreras
 * @param arrLength Tamanio del array
 */
void indexDegrees(Degree *degrees, int arrLength);
/**
 * @fn void showDegree(Degree)
 * @brief Muestra una carrera
 *
 * @param degree Carrera a mostrar
 */
void showDegree(Degree degree);
/**
 * @fn int validDegree(Degree*, int, int*, int)
 * @brief Comprobar que se seleccione una carrera valida
 *
 * @param degrees Array de carreras
 * @param arrLength Tamanio del array
 * @param output Variable donde guardar el ID de la carrera
 * @param max_attempts Cantidad de intentos
 * @return 1 si es valido | 0 si no es valido
 */
int validDegree(Degree *degrees, int arrLength, int *output, int max_attemps);
#endif /* DEGREE_H_ */
