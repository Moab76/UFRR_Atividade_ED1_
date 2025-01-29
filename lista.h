#ifndef LISTA_H
#define LISTA_H
#include "listaEncadeada.h"


typedef struct Node{
    char *palavra;
    ListaEncadeada *quantidades;
    struct Node *prox;
   
} Node;

typedef struct lista {
    Node *cabeca;
    int tam;
} Listas;

Listas *criarLista1();
void destruirLista1(Listas *L);
void inserirValores1(Listas *L, char* palavra, int linha);

void imprimirLista1(Listas *L);
void script(Listas *L, char* palavra, int linha);


#endif