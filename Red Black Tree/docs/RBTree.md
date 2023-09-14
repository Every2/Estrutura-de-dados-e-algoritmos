# Red-Black Tree (Árvore Rubro-Negra)

Uma Red-Black Tree é uma estrutura de dados de árvore binária balanceada, usada principalmente para armazenar e organizar dados de maneira eficiente. Ela mantém a propriedade de equilíbrio para garantir operações de inserção, exclusão e pesquisa em tempo O(log n), onde "n" é o número de elementos na árvore.

## Estrutura da Árvore

Uma Red-Black Tree consiste em nós que possuem as seguintes propriedades:

1. **Cor:** Cada nó é colorido de vermelho ou preto.
2. **Propriedade de Rubro-Negro:** A árvore deve satisfazer várias regras para garantir o equilíbrio da árvore, que são definidas a seguir.

### Propriedades da Árvore Rubro-Negra

1. **Raiz Negra:** A raiz da árvore é sempre preta.

2. **Nós Vermelhos:** Um nó vermelho não pode ter filhos vermelhos. Isso significa que não pode haver dois nós vermelhos consecutivos em nenhum caminho da raiz para as folhas.

3. **Propriedade de Caminho Negro:** Todo caminho da raiz para uma folha deve ter o mesmo número de nós pretos. Isso garante que a árvore esteja equilibrada em altura.

4. **Folhas Pretas:** Todas as folhas (nós nulos) são pretas.

## Operações Principais

Uma Red-Black Tree suporta várias operações principais:

1. **Inserção:** Adicionar um novo elemento à árvore enquanto mantém as propriedades da árvore Rubro-Negra.

2. **Exclusão:** Remover um elemento da árvore enquanto mantém as propriedades da árvore Rubro-Negra.

3. **Pesquisa:** Encontrar um elemento específico na árvore.

4. **Travessia:** Percorrer a árvore em ordem, pré-ordem ou pós-ordem para acessar todos os elementos em ordem específica.
