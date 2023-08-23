# Implementação de Pilha em C

## Código em C

O código em C apresentado implementa uma estrutura de dados de pilha (stack) usando um array. A pilha é uma estrutura de dados linear que segue a lógica LIFO (Last-In-First-Out), onde o último elemento inserido é o primeiro a ser removido. Os principais componentes do código incluem a estrutura `Stack` e funções para criar, manipular e destruir a pilha.

### Estrutura `Stack`

- `int top`: A posição do elemento no topo da pilha.
- `int capacity`: A capacidade máxima da pilha (tamanho do array).
- `int* array`: Um ponteiro para um array que armazena os elementos da pilha.

### Funções

- `stackType* createStack(int capacity)`: Cria e retorna uma nova pilha.
- `int isFull(stackType* stack)`: Verifica se a pilha está cheia.
- `int isEmpty(stackType* stack)`: Verifica se a pilha está vazia.
- `void push(stackType* stack, int element)`: Adiciona um elemento à pilha.
- `int pop(stackType* stack)`: Remove e retorna o elemento do topo da pilha.
- `int showTop(stackType* stack)`: Retorna o elemento no topo da pilha sem removê-lo.
- `void destroyStack(stackType* stack)`: Libera a memória alocada para a pilha.

## Exemplo de Uso

- A função `main()` demonstra o uso da pilha implementada.
- Cria uma pilha com capacidade para 100 elementos.
- Adiciona elementos à pilha, remove um elemento e, finalmente, libera a memória alocada para a pilha.

# Implementação de Pilha em C++

## Código em C++

O código em C++ apresentado também implementa uma estrutura de dados de pilha (stack), mas oferece uma implementação mais flexível usando templates e um array ou um vetor (vector) para armazenar os elementos da pilha.

### Classe `Stack`

- `Stack()`: O construtor padrão inicializa uma pilha vazia.
- `Stack(std::array<T, N> stackArray)`: Um construtor personalizado permite que você crie uma pilha a partir de um `std::array` existente.
- `void push(const T& element)`: Adiciona um elemento à pilha, seja usando um `std::array` (se especificado) ou um vetor (vector).
- `bool isEmpty() const`: Verifica se a pilha está vazia.
- `T showTop()`: Retorna o elemento no topo da pilha sem removê-lo.
- `T pop()`: Remove e retorna o elemento do topo da pilha.
- `useVector`: Um atributo booleano que determina se a pilha usa um vetor (vector) para armazenar elementos ou um `std::array` (se especificado).
- `topIndex`: Mantém o índice do topo da pilha.
- `dynamicStack`: Um vetor (vector) usado para armazenar elementos quando `useVector` é verdadeiro.
- `plainStack`: Um `std::array` usado para armazenar elementos quando `useVector` é falso.

## Exemplo de Uso

```c
//c
int main()
{
    stackType* stack = createStack(100);
  
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
  
    printf("%d popped from stack\n", pop(stack));
    destroyStack(stack);
    return 0;
}
```

```c++
//c++
int main() {
    
    Stack<char> stackVector;

    Stack<int, 10> stackArray;

    stackVector.push('a');
    stackVector.push('b');
    stackVector.push('c');

    while (!stackVector.isEmpty()) {
        std::cout << stackVector.pop() << " ";
    }
    std::cout << '\n';

    stackArray.push(1);
    stackArray.push(2);
    stackArray.push(3);

    while (!stackArray.isEmpty()) {
        std::cout << stackArray.pop() << " ";
    }
    std::cout << '\n';

    return 0;
}

```