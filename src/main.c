#include "labirinto.h"
#include "fila.h"
#include <stdbool.h>

int Menu(){
    int opcao;

    printf("Menu: \n");
    printf("1 - DFS \n");
    printf("2 - DFS \n");
    printf("3 - DFS \n");
    printf("4 - DFS \n");
    printf("0 - SAIR \n");
    scanf("%d", &opcao);
    return(opcao);
}

int main() {
    int opcao = -1;
    int op;

    while (opcao != 0) {
        opcao = Menu();
     
    switch (opcao) {
    case 1:
        op = 1;
        break;

    case 2:
         op = 2;
        break;

    case 3:
         op = 3;
    break;

    case 4:
        op = 4;
    break;

    case 0:
        return 0;

    default:
        printf("Opcao invalida\n");
        op = -1;
        break;
    }

    if(op != -1){

    int **vetor;
    vetor = lerEntrada(vetor, op);
//    int tam = sizeof(vetor) / sizeof(vetor[0]); //Para usar tenho que definir a matriz[X][Y].
    int tam = TAMVETOR;
    char *str = malloc(100);


    Labirinto lab;
    Lista l;

    ItemLista itemLista;

    FLabirintoVazio(&lab);

    for (int i = tam - 1; i >= 0; i--) {
        FLVazia(&l);

        for (int j = 0; j < tam; j++) {
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

    if(vetor[i][j] == 0)
        vetor[i][j] = ++cont;
    else {
        printf("Primeira posicao do vetor impossibilita os testes\n");
        return 0;
    }

    int soma=0;
    
    POPLAB(&lab, &listaAux);
    PUSHLAB(&labAux, listaAux);

    while(i < linha && j < coluna) {
        soma++;

        if(!(itemPilha.val_I == i && itemPilha.val_J == j)) {
            itemPilha.val_I = iA;
            itemPilha.val_J = jA;
            PUSH(&p, itemPilha);
        }
        
        if(i == 0) { // ========== 1 ==========
            if(j < (coluna - 1) && vetor[i][j + 1] == 0) {
                vetor[i][j + 1] = ++cont;
                jA = j;
                j++;
            }
            else if(vetor[i + 1][j] == 0) {
                vetor[i + 1][j] = ++cont;
                iA = i;
                i++;
            } else {
                POP(&p, &itemPilha);

                i = itemPilha.val_I;
                j = itemPilha.val_J;
            }
        } 
        
        else if(i == linha - 1) { // ========== 2 ==========
            jA = j;
            iA = i;

            if(vetor[i][j + 1] == 0) {
                vetor[i][j + 1] = ++cont;
                j++;
            } else {
                i--;
            }
        } 

        else if(j == 0) { // ========== 3 ==========
            iA = i;
            jA = j;

            if(vetor[i + 1][j] == 0) {
                vetor[i + 1][j] = ++cont;
                i++;
            } else if(vetor[i][j + 1] == 0) {
                vetor[i][j + 1] = ++cont;
                j++;
            }
            else if(vetor[i - 1][j] == 0) {
                vetor[i - 1][j] = ++cont;
                i--;
            }
            else {
                POP(&p, &itemPilha);

                i = itemPilha.val_I;
                j = itemPilha.val_J;
            }
        } 
        
        else if(j == coluna - 1) { // ========== 4 ==========
            iA = i;
            jA = j;

            if(vetor[i + 1][j] == 0) {
                vetor[i + 1][j] = ++cont;
                i++;
            } else if(vetor[i][j - 1] == 0) {
                vetor[i][j - 1] = ++cont;
                j--;
            }
            else if(vetor[i - 1][j] == 0) {
                vetor[i - 1][j] = ++cont;
                i--;
            }
            else {
                POP(&p, &itemPilha);

                i = itemPilha.val_I;
                j = itemPilha.val_J;
            }
        } else { // ========== 5 ==========
            iA = i;
            jA = j;

            if(vetor[i + 1][j] == 0) {
                vetor[i + 1][j] = ++cont;
                i++;
            } else if(vetor[i][j + 1] == 0) {
                vetor[i][j + 1] = ++cont;
                j++;
            } else if(vetor[i][j - 1] == 0) {
                vetor[i][j - 1] = ++cont;
                j--;
            }
            else if(vetor[i - 1][j] == 0) {
                vetor[i - 1][j] = ++cont;
                i--;
            }
            else {
                POP(&p, &itemPilha);

                i = itemPilha.val_I;
                j = itemPilha.val_J;
            }
        }

        if(i == linha - 1 && j == coluna -1) {
            if(vetor[i][j] == 0)
                vetor[i][j] = ++cont;
            break;
        }
    }

    for(i=0; i < tam; i++) {
        for(j=0; j < tam; j++) {
            printf("%d\t", vetor[i][j]);
        }
        printf("\n");
    }

    printf("Iteracoes: %d\n", soma);
    }
    }
    
    return 0;
}
