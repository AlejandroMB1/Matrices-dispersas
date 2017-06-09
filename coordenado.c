#include "Proyecto.h"

tipoMatriz **crearMatriz(int filas, int column){

	tipoMatriz **matrix = (tipoMatriz **) malloc (filas*sizeof(tipoMatriz *));

	for (int i = 0; i < filas; i++){
		matrix[i]=(tipoMatriz *) malloc (column*sizeof(tipoMatriz));
	}
	return matrix;
}

tipoMatriz **AsignarValores(tipoMatriz **matrix, int filas, int column){

	
	srand(time(NULL));
	int n = 0;
	int p = ((filas*column)*0.4);
	while (n<=p){
		int posfil=rand()%filas;
		int poscol=rand()%column;
		int q = rand()%99+1;
		matrix[posfil][poscol].info=q;
		n++;
	}
	return matrix;
}


tipoMatriz **llenarmatrix(tipoMatriz **matrix, int filas, int column){
	
	srand(time(NULL));
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < column; j++){
			int p = rand()%99+1;
			matrix[i][j].posx = j;
			matrix[i][j].posy = i;
			matrix[i][j].info = p;
		}
	}
	return matrix;
}


tipoMatriz **llenarDeCeros(tipoMatriz **matrix, int filas, int column){
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < column; j++){
			matrix[i][j].info = 0;
			matrix[i][j].posx = j;
			matrix[i][j].posy = i;
		}

	}
	return matrix;
}


tipoMatriz **crearDeMatrizCompleta(tipoMatriz **matrix, int filas, int column,int t){

	tipoMatriz **Dispersa = crearMatriz(filas, column);
	llenarDeCeros(Dispersa, filas, column);	
	int m = 0, n = 1 ;
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < t; j++){
			if(i % 2 == 0){
				if(m > column - 2){
					m = 0; 
				}
				Dispersa[i][m].info = matrix[i][j].info;
					m = m+2;
					
			}
			else{
				if(n > column){
					n = 1; 
				}
				Dispersa[i][n].info = matrix[i][j].info;
					n = n + 2;
			}
		}	
	
	}
	
	
	return Dispersa;
}


tipoMatriz **obtenerMatrizCompleta(tipoMatriz **dispersa, int filas, int column){
	int a = 0;
	int c = column/2;
	tipoMatriz **completa = crearMatriz(filas,c);
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < column; j++){
			if(a == c){
				a = 0;
			}
			
			if(dispersa[i][j].info != 0){
				completa[i][a].info = dispersa[i][j].info;
				a++;
			}
					
		}	
	}
	return completa;
}

tipoVectorCor llenarVectorCor(tipoMatriz **matrix, int filas, int column){
	
	tipoVectorCor Vec;


	int n = 0;
	int p = 0;
	int q = 0;

	for (int i = 0; i < filas; i++){	
		for (int j = 0; j < column; j++){
			if(matrix[i][j].info != 0){
				Vec.filas[p] = matrix[i][j].posy;
				Vec.columna[q] = matrix[i][j].posx;
				Vec.valor[n] = matrix[i][j].info;
				n++;
				p++;
				q++;	
			}
		}
	}
	
	while(n <= 50){
		Vec.filas[p] = -1;
		Vec.columna[p] = -1;
		Vec.valor[p] = -1;
		n++;
	}
	
	return Vec;
}






void imprimir(int filas, int column, tipoMatriz **matrix){ 

	printf("\n");
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < column; j++){
			printf("[ %d ]",matrix[i][j].info);
			
				
		}
	printf("\n");
	}
}



void imprimirV(int filas, tipoVectorCor Vec){
	printf("\n");
	printf("FORMATO COORDENADO: ");
	printf("\n");
	int i=0;
	while (Vec.valor[i] > 0){
			printf("\n<%d>:<%d>:<%d>\n",Vec.valor[i],Vec.filas[i],Vec.columna[i]);	
			i++;
	}
}



// OPERACIONES DEL TAD MATRIZ DISPERSA

//obtener elemento vector coordenado

int ObtenerElementoVec(tipoVectorCor Vec,int fila, int column,int n){

	int p=0,q=0,s=0;

	int elemento = 0;

	while(q<=n){
		q++;
		p++;
		s++;
		if(fila==Vec.filas[q]&&column==Vec.columna[p]){
			elemento=Vec.valor[s];
		}
	}

	return elemento;

}

//obtener fila y guardarla en un arreglo con el formato coordenado:

int *ObtenerFilaVC(tipoVectorCor veCoor, int posfila, int column,int n){
	int a = 0;
	int *fila = (int *)malloc(column * sizeof(int));
	for (int j = 0; j < n; j++){
		if(veCoor.filas[j] == posfila){
			fila[a] = veCoor.valor[j];
			a++;
			
		}		
		
	}
	return fila;
}


void ImprimirVectorFilas(int *vector, int column){
	
	printf("\nFila obtenida(vector): ");
	for(int i = 0; i < column; i++){
		if(vector[i] > 0 && vector[i] < 100){
			printf("<%d>", vector[i]);
		}
	}
	printf("\n");
	
}

//obtener fila y guardarla en una lista con el formato coordenado:

tipoListaSimple *crearNodoSimple(int elemento){
	tipoListaSimple *nodito;
	nodito = (tipoListaSimple *)malloc(sizeof(tipoListaSimple));
	nodito -> siguiente = NULL;
	nodito -> valor = elemento;
	return nodito;

}

