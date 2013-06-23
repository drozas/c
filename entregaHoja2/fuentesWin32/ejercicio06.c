/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 6. Define una estructura de datos fecha. 
                 Recibe dos fechas y las imprime en orden, pero 
				 accediendo por punteros*/

#include <stdio.h>
#include <stdlib.h>

/*Definicion  y renombramiento de tipo fecha*/
struct tipoFecha{
	int dia,mes;
	unsigned anio;
	};
typedef struct tipoFecha tFecha;
	
int main(void)
{
	tFecha *ptFecha1, *ptFecha2;
	int fecha1mayor = 0;
	/*Reservamos memoria para ambas fechas con cada puntero*/
	ptFecha1 = (tFecha*)malloc(sizeof(tFecha));
	ptFecha2 = (tFecha*)malloc(sizeof(tFecha));
	
	if ((ptFecha1 != NULL) && (ptFecha2 != NULL))
	{		
		/*Pedimos dos fechas */
		do
		{
			printf("Introduzca el dia de la primera fecha : ");
			scanf("%i", &ptFecha1->dia);
		}while(ptFecha1->dia<1 || ptFecha1->dia>31);
	
		do
		{
			printf("Introduzca el mes de la primera fecha  :");
			scanf("%i", &ptFecha1->mes);
		}while(ptFecha1->mes<1 || ptFecha1->mes>12);
	
		printf("Introduzca el año de la primera fecha : ");
		scanf("%i", &ptFecha1->anio);
		
	
		do
		{
			printf("Introduzca el dia de la segunda fecha : ");
			scanf("%i", &ptFecha2->dia);
		}while(ptFecha2->dia<1 || ptFecha2->dia>31);
	
		do
		{
			printf("Introduzca el mes de la segunda fecha  :");
			scanf("%i", &ptFecha2->mes);
		}while(ptFecha2->mes<1 || ptFecha2->mes>12);
	
		printf("Introduzca el año de la segunda fecha : ");
		scanf("%i", &ptFecha2->anio);	

	
		/*Y a continuacion procedemos a compararlas */
		if (ptFecha1->anio == ptFecha2->anio)
		{
			if(ptFecha1->mes == ptFecha2->mes)
			{
				if(ptFecha1->dia == ptFecha2->dia)
				{
					fecha1mayor=0;
				}else if(ptFecha1->dia > ptFecha2->dia){
					fecha1mayor=1;
			
				}else{
					fecha1mayor=-1;
				}
				
			}else if(ptFecha1->mes > ptFecha2->mes){
				fecha1mayor=1;
			
			}else{
				fecha1mayor=-1;
			}
		
		}else if(ptFecha1->anio > ptFecha2->anio){
			fecha1mayor=1;
		
		}else{
			fecha1mayor=-1;
		}		
	
		/*Y mostramos el resultado por pantalla*/
		switch(fecha1mayor){
			case 0 : 
				printf("¡Las dos fechas son iguales!\n");
				printf("\t%2i-%i-%i\n", ptFecha1->dia, ptFecha1->mes, ptFecha1->anio);
				printf("\t%2i-%i-%i\n", ptFecha2->dia, ptFecha2->mes, ptFecha2->anio);
				break;
			case 1 :
				printf("La fecha 1 es mayor :\n");
				printf("\t%2i-%i-%i\n", ptFecha1->dia, ptFecha1->mes, ptFecha1->anio);
				printf("\t%2i-%i-%i\n", ptFecha2->dia, ptFecha2->mes, ptFecha2->anio);
				break;
			case -1 :
				printf("La fecha 2 es mayor :\n");
				printf("\t%2i-%i-%i\n", ptFecha2->dia, ptFecha2->mes, ptFecha2->anio);
				printf("\t%2i-%i-%i\n", ptFecha1->dia, ptFecha1->mes, ptFecha1->anio);
		}

		/*Por ultimo, liberamos la memoria*/
		free(ptFecha1);
		free(ptFecha2);
		return 0;
	
	}else{
		printf("Error : No hay espacio en memoria suficiente\n");
		return -1;
	}
}
