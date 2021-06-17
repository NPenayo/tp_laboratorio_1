/*
 * arrays.c
 *
 *  Created on: Apr 22, 2021
 *      Author: Nicolas Alejandro Penayo
 */
#include "Arrays.h"

#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
void initializeChar(char arr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		strcpy(&arr[i], " ");
	}

}
void initializeString(char arr[][STRING_LENGTH], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayLength; j++) {
			strcpy(&arr[i][j], " ");
		}
	}

}
void initializeInt(int arr[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		arr[i] = 0;
	}
}
void initializeFloat(float arr[], int arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		arr[i] = 0;
	}
}
void appendCharToArray(char input, char arr[], int index) {
	arr[index] = input;
}
void appendIntToArray(int input, int arr[], int index) {
	arr[index] = input;
}
void appendFloatToArray(float input, float arr[], int index) {
	arr[index] = input;
}
int appendToString(char message[], char output[], int strLenght) {
	int resp;
	printf("\n%s: ", message);
	__fpurge(stdin);
	char aux[STRING_LENGTH];
	initializeChar(aux, STRING_LENGTH);
	if (fgets(aux, strLenght, stdin) != NULL) {
		resp = 1;
		for (int i = 0; i < strLenght; i++) {
			if (isdigit(aux[i])) {
				resp = 0;
				break;
			}
		}
		for (int i = 0; i < strLenght; i++) {
			aux[i] = tolower(aux[i]);
		}
		aux[strcspn(aux, "\n")] = 0;
		strcpy(output, aux);

	}
	return resp;
}
void swapInt(int *arr, int a, int b) {
	int aux;
	aux = arr[a];
	arr[a] = arr[b];
	arr[b] = aux;
}

void swapFloat(float *arr, int a, int b) {
	float aux;
	aux = arr[a];
	arr[a] = arr[b];
	arr[b] = aux;
}

void swapChar(char *arr, int a, int b) {
	char aux;
	aux = arr[a];
	arr[a] = arr[b];
	arr[b] = aux;
}

void swapString(char arr[][STRING_LENGTH], int arrLength, int a, int b) {
	char aux[1][STRING_LENGTH];
	initializeString(aux, 1);
	strcpy(aux[0], &arr[a][STRING_LENGTH]);
	strcpy(&arr[a][STRING_LENGTH], &arr[b][STRING_LENGTH]);
	strcpy(&arr[b][STRING_LENGTH], aux[0]);

}
void quicksortFloatAsc(float *A, int izq, int der) {
	if (der - izq > 1) {
		{
			int centro = (izq + der) / 2;
			if (A[izq] > A[centro]) {

			}
			swapFloat(A, izq, centro);
			if (A[izq] > A[der])
				swapFloat(A, izq, der);
			if (A[centro] > A[der])
				swapFloat(A, centro, der);
			swapFloat(A, centro, der - 1);
		}
		{
			int i = izq, j = der - 1;
			int pivote = A[der - 1];
			do {
				do
					i++;
				while (A[i] < pivote);
				do
					j--;
				while (A[j] > pivote);
				swapFloat(A, i, j);
			} while (j > i);
		}
	}
}

void quicksortCharAsc(char *A, int izq, int der) {
	if (der - izq > 1) {
		{
			int centro = (izq + der) / 2;
			if (A[izq] > A[centro]) {

			}
			swapChar(A, izq, centro);
			if (A[izq] > A[der])
				swapChar(A, izq, der);
			if (A[centro] > A[der])
				swapChar(A, centro, der);
			swapChar(A, centro, der - 1);
		}
		{
			int i = izq, j = der - 1;
			int pivote = A[der - 1];
			do {
				do
					i++;
				while (A[i] < pivote);
				do
					j--;
				while (A[j] > pivote);
				swapChar(A, i, j);
			} while (j > i);
		}
	}
}
