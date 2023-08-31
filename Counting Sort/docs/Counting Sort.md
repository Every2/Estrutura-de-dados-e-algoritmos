# Counting Sort

O Counting Sort é um algoritmo de ordenação eficiente para ordenar coleções de números inteiros dentro de um intervalo específico. Ele é especialmente útil quando você sabe previamente o intervalo dos números na coleção, pois seu desempenho é linear, tornando-o mais rápido do que algoritmos de ordenação como o Quicksort ou o Merge Sort em algumas situações.

## Como Funciona

O algoritmo Counting Sort funciona contando a frequência de cada número na coleção e, em seguida, recria a coleção ordenada com base nessa contagem.

1. **Contagem**: Primeiro, o algoritmo percorre a coleção original e conta quantas vezes cada número aparece. Isso é feito usando um array (ou lista) de contagem, onde o índice do array representa o número e o valor no índice é a contagem desse número.

2. **Atualização da Contagem**: Em seguida, o algoritmo atualiza o array de contagem para refletir a posição correta de cada número na coleção ordenada. Isso é feito acumulando as contagens anteriores.

3. **Construção da Coleção Ordenada**: Por fim, o algoritmo percorre a coleção original novamente e usa o array de contagem atualizado para determinar a posição correta de cada número na coleção ordenada.
