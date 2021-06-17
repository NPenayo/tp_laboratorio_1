/**
 * validations.h
 *
 *  Author: Nicolas Alejandro Penayo
 *  Description: Validaciones de datos
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_
/**
 * @fn int validChar(char*,char *,char*,char *,int,int)
 * @brief Valida que el dato ingresado sea un char
 *
 * @param requestMsg Mensaje a para mostrar al usuario en primera instancia
 * @param errorMsg Mensaje a mostrar en caso de error
 * @param output Variable donde se guarda el dato a validar
 * @param valid_values Chars validos
 * @param arrLength Cantidad de chars validos
 * @param max_attempts Numero de intentos
 * @return 1 si es valido 0 si es invalido
 */
int validChar(char* requestMsg, char* errorMsg, char *output,
		char *valid_values, int arrLength, int max_attempts);
/**
 * @fn int validInt(char[], char[], int*, int, int, int)
 * @brief Valida que el dato ingresado sea un int
 *
 * @param requestMsg Mensaje a para mostrar al usuario en primera instancia
 * @param errorMsg Mensaje a mostrar en caso de error
 * @param output Variable donde se guarda el dato a validar
 * @param min_value Valor minimo que puede tomar la variable
 * @param max_value Valor maximo que puede tomar la variable
 * @param max_attempts Numero de intentos
 * @return 1 si es valido 0 si es invalido
 */
int validInt(char* requestMsg, char* errorMsg, int *output, int min_value,
		int max_value, int max_attempts);
/**
 * @fn int validFloat(char[], char[], float*, float, float, int)
 * @brief Valida que el dato ingresado sea un float
 *
 * @param requestMsg Mensaje a para mostrar al usuario en primera instancia
 * @param errorMsg Mensaje a mostrar en caso de error
 * @param output Variable donde se guarda el dato a validar
 * @param min_value Valor minimo que puede tomar la variable
 * @param max_value Valor maximo que puede tomar la variable
 * @param max_attempts Numero de intentos
 * @return 1 si es valido 0 si es invalido
 */
int validFloat(char* requestMsg, char* errorMsg, float *output,
		float min_value, float max_value, int max_attempts);

/**
 * @fn int appendToString(char*, char*)
 * @brief Validate if a string have an number in it
 *
 * @param input_string
 * @param output
 * @param strLenght
 */
int validString(char *message, char *errMessage, char *output, int strLenght, int max_attempts);
#endif /* VALIDATIONS_H_ */
