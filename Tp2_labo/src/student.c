/*
 * student.c
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *     Description: Struct Student y funciones relacionadas
 */

#include "student.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Arrays.h"
#include "Validations.h"
#define MAX_ATTEMPTS 3
#define MIN_DOCKET 1000
int docket = MIN_DOCKET;
//CRUD Students
int createStudent(Student arr[], int arrLenght, int index, Degree dgarr[],
		int dgArrLength) {
	int resp = 0;
	char sexValues[2] = { 'f', 'm' };
	char gender;
	int age;
	int score1;
	int score2;
	char surname[30];
	int id_degree;
	//initializeChar(surname);
	printf("\n*************** Alta alumnos *********");
	if (validChar("Sexo(f/m):", "Error.Dato ingresado incorrecto", &gender,
			sexValues, 2, MAX_ATTEMPTS)
			&& validInt("Edad(+18):", "Error. La edad ingresada es invalida",
					&age, 18, 70,
					MAX_ATTEMPTS)
			&& validInt("Nota 1 (1-10): ", "Error. Nota invalida", &score1, 1,
					10,
					MAX_ATTEMPTS)
			&& validInt("Nota 2 (1-10): ", "Error. Nota invalida", &score2, 1,
					10,
					MAX_ATTEMPTS) && appendToString("Apellido", surname, 30)
			&& validDegree(dgarr, dgArrLength, &id_degree, MAX_ATTEMPTS)) {

		Student newStudent;
		newStudent.docket = docket;
		docket++;
		strcpy(newStudent.surname, surname);
		newStudent.score1 = score1;
		newStudent.score2 = score2;
		newStudent.scoreAvg = (float) (newStudent.score1 + newStudent.score2)
				/ 2;
		newStudent.gender = gender;
		newStudent.age = age;
		newStudent.id_degree = id_degree;
		newStudent.assigned = 1;
		arr[index] = newStudent;
		resp = 1;
	}else{
		printf("\nOcurrio un error en la carga de datos.");
	}
	return resp;
}
void indexStudents(Student arr[], int arrLength, Degree dgarr[],
		int dgArrLength) {
	printf("\n************ Listado de Alumnos ************");
	printf("\n\n | %6s | %10s | %4s | %4s | %6s | %6s | %8s | %7s", "Legajo",
			"Apellido", "Edad", "Sexo", "Nota 1", "Nota 2", "Promedio",
			"Carrera");
	printf(
			"\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");

	for (int i = 0; i < arrLength; i++) {
		showStudent(arr[i], dgarr, dgArrLength);
	}
}
void showStudent(Student student, Degree dgarr[], int dgArrLength) {
	char degDescription[20];
	getDescription(dgarr, dgArrLength, student.id_degree, degDescription);
	if (student.assigned) {
		student.surname[0] = toupper(student.surname[0]);
		printf("\n | %6d | %-10s | %4d | %4c | %6d | %6d | %8.2f | %7s",
				student.docket, student.surname, student.age, student.gender,
				student.score1, student.score2, student.scoreAvg,
				degDescription);
	}

}
int updateStudent(Student student, Student *students, int arrLength) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		if (students[i].docket == student.docket) {
			students[i] = student;
			resp = 1;
		}
	}

	return resp;
}
int deleteStudent(Student student, Student *students, int arrLength) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		if (students[i].docket == student.docket) {
			student.assigned = 0;
			students[i] = student;
			resp = 1;
		}
	}
	return resp;
}
//Get Students attributes
int getStudentByDocket(Student arr[], int arrLength, int to_find,
		Degree dgarr[], int dgArrLength, Student *output) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		if (arr[i].docket == to_find && arr[i].assigned) {
			*output = arr[i];
			resp = 1;
			break;
		}
	}
	return resp;
}
void initializeStudents(Student students[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		students[i].assigned = 0;
	}

}
int getUnassigned(Student students[], int arrLength, int *to_assign) {
	int resp = 0;
	for (int i = 0; i < arrLength; i++) {
		if (!(students[i].assigned)) {
			*to_assign = i;
			resp = 1;
			break;
		}
	}
	return resp;
}
/*int isEmpty(Student students[], int arrLength) {
	int resp = 0;
	int aux = 0;
	for (int i = 0; i < arrLength; i++) {
		if (!students[i].assigned) {
			aux++;
		}
	}
	if (aux == arrLength) {
		resp = 1;
	}
	return resp;
}*/
void orderBy(Student *students, int stArrLength, Degree *degrees,
		int dgArrLength, char arg, char mode) {
	int auxInt[20];
	float auxFloat[20];
	initializeInt(auxInt, STRING_LENGTH);
	initializeFloat(auxFloat, 20);
	switch (arg) {
	//Por legajo
	case 'a':
		for (int i = 0; i < stArrLength; i++) {
			if (students[i].assigned) {
				appendIntToArray(students[i].docket, auxInt, i);
			}
		}
		if (mode == 'a') {
			quicksortIntAsc(&auxInt[stArrLength], 0, stArrLength);
			for (int i = 0; i < stArrLength - 1; i++) {
				swapStudent(students, i, i + 1);
			}
		} else {

		}
		break;
		//Por apellido
	case 'b':
		if (mode == 'a') {
			for (int i = 0; i < stArrLength - 1; i++) {
				for (int j = i; j < stArrLength; j++) {
					if (students[i].assigned && students[j].assigned) {
						if (strcmp(students[i].surname, students[j].surname)
								> 0) {
							swapStudent(students, i, j);
						}
					}
				}

			}
		} else {

		}
		break;
		//Por promedio, si el promedio es igual, por legajo
	case 'c':
		if (mode == 'a') {
			for (int i = 0; i < stArrLength; i++) {

			}
		} else {

		}
		break;
	}
}

void swapStudent(Student *students, int a, int b) {
	Student aux;
	aux = students[a];
	students[a] = students[b];
	students[b] = aux;
}
