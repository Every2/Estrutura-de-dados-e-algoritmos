# Documentação do Algoritmo Insertion Sort

## Introdução

O algoritmo de ordenação por inserção, também conhecido como **Insertion Sort**, é um método eficiente para ordenar uma lista de elementos. Este algoritmo é particularmente adequado para pequenas listas ou quando a maior parte da lista já está ordenada. Ele é chamado de "inserção" porque trabalha como se estivéssemos inserindo cada elemento na posição correta em uma sublista ordenada à medida que percorremos a lista original.

## Funcionamento

O funcionamento básico do algoritmo de ordenação por inserção pode ser descrito da seguinte forma:

1. Inicie com um elemento na posição 1 da lista (o segundo elemento).
2. Compare este elemento com o elemento à sua esquerda (posição 0).
3. Se o elemento à esquerda for maior, troque os dois elementos.
4. Repita o passo 3 até que o elemento à esquerda seja menor ou até que não haja mais elementos à esquerda.
5. Mova para o próximo elemento na lista (posição 2) e repita os passos 2 a 4 até que todos os elementos estejam em ordem.