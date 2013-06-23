/*************************************************************@
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 3. Convierte grados celsius en grados farenheit*/

#include <stdio.h>

int main(void)
{
		float g_celsius, g_farenheit;
	
		printf("Introduce la temperatura en grados celsius : ");
		scanf("%f", &g_celsius);
		/*Aplicamos la formula y mostramos por pantalla*/
		g_farenheit=((g_celsius*9)/5.0)+32;
		printf("%.1f grados celsius equivalen a %.1f grados farenheit", g_celsius, g_farenheit);
		return 0;
}
