/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 16. Programa que realiza operaciones de calculadora 
				 basica*/

#include <stdio.h>

int main(void)
{
	int opcion;
	float a, b;
	
	do
	{
		printf("\n\n##################################################\n");
		printf("#### P R O G R A M A   C A L C U L A D O R A #####\n");
		printf("##################################################\n\n");
		printf(" \t  - 1 : realizar una suma\n");
		printf(" \t  - 2 : realizar una resta\n");
		printf(" \t  - 3 : realizar una multiplicacion\n");
		printf(" \t  - 4 : realizar una division\n");
		printf(" \t  - 0 : salir del programa\n");
		printf(" \t\t Escoge una opcion : ");
		
		scanf("%i", &opcion);
				
		switch (opcion)
		{
			case 1:
				printf("\t\t Introduzca un sumando : ");
				scanf("%f", &a);
				printf("\t\t Introduzca el otro sumando : ");
				scanf("%f", &b);
				printf("\t\t El resultado es : %.2f\n", a+b);
				break;
			case 2:
				printf("\t\t Introduzca el minuendo : ");
				scanf("%f", &a);
				printf("\t\t Introduzca el sustraendo : ");
				scanf("%f", &b);
				printf("\t\t El resultado es : %.2f\n", a-b);
				break;	
			case 3:
				printf("\t\t Introduzca un operando : ");
				scanf("%f", &a);
				printf("\t\t Introduzca el otro : ");
				scanf("%f", &b);
				printf("\t\t El resultado es : %.2f\n", a*b);
				break;				
			case 4:
				printf("\t\t Introduzca el dividendo : ");
				scanf("%f", &a);
				printf("\t\t Introduzca el divisor : ");
				scanf("%f", &b);
				printf("\t\t El resultado es : %.2f\n", a/b);
				break;	
			case 0:
				printf("\t\t Adios!\n");	
				break;			
			
			default :
				printf("\t\t ¡Operacion incorrecta!\n");	
		}			
	}while (opcion != 0);
	
	return 0;
}
