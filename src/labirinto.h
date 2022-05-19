#ifndef LABIRINTO_H 
#define LABIRINTO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "pilha.h"
#include "lista.h"

#define TAMVETOR 6
#define MAXTAM 100

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
void POPLAB(Labirinto *s, Lista *l);

int **lerEntrada(int **matriz, int Inteiro);
void tokenizar(char *str, int **matriz, int contador);

/*
void LabirintoRemove(Labirinto *s, ItemLab *d);
*/

#endif