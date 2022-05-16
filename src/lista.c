#include "lista.h"

void Swap(ItemLista *a, ItemLista *b){
	ItemLista aux;
	aux = *a;
	*a  = *b;
	*b  = aux;
}

void FLVazia(Lista *l){
	l->first = 0;
	l->last  = 0;
}

void LInsert(Lista *l, ItemLista d){
	if (l->last >= MAXTAM){
		printf("LISTA CHEIA!\n");
	}else{
		l->vetLista[l->last] = d;
		l->last ++;
	}
}

void LRemove(Lista *l, ItemLista d){
	bool ok = false;

	if(l->first == l->last)
		printf("LISTA VAZIA!\n");
	else{
		for(int i=l->first; i<l->last; i++)
			if(l->vetLista[i].val == d.val){
				Swap(&l->vetLista[i], &l->vetLista[i+1]);
				ok = true;	
			}
	
		if(ok)
			l->last --;
	}
}


void LImprime(Lista *l){
	for(int i=l->first; i<l->last; i++)
		printf("%d\t", l->vetLista[i].val);
	printf("\n");
}






