#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

ListaEncadeada *criarLista() {
    ListaEncadeada *lista = (ListaEncadeada *)malloc(sizeof(ListaEncadeada));
    lista->cabeca = NULL;
    lista->tam = 0;
    return lista;
}

void destruirLista(ListaEncadeada *L) {
    Nodo *atual = L->cabeca;
    Nodo *temp;
    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(L);
    
}

// Função para adicionar um número de linha à lista de quantidades
void inserirValores(ListaEncadeada *L, int linha) {
    Nodo *novo = (Nodo *)malloc(sizeof(Nodo));
    novo->linha = linha;
    novo->quantidade = 1;  // Inicia com uma ocorrência na linha
    // Inserir de forma ordenada (com base no número da linha)
    if (L->cabeca == NULL || L->cabeca->linha > linha) {
        novo->prox = L->cabeca;
        L->cabeca = novo;
    } else {
        Nodo *atual = L->cabeca;
        while (atual->prox != NULL && atual->prox->linha < linha) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
    L->tam++;
}


void imprimirLista(ListaEncadeada *L) {
    Nodo *atual = L->cabeca;
    while (atual != NULL) {
        printf("Linha %d | Quantidade %d -> ", atual->linha, atual->quantidade);  // Imprime linha e quantidade
        atual = atual->prox;
    }
    printf("\n");
}

// Função para incrementar a quantidade de uma linha na lista
void adicionarQuantidade(ListaEncadeada *L, int linha) {
    for (Nodo *N = L->cabeca; N != NULL; N = N->prox) {
        if (N->linha == linha) {
            N->quantidade++;  // Incrementa a quantidade na linha
            return;
        }
    }

    // Caso não encontre, cria uma nova linha para a palavra
    inserirValores(L, linha);
}

