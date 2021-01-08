<h1> Algoritmo de Kruskal </h1>

<b>Conceito</b><p align="justify">É um algoritmo em teoria dos grafos que busca uma árvore geradora mínima para um grafo conexo com pesos. Isto significa que ele encontra um subconjunto das arestas que forma uma árvore que inclui todos os vértices, onde o peso total, dado pela soma dos pesos das arestas da árvore, é minimizado. Foi publicado por Joseph Kruskal, em 1956. 
O algoritmo de Kruskal faz crescer uma floresta geradora até que ela se torne conexa.  A floresta cresce de modo a satisfazer o critério de minimalidade de MSTs baseado em circuitos.</p>

<b>Como utilizar o algoritmo desenvolvido</b>

Para utilizar, basta escolher o número de vértices, por exemplo v = 6 e inserir a matriz de adjacência, por exemplo:

0 3 1 6 0 0 <br />
3 0 5 0 3 0 <br />
1 5 0 5 6 4 <br />
6 0 5 0 0 2 <br />
0 3 6 0 0 6 <br />
0 0 4 2 6 0 <br /> 

Daí, o algoritmo irá criar a árvore geradora com peso mínimo.
