/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 2
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 7. Calcula la ecuacion de la recta, dados
                 dos de sus puntos*/

#include <stdio.h>

/*Definicion  y renombramiento de tipo punto*/
struct tipoPunto{
	float x,y;
	};
typedef struct tipoPunto tPunto;
	
int main(void)
{
	tPunto pto1,pto2;
	float m,b;
	
	
	/*Obtenemos los valores de los puntos*/
	printf("Vamos a calcular la ecuacion de una recta, dados dos puntos.\n");
	printf("\t Primer punto \n");
	printf("\t ¿Valor de x? : ");
	scanf("%f", &pto1.x);
	printf("\t ¿Valor de y? : ");
	scanf("%f", &pto1.y);
	printf("\t Segundo punto \n");
	printf("\t ¿Valor de x? : ");
	scanf("%f", &pto1.x);
	printf("\t ¿Valor de y? : ");
	scanf("%f", &pto1.y);
	
	/*Calculamos pendiente e interseccion*/
	m = (pto2.y-pto1.y)/(pto2.x-pto1.x);
	b = pto1.y - m*pto1.x;
	
	printf("\n ### La ecuacion de la recta es y = %.2f*x + %.2f ###\n", m, b); 
	return 0;
}
