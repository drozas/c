/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 12. Calcula la factura del agua */

#include <stdio.h>

int main(void)
{
	float m3, total, m3t0, m3t1, m3t2;
	total = 0.0 , m3t0 = 0.0 , m3t1 = 0.0 ,m3t2 = 0.0;
	
	printf("****************************************************************\n");
	printf("           Bienvenid@ a Aguas Bender\n"); 
	printf("****************************************************************\n\n");
	do
	{
		printf("Por favor, introduzca el nº de m3 consumidos este mes : ");
		scanf("%f", &m3);
		if (m3<0.0)
		{
			printf("El numero debe ser positivo\n");
		}
	}while(m3<0.0);
	
	
	/*A continuacion, distinguimos los tramos de cobro*/
	if (m3<=0.5)
	{
		m3t0 = m3;
	}else if (m3<=15.0)
	{
		m3t0 = 0.5;		
		m3t1 = m3-0.5;
	}else{
		m3t0 = 0.5;
		m3t1 = 14.5;
		m3t2 = m3-15;
	}
	
	total = 6.0 + (m3t0*0.0) + (m3t1 * 0.75) + (m3t2 * 1.5);
	
	/*Mostramos el detalle de la factura*/
	printf("\n####################### F A C T U R A ###########################\n\n");
	printf(" - Cuota de servicio : 6 €\n");
	printf(" - Tramo 0 [0.0-0.5m3] : %.2f x 0.75 = %.2f €\n", m3t0, m3t0*0.0);
	printf(" - Tramo 1 [0.5-15m3] : %.2f x 0.75 = %.2f €\n", m3t1, m3t1*0.75);
	printf(" - Tramo 2 [a partir de 15m3] : %.2f x 1.5 = %.2f €\n", m3t2, m3t2*1.5);
	printf("\n\t\t Total = %.2f € \n", total);
	printf("\n\t\t Total con iva (16%) = %.2f € \n\n", total+total*0.16);
	printf("#################################################################\n");
	
	return 0;
}
