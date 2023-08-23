## Linked List

Uma Linked List, ou lista encadeada, é uma estrutura de dados linear que consiste em uma sequência de elementos, chamados nós, onde cada nó contém dados e uma referência (ou ponteiro) para o próximo nó na sequência. As linked lists são amplamente utilizadas na programação para armazenar e manipular dados de maneira dinâmica. Elas são especialmente úteis quando o tamanho da lista pode crescer ou diminuir durante a execução do programa.


## Estrutura do Nó

Cada nó na lista é definido por uma estrutura `Node` que contém dois campos principais:

- `int data`: Armazena os dados associados ao nó.
- `Node* next`: É um ponteiro para o próximo nó na lista.

### Função `insertAtBeginning(NodeType** head_ref, int new_data)`

- **Descrição**: Insere um novo nó com `new_data` no início da lista.
- **Parâmetros**:
  - `head_ref`: Ponteiro para um ponteiro que aponta para a cabeça da lista.
  - `new_data`: Novo dado a ser inserido.
- **Passos**:
  1. Aloca um novo nó na memória.
  2. Define o `data` do novo nó como `new_data`.
  3. Atualiza o `next` do novo nó para apontar para o nó anterior no início da lista.
  4. Atualiza o `head_ref` para apontar para o novo nó.

### Função `insertAfter(NodeType* prev_node, int new_data)`

- **Descrição**: Insere um novo nó com `new_data` após um nó específico `prev_node`.
- **Parâmetros**:
  - `prev_node`: Nó após o qual o novo nó deve ser inserido.
  - `new_data`: Novo dado a ser inserido.
- **Passos**:
  1. Verifica se `prev_node` não é nulo.
  2. Aloca um novo nó na memória.
  3. Define o `data` do novo nó como `new_data`.
  4. Atualiza o `next` do novo nó para apontar para o nó seguinte a `prev_node`.
  5. Atualiza o `next` de `prev_node` para apontar para o novo nó.

### Função `insertAtEnd(NodeType** head_ref, int new_data)`

- **Descrição**: Insere um novo nó com `new_data` no final da lista.
- **Parâmetros**:
  - `head_ref`: Ponteiro para um ponteiro que aponta para a cabeça da lista.
  - `new_data`: Novo dado a ser inserido.
- **Passos**:
  1. Aloca um novo nó na memória.
  2. Define o `data` do novo nó como `new_data`.
  3. Define o `next` do novo nó como nulo.
  4. Se a lista estiver vazia, atualiza o `head_ref` para apontar para o novo nó.
  5. Caso contrário, percorre a lista até encontrar o último nó e atualiza o `next` do último nó para apontar para o novo nó.

### Função `deleteNode(NodeType** head_ref, int key)`

- **Descrição**: Exclui o primeiro nó com um valor específico `key` da lista.
- **Parâmetros**:
  - `head_ref`: Ponteiro para um ponteiro que aponta para a cabeça da lista.
  - `key`: Chave a ser excluída.
- **Passos**:
  1. Verifica se o primeiro nó (`*head_ref`) não é nulo e se contém a chave a ser excluída.
  2. Se encontrar a chave, atualiza o `*head_ref` para apontar para o segundo nó (ou nulo) e libera o primeiro nó.
  3. Caso contrário, percorre a lista para encontrar o nó anterior ao nó com a chave e atualiza o `next` do nó anterior para apontar para o nó seguinte ao nó com a chave.

### Função `searchNode(NodeType** head_ref, int key)`

- **Descrição**: Verifica se um valor específico `key` está presente na lista.
- **Parâmetros**:
  - `head_ref`: Ponteiro para um ponteiro que aponta para a cabeça da lista.
  - `key`: Chave a ser buscada.
- **Retorno**: Retorna 1 se encontrar a chave, caso contrário, retorna 0.

### Função `sortLinkedList(NodeType** head_ref)`

- **Descrição**: Ordena os elementos da lista em ordem crescente usando o algoritmo de ordenação da bolha.
- **Parâmetros**:
  - `head_ref`: Ponteiro para um ponteiro que aponta para a cabeça da lista.
