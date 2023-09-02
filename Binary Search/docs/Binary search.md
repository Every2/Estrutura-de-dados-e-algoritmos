# Pesquisa Binária

## Introdução

A pesquisa binária é um algoritmo eficiente para encontrar um valor específico em um conjunto de dados ordenado. Ela funciona dividindo repetidamente o conjunto de dados pela metade e comparando o valor desejado com o elemento do meio. Esse processo de divisão e comparação continua até que o valor seja encontrado ou seja determinado que o valor não está presente no conjunto de dados.

## Funcionamento

O algoritmo de pesquisa binária funciona da seguinte maneira:

1. Inicialmente, o conjunto de dados deve estar ordenado em ordem crescente ou decrescente.

2. O algoritmo calcula o elemento do meio do conjunto de dados.

3. Compara o valor desejado com o elemento do meio:
   - Se eles forem iguais, o valor foi encontrado, e a pesquisa é concluída.
   - Se o valor desejado for menor que o elemento do meio, a pesquisa continua na metade inferior do conjunto de dados.
   - Se o valor desejado for maior que o elemento do meio, a pesquisa continua na metade superior do conjunto de dados.

4. O processo é repetido nas metades resultantes até que o valor seja encontrado ou até que a metade em que a pesquisa está sendo realizada não contenha mais elementos.