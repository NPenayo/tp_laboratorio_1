/*
 * arrays.h
 *
 *  Created on: Apr 22, 2021
 *      Author: Nicolas Alejandro Penayo
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_
#define STRING_LENGTH 20

/**
 * @brief Insertar un dato en un array de tipo char
 *
 * @param char Dato a insertar
 * @param char[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendCharToArray(char, char[], int);
/**
 * @fn int appendToString(char*, char*)
 * @brief Cargar texto en un string
 *
 * @param input_string
 * @param output
 * @param strLenght
 */
int appendToString(char *message, char *output, int strLenght);
/**
 * @brief Insertar un dato en un array de tipo int
 *
 * @param int Dato a insertar
 * @param int[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendIntToArray(int, int[], int);

/**
 * @brief Insertar un dato en un array de tipo flotante
 *
 * @param float Dato a insertar
 * @param float[] Array donde se inserta el dato
 * @param int Largo del array
 */
void appendFloatToArray(float, float[], int);

/**
 * @brief Inicializa un array de caracteres
 *
 * @param char[] Array a inicializar
 * @param int Largo del array
 */
void initializeChar(char[],int arrLength);
/**
 * @brief Inicializa un string
 *
 * @param char[] Array a inicializar
 * @param int Largo del array
 */
void initializeString(char[][STRING_LENGTH], int);

/**
 * @brief Inicializa un array de numeros
 *
 * @param int[] Array a inicializar
 * @param int Largo del array
 */
void initializeInt(int[], int);

/**
 * @brief Inicializa un array de tipo flotante
 *
 * @param float[] Array a inicializar
 * @param int Largo del array
 */
void initializeFloat(float[], int);
/**
 * @fn void swapInt(int, int)
 * @brief Intercambiar dos valores del tipo int
 *
 * @param arr Array donde se encuentran los valores a intecambiar
 * @param a Valor 1 para intercambiar
 * @param b Valor 2 para intercambiar
 */
void swapInt(int *arr, int a, int b);
/**
 * @fn void swapFloat(float, float)
 * @brief Intercambiar dos valores del tipo float
 *
 * @param arr Array donde se encuentran los valores a intecambiar
 * @param a Valor 1 para intercambiar
 * @param b Valor 2 para intercambiar
 */
void swapFloat(float *arr, int a, int b);
/**
 * @fn void swapChar(char*, int, int)
 * @brief Intercambiar dos valores del tipo char
 *
 * @param arr Array donde se encuentran los valores a intecambiar
 * @param a Valor 1 para intercambiar
 * @param b Valor 2 para intercambiar
 */
void swapChar(char *arr, int a, int b);
/**
 * @fn void swapString(char*, int, int)
 * @brief Intercambiar dos cadenas de caracteres
 *
 * @param arr Array donde se encuentran los valores a intecambiar
 * @param a Valor 1 para intercambiar
 * @param b Valor 2 para intercambiar
 */
void swapString(char arr[][STRING_LENGTH], int arrLength,int a, int b);

void quicksortIntAsc(int *A, int izq, int der);
void quicksortFloatAsc(float *A, int izq, int der);
void quicksortCharAsc(char *A, int izq, int der);
#endif /* ARRAYS_H_ */
