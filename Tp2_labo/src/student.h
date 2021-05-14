/*
 * student.h
 *
 *  Created on: 29 Apr 2021
 *      Author: Nicolas Alejandro Penayo
 *      Description: Struct Student y funciones relacionadas
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include "degree.h"
#define AMOUNT 20
typedef struct {
	int docket;
	char gender;
	int age;
	int score1;
	int score2;
	float scoreAvg;
	char surname[AMOUNT];
	int assigned;
	int id_degree;
} Student;

//CRUD alumnos
int createStudent(Student arr[], int stArrLength, int index, Degree dgarr[],
		int dgArrLength);
void indexStudents(Student arr[], int arrLength, Degree dgarr[],
		int dgArrLength);
void showStudent(Student student, Degree dgarr[], int dgArrLength);
int updateStudent(Student student, Student *students, int arrLength);
int deleteStudent(Student student, Student *students, int arrLength);
//Obtener alumno por id
int getStudentByDocket(Student arr[], int arrLength, int to_find,
		Degree dgarr[], int dgArrLength, Student *output);
//Inicializar array de alumnos
void initializeStudents(Student students[], int arrLength);
//Obtener posicion libre en array de alumnos
int getUnassigned(Student students[], int arrLength, int *to_assign);
//Verificar si hay registros cargados
int isEmpty(Student students[], int arrLength);

void orderBy(Student *students,int stArrLength,Degree *degrees,int dgArrLength,char arg,char mode);
void swapStudent(Student *students,int a,int b);
#endif /* STUDENT_H_ */
