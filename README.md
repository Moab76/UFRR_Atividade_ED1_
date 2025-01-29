# Programa de Contagem de Palavras em um Texto

Este programa em C realiza a contagem de palavras em um arquivo de texto e exibe as palavras encontradas junto com a quantidade de vezes que cada uma aparece em diferentes linhas. O programa utiliza uma lista encadeada para armazenar as palavras e suas respectivas ocorrências por linha.

## Funcionalidades

- **Leitura de Arquivo:** O programa lê o conteúdo de um arquivo de texto e processa linha por linha.
- **Contagem de Palavras:** Para cada palavra encontrada no texto, o programa conta quantas vezes ela aparece em cada linha.
- **Estrutura de Dados:** Utiliza listas encadeadas para armazenar as palavras e suas quantidades de ocorrências.
- **Impressão de Resultados:** Exibe as palavras encontradas e suas respectivas quantidades de ocorrências por linha.

## Estrutura do Projeto

O projeto é composto por três arquivos principais:

- `main.c`: Arquivo principal, responsável por ler o arquivo de entrada, processar as palavras e imprimir o resultado.
- `lista.h` e `listaEncadeada.h`: Definem as funções e a estrutura de dados utilizada para armazenar as palavras e suas ocorrências.
- `listaEncadeada.c`: Implementa as funções que manipulam as listas encadeadas.

## Como Usar

### Pré-requisitos

Certifique-se de ter o compilador GCC instalado em seu sistema. Caso não tenha, instale-o seguindo a documentação de seu sistema operacional.

### Passos

1. **Clone o repositório ou baixe os arquivos do projeto:**

    ```bash
    git clone https://github.com/seu-usuario/nome-do-repositorio.git
    cd nome-do-repositorio
    ```

2. **Compile o programa:**

    No terminal, navegue até o diretório onde os arquivos estão e execute:

    ```bash
    gcc -o contagem_palavras main.c listaEncadeada.c
    ```

3. **Prepare o arquivo de entrada:** 

    O programa espera um arquivo de texto contendo o texto a ser analisado. O nome do arquivo deve ser `historia_aventura.txt` ou modifique o código para passar o nome do arquivo como argumento.

4. **Execute o programa:**

    Após compilar, execute o programa com:

    ```bash
    ./contagem_palavras
    ```

    O programa lerá o arquivo `historia_aventura.txt`, contará as palavras e imprimirá o resultado no terminal.

### Exemplo de Saída

Ao rodar o programa, a saída será algo como:
```bash
Palavra "escuridão" 23 -> 1 
Palavra "tempos" 23 -> 1 
Palavra "amizade" 23 -> 1 
Palavra "buscar" 23 -> 1 
Palavra "outros" 23 -> 1 ...
```

Cada linha exibe a palavra, seguida pela linha onde ela foi encontrada e a quantidade de vezes que apareceu naquela linha.

## Estrutura de Dados

O programa utiliza uma lista encadeada para armazenar as palavras e suas quantidades de ocorrências. Cada palavra é armazenada com uma lista de quantidades, que armazena o número de vezes que a palavra aparece em cada linha.

- **Node (Estrutura de Palavra):** Contém a palavra e um ponteiro para a lista de quantidades.
- **ListaEncadeada (Estrutura de Quantidades):** Contém os números das linhas e as contagens de ocorrências para cada linha.
