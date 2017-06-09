#include "Proyecto.h"

tipoMatriz **crearMatriz(int filas, int column){

	tipoMatriz **matrix = (tipoMatriz **) malloc(filas*sizeof(tipoMatriz *));

	for (int i = 0; i < filas; i++){
		matrix[i]=(tipoMatriz *) malloc (column*sizeof(tipoMatriz));
	}
	return matrix;
}

tipoMatriz **AsignarValores(tipoMatriz **matrix, int filas, int column){

	int posfil,poscol;
	srand(time(NULL));
	int n = 0;
	int p = ((filas*column)*0.4);
	while (n<=p){
		posfil=rand()%filas;
		poscol=rand()%column;
		int q = rand()%99+1;
		matrix[posfil][poscol].info=q;
		n++;
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


void imprimir(int filas, int column, tipoMatriz **matrix){
	printf("\n");
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < column; j++){
				printf("[ %d ]",matrix[i][j].info);	
		}
	printf("\n");
	}
}

tipoVectorCSR llenarVectorCSR(tipoMatriz **matrix, int filas, int column){
	
	tipoVectorCSR v;
	int n = 0, t = 0; 
     

	for (int i = 0; i < filas; i++){	
		for (int j = 0; j < column; j++){
			if(matrix[i][j].info != 0){
				v.columna[n] = j;
				v.valor[n] = matrix[i][j].info;
				n++;	
			}
		}
	}

	return v;
}

void imprimirVecCSR(int filas, tipoVectorCSR Vec){
	printf("\n");
	printf("FORMATO COMPRIMIDO POR FILAS: ");
	printf("\n");
	int i=0;
	while(Vec.valor[i] > 0 && Vec.valor[i] < 100 && Vec.columna[i] < 100 && Vec.columna[i] > 0){
			printf("\n<%d>:<%d>\n",Vec.valor[i],Vec.columna[i]);
					
			i++;	
	}
	printf("\n");
	printf("Vector cfilas: ");
	int b = 0;
	/*
	while(b != Vec.columna[i]){
		printf("<%d>",Vec.cfilas[b]);
		b++;
	}
	*/
	printf("\n");
}

//obtener elemento vector CSR

int ObtenerElementoVecCSR(tipoVectorCSR Vec,int elemento){
	int i = 0;
	
	
	while(Vec.valor[i] > 0 && Vec.valor[i] < 100){
		if(elemento == Vec.valor[i]){
			return elemento;
		}
		else{
			return 0;
		}
		i++;
	}
}



//obtener columna y guardarla en un arreglo con el formatoCSR:

int *ObtenerColumnaCSR(tipoVectorCSR vec, int poscolumn, int filas,int n){
	
	int a = 0;
	int *columna = (int *)malloc(filas * sizeof(int));
	
	for (int j = 0; j < n; j++){
		if(vec.columna[j] == poscolumn){
			columna[a] = vec.valor[j];
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

//obtener columna y guardarla en una lista con el formato CSR:

tipoListaSimple *crearNodoSimple(int elemento){
	tipoListaSimple *nodito;
	nodito = (tipoListaSimple *)malloc(sizeof(tipoListaSimple));
	nodito -> siguiente = NULL;
	nodito -> valor = elemento;
	return nodito;

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


tipoListaSimple *ObtenerColCSR(tipoListaSimple *lista,tipoVectorCSR vec, int poscolumn, int filas){
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


//obtener columna dispersa CSR

tipoVectorCSR ObtenerColumnaDisCSR(tipoMatriz **matrix, int filas, int column, int poscolumn){
	
	tipoVectorCSR vec;
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


void ImprimirVectorColumnDisCSR(tipoVectorCSR vector, int filas){
	
	printf("\nColumna dispersa obtenida(vector): ");
	for(int i = 0; i < filas; i++){
			printf("<%d>", vector.valor[i]);
	}
	printf("\n");
}

//obtiene la cantidad de valores distintos de 0 en la matrizS

int obtenerNumElementosCSR(tipoVectorCSR vec){
	int i = 0;
	while(vec.valor[i] > 0 && vec.valor[i] < 100){
		i++;
	}

	return i;
	
}

//suma dos matrices en el formatoCSR:

tipoVectorCSR SumarMatricesCSR(tipoMatriz **A, tipoVectorCSR VecA, tipoVectorCSR VecB, int filas, int columnas){
	
	tipoVectorCSR r = llenarVectorCSR(A,filas,columnas);
	int i = 0;
	while(VecA.valor[i] != -1){
		
		r.valor[i] = VecA.valor[i] + VecB.valor[i];
		i++;
	
	}
	
	return r;
}



int main(int argc, char *argv[]){
	int filas = atoi(argv[1]);
	int column = atoi(argv[2]);
	
	tipoMatriz **m = crearMatriz(filas,column);
	m = llenarDeCeros(m,filas,column);
	printf("\n");
	printf("MATRIZ DISPERSA: ");
	printf("\n");
	m = AsignarValores(m,filas,column);
	imprimir(filas,column,m);
	
	
	tipoVectorCSR VecCsr = llenarVectorCSR(m, filas, column);
	imprimirVecCSR(filas, VecCsr);

	//operaciones del TAD
	printf("\n");
	printf("\n");
	printf("---- OPERACIONES DEL TAD ---- ");
	printf("\n");
	
	int n = filas * column;
	int poscolumn = 1;
	
	
	//obtener elemento VectorCSR:
	int e = 47;
	int elemento = ObtenerElementoVecCSR(VecCsr,e);
	printf("\nelemento obtenido: %d\n",elemento);
	//obtener columna y guardarla en un arreglo:
	
	int *columna = ObtenerColumnaCSR(VecCsr, poscolumn, filas,n);
	ImprimirVectorColumnas(columna, filas);
	
	//Obtener columna y guardarla en una lista:
	
	tipoListaSimple *listaC = NULL;
	listaC = ObtenerColCSR(listaC,VecCsr,poscolumn,filas);
	imprimirListaSimple(listaC);
	
	
	//obtener columna dispersa(arreglo):
	
	tipoVectorCSR VecDisCSR = ObtenerColumnaDisCSR(m,filas,column,poscolumn);
	ImprimirVectorColumnDisCSR(VecDisCSR, filas);
	
	//obtener el numero de elemento distintos de 0 que contiene una matriz dispersa CSR:
	
	int cantidad = obtenerNumElementosCSR(VecCsr);
	printf("\nnumero de elementos: %d\n", cantidad);
	/*
	//dispersa 2:
		
	tipoMatriz **A = crearMatriz(filas,column);
	A = llenarDeCeros(A,filas,column);
	A = AsignarValores(A,filas,column);
	imprimir(filas,column,A);
	tipoVectorCSR  VecA = llenarVectorCSR(A, filas, column);
	
	
	//Suma de matrices:
	printf("\n");
	printf("\n");
	printf("SUMAR DOS MATRICES DISPERSAS: \n");
	printf("\n");
	tipoVectorCSR resultado = SumarMatricesCSR( A, VecA,  VecCsr,  filas, column);
	imprimirVecCSR(filas,resultado);
	*/
	return 0;
}