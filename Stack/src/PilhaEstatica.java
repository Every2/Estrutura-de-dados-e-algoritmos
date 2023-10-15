package Pilha;

public class PilhaEstatica<T> implements Pilha<T> {
    private T[] dados = null;
    private int topo = -1;

    public PilhaEstatica(int tamanho) {
        dados = (T[])new Object[tamanho];
    }


    @Override
    public void adicionar(T dado) {
        if (isCheia()) {
            throw new IllegalStateException("Pilha.Pilha cheia!");
        }

        topo = topo + 1;
        dados[topo] = dado;
    }

    @Override
    public T remover() {
        if (isVazia()) {
            throw new IllegalStateException("Pilha.Pilha está vazia!");
        }
        T valor = dados[topo];
        topo = topo - 1;
        return valor;
    }

    @Override
    public boolean isCheia() {
        return topo == dados.length - 1;
    }

    @Override
    public boolean isVazia() {
        return topo == -1;
    }

    @Override
    public void limpar() {
        topo = -1;
        for (int i = 0; i <= topo; i++) {
            T dado = dados[i];
        }
    }
}
