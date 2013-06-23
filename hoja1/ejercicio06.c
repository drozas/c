/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 1
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 6. Lee un numero natural, y mira si la suma
				 de sus cifras pares es igual a la suma de las impares */


#include <stdio.h>

int main(void)
{
	int contPares,contImpares,n,i,j;
	int cifras [10];
	contPares=0;
	contImpares=0;
	
	do
	{
		printf("Escribe un numero : ");
		scanf("%i",&n);
		if (n<=0)
		{
			printf("Tiene que ser un numero natural\n");
		}
	}	
	while(n<=0);
		
	/*Guardamos todas sus cifras en un array*/
	i=0;
	while(n>9)
	{
		cifras[i]=n%10;
		n=n/10;
		i++;
	}		
	cifras[i]=n;

	/*Ahora haremos el recuento de las cifras, y veremos si es igual*/
	for(j=0;j<=i;j++)
	{
		if (cifras[j]%2==0)
		{
			contPares = contPares + cifras[j];
		}else{
			contImpares = contImpares + cifras[j];
		}
	}
	
	/*Y por ultimo comprobamos si se cumple la propiedad*/
	if(contPares==contImpares)
	{
		printf("En este numero se cumple que las suma de sus cifras pares es igual a la suma de sus cifras impares.\n");
	}else{
		printf("En este numero no se cumple la propiedad.\n");
	}	
	
	return 0;
}
