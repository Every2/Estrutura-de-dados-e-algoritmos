# Fibonacci Heap

Um Heap de Fibonacci é uma estrutura de dados de fila de prioridade que oferece um tempo médio amortizado eficiente para operações como inserção, extração do mínimo e diminuição da chave. É uma das estruturas de dados mais eficientes para resolver algoritmos como o algoritmo de Dijkstra e o algoritmo de Prim.

## Overview

O Heap de Fibonacci é uma coleção de árvores (sub-heaps) que satisfazem algumas propriedades essenciais::

1. Cada árvore é uma árvore binomial.
2. Não existem duas árvores binomiais na coleção com o mesmo grau (número de filhos)..
3. A raiz de cada árvore binomial possui um valor menor ou igual aos valores de seus filhos.
4. Há no máximo uma árvore binomial de cada grau em um determinado momento.

A estrutura de dados do Heap de Fibonacci suporta as seguintes operações principais::

- **Inserção**: Adicionar um elemento à fila de prioridade.
- **Extração do Mínimo**: Remover e retornar o elemento com o valor mínimo na fila de prioridade.
- **Key Decrease**: Diminuir o valor de um elemento específico na fila de prioridade.
- **Exclusão**: Remover um elemento específico da fila de prioridade.