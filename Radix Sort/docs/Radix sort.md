# Radix Sort

O Radix Sort é um algoritmo de ordenação eficiente que funciona classificando os elementos com base em seus dígitos, começando pelo dígito menos significativo até o dígito mais significativo. Este algoritmo é especialmente útil para ordenar números inteiros ou strings.

## Como funciona

O Radix Sort opera da seguinte maneira:

1. **Inicialização**: Determine o número máximo de dígitos nos elementos a serem ordenados. Isso determinará quantas iterações o algoritmo precisará realizar.

2. **Iterações**: Para cada dígito, da direita para a esquerda, realize as seguintes etapas:
   - **Distribuição**: Coloque cada elemento em um dos 10 baldes (0 a 9) com base no valor do dígito atual.
   - **Coleta**: Colete os elementos de volta na ordem em que foram distribuídos, preservando a ordem relativa dos dígitos.

3. **Repetição**: Repita as etapas de distribuição e coleta para cada dígito, indo do menos significativo para o mais significativo.

4. **Resultado**: Após a última iteração, os elementos estarão ordenados.