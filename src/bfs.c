#include "labirinto.h"
#include "fila.h"

void FazBFS(int op){
    Fila f;
    FFVazia(&f);

    ItemFila itemFila;

    int **vetor;
    vetor = lerEntrada(vetor, op);
    int tam = TAMVETOR;
    char *str = malloc(100);

    Labirinto lab;
    Lista l;

    ItemLista itemLista;

    FLabirintoVazio(&lab);

    for (int i = tam - 1; i >= 0; i--)
    {
        FLVazia(&l);

        for (int j = 0; j < tam; j++)
        {
            itemLista.val = vetor[i][j];

            LInsert(&l, itemLista);
        }
        PUSHLAB(&lab, l);
    }

    ItemLab itemLab;
    Lista listaAux;
    FLVazia(&listaAux);

    Labirinto labAux;
    FLabirintoVazio(&labAux);

    Pilha p;
    ItemPilha itemPilha;
    itemPilha.val_I = 0;
    itemPilha.val_J = 0;

    FPVazia(&p);

    int i, j, iA, jA, cont;
    int linha, coluna;

    i = j = iA = jA = cont = 0;
    linha = coluna = tam;

    if (vetor[i][j] == -1 || vetor[tam - 1][tam - 1] == -1)
    {
        printf("Primeira ou ultima posicao do vetor impossibilita os testes\n");
    }
    else
    {

        if (vetor[i][j] == 0)
            vetor[i][j] = ++cont;

        int soma = 0;
        int bkp_i;
        int bkp_j;

        while (i < linha && j < coluna)
        {
            bkp_i = i;
            bkp_j = j;
            soma++;

            if (i == 0) { // ========== 1 ==========
                if (j < (coluna - 1) && vetor[i][j + 1] == 0)
                {
                    vetor[i][j + 1] = ++cont;
                    jA = j + 1;
                    itemFila.i_aux = bkp_i;
                    itemFila.j_aux = jA;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i + 1][j] == 0)
                {
                    vetor[i + 1][j] = ++cont;
                    iA = i + 1;

                    itemFila.i_aux = iA;
                    itemFila.j_aux = bkp_j;
                    Enfileira(&f, itemFila);
                }
            }

            else if (i == linha - 1) { // ========== 2 ==========
               
                if (vetor[i][j + 1] == 0)
                {
                    vetor[i][j + 1] = ++cont;
                    jA = j + 1;
                    itemFila.i_aux = bkp_i;
                    itemFila.j_aux = jA;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i - 1][j] == 0)
                {
                    vetor[i - 1][j] = ++cont;
                    iA = i - 1;
                    itemFila.i_aux = iA;
                    itemFila.j_aux = bkp_j;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i][j - 1] == 0)
                {
                    vetor[i][j - 1] = ++cont;
                    jA = j - 1;
                    itemFila.i_aux = bkp_i;
                    itemFila.j_aux = jA;
                    Enfileira(&f, itemFila);
                }
            }

            else if (j == 0) { // ========== 3 ==========

                if (vetor[i + 1][j] == 0)
                {
                    vetor[i + 1][j] = ++cont;
                    iA = i + 1;
                    itemFila.i_aux = iA;
                    itemFila.j_aux = bkp_j;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i][j + 1] == 0)
                {
                    vetor[i][j + 1] = ++cont;
                    jA = j + 1;
                    itemFila.i_aux = bkp_i;
                    itemFila.j_aux = jA;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i - 1][j] == 0)
                {
                    vetor[i - 1][j] = ++cont;
                    iA = i - 1;
                }
            }

            else if (j == coluna - 1) { // ========== 4 ==========

                if (vetor[i + 1][j] == 0)
                {
                    vetor[i + 1][j] = ++cont;
                    iA = i + 1;
                    itemFila.i_aux = iA;
                    itemFila.j_aux = bkp_j;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i][j - 1] == 0)
                {
                    vetor[i][j - 1] = ++cont;
                    jA = j - 1;
                    itemFila.i_aux = bkp_i;
                    itemFila.j_aux = jA;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i - 1][j] == 0)
                {
                    vetor[i - 1][j] = ++cont;
                    iA = i - 1;
                }
            }
            else { // ========== 5 ==========

                if (vetor[i + 1][j] == 0)
                {
                    vetor[i + 1][j] = ++cont;
                    iA = i + 1;
                    itemFila.i_aux = iA;
                    itemFila.j_aux = bkp_j;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i][j + 1] == 0)
                {
                    vetor[i][j + 1] = ++cont;
                    jA = j + 1;
                    itemFila.i_aux = bkp_i;
                    itemFila.j_aux = jA;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i][j - 1] == 0)
                {
                    vetor[i][j - 1] = ++cont;
                    jA = j - 1;
                    itemFila.i_aux = bkp_i;
                    itemFila.j_aux = jA;
                    Enfileira(&f, itemFila);
                }
                if (vetor[i - 1][j] == 0)
                {
                    vetor[i - 1][j] = ++cont;
                    iA = i - 1;
                    itemFila.i_aux = iA;
                    itemFila.j_aux = bkp_j;
                    Enfileira(&f, itemFila);
                }
            }

            if (i == linha - 1 && j == coluna - 1)
            {
                if (vetor[i][j] == 0)
                    vetor[i][j] = ++cont;
                break;
            }
            Desenfileira(&f, &itemFila);

            i = itemFila.i_aux;
            j = itemFila.j_aux;

            if(bkp_i == i && bkp_j == j) {
                printf("impossivel chegar no caminho final\n");
                return;
            }
        }

        for (i = 0; i < tam; i++)
        {
            for (j = 0; j < tam; j++)
            {
                printf("%d\t", vetor[i][j]);
            }
            printf("\n");
        }

        printf("Iteracoes: %d\n", soma);
    }
}