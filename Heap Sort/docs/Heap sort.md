# Heap Sort

## Visão Geral

O **Heap Sort** é um algoritmo de ordenação eficiente que utiliza uma estrutura de dados chamada heap (ou heap binária) para realizar a ordenação de um array ou vetor de elementos. É um algoritmo de ordenação in-place, o que significa que a ordenação ocorre diretamente no array de entrada, sem a necessidade de espaço extra para armazenar elementos temporários.

O Heap Sort é conhecido por sua eficiência, com uma complexidade de tempo de O(n log n) no pior caso, onde 'n' é o número de elementos no array a ser ordenado. Além disso, o Heap Sort é um algoritmo de ordenação estável, o que significa que ele não altera a ordem relativa de elementos iguais.

## Funcionamento

O Heap Sort funciona da seguinte maneira:

1. **Construção de um heap máximo**: Primeiro, um heap máximo é construído a partir do array de entrada. Isso envolve organizar os elementos do array de forma que a propriedade do heap máximo seja mantida. O heap máximo é uma árvore binária onde o valor de cada nó pai é maior ou igual ao valor de seus filhos.

2. **Extração dos elementos do heap**: Uma vez que o heap máximo é construído, o maior elemento (que está sempre na raiz da árvore) é extraído e colocado na posição correta no array. Em seguida, o heap é reajustado para manter a propriedade do heap máximo. Esse processo é repetido até que todos os elementos estejam ordenados.
