/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 14. Dibuja un calendario del mes. */

#include <stdio.h>

int main(void)
{
	int diaInicio, nTotal, diaActual, nuevaLinea, i;
	char nombreMes[12];
	
	/*Pedimos el nombre del mes*/
	printf("Cual es el nombre del mes? : ");
	scanf("%s", &nombreMes);
	
	/*Pedimos el numero de dias*/
	do
	{
		printf("¿Cuantos dias tiene el mes? : ");
		scanf("%i", &nTotal);
	}while(nTotal<28 || nTotal>31);

	/*Y el dia en el que empieza, y aprovechamos para darle "el peso" */
	do
	{
		printf("1.domingo\n2.sabado\n3.viernes\n4.jueves\n5.miercoles\n6.martes\n7.lunes\n");	
		printf("¿Que dia empieza el mes ? : ");
		scanf("%i", &diaInicio);
	}while(diaInicio<1 || diaInicio>7);
	
	
	/*Pintamos los dias y los espacios en blanco de la primera semana*/
	printf("%s\n", nombreMes);
	printf(" L  M  X  J  V  S  D\n");
	for(i=1; i<=(7-diaInicio);i++)
		printf("   ");
	
	/*Dibujamos los dias de la primera semana*/ 
	for(diaActual=1; diaActual<=diaInicio; diaActual++)
	{
		printf("%2i ",diaActual);
	}
		printf("\n");
	
	nuevaLinea = 0;
	
	/*Y por ultimo, el resto de dias*/
	for(diaActual=(diaInicio +1); diaActual<=nTotal; diaActual++)
	{
		/*En nueva linea guardamos la "cuenta relativa"*/
		nuevaLinea++;
		printf("%2i ",diaActual);
		/*Y cuando sea modulo de 7 (una semana), escribimos fin de linea*/
		if(nuevaLinea%7==0)
			printf("\n");
	}
		
	return 0;
}
