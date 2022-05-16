#ifndef LABIRINTO_H 
#define LABIRINTO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "pilha.h"
#include "lista.h"


#define MAXTAM 4

typedef struct ItemLab{
	int val;
    
}ItemLab;

typedef struct Labirinto{
    Lista vLista[MAXTAM];
    
	int topo;
	int base;
}Labirinto;

void FLabirintoVazio(Labirinto *s);
void PUSHLAB(Labirinto *s, Lista l);
void LabirintoImprime(Labirinto *s);
/*
void POPLAB(Labirinto *s, ItemLab **d);
void LabirintoRemove(Labirinto *s, ItemLab *d);
*/

#endif