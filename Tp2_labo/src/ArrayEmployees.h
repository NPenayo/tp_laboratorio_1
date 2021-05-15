/*
 * ArrayEmployees.h
 *
 *  Created on: 12 May 2021
 *      Author: npenayo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} Employee;
typedef struct {
	int id;
	char name[51];
	int isEmpty;
} Department;
/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 * */
int initEmployees(Employee *list, int len);
/** \brief add in a existing list of employees the values received as parameters
 *     in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
int addEmployee(Employee *list, int len, Department *dplist, int dplen,int *id);
/** \brief find an Employee by Id en returns the index position in array. *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 * */
int findEmployeeById(Employee *list, int len, int id);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*
 * \param len int
 * \param id int
 * \param dplist Department*
 * \param dplens int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 * */
int removeEmployee(Employee *list, int len, int id);
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 * */
int sortEmployees(Employee *list, int len, int order, Department *dplist,
		int dplens);
/** \brief print the content of employees array
 * \param list Employee*
 * \param length int
 * \return int
 * */
int printEmployees(Employee *list, int length, Department *departments,
		int dep_lens);
/** \brief print an employee
 * \param employee Employee
 * \param departments Department*
 * \param dep_lens int
 * */
void printEmployee(Employee employee, Department *departments, int dep_lens);

/** \brief Get an empty index from employees array
 *  \param employees Employee*
 *  \param length int
 *  \param emptyIndex int*
 *  \return Return 1 if found an index and 0 if the array is complete
 */
int getEmpty(Employee *employees, int length, int *emptyIndex);

/** \brief Evaluate if the employees array have a register in it
 *  \param employees Employee*
 *  \param length int
 *  \return Return 1 if is completly empty and 0 if the array have a register in it
 */
int isEmpty(Employee *employees, int length);
/** \brief Get department name by it's id
 *  \param departments Department*
 *  \param length int
 *  \param id int
 *  \param name char*
 *  \return int Return (1) if found the department - (0) if Error [Invalid length or NULL pointer]
 */
int getDepartmentbyId(Department *departments, int length, int id, char *name);
/** \brief print the content of departments array
 * \param list Department*
 * \param length int
 * \return int
 * */
int printDepartments(Department *departments, int length);
/** \brief print an department
 * \param employee Department
 *
 */
void printDepartment(Department department);
#endif /* ARRAYEMPLOYEES_H_ */
