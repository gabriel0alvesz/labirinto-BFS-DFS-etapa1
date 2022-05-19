#ifndef PILHA_H 
#define PILHA_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXTAM 100

typedef struct ItemPilha{
	int val;
	int val_I;
	int val_J;
}ItemPilha;

typedef struct Pilha{
	ItemPilha vet[MAXTAM];
	int top;
	int base;
}Pilha;

void FPVazia(Pilha *p);
void PUSH(Pilha *p, ItemPilha d);
void POP(Pilha *p, ItemPilha *d);
void PRemove(Pilha *p, ItemPilha d);
void PImprime(Pilha *p);

#endif