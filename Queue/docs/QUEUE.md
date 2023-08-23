# Estrutura de Dados Fila e Classe Queue

# Estrutura de Dados Fila

Uma fila é uma estrutura de dados linear que segue a lógica FIFO (First-In-First-Out), o que significa que o primeiro elemento inserido na fila é o primeiro a ser removido. Em uma fila, a inserção de elementos ocorre no final, chamado de "rear", e a remoção de elementos ocorre no início, chamado de "front". A fila é uma estrutura de dados bastante comum e é usada para muitas aplicações do mundo real, como gerenciamento de tarefas em sistemas operacionais, controle de impressoras em uma rede e muito mais.

Principais operações em uma fila:

-  Enqueue: Adiciona um elemento ao final da fila.
-  Dequeue: Remove o elemento do início da fila.
-  isEmpty: Verifica se a fila está vazia.
-  isFull: Verifica se a fila está cheia (em algumas implementações).

# Estrutura Queue

# Atributos

- int* array: Um ponteiro para um array que armazena os elementos da fila.
- int size: O número de elementos atualmente na fila.
- int capacity: A capacidade máxima da fila (tamanho do array).
- int front: A posição do primeiro elemento na fila.
- int rear: A posição do último elemento na fila.

# Funções

`queueType* createQueue(int capacity)`

- Cria e retorna uma nova fila.
- Parâmetro capacity: A capacidade máxima desejada da fila.
- Aloca memória para a estrutura Queue, inicializa seus atributos e aloca memória para o array de acordo com a capacidade especificada.

`int isFull(queueType* queue)`

- Verifica se a fila está cheia. 
- Retorna 1 se a fila estiver cheia (não pode acomodar mais elementos), caso contrário, retorna 0.

`int isEmpty(queueType* queue)`

- Verifica se a fila está vazia.
- Retorna 1 se a fila estiver vazia (sem elementos), caso contrário, retorna 0.

`void enqueue(queueType* queue, int item)`

- Adiciona um elemento ao final da fila.
- Parâmetro item: O elemento a ser adicionado à fila.
- Verifica se a fila está cheia antes de adicionar o elemento.
- Atualiza a posição do elemento no array e o tamanho da fila.

`int dequeue(queueType* queue)`

- Remove e retorna o elemento do início da fila.
- Retorna INT_MIN se a fila estiver vazia.
- Atualiza a posição do primeiro elemento e o tamanho da fila após a remoção.

`int front(queueType* queue)`

- Retorna o elemento na frente da fila sem removê-lo.
- Retorna INT_MIN se a fila estiver vazia.

`int rear(queueType* queue)`

- Retorna o elemento no final da fila sem removê-lo.
- Retorna INT_MIN se a fila estiver vazia.

`void destroyQueue(queueType* queue)`

- Libera a memória alocada para a fila e o array.
- É importante chamar esta função quando a fila não for mais necessária para evitar vazamentos de memória.

# Classe Queue

A classe Queue apresentada é uma implementação de uma fila genérica em C++ usando um array de tamanho fixo. Aqui está uma explicação dos principais elementos da classe Queue:
Atributos Privados

-  std::array<T, N> queue: Este atributo é um std::array que armazena os elementos da fila. É um array de tamanho fixo.
-  int front: Mantém a posição do primeiro elemento na fila.
-  int rear: Mantém a posição do último elemento na fila.
-  int count: Mantém o número atual de elementos na fila.

# Construtores

- Queue(): O construtor padrão inicializa a fila, definindo front como 0, rear como -1 e count como 0.
- Queue(const std::array<T, N>& arr): Este construtor personalizado permite que você crie uma instância da classe Queue a partir de um std::array. Ele recebe um std::array como argumento. O construtor verifica se o tamanho do std::array passado como argumento é maior que o tamanho máximo N da fila. Se for maior, ele lança uma exceção. Caso contrário, ele itera pelo std::array passado e chama enQueue para inserir cada elemento na fila.
Este construtor personalizado é útil quando você deseja inicializar uma fila com elementos de um std::array existente. Isso permite que você preencha a fila com dados predefinidos de maneira conveniente.

# Métodos Públicos

- bool isFull(): Verifica se a fila está cheia, ou seja, se o número de elementos na fila é igual ao tamanho máximo N.
- bool isEmpty(): Verifica se a fila está vazia, ou seja, se o número de elementos na fila é zero.
- void enQueue(T element): Adiciona um elemento à fila, desde que a fila não esteja cheia. Se a fila estiver cheia, lança uma exceção.
- T deQueue(): Remove o elemento da frente da fila, desde que a fila não esteja vazia. Se a fila estiver vazia, lança uma exceção.
- void printQueue(): Imprime o conteúdo da fila, mostrando o elemento da frente, todos os elementos na fila e o elemento de trás.

# Exemplos de Uso em C e C++
```cpp
//C++
int main() {
    std::array<int, 5> myArray = {7, 2, 3, 4, 5};
    Queue<int, 5> arrQueue(myArray); 
    Queue<int, 5> myQueue; 

    arrQueue.printQueue();
    arrQueue.deQueue();
    arrQueue.printQueue();
    std::cout << '\n';
    myQueue.enQueue(1);
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    myQueue.enQueue(4);
    myQueue.enQueue(5);
    myQueue.printQueue();
    myQueue.deQueue();
    myQueue.printQueue();

    return 0;
}
```

```c
//C
int main()
{
    struct Queue* queue = createQueue(4);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n\n", dequeue(queue));
 
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
 
    destroyQueue(queue);

    return 0;
}
```