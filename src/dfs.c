#include "labirinto.h"
#include "fila.h"

void FazDFS(int op) {
    int **vetor;
    vetor = lerEntrada(vetor, op);
    //    int tam = sizeof(vetor) / sizeof(vetor[0]); //Para usar tenho que definir a matriz[X][Y].
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

        POPLAB(&lab, &listaAux);
        PUSHLAB(&labAux, listaAux);

        int aux_i = 0, aux_j = 0;

        while (i < linha && j < coluna)
        {
            soma++;
            aux_i = i;
            aux_j = j;

            if (!(itemPilha.val_I == i && itemPilha.val_J == j))
            {
                itemPilha.val_I = iA;
                itemPilha.val_J = jA;
                PUSH(&p, itemPilha);
            }

            if (i == 0)
            { // ========== 1 ==========
                if (j < (coluna - 1) && vetor[i][j + 1] == 0)
                {
                    vetor[i][j + 1] = ++cont;
                    jA = j;
                    j++;
                }
                else if (vetor[i + 1][j] == 0)
                {
                    vetor[i + 1][j] = ++cont;
                    iA = i;
                    i++;
                }
                else
                {
                    POP(&p, &itemPilha);

                    i = itemPilha.val_I;
                    j = itemPilha.val_J;
                }
            }

            else if (i == linha - 1)
            { // ========== 2 ==========
                jA = j;
                iA = i;

                if (vetor[i][j + 1] == 0)
                {
                    vetor[i][j + 1] = ++cont;
                    j++;
                }
                else if (vetor[i - 1][j] == 0)
                {
                    vetor[i - 1][j] = ++cont;
                    i--;
                }
                else
                {
                    POP(&p, &itemPilha);

                    i = itemPilha.val_I;
                    j = itemPilha.val_J;
                }
            }

            else if (j == 0)
            { // ========== 3 ==========
                iA = i;
                jA = j;

                if (vetor[i + 1][j] == 0)
                {
                    vetor[i + 1][j] = ++cont;
                    i++;
                }
                else if (vetor[i][j + 1] == 0)
                {
                    vetor[i][j + 1] = ++cont;
                    j++;
                }
                else if (vetor[i - 1][j] == 0)
                {
                    vetor[i - 1][j] = ++cont;
                    i--;
                }
                else
                {
                    POP(&p, &itemPilha);

                    i = itemPilha.val_I;
                    j = itemPilha.val_J;
                }
            }

            else if (j == coluna - 1)
            { // ========== 4 ==========
                iA = i;
                jA = j;

                if (vetor[i + 1][j] == 0)
                {
                    vetor[i + 1][j] = ++cont;
                    i++;
                }
                else if (vetor[i][j - 1] == 0)
                {
                    vetor[i][j - 1] = ++cont;
                    j--;
                }
                else if (vetor[i - 1][j] == 0)
                {
                    vetor[i - 1][j] = ++cont;
                    i--;
                }
                else
                {
                    POP(&p, &itemPilha);

                    i = itemPilha.val_I;
                    j = itemPilha.val_J;
                }
            }
            else
            { // ========== 5 ==========
                iA = i;
                jA = j;

                if (vetor[i + 1][j] == 0)
                {
                    vetor[i + 1][j] = ++cont;
                    i++;
                }
                else if (vetor[i][j + 1] == 0)
                {
                    vetor[i][j + 1] = ++cont;
                    j++;
                }
                else if (vetor[i][j - 1] == 0)
                {
                    vetor[i][j - 1] = ++cont;
                    j--;
                }
                else if (vetor[i - 1][j] == 0)
                {
                    vetor[i - 1][j] = ++cont;
                    i--;
                }
                else
                {
                    POP(&p, &itemPilha);

                    i = itemPilha.val_I;
                    j = itemPilha.val_J;
                }
            }

            if(aux_i == i && aux_j == j) {
                printf("impossivel chegar no caminho final\n");
                return;
            }

            if (i == linha - 1 && j == coluna - 1)
            {
                if (vetor[i][j] == 0)
                    vetor[i][j] = ++cont;
                break;
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