#include "labirinto.h"

int main(){

	int vetor[MAXTAM][MAXTAM] = {
		{0,  0,  0,  0},
		{0,  0, -1, -1},
		{0, -1,  0,  0},
		{0,  0,  0,  0}
	};

	int tam = sizeof(vetor)/sizeof(vetor[0]);
	
    int i = 0; 
    int j = 0;
	int linhas = tam;
	int colunas = tam;
	int cont = -2;
    vetor[i][j] = -1;

    while (i != linhas && j != colunas) // Percorrendo matriz pelos maiores valores
    {
        if (i < linhas - 1 && j == 0)
        {
            //if(vetor[i][j + 1] >= vetor[i + 1][j] && vetor[i][j + 1] != -1)
			if(vetor[i][j + 1] == 0)
            {
                //soma += vetor[i][j + 1];
                vetor[i][j + 1] = cont--;
                j++;
            }
            else if(vetor[i + 1][j] == 0)
            {
               // soma += vetor[i + 1][j];
                vetor[i + 1][j] = cont--;
                i++;
            }
        }
        else if (i < linhas - 1 && j == colunas - 1)
        {
            //if(vetor[i][j - 1] >= vetor[i + 1][j] && vetor[i][j - 1] != -1)
			if(vetor[i][j - 1] == 0)
            {
               // soma += vetor[i][j - 1];
                vetor[i][j - 1] = cont--;
                j--;
            }
            else if(vetor[i + 1][j] == 0)
            {
                //soma += vetor[i + 1][j];
                vetor[i + 1][j] = cont--;
                i++;
            }
        }
        else if(i == linhas - 1 && j < colunas - 1)
        {
           // soma += vetor[i][j+1];
            vetor[i][j+1] = cont--;
            j++;
        }
        else if(i == linhas - 1 && j == colunas - 1)
        {
            j++;
        }
        else if(i != linhas - 1 && j != colunas - 1)
        {
            //if(vetor[i][j - 1] > vetor[i + 1][j] && vetor[i][j - 1] > vetor[i][j + 1])
			if(vetor[i][j - 1] == 0)
            {
                //soma += vetor[i][j - 1];
                vetor[i][j - 1] = cont--;
                j--;
            }
            //else if(vetor[i + 1][j] > vetor[i][j - 1] && vetor[i + 1][j] > vetor[i][j + 1])
			else if(vetor[i + 1][j] == 0)
            {
                //soma += vetor[i + 1][j];
                vetor[i + 1][j] = cont--;
                i++;
            }
            else if(vetor[i][j + 1] == 0)
            {
                //soma += vetor[i][j + 1];
                vetor[i][j + 1] = cont--;
                j++;
            }
        }
    }
   // return soma;

	for(int i=0; i < tam; i++) {
		for(int j=0; j < tam; j++)
			printf("%d\t", vetor[i][j]);
		printf("\n");
	}

	return 0;


	printf("tam: %d\n", tam);

	Labirinto lab;
	Lista l;

	ItemLista itemLista;

	FLabirintoVazio(&lab);

	for(int i=tam-1; i >= 0; i--) {
		FLVazia(&l);

		for(int j=0; j < tam; j++) {
			itemLista.val = vetor[i][j];

			LInsert(&l, itemLista);
		}
		PUSHLAB(&lab, l);
	}
	LabirintoImprime(&lab);

	return 0;
}
