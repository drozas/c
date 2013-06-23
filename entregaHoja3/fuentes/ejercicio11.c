/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 11. Procesa un archivo de texto calculando los
				 valores y devuelve sus resultados en un fichero binario*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fichero_origen = fopen("datos.txt", "rt");
	int n1, n2, res;
	char signo;
	FILE *fichero_destino = fopen("resultados.dat", "wb");
	
	/*Leemos del fichero de texto */
	while(fscanf(fichero_origen, "%i %c %i",&n1, &signo, &n2) != EOF)
	{
		/*Realizamos y guardamos el resultado de la operacion adecuada en funcion del signo*/
		if (signo=='+')
		{
			res = n1 + n2;
			fwrite(&res, sizeof(res), 1, fichero_destino);
		}
		else if (signo == '-')
		{
			res = n1 - n2;
			fwrite(&res, sizeof(res), 1, fichero_destino);
		}
		else
		{
			printf("Caracter de signo desconocido. No se guardara en fichero binario.\n");
		}
	}
	
	fclose(fichero_destino);
	fclose(fichero_origen);

	return 0;
}
