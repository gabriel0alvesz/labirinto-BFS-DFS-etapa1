#include "labirinto.h"

void FLabirintoVazio(Labirinto *s){
	s->topo   = 0;
	s->base  = 0;
}

void PUSHLAB(Labirinto *s, Lista l){
    ItemLista item;

	if (s->topo >= MAXTAM){
		printf("LABIRINTO CHEIO!\n");
	}else{
        FLVazia(&s->vLista[s->topo]);

        for(int i=l.first; i<l.last; i++) {
            item.val = l.vetLista[i].val;
            LInsert(&s->vLista[s->topo], item);
        }
		s->topo ++;
	}
}

void LabirintoImprime(Labirinto *s){
	if(s->base == s->topo)
		printf("LABIRINTO VAZIO!\n");
	for(int j=s->topo-1; j>=s->base; j--) {
        LImprime(&s->vLista[j]);
    }
	printf("\n");
}

void POPLAB(Labirinto *s, Lista *l){
	if(s->base == s->topo)
		printf("LABIRINTO VAZIO!\n");
	else{
		s->topo --;
		*l = s->vLista[s->topo];
	}
}