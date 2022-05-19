#include "labirinto.h"
#include "fila.h"
#include <stdbool.h>

int Menu();

int main() {
    int opcao = -1;

    while (opcao != 0) {
        opcao = Menu();

        if(opcao > 0 && opcao <= 6) {
            printf("Fazendo com BFS:\n");
            FazBFS(opcao); 
            printf("\nFazendo com DFS:\n");
            FazDFS(opcao);
        } else if(opcao == 0)
            break; 
        else {
            printf("Opcao invalida\n");
        }
    }
    return 0;
}

int Menu() {
    int opcao;

    printf("Menu BFS - DFS: \n");
    printf("1 - BFS - DFS - Entrada 1\n");
    printf("2 - BFS - DFS - Entrada 2\n");
    printf("3 - BFS - DFS - Entrada 3\n");
    printf("4 - BFS - DFS - Entrada 4\n");
    printf("5 - BFS - DFS - Entrada 5\n");
    printf("6 - BFS - DFS - Entrada 6\n");

    printf("0 - SAIR \n");
    scanf("%d", &opcao);
    return (opcao);
}
