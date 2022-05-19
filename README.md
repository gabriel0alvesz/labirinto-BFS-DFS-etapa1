# Labirinto utilizando BFS e DFS
## Introdução
<p align="justify">
  Para a resolução do problema do labirinto, que consiste em criar uma matriz quadrada NxN e marcar obstáculos do labirinto. O algoritmo deve caminhar pela matriz, saindo da posição (0,0) e tendo "END GAME" na posição NxN. No caso do código fonte disponibilizado, trabalhamos com entradas de matrizes com tamanho 6x6. Para a solução utilizamos estruturas básicas nos respectivos repositórios, <a href = "https://github.com/mpiress/dynamic_list">Lista Dinâmica</a>, <a href = "https://github.com/mpiress/dynamic_stack">Pilha Dinâmica</a>, <a href = "https://github.com/mpiress/dynamic_queue">Fila Dinâmica</a> do professor <a href ="https://github.com/mpiress">Michel Pires</a>.<br>
   BFS - BREADTH FIRST SEARCH. Utiliza Fila, cujo o primeiro elemento a entrar é o primeiro elemento a sair.<br>
   DFS - DEPTH FIRST SEARCH. Utiliza Pilha em dois estágios.
</p>

## Lógica
<p align="justify">
  O desenvolvimento se baseia em 3 etapas:
  <ol>
    <li> Leitura dos dados das matrizes</li>
    <li> Execução do BFS com a respectiva entrada</li>
    <li> Execução do DFS com a respectiva entrada</li>
</ol>
  1. A leitura das matrizes são feitas nos arquivos chamados entradaX.txt (X indo de 1 a 6). <br>
  2. O algoritmo BFS foi desenvolvido utilizando Fila dinâmica. Utilizando as funções Enfileira e Desenfileira para execução lógica.<br>
  3. O algoritmo DFS foi desenvolvido utilizando Pilha Dinâmica. Utilizando as funções PUSH e POP para execução lógica.
</p>

## Imagens e Exemplos

### Menu Inicial
<p align="left">
  <img src="imgs/menu.PNG"></img>
</p>

### Main
<p align="center">
  <img src="imgs/main.PNG"></img>
</p>

### Entradas
<p align="center">
  
  <img src="imgs/dados1.PNG" ></img>
  <img src="imgs/dados2.PNG"></img>
  <img src="imgs/dados3.PNG"></img>
  <br>
  <img src="imgs/dados4.PNG" ></img>
  <img src="imgs/dados5.PNG"></img>
  <img src="imgs/dados6.PNG"></img>
  
</p>

### Saídas
<p align="left">
  
  <img src="imgs/entrada1.PNG" ></img>
  <img src="imgs/entrada2.PNG"></img>
  <br>
</p>

#### Entrada Inválida
<p align="left">
  <img src="imgs/entradainvalida.PNG"></img>
</p>

# Conclusão
<p align="justify">
  Dados as execuções, foi avaliado conforme o número de iterações que o algoritmo DFS é mais rápido que o algoritmo BFS.
</p>


# Compilação e Execução

Makefile realiza o procedimento de compilação e execução.

|Comando| Funcao|
|----|----|
|`make clean`|Limpa tudo|
|`make r`|Executa a compilação utilizando gcc e executa o programa da pasta build após a realização da compilação.|
