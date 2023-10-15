package Pilha;

public interface Pilha<T> {
    void adicionar(T valor);
    T remover();
    boolean isCheia();
    boolean isVazia();
    void limpar();
}
