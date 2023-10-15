package PilhaEncadeada;
import Pilha.Pilha;

public class PilhaEncadeada<T> implements Pilha<T> {
    private static class No<T> {
        public No anterior;
        public T dado;
    }

    private No<T> topo = null;

    @Override
    public void adicionar(T valor) {
        var novo = new No<T>();
        novo.dado =  valor;
        novo.anterior = topo;
        topo = novo;
    }

    @Override
    public T remover() {
        if (isVazia()) {
            throw new IllegalStateException("Fila vazia!");
        }
        var dado = topo.dado;
        topo = topo.anterior;

        return dado;
    }
    @Override
    public boolean isCheia() {
        return false;
    }

    @Override
    public boolean isVazia() {
        return topo == null;
    }

    @Override
    public void limpar() {
        topo = null;
    }

}
