/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 4. Calcular una expresion de sumatorio matematica*/

#include <stdio.h>

int main(void)
{
	int i,n,res;
	
	printf("Vamos a calcular la expresion : \n Sumatorio i=1..n de ((i*i)+1)/i \n");
	/*Controlamos que el valor sea al menos 1*/
	do
	{
		printf("Introduzca el valor de n : ");
		scanf("%i", &n);
		if(n<=0)
		{
			printf("El valor de n tiene que ser al menos 1\n");
		}			
	}while(n<=0);
	
	/*Calculamos el valor de la expresion*/
	for(i=1;i<=n;i++)
	{
		res=res+(((i*i)+1)/i);
	}
	
	printf("Resultado de la expresion : %.i \n", res);
	return 0;
}
