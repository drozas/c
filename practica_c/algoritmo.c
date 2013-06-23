/*  	FILE *fichero = fopen("texto.txt", "rt"); */
/* 	int n; */
/* 	tNodo *lista; */
/* 	lista = NULL; */
/* 	int vocales[5]; */
	
/* 	int i;		 */

/* 	/\*Primero realizamos el procesado del texto*\/ */
/* 	if (fichero!=NULL) */
/* 	{ */
/* 		while(!feof(fichero)) */
/* 		{ */
/* 			n = fgetc(fichero); */

/* 			if (n != EOF) */
/* 			{ */
/* 			  if(n != ' ') */
/* 			    { */
/* 			      /\*Guardamos en un aux mientras no sea fin de palabra*\/ */
/* 			      palabraAux = concat(palabraAux,n); */
/* 			    }else{ */
/* 			      /\*Miramos si dicha palabra ya existe en nuestro diccionario*\/ */
/* 			      pos = existePalabra(palabraAux, &lista) */

/* 				if (pos>=0) */
/* 				  { */
/* 				    /\*Aumentamos el indice contador de esa palabra*\/ */
/* 				    /\*Y tendremos que guardar la linea en la que esta tambien*\/ */
/* 				  }else{ */
/* 				    /\*Y si no la insertamos*\/ */
/* 				    insertar(&lista, palabraAux); */
/* 				  } */
/* 			    } */
/* 			} */
	
/* 		} */
/* 		fclose(fichero); */
		
/* 		/\*Recorremos mostrando la info*\/ */
/* 		recorrer(lista); */
/* 		/\*Por ultimo liberamos la memoria*\/ */
/* 		liberar(lista); */
	
/* 	}else{ */
/* 		printf("Error al abrir el fichero \n"); */
/* 	} */

  //~ char [15] stringPrueba;

  //~ strcpy(stringPrueba,"hola");

  //~ printf("Cadena de prueba : %s\n", stringPrueba);




/*OTROS NODOS DE ESTRUCTURAS*/




//~ /*Tipo nodo para lista dinamica de listas dinamicas*/
//~ struct tipoNodo{
  //~ struct tipoNodo *sig;
  //~ tipoNodoCar *palabra; 
  //~ tipoNodoInt *lineas;
	//~ };
//~ typedef struct tipoNodo tNodo;


//~ /*Tipo nodo para lista dinamica de caracteres*/
//~ struct tipoNodoCar
//~ {
  //~ struct tipoNodoCar *sig;
  //~ char car;
//~ };
//~ typedef struct tipoNodoCar tNodoCar;

//~ /*Tipo nodo para lista dinamica de lineas de aparicion*/
//~ struct tipoNodoInt
//~ {
  //~ struct tipoNodoInt *sig;
  //~ int linea
//~ };
//~ typedef struct tipoNodoInt tNodoInt;
