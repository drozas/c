/*************************************************************
	Asignatura : Programacion en C/C++
	Practica : Hoja de problemas 3
	Autor : David Rozas Domingo
*************************************************************/

/* Descripcion : Ejercicio 12. Fichero de definicion para el TAD pila*/


/*Inicializa una pila*/
void CrearVacia (tNodo **pila)
{
	*pila = NULL;
}

/*Inserta un elemento en la cima de la pila*/
void InsertarElemento(tNodo **pila, int valor)
{
	tNodo *pAux;
	
	if(pila==NULL)
	{
		/*Si es el primer elemento*/
		pAux = malloc(sizeof(tNodo));
		if (pAux!=NULL)
		{
			/*Guardamos info, y le apuntamos con el indice ppal*/
			pAux->valor = valor;
			pAux->sig = NULL;
			*pila = pAux;			
		}
	}else{
		/*Si habia mas elementos*/
		pAux = malloc(sizeof(tNodo));
		if (pAux!=NULL)
		{
			/*Guardamos info, apuntamos al contenido anterior, y le apuntamos desde ppal.*/
			pAux->valor = valor;
			pAux->sig = *pila;
			*pila = pAux;
		}
	}
}

/*Devuelve el elemento que esta en la cima, y lo elimina de la pila*/
int DevolverCima(tNodo **pila)
{
	tNodo *pAux;
	int valAux;
	
	pAux = *pila;
	if(pAux==NULL)
	{
		printf("¡La pila está vacia!\n");
		return 0;
	}else{
		valAux = pAux->valor;
		/*Desplazamos el indice ppal, y liberamos la memoria*/
		*pila = pAux->sig;
		free(pAux);
		return valAux;
	}
}
