# Documentação da B+Tree Genérica

## Introdução

A B+Tree é uma estrutura de dados de árvore balanceada que é comumente usada em sistemas de gerenciamento de bancos de dados e sistemas de armazenamento em disco. Ela oferece operações eficientes de inserção, busca e exclusão. Esta documentação descreverá as operações de inserção e exclusão em uma B+Tree genérica.

## Estrutura da B+Tree

Uma B+Tree é composta por nós internos e folhas. Os nós internos contêm chaves e ponteiros para os filhos, enquanto as folhas contêm chaves e ponteiros para os dados associados a essas chaves.

### Nó Interno

- `keys`: Uma lista ordenada de chaves que define os intervalos de valores representados pelos filhos.
- `pointers`: Uma lista de ponteiros para os filhos, referenciando subárvores ou nós folhas.

### Folha

- `keys`: Uma lista ordenada de chaves que armazenam os valores.
- `data`: Uma lista de dados associados às chaves.

## Inserção em uma B+Tree

A operação de inserção em uma B+Tree é realizada em três etapas principais:

1. **Localização do Nó Adequado**: Começamos na raiz da árvore e descemos pelos nós internos até encontrar a folha apropriada onde a chave deve ser inserida.

2. **Inserção na Folha**: Na folha, a chave e seus dados correspondentes são inseridos. Se a folha estiver cheia após a inserção, é realizada uma divisão.

3. **Propagação da Divisão**: Se a divisão ocorreu, a chave do meio e um ponteiro para a nova folha são inseridos no nó pai. Se o nó pai estiver cheio após a inserção, o processo é repetido até a raiz.

### Exclusão em uma B+Tree

A operação de exclusão em uma B+Tree é um pouco mais complexa do que a inserção, pois envolve casos especiais para manter a estrutura da árvore. As etapas principais da exclusão são as seguintes:

1. Localização da Folha a Ser Excluída: Começamos na raiz e descemos pelos nós internos até encontrar a folha que contém a chave a ser excluída.

2. Exclusão na Folha: Excluímos a chave e seus dados correspondentes da folha. Se a folha ficar abaixo do limite mínimo de chaves após a exclusão, consideramos fusão ou redistribuição com as folhas vizinhas.

3. Propagação da Fusão/Redistribuição: Se a fusão ou redistribuição ocorreu, atualizamos as chaves nos nós pais conforme necessário. Se um nó pai ficar abaixo do limite mínimo após a exclusão, o processo é repetido até a raiz.