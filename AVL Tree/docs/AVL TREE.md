# Árvore AVL

Uma Árvore AVL (Árvore de Balanceamento Automático) é uma estrutura de dados de árvore binária de busca em que a altura das subárvores esquerda e direita de qualquer nó difere em no máximo uma unidade. Essa propriedade de balanceamento garante que a árvore permaneça balanceada após a inserção ou remoção de nós, mantendo um desempenho eficiente para operações de busca, inserção e exclusão.

## Funcionamento Básico

Uma Árvore AVL é uma árvore binária de busca em que cada nó possui um valor (chave) associado. As seguintes propriedades são mantidas:

1. Para cada nó na árvore, a subárvore esquerda contém apenas nós com chaves menores do que a chave do nó e a subárvore direita contém apenas nós com chaves maiores do que a chave do nó.

2. A diferença de altura entre a subárvore esquerda e a subárvore direita de qualquer nó (o fator de balanceamento) não pode exceder 1.

## Operações Principais

### Inserção

Para inserir um novo nó em uma Árvore AVL, siga estas etapas:

1. Insira o nó na árvore como faria em uma árvore de busca binária padrão.

2. Atualize as alturas dos nós pai do novo nó.

3. Verifique o fator de balanceamento em cada nó pai e, se necessário, aplique rotações (simples ou duplas) para manter o balanceamento da árvore.

### Exclusão

Para excluir um nó de uma Árvore AVL, siga estas etapas:

1. Exclua o nó da árvore como faria em uma árvore de busca binária padrão.

2. Atualize as alturas dos nós pai do nó excluído.

3. Verifique o fator de balanceamento em cada nó pai e, se necessário, aplique rotações (simples ou duplas) para manter o balanceamento da árvore.