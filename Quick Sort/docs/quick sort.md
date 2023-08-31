# Quick Sort

## Introdução

O **Quick Sort** é um dos algoritmos de ordenação mais eficientes e amplamente utilizados. Ele pertence à categoria de algoritmos de ordenação baseados em comparações e utiliza a abordagem "divide e conquista" para classificar elementos de uma lista ou array em ordem crescente ou decrescente.

## Funcionamento

O algoritmo Quick Sort funciona da seguinte maneira:

1. **Escolha um Pivô:** O primeiro passo é escolher um elemento da lista chamado de "pivô". A escolha do pivô é crítica para o desempenho do algoritmo, e existem várias estratégias para selecioná-lo, sendo a escolha do pivô médio muitas vezes a mais eficaz.

2. **Partição:** O array é dividido em duas sub-listas: uma contendo elementos menores que o pivô e outra contendo elementos maiores que o pivô. Isso é feito reorganizando os elementos de forma que os elementos menores que o pivô fiquem à esquerda e os maiores à direita. O pivô está agora na sua posição final.

3. **Recursão:** Repita os passos 1 e 2 para as sub-listas resultantes. Ou seja, aplique o Quick Sort recursivamente às sub-listas menores.

4. **Combinação:** Quando as sub-listas se tornam vazias ou contêm apenas um elemento, a lista está ordenada. Isso acontece porque, por definição, uma lista vazia ou com um elemento já está ordenada.