- **Passos**:
  1. Verifica se a lista está vazia ou contém apenas um elemento.
  2. Usa o algoritmo de ordenação da bolha para percorrer a lista e trocar valores conforme necessário até que a lista esteja ordenada.

### Função `printList(NodeType* node)`

- **Descrição**: Imprime todos os elementos da lista.
- **Parâmetros**:
  - `node`: Ponteiro para o primeiro nó da lista.
- **Passos**:
  1. Percorre a lista a partir do primeiro nó até o último nó, imprimindo o valor de cada nó.

# Linked List em C++

Em C++, a Linked List é implementada como uma classe chamada `LinkedList`, que utiliza uma classe de nó `Node`.

## Classe `Node`

- **Membros Privados**:
  - `T data`: Armazena os dados associados ao nó.
  - `std::shared_ptr<Node<T>> next`: É um ponteiro inteligente compartilhado para o próximo nó na lista.
- **Método Construtor `Node(const T& value)`**: Inicializa o nó com um valor.

## Classe `LinkedList`

- **Membros Privados**:
  - `std::shared_ptr<Node<T>> head`: É um ponteiro inteligente compartilhado para o primeiro nó na lista.
- **Método Construtor `LinkedList()`**: Inicializa a lista encadeada vazia.
- **Método `insertAtBeginning(const T& newData)`**: Insere um novo nó com `newData` no início da lista.
- **Método `insertAfter(const std::shared_ptr<Node<T>>& prev_node, const T& new_data)`**: Insere um novo nó com `new_data` após um nó específico `prev_node`.
- **Método `insertAtEnd(const T& new_data)`**: Insere um novo nó com `new_data` no final da lista.
- **Método `getNodeWithValue(const T& value) const`**: Obtém um nó com um valor específico `value`.
- **Método `deleteNode(const T& key)`**: Exclui o primeiro nó com um valor específico `key` da lista.
- **Método `searchNode(const T& key) const`**: Verifica se um valor específico `key` está presente na lista.
- **Método `sortLinkedList()`**: Ordena os elementos da lista em ordem crescente usando o algoritmo de ordenação da bolha.
- **Método `printList() const`**: Imprime todos os elementos da lista.

## Exemplos de Uso


```cpp
int main(){
    LinkedList<int> myList;

    myList.insertAtEnd(1);
    myList.insertAtEnd(3);
    myList.insertAtEnd(5);

    std::cout << "Original list: " << '\n';
    myList.printList(); 

    myList.insertAtBeginning(0);
    myList.insertAtBeginning(-1);

    std::cout << "List after insertAtBeginning: " << '\n';
    myList.printList(); 

    std::shared_ptr<Node<int>> node1 = myList.getNodeWithValue(1);
    if (node1) {
        myList.insertAfter(node1, 2);
    }

    std::cout << "List after 1 inserted: " << '\n';
    myList.printList(); 

    myList.deleteNode(2);

    std::cout << "List after 2 deleted: " << '\n';
    myList.printList(); 
    
    int searchValue = 3;
    if (myList.searchNode(searchValue)) {
        std::cout << "The value " << searchValue << " is in the list" << '\n';
    } else {
        std::cout << "The value " << searchValue << " isn't in the list" << '\n';
    }

    myList.sortLinkedList();

    std::cout << "List after sort: " << '\n';
    myList.printList(); 

    return 0;
}
```

```c
int main() {
  nodetype* head = NULL;

  insertAtEnd(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);
  insertAtEnd(&head, 4);
  insertAfter(head->next, 5);

  printf("Linked list: ");
  printList(head);

  printf("\nAfter deleting an element: ");
  deleteNode(&head, 6);
  printList(head);

  int item_to_find = 3;
  if (searchNode(&head, item_to_find)) {
  printf("\n%d is found", item_to_find);
  } else {
  printf("\n%d is not found", item_to_find);
  }

  sortLinkedList(&head);
  printf("\nSorted List: ");
  printList(head);
}
```