#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "listaEncadeada.h"

int main() {
    FILE *arquivo;
    char linha[200];  // Buffer para armazenar cada linha
    Listas *L = criarLista1();  // Criar lista de palavras

    arquivo = fopen("historia_aventura.txt", "r");  // Abre o arquivo em modo de leitura

    if (arquivo == NULL) {  // Verifica se houve erro ao abrir o arquivo
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Leitura linha por linha
    int numero_linha = 1;  // Contador para o índice da linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        char palavra[200];  // Buffer para armazenar cada palavra
        int idx = 0;

        // Processar a linha para separar as palavras
        for (int i = 0; i < strlen(linha); i++) {
            if (linha[i] == ' ' || linha[i] == '\n' || linha[i] == '\0') {
                palavra[idx] = '\0';  // Finaliza a palavra
                if (idx > 0) {
                    
                    script(L, palavra, numero_linha);  // Chama a função script para atualizar a lista
                }
                idx = 0;  // Reinicia o índice para a próxima palavra
            } else {
                palavra[idx] = linha[i];
                idx++;
            }
        }
        numero_linha++;  // Incrementa o índice da linha
    }

    fclose(arquivo);  // Fecha o arquivo
    imprimirLista1(L);  // Imprime a lista de palavras e suas quantidades
    destruirLista1(L);  // Destrói a lista encadeada após uso

    return 0;
}
