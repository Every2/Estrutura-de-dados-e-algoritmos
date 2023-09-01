# Bucket Sort - Ordenação por Baldes

O Bucket Sort é um algoritmo de ordenação eficiente que funciona dividindo os elementos a serem classificados em "baldes" e, em seguida, ordenando cada balde individualmente, ou seja, em ordenação interna. É útil quando a entrada é distribuída uniformemente no intervalo a ser ordenado.

## Passos do Algoritmo

1. Crie um número fixo de baldes vazios.
2. Percorra o array de entrada e distribua cada elemento em um dos baldes com base em uma função de mapeamento. A função de mapeamento deve ser escolhida de acordo com a distribuição dos elementos.
3. Ordena cada balde individualmente usando um algoritmo de ordenação interno, como o Insertion Sort.
4. Concatene os baldes em ordem para obter o array classificado.