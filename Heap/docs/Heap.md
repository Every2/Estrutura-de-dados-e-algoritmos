# Heap

## Introdução

A heap é uma estrutura de dados fundamental usada para manter um conjunto de elementos com uma propriedade específica, como uma ordem de prioridade. Geralmente, é representada como uma árvore binária, onde cada nó pai tem um valor maior (em uma max-heap) ou menor (em uma min-heap) do que seus filhos. A estrutura de heap é comumente usada para implementar filas de prioridade e para solucionar problemas relacionados à ordenação, como o heapsort.

## Funções Principais

### 1. `insert(key)`

**Descrição:** Insere um elemento na heap.

**Parâmetros:**
- `key`: O valor a ser inserido na heap.

**Comportamento:**
- Insere o elemento `key` na heap de acordo com as regras da heap (max-heap ou min-heap).
- Reorganiza a heap para manter a propriedade da heap após a inserção.

### 2. `deleteRoot()`

**Descrição:** Remove e retorna o elemento de maior prioridade (max-heap) ou de menor prioridade (min-heap) da heap, que é o elemento na raiz da árvore.

**Retorno:**
- O elemento raiz removido.

**Comportamento:**
- Remove o elemento raiz da heap.
- Reorganiza a heap para manter a propriedade da heap após a remoção.

### 3. `heapifyUp(index)`

**Descrição:** Ajusta a heap após a inserção de um novo elemento, movendo-o para cima na árvore, se necessário.

**Parâmetros:**
- `index`: O índice do elemento recém-inserido.

**Comportamento:**
- Compara o elemento no índice `index` com seu pai na heap.
- Se o elemento for maior (max-heap) ou menor (min-heap) do que seu pai, troca os elementos e repete o processo até que a propriedade da heap seja restaurada.

### 4. `heapifyDown(index)`

**Descrição:** Ajusta a heap após a remoção do elemento raiz, movendo o novo elemento raiz para baixo na árvore, se necessário.

**Parâmetros:**
- `index`: O índice do elemento raiz após a remoção.

**Comportamento:**
- Compara o elemento no índice `index` com seus filhos na heap.
- Se o elemento for menor (max-heap) ou maior (min-heap) do que seus filhos, troca os elementos com o filho apropriado e repete o processo até que a propriedade da heap seja restaurada.

## Notas Adicionais

- A função `insert` adiciona um elemento à heap, enquanto a função `deleteRoot` remove o elemento de maior ou menor prioridade da heap, dependendo se é uma max-heap ou min-heap.
- As funções `heapifyUp` e `heapifyDown` são cruciais para manter a integridade da heap após inserções e remoções.
- Uma heap pode ser implementada como uma max-heap (onde o elemento de maior valor está na raiz) ou como uma min-heap (onde o elemento de menor valor está na raiz). A escolha depende dos requisitos específicos do problema.
- A complexidade de tempo típica para inserção e remoção em uma heap é O(log n), onde n é o número de elementos na heap.