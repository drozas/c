/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 13. Programa que realiza operaciones de calculadora 
				 basica*/

#include <stdio.h>

int main(void)
{
	char opcion;
	
	
	do
	{
		/*printf("\n\n##################################################\n");
		printf("#### P R O G R A M A   C A L C U L A D O R A #####\n");
		printf("##################################################\n\n");
		printf(" \t  - 'S' : realizar una suma\n");
		printf(" \t  - 'R' : realizar una resta\n");
		printf(" \t  - 'M' : realizar una multiplicacion\n");
		printf(" \t  - 'D' : realizar una division\n");
		printf(" \t  - 'F' : salir del programa\n");*/
		printf(" \t\t Escoge una opcion : ");
		scanf("%c", &opcion);		
		printf("valor de opcion %c\n", opcion);
		
		switch (opcion) {
			case 'S' :
					printf("Has escogido sumar \n");
					break;
			case 'R' :
					printf("Has escogido restar \n");
					break;
			case 'M' :
					printf("Has escogido multiplicar \n");
					break;
			case 'D' :
					printf("Has escogido dividir \n");
					break;
			case 'F' :
					printf("Adios! \n");
					break;			
			default :
					printf("Opcion incorrecta \n");
		}
		
	}while (opcion !='F');
	
	return 0;
}
