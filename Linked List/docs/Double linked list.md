# Documentação da Double Linked List

## Descrição

Uma Double Linked List (ou Lista Duplamente Encadeada, em português) é uma estrutura de dados linear que consiste em uma coleção de elementos, cada um dos quais é representado por um nó. Cada nó em uma lista duplamente encadeada armazena um elemento de dados e mantém referências tanto para o nó anterior quanto para o próximo nó na sequência. Isso permite que você navegue pela lista tanto para frente quanto para trás, daí o termo "duplamente encadeada".

## Classe `Node`

A classe `Node` representa um nó na lista duplamente encadeada. Cada nó contém um dado, um ponteiro para o próximo nó e um ponteiro para o nó anterior.

### Construtor

- `Node(T data)`: Inicializa um nó com o dado especificado.

## Classe `DoubleLinkedList`

A classe `DoubleLinkedList` representa a lista duplamente encadeada.

### Atributos

- `std::shared_ptr<Node<T>> head`: Ponteiro para o primeiro nó da lista.

### Funções

## Função `insertFront(T data)`

Esta função insere um novo nó com o dado especificado no início da lista duplamente encadeada. Aqui está como funciona:

1.    Ela cria um novo nó com o dado `data`.
2.    Em seguida, configura o ponteiro `next` do novo nó para apontar para o nó atualmente no início da lista (`head`).
3.    Se a lista não estiver vazia (ou seja, `head` não é `nullptr`), então ela configura o ponteiro `prev` do nó atual no início da lista para apontar para o novo nó, estabelecendo assim a relação bidirecional entre os nós.
4.    Finalmente, atualiza o ponteiro head para apontar para o novo nó, tornando-o o novo início da lista.

## Função `insertAfter(std::shared_ptr<Node<T>> prev_node, T data)`

Esta função insere um novo nó com o dado especificado após um nó específico na lista duplamente encadeada. Aqui está como funciona:

1.    Ela verifica se o nó `prev_node` passado como argumento é válido (ou seja, não é `nullptr`).
2.    Em seguida, cria um novo nó com o dado `data`.
3.    Configura o ponteiro `next` do novo nó para apontar para o próximo nó após `prev_node`.
4.    Configura o ponteiro `prev` do novo nó para apontar para `prev_node`, estabelecendo assim a relação bidirecional entre os nós.
5.    Se o próximo nó após `prev_node` existir (ou seja, não for `nullptr`), ela atualiza o ponteiro `prev` desse próximo nó para apontar para o novo nó.
6.    Finalmente, configura o ponteiro `next` de `prev_node` para apontar para o novo nó, inserindo assim o novo nó na lista após `prev_node`.

## Função `insertEnd(T data)`

Esta função insere um novo nó com o dado especificado no final da lista duplamente encadeada. Aqui está como funciona:

1.    Ela cria um novo nó com o dado `data`.
2.    Verifica se a lista está vazia (ou seja, head é `nullptr`).
3.    Se a lista estiver vazia, ela simplesmente configura `head` para apontar para o novo nó, tornando-o o único nó na lista.
4.    Se a lista não estiver vazia, ela percorre a lista a partir do início (usando um ponteiro temporário) até encontrar o último nó.
5.    Configura o ponteiro `next` do último nó encontrado para apontar para o novo nó, e o ponteiro `prev` do novo nó para apontar para o último nó, estabelecendo assim a relação bidirecional entre os nós.

## Função `deleteNode(std::shared_ptr<Node<T>> del_node)`

Esta função exclui um nó específico da lista duplamente encadeada. Aqui está como funciona:

1.    Ela verifica se a lista não está vazia (ou seja, head não é `nullptr`) e se o nó a ser excluído (`del_node`) é válido (ou seja, não é `nullptr`).
2.    Se o nó a ser excluído é o primeiro nó da lista (ou seja, `head` aponta para ele), atualiza `head` para apontar para o próximo nó após `del_node`, efetivamente removendo o primeiro nó.
3.    Se o próximo nó após `del_node` existir (ou seja, não for `nullptr`), ela atualiza o ponteiro prev desse próximo nó para apontar para o nó anterior a `del_node`.
4.    Se o nó anterior a `del_node` existir (ou seja, não for `nullptr`), ela atualiza o ponteiro next desse nó anterior para apontar para o próximo nó após `del_node`.
5.    Como resultado, `del_node` é removido da lista e sua memória será desalocada automaticamente quando não houver mais referências a ele.