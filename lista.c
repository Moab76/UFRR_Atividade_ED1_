#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaEncadeada.h"

Listas *criarLista1() {
    Listas *lista = (Listas *)malloc(sizeof(Listas));
    lista->cabeca = NULL;
    lista->tam = 0;
    return lista;
}

void destruirLista1(Listas *L) {
    Node *atual = L->cabeca;
    Node *temp;
    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp->palavra);
        destruirLista(temp->quantidades);
        free(temp);
    }
    free(L);
}

void imprimirLista1(Listas *L) {
    Node *atual = L->cabeca;
    while (atual != NULL) {
        printf("Palavra \"%s\" ", atual->palavra);  // Imprime a palavra
        Nodo *quantidade_atual = atual->quantidades->cabeca;
        while (quantidade_atual != NULL) {
            printf("%d -> %d", quantidade_atual->linha, quantidade_atual->quantidade);  // Linha -> Quantidade
            if (quantidade_atual->prox != NULL) {
                printf(" | ");  // Separador entre entradas de linha
            }
            quantidade_atual = quantidade_atual->prox;
        }
        printf(" ->\n");  // Finaliza a linha de saída
        atual = atual->prox;
    }
}


void script(Listas *L, char* palavra, int linha) {
    // Busca a palavra na lista encadeada
    for (Node *N = L->cabeca; N != NULL; N = N->prox) {
        if (strcmp(N->palavra, palavra) == 0) {  // Palavra encontrada
            adicionarQuantidade(N->quantidades, linha);  // Atualiza a quantidade de ocorrências na linha
            return;
        }
    }

    // Se a palavra não for encontrada, cria um novo nó
    inserirValores1(L, palavra, linha);
}


void inserirValores1(Listas *L, char* palavra, int linha) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->palavra = strdup(palavra);  // Aloca e copia a palavra
    novo->quantidades = criarLista();  // Cria a lista de quantidades para essa palavra
    inserirValores(novo->quantidades, linha);  // Insere o número da linha na lista de quantidades
    novo->prox = L->cabeca;  // Insere no início da lista
    L->cabeca = novo;  // Atualiza a cabeça da lista
    L->tam++;  // Incrementa o tamanho da lista
}


