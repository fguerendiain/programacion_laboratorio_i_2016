#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief recibe un entero del usuario validando lo ingresado
 *
 * \param (userinput) direccion de memoria de la variable donde guardar el dato ingresado por el usuario
 * \param (min) control de rango a validar, numero entero minimo permitido
 * \param (max) control de rango a validar, numero entero maximo permitido
 * \param (msgFirstTime) mensaje que se le muestra al usuario en el primer intento
 * \param (msgError) mensaje que se le muestra al usuario a partir del segundo intento
 * \param (trays) cantidad maxima de intentos
 *
 * \return (0 = dato correcto dentro del rango | -1 = dato incorrecto o igual a 0 | -2 dato correcto fuera de rango)
 *
 */

int getUserInputInt(int *userInput, int min, int max, char *msgFirstTime, char *msgError, int trays)
{
    {
    int ret;
    char auxBuffer[4000];
    int flagFirstInput = 0;
    int validateUserInput;
    int endOfTrays = 0;

    do
    {
        endOfTrays++;
        if(flagFirstInput == 0)
        {
            printf("%s",msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf("%s",msgError);
        }

        scanf("%s",auxBuffer);
        validateUserInput = atoi(auxBuffer);

        if(validateUserInput != 0)
        {
            if(validateUserInput < min || validateUserInput > max)
            {
                ret = -2; // la funcion indica que el usuario ingreso un numero fuera del rango establecido
                *userInput = 0;
            }
            else
            {
                ret = 0;  // la funcion indica que el usuario ingreso un numero dentro del rango establecido
                *userInput = validateUserInput;
                endOfTrays=trays;
            }
        }
        else
        {
            ret = -1; //el usuario no ingreso un numero o ingreso 0
            *userInput = 0;
        }
        erradicateStdin();
    }while(endOfTrays != trays);
    return ret;
    }
}
/*

float getUserInputFloat(float *userInput,char *msgFirstTime, int min, int max, char *msgError)
{
    {
    int ret = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf(msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf(msgError);
        }

        validateUserInput = scanf("%f", userInput);

        if(validateUserInput == 0 || userInput < min || userInput > max)
        {
            return ret;
        }
        erradicateStdin();
    }
    return 0;
    }
}


char getUserInputChar(char *userInput,char *msgFirstTime, char *msgError)
{
    {
    int ret = -1;
    int flagFirstInput = 0;
    int validateUserInput;

    do
    {
        if(flagFirstInput == 0)
        {
            printf(msgFirstTime);
            flagFirstInput++;
        }
        else
        {
            printf(msgError);
        }

        validateUserInput = scanf("%c", userInput);

        if(validateUserInput == 0)
        {
            return ret;
        }
        erradicateStdin();
    }
    return 0;
    }
}


char getUserInputString(char *userImput,char *msgFirstTime, cantMinLetras,cantMaxLetras,char *msgError)
{
    printf(msgFirstTime);
    gets(userImput);

    if(strlen(userImput) > cantMaxLetras && strlen(userImput) < cantMinLetras)
    {
        ret
    }

}

*/