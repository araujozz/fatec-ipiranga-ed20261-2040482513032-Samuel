#include "minhabib.h"
#include <stdio.h>
#include <stdlib.h>

// Criar novo nó
No* criar_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Inserção recursiva na BST
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

// Nós internos (tem pelo menos 1 filho)
void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL)
        return;

    if (raiz->esq != NULL || raiz->dir != NULL)
        printf("%d ", raiz->valor);

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

// Folhas (sem filhos)
void imprimir_folhas(No* raiz) {
    if (raiz == NULL)
        return;

    if (raiz->esq == NULL && raiz->dir == NULL)
        printf("%d ", raiz->valor);

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

// Imprimir por níveis
void imprimir_niveis(No* raiz, int nivel_atual) {
    if (raiz == NULL)
        return;

    if (nivel_atual == 0) {
        printf("%d ", raiz->valor);
    } else {
        imprimir_niveis(raiz->esq, nivel_atual - 1);
        imprimir_niveis(raiz->dir, nivel_atual - 1);
    }
}


// Altura da árvore
int calcular_altura(No* no) {
    if (no == NULL)
        return -1;

    int alt_esq = calcular_altura(no->esq);
    int alt_dir = calcular_altura(no->dir);

    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
}

// Profundidade de um valor
int calcular_profundidade(No* raiz, int valor, int profundidade_atual) {
    if (raiz == NULL)
        return -1;

    if (raiz->valor == valor)
        return profundidade_atual;

    int esq = calcular_profundidade(raiz->esq, valor, profundidade_atual + 1);
    if (esq != -1)
        return esq;

    return calcular_profundidade(raiz->dir, valor, profundidade_atual + 1);
}


// Ancestrais (caminho até raiz)
void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL)
        return;

    if (raiz->valor == valor)
        return;

    if (raiz->esq && (raiz->esq->valor == valor)) {
        printf("%d ", raiz->valor);
        return;
    }

    if (raiz->dir && (raiz->dir->valor == valor)) {
        printf("%d ", raiz->valor);
        return;
    }

    imprimir_ancestrais(raiz->esq, valor);
    imprimir_ancestrais(raiz->dir, valor);

    if ((raiz->esq && raiz->esq->valor == valor) ||
        (raiz->dir && raiz->dir->valor == valor)) {
        printf("%d ", raiz->valor);
    }
}

// Descendentes (subárvore)
void imprimir_descendentes(No* no) {
    if (no == NULL)
        return;

    if (no->esq) {
        printf("%d ", no->esq->valor);
        imprimir_descendentes(no->esq);
    }

    if (no->dir) {
        printf("%d ", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}

// Buscar nó
No* buscar_no(No* raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    if (raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar_no(raiz->esq, valor);
    else
        return buscar_no(raiz->dir, valor);
}

// Grau do nó
int calcular_grau(No* no) {
    if (no == NULL)
        return 0;

    int grau = 0;
    if (no->esq) grau++;
    if (no->dir) grau++;

    return grau;
}

// ================= FUNÇÃO PRINCIPAL =================

void analisar_arvore(No* raiz, int valorBusca) {
    if (raiz == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    printf(" DIAGNOSTICO GERAL \n");

    // Raiz
    printf("Raiz: %d\n", raiz->valor);

    // Nós internos
    printf("Nos internos: ");
    imprimir_nos_internos(raiz);
    printf("\n");

    // Folhas
    printf("Folhas: ");
    imprimir_folhas(raiz);
    printf("\n");

    // Níveis
    int altura = calcular_altura(raiz);
    for (int i = 0; i <= altura; i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(raiz, i);
        printf("\n");
    }

    printf("\n DIAGNOSTICO ESPECIFICO (%d) \n", valorBusca);

    No* alvo = buscar_no(raiz, valorBusca);

    if (alvo == NULL) {
        printf("Valor nao encontrado.\n");
        return;
    }

    // Grau
    printf("Grau do no: %d\n", calcular_grau(alvo));

    // Ancestrais
    printf("Ancestrais: ");
    imprimir_ancestrais(raiz, valorBusca);
    printf("\n");

    // Descendentes
    printf("Descendentes: ");
    imprimir_descendentes(alvo);
    printf("\n");

    // Altura
    printf("Altura do no: %d\n", calcular_altura(alvo));

    // Profundidade
    printf("Profundidade: %d\n",
        calcular_profundidade(raiz, valorBusca, 0));

    // Subárvore
    printf("\n=== SUBARVORE ===\n");
    for (int i = 0; i <= calcular_altura(alvo); i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(alvo, i);
        printf("\n");
    }
}
