# Hash Table

Uma Tabela de Hash, também conhecida como Hash Table ou Dicionário, é uma estrutura de dados amplamente utilizada na ciência da computação para armazenar e recuperar dados de forma eficiente. Ela é baseada no conceito de mapeamento de chaves únicas para valores associados, permitindo a recuperação rápida dos valores a partir de suas chaves.

## Definição

Uma Tabela de Hash é uma coleção de pares chave-valor, em que:

- **Chave:** É uma identificação única associada a um valor. As chaves geralmente são strings ou números, mas podem ser qualquer tipo de dado que possa ser convertido em um valor hash.
- **Valor:** É a informação que queremos armazenar e recuperar, associada à chave.

O principal objetivo de uma tabela de hash é proporcionar uma forma eficiente de buscar, inserir e excluir valores com base em suas chaves. Isso é alcançado por meio de uma função de hash.

## Função de Hash

Uma função de hash (ou simplesmente "hash") é um algoritmo que transforma uma chave em um valor inteiro, conhecido como índice ou posição. Esse índice é usado para acessar diretamente a localização da tabela onde o valor correspondente está armazenado. A função de hash deve ser determinística, o que significa que sempre deve retornar o mesmo índice para a mesma chave.

A qualidade de uma função de hash é fundamental para evitar colisões (quando duas chaves diferentes geram o mesmo índice). Boas funções de hash distribuem as chaves uniformemente ao longo da tabela, minimizando as colisões.

## Funcionamento

O funcionamento básico de uma tabela de hash pode ser resumido em três operações principais:

1. **Inserção:** Associação de uma chave a um valor. A função de hash é usada para encontrar a posição na tabela onde o valor será armazenado.

2. **Recuperação:** Busca de um valor com base na chave. Novamente, a função de hash é usada para encontrar a posição onde o valor deve estar localizado.
