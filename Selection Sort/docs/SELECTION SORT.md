# Selection Sort

## Introdução

O algoritmo de ordenação por seleção (Selection Sort) é um algoritmo simples de ordenação que divide a lista não ordenada em duas partes: uma parte ordenada e outra parte não ordenada. Inicialmente, a parte ordenada está vazia e a parte não ordenada contém todos os elementos. O algoritmo então encontra o menor (ou maior, dependendo do critério de ordenação) elemento na parte não ordenada e o move para o final da parte ordenada. Esse processo é repetido até que toda a lista esteja ordenada.

## Funcionamento

### 1. Inicialização
- A parte ordenada é inicialmente vazia.
- A parte não ordenada contém todos os elementos da lista.

### 2. Seleção do Menor Elemento
- Encontre o menor elemento na parte não ordenada.
- Troque-o com o primeiro elemento da parte não ordenada, movendo-o para o final da parte ordenada.

### 3. Expansão da Parte Ordenada
- Aumente o tamanho da parte ordenada em 1.
- Diminua o tamanho da parte não ordenada em 1.

### 4. Repita
- Repita os passos 2 e 3 até que a parte não ordenada esteja vazia.
- Nesse ponto, a lista estará totalmente ordenada.