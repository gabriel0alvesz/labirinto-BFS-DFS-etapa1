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
	for(int j=s->topo-1; j>=s->base; j--) {
        LImprime(&s->vLista[j]);
    }
	printf("\n");
}
/*

void POPLAB(Labirinto *s, ItemLab **d){
	if(s->base == s->topo)
		printf("LABIRINTO VAZIO!\n");
	else{
		s->topo --;
		*d = s->vetLab[s->topo];
	}
}

void LabirintoRemove(Labirinto *s, ItemLab *d){
	Labirinto aux;
	ItemLab *rem;

	FLabirintoVazio(&aux);

	if(s->base == s->topo)
		printf("LABIRINTO VAZIO!\n");
	else{
		while(s->topo > s->base){
			POPLAB(s, &rem);
			if(rem->val != d->val)
				PUSHLAB(&aux, rem);
		}

		while(aux.topo > aux.base){
			POPLAB(&aux, &rem);
			PUSHLAB(s, rem);
		}
	}
}


*/


