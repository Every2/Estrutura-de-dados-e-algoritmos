# B-tree

A B-tree é uma estrutura de árvore balanceada amplamente utilizada em computação para armazenar e gerenciar dados de forma eficiente. Ela é especialmente útil para armazenar e recuperar dados em sistemas de gerenciamento de banco de dados e sistemas de arquivos. A B-tree é projetada para manter um equilíbrio entre a altura da árvore e o número de chaves em cada nó, o que a torna eficiente para operações de busca, inserção e exclusão.

## Estrutura

Uma B-tree é uma árvore em que cada nó pode ter várias chaves e vários filhos. Os nós são organizados de maneira que todas as chaves em um nó pai sejam maiores que as chaves em seus filhos à esquerda e menores que as chaves em seus filhos à direita. A estrutura básica de um nó em uma B-tree inclui:

- `is_leaf`: Um indicador de se o nó é uma folha (true) ou um nó interno (false).
- `keys`: Um vetor de chaves armazenadas no nó.
- `children`: Um vetor de ponteiros para os nós filhos.

## Operações Principais

### Inserção

A operação de inserção em uma B-tree envolve encontrar o local correto para inserir a chave e, se necessário, dividir um nó se ele estiver cheio. O processo continua recursivamente até que a chave seja inserida.

### Busca

A operação de busca em uma B-tree é semelhante à busca em uma árvore binária de pesquisa. Começa na raiz e segue os nós até encontrar a chave desejada ou determinar que a chave não está presente na árvore.

### Exclusão

A operação de exclusão em uma B-tree pode ser complexa devido às regras de balanceamento. Ela envolve a remoção da chave e possíveis ajustes na estrutura da árvore para manter a propriedade da B-tree.

### Percorrendo a Árvore

Existem várias maneiras de percorrer uma B-tree, incluindo a travessia em ordem, pré-ordem e pós-ordem. Cada método de travessia fornece uma ordem diferente das chaves da árvore.
