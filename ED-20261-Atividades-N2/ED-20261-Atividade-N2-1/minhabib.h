#ifndef MINHABIB_H
#define MINHABIB_H

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

// Função principal
void analisar_arvore(No* raiz, int valorBusca);

// Funções auxiliares
void imprimir_nos_internos(No* raiz);
void imprimir_folhas(No* raiz);
void imprimir_niveis(No* raiz, int nivel_atual);
int calcular_altura(No* no);
int calcular_profundidade(No* raiz, int valor, int profundidade_atual);
void imprimir_ancestrais(No* raiz, int valor);
void imprimir_descendentes(No* no);
int calcular_grau(No* no);
No* buscar_no(No* raiz, int valor);

// Função de inserção
No* inserir(No* raiz, int valor);

#endif