tipoListaSimple *ObtenerFilaL(tipoListaSimple *lista,tipoVectorCor vec,int posfila, int column){
	int i = 0;
	int b = 0;
	while( i < column){
		
		
		while(vec.filas[b] != posfila ){
			b++;
		}
		int elemento = vec.valor[b];
		tipoListaSimple *tmpNodo = crearNodoSimple(elemento);
		tipoListaSimple *p;
		if(lista == NULL){
			lista = tmpNodo;

		}
		else{
			p = lista;
			while(p -> siguiente != NULL){
				p = p -> siguiente;
			
			}
			p -> siguiente = tmpNodo;
		}
		b++;
		i++;
	}
	return lista;
}


void imprimirListaSimple(tipoListaSimple *lst){
	tipoListaSimple *p  = lst;
	printf("\n");
	printf("lista: ");
	while(p != NULL){
		if( p -> valor > 0 && p -> valor < 100)
			printf("<%d>",p -> valor);
			p = p -> siguiente;
	}
	printf("\n");
}

//obtener columna y guardarla en un arreglo con el formato coordenado:

int *ObtenerColumnaVC(tipoVectorCor veCoor, int poscolumn, int filas,int n){
	
	int a = 0;
	int *columna = (int *)malloc(filas * sizeof(int));
	
	for (int j = 0; j < n; j++){
		if(veCoor.columna[j] == poscolumn){
			columna[a] = veCoor.valor[j];
			a++;
		}
	}
	return columna;
}

void ImprimirVectorColumnas(int *vector, int filas){
	
	printf("\nColumna obtenida(vector): ");
	for(int i = 0; i < filas; i++){
		if(vector[i] > 0 && vector[i] < 100){
			printf("<%d>", vector[i]);
		}
	}
	printf("\n");
	
}

//obtener columna y guardarla en una lista con el formato coordenado:

tipoListaSimple *ObtenerColumnaL(tipoListaSimple *lista,tipoVectorCor vec, int poscolumn, int filas){
	int i = 0;
	int b = 0;
	while( i < filas-filas/3){
		
		while(vec.columna[b] != poscolumn){
			b++;
		}
		int elemento = vec.valor[b];
		tipoListaSimple *tmpNodo = crearNodoSimple(elemento);
		tipoListaSimple *p;
		if(lista == NULL){
			lista = tmpNodo;

		}
		else{
			p = lista;
			while(p -> siguiente != NULL){
				p = p -> siguiente;
			
			}
			p -> siguiente = tmpNodo;
		}
		b++;
		i++;
	}
	return lista;
}

//obtener fila dispersa:

tipoVectorCor ObtenerFilaDis(tipoMatriz **matrix, int filas, int column, int posfila){
	
	tipoVectorCor vec;
	int a=0;

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < column*2; j++){

			if(i==posfila){
				vec.valor[a]=matrix[i][j].info;
				a++;
			}
		}
	}
	return vec;
}

void ImprimirVectorFilasDis(tipoVectorCor vector, int column){
	
	printf("\nFila dispersa obtenida(vector): ");
	for(int i = 0; i < column*2; i++){
			printf("<%d>", vector.valor[i]);
	}
	printf("\n");
}


//obtener columna dispersa

tipoVectorCor ObtenerColumnaDis(tipoMatriz **matrix, int filas, int column, int poscolumn){
	
	tipoVectorCor vec;
	int a=0;

	for (int i = 0; i < filas; i++){
		for (int j = 0; j < column; j++){

			if(j==poscolumn){
				vec.valor[a]=matrix[i][j].info;
				a++;
			}
		}
	}
	return vec;
}


void ImprimirVectorColumnDis(tipoVectorCor vector, int filas){
	
	printf("\nColumna dispersa obtenida(vector): ");
	for(int i = 0; i < filas; i++){
			printf("<%d>", vector.valor[i]);
	}
	printf("\n");
}







//obtener el numero de elemento distintos de 0 que contiene una matriz dispersa:

int obtenerNumElementos(tipoVectorCor vec){
	int i = 0;
	while(vec.valor[i] > 0 && vec.valor[i] < 100){
		i++;
	}

	return i;
	
}

//modificar posicion:

tipoVectorCor modificarPosCor(tipoVectorCor Vec,int x, int y, int n, int filas){

	for (int i = 0; i < filas; ++i)
	{
		if(Vec.filas[i] == x && Vec.columna[i] == y){
			Vec.valor[i] = n;
			return Vec;
		}

		else
			i++;
	}

	//printf("El numero que ingreso no existe en la matriz\n");
	return Vec;



}
//suma de matrices:



tipoVectorCor SumarMatrices(tipoMatriz **A, tipoVectorCor VecA, tipoVectorCor VecB, int filas, int columnas){
	
	tipoVectorCor r = llenarVectorCor(A,filas,columnas);
	int i = 0;
	while(VecA.valor[i] != -1){
		
		r.valor[i] = VecA.valor[i] + VecB.valor[i];
		i++;
	
	}
	
	return r;
}



tipoVectorCor transpuesta(tipoVectorCor a, int filas, int columnas){
	
	tipoVectorCor t;
	int i = 0;
	int acumu = 2;
	int r = obtenerNumElementos(a);
	while(i < r ){
			
		if(i==0){
			t.valor[i] = a.valor[i];
			t.filas[i] = a.filas[i];
			t.columna[i] = a.columna[i];
			
		}
		else{
			t.valor[i] = a.valor[acumu];
			t.filas[i] = a.valor[acumu];
			t.columna[i] = a.valor[acumu];
		
		
			
		}
		i++;
		acumu+=1;
	}
	
	
	return t;	
}









