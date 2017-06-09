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


void imprimirLista(tipoLista *lst){
	tipoLista *p  = lst;
	while(p != NULL){
		printf("\n<%d>:<%d>\n",p->valor, p->columna);
		p = p -> siguiente;
	}

}


tipoLista *CrearNodo(int val, int column){
	tipoLista *nodito;
	nodito = (tipoLista *)malloc(sizeof(tipoLista));
	nodito -> siguiente = NULL;
	nodito -> valor = val;
	nodito -> columna = column;
	return nodito;
	
}


tipoLista *adicionarLista(int valor,int column, tipoLista *lst){
	tipoLista *tmpNodo = CrearNodo(valor,column);
	tipoLista *p;
	if(lst == NULL){
		lst = tmpNodo;

	}
	else{
		p = lst;
		while(p -> siguiente != NULL){
			p = p -> siguiente;
		
		}
		p -> siguiente = tmpNodo;
	}
	return lst;
}


tipoLista *crearLista(tipoMatriz **matrix, int filas, int column){
	
	tipoLista *lst = NULL;
	for (int i = 0; i < filas; i++){	
		for (int j = 0; j < column; j++){
			if(matrix[i][j].info != 0){
				lst = adicionarLista(matrix[i][j].info,matrix[i][j].posx, lst);
				
			}
			
		}
	}
	return lst;
	
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
	
		
	  
	tipoLista *lista = NULL;
	lista = crearLista(m,filas,column);
	imprimirLista(lista);
	
	
	
	return 0;
	
}