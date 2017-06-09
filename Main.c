#include "coordenado.c"


int main(int argc, char *argv[]){
	int filas = atoi(argv[1]);
	int column = atoi(argv[2]);
	
	//MATRIZ COMPLETA:
	tipoMatriz **matrix = crearMatriz(filas,column);
	matrix = llenarmatrix(matrix,filas,column);
	printf("\n");
	printf("MATRIZ COMPLETA: ");
	printf("\n");
	imprimir(filas,column,matrix);
	
	//PRIMERA OPERACION, CREAR INSTANCIA DE DISPERSA A PARTIR DE UNA MATRIZ COMPLETA:
	int columnD = 2 * column;
	
	tipoMatriz **disper = crearDeMatrizCompleta(matrix,filas,columnD,column);
	printf("\n");
	printf("MATRIZ DISPERSA: ");
	printf("\n");
	imprimir(filas,columnD,disper);
	
	/*
	//SI SE DESEA CREAR UNA MATRIZ DISPERSA DIRECTAMENTE:
	tipoMatriz **disper = crearMatriz(filas,column);
	disper = llenarDeCeros(disper,filas,column);
	disper = AsignarValores(disper,filas,column);
	imprimir(filas,column,disper);
	*/
	
	//SEGUNDA OPERACION,OBTENER MATRIZ COMPLETA DE UNA MATRIZ DISPERSA
	printf("\n");
	printf("MATRIZ COMPLETA: ");
	printf("\n");
	//tipoMatriz **completa = obtenerMatrizCompleta(disper,filas, column);//usar solo con matriz directa	
	tipoMatriz **completa = obtenerMatrizCompleta(disper,filas, columnD);
	imprimir(filas,column,completa);
	
	
	//FORMATO VECTOR COORDENADO:
	
	// NOTA: LOS VECTORES SE LLENAN CON RESPECTO A LA MATRIZ DISPERSA:
	
	//tipoVectorCor  Vec = llenarVectorCor(disper, filas, column);//usar solo con matriz directa
	
	tipoVectorCor  Vec = llenarVectorCor(disper, filas, columnD);
	imprimirV(filas, Vec);
	
		
	//OPERACIONES DEL TAD MATRIZ DISPERSA: 
	
	//obtener elemento Vector Coordenado:
	int posfila = 2;
	int poscolumn = 2;
	int n = filas*column;
	int elemento = ObtenerElementoVec(Vec,posfila,poscolumn,n);
	printf("\nelemento obtenido: %d\n",elemento);
	
		
	//obtener fila y guardarla en un arreglo:
	int *fila = ObtenerFilaVC(Vec, posfila, column,n);
	ImprimirVectorFilas(fila, column);
	
	//obtener fila y guardarla en una lista:
	
	tipoListaSimple *listaF = NULL;
	listaF = ObtenerFilaL(listaF,Vec,posfila,column);
	imprimirListaSimple(listaF);
	
	//obtener columna y guardarla en un arreglo:
	int *columna = ObtenerColumnaVC(Vec, poscolumn, filas,n);
	ImprimirVectorColumnas(columna, filas);
	
	//Obtener columna y guardarla en una lista:
	
	tipoListaSimple *listaC = NULL;
	listaC = ObtenerColumnaL(listaC,Vec,poscolumn,filas);
	imprimirListaSimple(listaC);
	
	//obtener fila dispersa(arreglo):
	
	tipoVectorCor VecDisF = ObtenerFilaDis(disper,filas,column,posfila);
	ImprimirVectorFilasDis(VecDisF,column);
	
	//obtener columna dispersa(arreglo):
	
	tipoVectorCor VecDisC = ObtenerColumnaDis(disper,filas,column,poscolumn);
	ImprimirVectorColumnDis(VecDisC, filas);
	
	//obtener el numero de elemento distintos de 0 que contiene una matriz dispersa:
	
	int cantidad = obtenerNumElementos(Vec);
	printf("\nnumero de elementos: %d\n", cantidad);
	
	//modificar Posicion:
	
	Vec = modificarPosCor(Vec, 0, 1, 8,filas);
	printf("\n----- VECTOR MODIFICADO --------: \n");
	imprimirV(filas, Vec);
	
	
	//Sumar Matrices:
	
	printf("=======================================================================\n");
	printf("              SUMA - PRODUCTO MATRIZ - TRANSPUESTA\n");
	printf("=======================================================================");
	printf("\n");
	printf("\n");
			//dispersa 2:
		
	tipoMatriz **A = crearMatriz(filas,column);
	A = llenarDeCeros(A,filas,column);
	A = AsignarValores(A,filas,column);
	imprimir(filas,column,A);
	tipoVectorCor  VecA = llenarVectorCor(A, filas, column);
	
	
			//Operaciones:
	
	printf("\n");
	printf("SUMAR DOS MATRICES DISPERSAS: \n");
	tipoVectorCor resultado = SumarMatrices( A, VecA,  Vec,  filas, column);
	imprimirV(filas,resultado);
	printf("\n");
	printf("TRANSPUESTA: \n");
	printf("\n");
	tipoVectorCor t = transpuesta(VecA,filas,column);
	imprimirV(filas,t);
	
}
