# STACK

Uma stack (pilha) é uma estrutura de dados que segue o principio LIFO (Last in, First out/Última entrada, primeiro a sair). Quando colocamos um item dentro da pilha (push), o alocamos dentro no topo da stack, então pense que temos uma pilha de pratos. Se quisermos o último prato, temos que tirar os que estão em cima (pop). É exatamente assim que funciona o principio LIFO. 

Na implementação em C usamos tipos inteiros por padrão e usamos uma stack baseado em um array, já na implementação em C++ a função "isFull" é substituida por um tratamento de erro com throw e usa genéricos, assim a pilha pode ser de qualquer tipo e ela pode tanto não ter um tamanho fixo e se expandir, como também pode ter um tamanho fixo. 