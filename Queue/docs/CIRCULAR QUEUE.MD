## Fila Circular

Uma fila circular, também conhecida como fila de anel, é uma estrutura de dados que organiza elementos em uma ordem linear. A principal característica que a diferencia de uma fila tradicional é que, quando a capacidade máxima é atingida, a fila começa a reutilizar as posições iniciais. Em outras palavras, a fila não tem um fim definido; ela se "enrola" de volta ao início quando necessário.

Principais características de uma fila circular:

1. **Front (Frente)**: A posição da fila onde os elementos são removidos. É a parte mais antiga da fila.

2. **Rear (Fundo)**: A posição da fila onde os elementos são adicionados. É a parte mais recente da fila.

3. **Tamanho Fixo**: A fila circular tem um tamanho fixo, que é definido no momento da criação.

4. **Enfileiramento Circular**: Quando a fila está cheia e um novo elemento é adicionado, o próximo elemento é inserido no início da fila, reutilizando as posições disponíveis.

5. **Lógica de Enfileiramento e Desenfileiramento**: O enfileiramento (adição de elementos) e o desenfileiramento (remoção de elementos) são operações controladas de forma circular.

## C++

O código fornecido implementa uma fila circular genérica em C++. Ele utiliza uma classe template `CircularQueue` para criar filas circulares com diferentes tipos de elementos e tamanhos. Aqui está uma explicação passo a passo do código:

1. **Declaração da Classe `CircularQueue`**: A classe `CircularQueue` é definida como uma classe template. Isso permite criar filas circulares para diferentes tipos de elementos e tamanhos.

2. **Membros Privados**:
   - `std::array<T, N> elements`: Um array estático que armazena os elementos da fila.
   - `int front`: Índice do elemento na frente da fila.
   - `int rear`: Índice do elemento no final da fila.
   - `int size`: Tamanho atual da fila.

3. **Método Construtor `CircularQueue`**: O construtor inicializa os membros da fila, definindo `front` como 0, `rear` como -1 (indicando uma fila vazia) e `size` como 0.

4. **Método `isFull`**: Verifica se a fila está cheia com base no tamanho atual em relação ao tamanho máximo `N`. Retorna `true` se a fila estiver cheia e `false` caso contrário.

5. **Método `isEmpty`**: Verifica se a fila está vazia com base no tamanho atual. Retorna `true` se a fila estiver vazia e `false` caso contrário.

6. **Método `enqueue`**: Adiciona um elemento à fila. Se a fila estiver cheia, uma exceção `std::overflow_error` é lançada. Caso contrário, o elemento é adicionado na posição `rear` e o `rear` é atualizado de forma circular. O tamanho da fila é incrementado.

7. **Método `dequeue`**: Remove o elemento na frente da fila. Se a fila estiver vazia, uma exceção `std::underflow_error` é lançada. Caso contrário, o elemento na posição `front` é removido e o `front` é atualizado de forma circular. O tamanho da fila é decrementado, e o elemento removido é retornado.

8. **Método `printQueue`**: Imprime os elementos da fila. Começa na posição `front` e itera circularmente até a posição `rear`, exibindo os elementos da fila.

Esta implementação fornece uma estrutura eficiente para gerenciar filas circulares com um tamanho fixo, garantindo que as operações de enfileiramento e desenfileiramento sejam executadas de forma circular.

# Exemplos de Uso
```cpp
int main(){

    CircularQueue<int, 5> myQueue; 

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.printQueue();
    std::cout << '\n';
    myQueue.dequeue();
    myQueue.printQueue();

    return 0;
}
```

## C

1. **Definição do Tamanho Máximo da Fila**: É definido o tamanho máximo da fila como `MAX_SIZE` igual a 100. Isso limita a capacidade máxima da fila.

2. **Definição da Estrutura `CircularQueue`**: A estrutura `CircularQueue` é definida para representar a fila circular. Ela inclui:
   - `int element[MAX_SIZE]`: Um array que armazena os elementos da fila.
   - `int front`: Um índice que aponta para o elemento na frente da fila.
   - `int rear`: Um índice que aponta para o elemento no final da fila.

3. **Método `initialize`**: Esta função inicializa a fila circular, definindo `front` e `rear` como -1, indicando que a fila está vazia.

4. **Função `isEmpty`**: Verifica se a fila está vazia. Retorna 1 (verdadeiro) se `front` e `rear` forem iguais a -1 (ou seja, nenhum elemento na fila), caso contrário, retorna 0 (falso).

5. **Função `isFull`**: Verifica se a fila está cheia. Retorna 1 (verdadeiro) se o próximo índice após `rear` for igual a `front` (indicando que a fila está cheia), caso contrário, retorna 0 (falso).

6. **Função `enqueue`**: Adiciona um elemento à fila. Se a fila estiver cheia, imprime "Queue is full". Caso contrário, se a fila estiver vazia, `front` e `rear` são definidos como 0, e o elemento é adicionado na posição `rear`. Caso contrário, `rear` é atualizado de forma circular e o elemento é inserido na nova posição `rear`.

7. **Função `dequeue`**: Remove o elemento na frente da fila. Se a fila estiver vazia, imprime "Queue is empty" e retorna -1 (indicando erro). Caso contrário, o elemento na posição `front` é removido e armazenado em `removedElement`. Se `front` e `rear` forem iguais após a remoção (indicando que havia apenas um elemento na fila), `front` e `rear` são definidos como -1. Caso contrário, `front` é atualizado de forma circular.

8. **Função `display`**: Exibe os elementos da fila circular. Se a fila estiver vazia, imprime "Empty Queue". Caso contrário, exibe o elemento na frente da fila, seguido pelos elementos na fila, iterando de `front` para `rear` de forma circular. Finalmente, exibe o elemento no final da fila.

9. **Função `main`**: A função principal (`main`) demonstra o uso da fila circular.
    - Inicializa uma fila circular `cq` usando a função `initialize`.
    - Enfileira os valores de 1 a 5 na fila.
    - Exibe a fila.
    - Desenfileira dois elementos (remove os dois primeiros elementos).
    - Exibe a fila novamente.

Este código implementa uma fila circular simples em C, que é uma estrutura de dados eficiente para enfileiramento e desenfileiramento de elementos em uma ordem circular.

# Exemplos de Uso

```c 
int main() {
    typeCircularQ cq;
    initialize(&cq);

    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);
    enqueue(&cq, 4);
    enqueue(&cq, 5);

    display(&cq); 

    dequeue(&cq);
    dequeue(&cq);
    display(&cq); 
}
```