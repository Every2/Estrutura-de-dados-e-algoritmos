# Documentação da Priority Queue (Fila de Prioridade)

## Introdução

Uma fila de prioridade (ou Priority Queue) é uma estrutura de dados que armazena elementos com uma prioridade associada e permite a recuperação e remoção do elemento de maior (ou menor) prioridade de forma eficiente. Ela é amplamente utilizada em algoritmos que requerem a ordenação de elementos com base em suas prioridades, como algoritmos de busca, ordenação e otimização.

## Funcionalidades Principais

Uma Priority Queue geralmente oferece as seguintes funcionalidades principais:

1. **Push (Inserir)**: Adiciona um elemento à fila de prioridade, associando a ele uma prioridade.

2. **Pop (Remover)**: Remove e retorna o elemento de maior (ou menor) prioridade da fila de prioridade.

3. **Peek (Consultar)**: Retorna o elemento de maior (ou menor) prioridade da fila de prioridade sem removê-lo.

4. **isEmpty (Verificar se está vazia)**: Verifica se a fila de prioridade está vazia.

5. **Size (Tamanho)**: Retorna o número de elementos na fila de prioridade.

## Implementações Comuns

Existem várias implementações possíveis para uma fila de prioridade, sendo as mais comuns:

1. **Heap (Árvore binária)**: Implementado como um heap binário (min-heap ou max-heap), onde o elemento de maior (ou menor) prioridade está sempre na raiz da árvore.

2. **Lista encadeada**: Implementado como uma lista encadeada ordenada ou não ordenada, onde a busca e a remoção do elemento de maior (ou menor) prioridade podem não ser tão eficientes quanto com um heap.
