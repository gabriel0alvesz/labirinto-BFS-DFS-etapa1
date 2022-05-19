#ifndef LISTA_H 
#define LISTA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAXTAM 100

typedef struct ItemLista{
	int val;
	char *str;
}ItemLista;

typedef struct Lista{
	ItemLista vetLista[MAXTAM+1];
	int first;
	int atual;
	int last;
}Lista;


void FLVazia(Lista *l);
void LInsert(Lista *l, ItemLista d);
void LRemove(Lista *l, ItemLista d);
void Swap(ItemLista *a, ItemLista *b);
void LImprime(Lista *l);

#endif