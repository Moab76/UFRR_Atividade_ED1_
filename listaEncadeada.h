#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H


typedef struct nodo{
    int linha;
    int quantidade;
    struct nodo *prox;
   
} Nodo;

typedef struct listaEncadeada {
    Nodo *cabeca;
    int tam;
} ListaEncadeada;

ListaEncadeada *criarLista();
void destruirLista(ListaEncadeada *L);
void inserirValores(ListaEncadeada *L, int linha);
void imprimirLista(ListaEncadeada *L);
void adicionarQuantidade(ListaEncadeada *L, int linha);


#endif