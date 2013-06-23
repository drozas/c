/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 7. Calcula el valor de el numero e a partir
				 de su desarrollo en serie, con una precision determinada
				 por el usuario. */

#include <stdio.h>

int main(void)
{
	float e, termino_sig, termino_ant, precision;
	int permutacion_act, i, divAux;
	
	/*Inicializamos el valor de los dos primeros terminos : 1 y 1!*/
	termino_ant = 1;
	termino_sig = 1;
	/*Tambien el valor de e, y el de la primera permutacion que calcularemos*/
	e = termino_ant;
	permutacion_act = 2;
	
	printf("Vamos a calcular el valor del numero e, a partir de la siguiente definicion : \n");
	printf("e  = 1 + 1/1! + 1/2! + 1/3! + ... 1/n!\n\n");
	printf("Se define la precision como la diferencia entre dos terminos consecutivos de la serie\n.");
	do
	{
		printf("Introduce la precision con que quieres calcular : ");
		scanf("%f", &precision);
		if (precision<0.0 || precision>1.0)
			printf("Precisiones tipicas oscilan entre 0 y 1. Introduce el numero de nuevo\n");
		
	}while(precision<0.0 || precision>1.0);
	
	do
	{
		/*Sumamos el siguiente termino a e, y lo guardamos ya como el anterior*/
		e = e + termino_sig;
		termino_ant = termino_sig;
		
		/*Calculamos el siguiente termino de la serie : 1/permutacion_actual!*/
		divAux = 1;
		for(i=1; i<=permutacion_act; i++)
			divAux= divAux * i;
		termino_sig = 1.0/divAux;
		permutacion_act++;		

	}while((termino_ant-termino_sig)>precision);
	
	printf("Valor de e : %f", e); 
	return 0;
}
