/*
 * Autores: German, Alejo y Cami
 * Fecha de creación: 2 de Mayo
 * Fecha última modificación: 3 de Junio
 * Versión: 1.2
 * 
 * Archivo Proyecto Matriz Dispersa
 */


#ifndef __PROYECTO_H
#define __PROYECTO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Matriz{
	int info;
	int posx;
	int posy;
};
typedef struct Matriz tipoMatriz;

struct VectorCordenado{
	int valor[50];
	int filas[50];
	int columna[50];
};
typedef struct VectorCordenado tipoVectorCor;

struct VectorCSR{
	int valor[50];
	int cfilas[50];
	int columna[50];
	
};
typedef struct VectorCSR tipoVectorCSR;


struct listaSimple{
	int valor;
	struct listaSimple *siguiente;
	
};
typedef struct listaSimple tipoListaSimple;


struct lista{
	int valor;
	int columna;
	struct lista *siguiente;
	
};
typedef struct lista tipoLista;

struct vectorL{
	tipoLista veclis[50];
};
typedef struct vectorL tipoVecLis;

tipoMatriz **crearMatriz(int filas, int column);

tipoMatriz **AsignarValores(tipoMatriz **matrix, int filas, int column);

tipoMatriz **llenarmatrix(tipoMatriz **matrix, int filas, int column);

tipoMatriz **llenarDeCeros(tipoMatriz **matrix, int filas, int column);

tipoMatriz **crearDeMatrizCompleta(tipoMatriz **matrix, int filas, int column,int t);

tipoMatriz **obtenerMatrizCompleta(tipoMatriz **dispersa, int filas, int column);

void imprimir(int filas, int column, tipoMatriz **matrix);

tipoVectorCor llenarVectorCor(tipoMatriz **matrix, int filas, int column);

tipoVectorCSR llenarVectorCSR(tipoMatriz **matrix, int filas, int column);

tipoLista *CrearNodo(int valor, int columna);

void imprimirLista(tipoLista *lis);

void imprimirVecCSR(int filas, tipoVectorCSR Vec);

int ObtenerElementoVec(tipoVectorCor Vec,int fila, int column,int n);

//int ObtenerElementoVecCSR();

//int ObtenerElementoVecLis();

int *ObtenerFilaVC(tipoVectorCor veCoor, int posfila, int column,int n);

void ImprimirVectorFilas(int *vector, int column);

tipoListaSimple *ObtenerFilaL(tipoListaSimple *lista,tipoVectorCor vec,int posfila, int column);

int *ObtenerColumnaVC(tipoVectorCor veCoor, int poscolumn, int filas,int n);

void ImprimirVectorColumnas(int *vector, int filas);

tipoListaSimple *ObtenerColumnaL(tipoListaSimple *lista, tipoVectorCor vec, int poscolumn, int filas);

void imprimirListaSimple(tipoListaSimple *lista);

tipoVectorCor ObtenerFilaDisF(tipoMatriz **matrix, int filas, int column, int posfila);

void ImprimirVectorFilasDisF(tipoVectorCor vector, int column);

tipoVectorCor ObtenerColumnaDis(tipoMatriz **matrix, int filas, int column, int poscolumn);

void ImprimirVectorColumnDis(tipoVectorCor vector, int filas);

int obtenerNumElementos(tipoVectorCor vec);

tipoVectorCor modificarPosCor(tipoVectorCor Vec,int x, int y, int n, int filas);

tipoVectorCor SumarMatrices(tipoMatriz **A, tipoVectorCor VecA,tipoVectorCor VecB, int filas, int columnas);

tipoVectorCor transpuesta(tipoVectorCor a, int filas, int columnas);

int *ObtenerColumnaCSR(tipoVectorCSR vec, int poscolumn, int filas,int n);

tipoListaSimple *ObtenerColCSR(tipoListaSimple *lista,tipoVectorCSR vec, int poscolumn, int filas);

tipoVectorCSR ObtenerColumnaDisCSR(tipoMatriz **matrix, int filas, int column, int poscolumn);

void ImprimirVectorColumnDisCSR(tipoVectorCSR vector, int filas);

int obtenerNumElementosCSR(tipoVectorCSR vec);

tipoVectorCSR SumarMatricesCSR(tipoMatriz **A, tipoVectorCSR VecA, tipoVectorCSR VecB, int filas, int columnas);

int ObtenerElementoVecCSR(tipoVectorCSR Vec,int e);

#endif

