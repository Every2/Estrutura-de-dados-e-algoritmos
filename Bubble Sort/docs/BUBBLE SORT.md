# Bubble Sort

O Bubble Sort é um algoritmo de ordenação simples e eficiente que percorre repetidamente uma lista, compara elementos adjacentes e os troca se estiverem na ordem errada. Esse processo é repetido até que a lista esteja completamente ordenada. O algoritmo recebe o nome de "Bubble" devido aos elementos maiores "subindo" gradualmente para suas posições corretas, como bolhas na superfície da água.

## Parâmetros

- `array`: Uma referência para um `std::array` que você deseja ordenar. A função modificará este array diretamente para ordená-lo.

## Comportamento

A função `bubbleSort` segue o seguinte processo de ordenação:

1. Inicializa uma variável booleana `swapped` como `false`. Essa variável será usada para otimizar o algoritmo, permitindo que ele saia mais cedo caso a lista já esteja ordenada.
2. Itera sobre os elementos do array várias vezes, até que nenhum elemento seja trocado durante uma passagem completa pela lista (o que significa que a lista está ordenada).
3. Durante cada passagem pela lista, compara elementos adjacentes dois a dois.
4. Se um elemento for maior do que o próximo elemento, eles são trocados de lugar usando a função `std::swap`.
5. Se ocorrer pelo menos uma troca durante uma passagem completa, a variável `swapped` é definida como `true`.
6. Se nenhuma troca ocorrer durante uma passagem completa (ou seja, `swapped` permanecer `false`), o algoritmo assume que a lista está ordenada e sai antecipadamente.
