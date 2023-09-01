# Deque

## Introdução

Um Deque (Double-Ended Queue), também conhecido como fila de duas pontas, é uma estrutura de dados que permite a inserção e remoção eficiente de elementos tanto no início quanto no final da fila. É uma extensão das filas tradicionais (Queue) que permitem operações de inserção e remoção em ambas as extremidades.

## Funcionalidades Principais

Um Deque geralmente oferece as seguintes funcionalidades principais:

1. **Insert Front (Inserir na Frente)**: Adiciona um elemento na parte frontal do Deque.

2. **Insert Rear (Inserir na Parte de Trás)**: Adiciona um elemento na parte traseira do Deque.

3. **Delete Front (Remover na Frente)**: Remove e retorna o elemento da parte frontal do Deque.

4. **Delete Rear (Remover na Parte de Trás)**: Remove e retorna o elemento da parte traseira do Deque.

5. **Get Front (Obter Elemento da Frente)**: Retorna o elemento da parte frontal do Deque sem removê-lo.

6. **Get Rear (Obter Elemento da Parte de Trás)**: Retorna o elemento da parte traseira do Deque sem removê-lo.

7. **isEmpty (Verificar se Está Vazio)**: Verifica se o Deque está vazio.

8. **isFull (Verificar se Está Cheio)**: Verifica se o Deque está cheio (dependendo da implementação).

9. **getSize (Obter Tamanho)**: Retorna o número de elementos no Deque.

## Implementações

Um Deque pode ser implementado de várias maneiras, incluindo:

- **Array**: Utiliza um array para armazenar os elementos e aloca espaço para um número fixo de elementos.

- **Lista Encadeada**: Implementa o Deque como uma lista encadeada, permitindo alocar espaço dinamicamente conforme necessário.

- **Circulares**: Em algumas implementações, um array circular pode ser usado para economizar espaço e permitir uma inserção eficiente tanto na frente quanto na parte de trás.
