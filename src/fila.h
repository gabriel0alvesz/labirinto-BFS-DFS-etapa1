#ifndef FILA_H 
#define FILA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 100

typedef struct ItemFila{
	int val;
}ItemFila;

typedef struct Fila{
	ItemFila vet[MAXTAM];
	int first;
	int last;
}Fila;


void FFVazia(Fila *f);
void Enfileira(Fila *f, ItemFila d);
void Desenfileira(Fila *f, ItemFila *d);
void FRemove(Fila *f, ItemFila d);
void FImprime(Fila *f);

#endif