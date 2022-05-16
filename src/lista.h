#ifndef LISTA_H 
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 4

typedef struct ItemLista{
	int val;
}ItemLista;

typedef struct Lista{
	ItemLista vetLista[MAXTAM+1];
	int first;
	int last;
}Lista;


void FLVazia(Lista *l);
void LInsert(Lista *l, ItemLista d);
void LRemove(Lista *l, ItemLista d);
void Swap(ItemLista *a, ItemLista *b);
void LImprime(Lista *l);

#endif