// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;


No *inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->dado = valor;
        novo->esq  = NULL;
        novo->dir  = NULL;
        return novo;
    }
    if (valor < raiz->dado)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->dado)
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void liberarArvore(No *no) {
    if (no == NULL) return;
    liberarArvore(no->esq);
    liberarArvore(no->dir);
    free(no);
}

/*  Parte A — Funcoes de parentesco                                    */


/*
 * Imprime todos os ancestrais do no com 'valor', do pai ate a raiz.
 *
 * Implementada recursivamente: percorre a arvore buscando o valor e,
 * na volta da recursao (pos-ordem do caminho), imprime cada no ancestral.
 * Isso garante a ordem do pai ate a raiz (crescente de profundidade).
 *
 * Caso base 1: raiz == NULL  -> valor nao existe, retorna 0.
 * Caso base 2: raiz->dado == valor -> encontrado, nao imprime o proprio no.
 * Caso recursivo: desce para esq ou dir; na volta, se achou, imprime raiz.
 *
 * Retorna 1 se o valor foi encontrado no caminho (sinaliza para ancestrais).
 */
int imprimirAncestral(No *raiz, int valor) {
    if (raiz == NULL) return 0;           /* caso base: nao encontrado */
    if (raiz->dado == valor) return 1;    /* caso base: encontrou o no */

    int achou = 0;
    if (valor < raiz->dado)
        achou = imprimirAncestral(raiz->esq, valor); /* caso recursivo esq */
    else
        achou = imprimirAncestral(raiz->dir, valor); /* caso recursivo dir */

    if (achou) printf("%d ", raiz->dado); /* imprime ancestral na volta */
    return achou;
}

/*
 * Percorre a subarvore em em-ordem e imprime todos os nos.
 * Usado por imprimirDescendentes para percorrer a subarvore do no alvo.
 */
void percorrerEmOrdem(No *no) {
    if (no == NULL) return;
    percorrerEmOrdem(no->esq);
    printf("%d ", no->dado);
    percorrerEmOrdem(no->dir);
}

/*
 * Imprime todos os descendentes do no com 'valor' (em-ordem),
 * exceto o proprio no.
 *
 * Localiza o no alvo e, em seguida, percorre em-ordem suas
 * subarvores esquerda e direita separadamente (excluindo o proprio no).
 */
void imprimirDescendentes(No *raiz, int valor) {
    if (raiz == NULL) {
        printf("(valor nao encontrado na arvore)\n");
        return;
    }
    if (raiz->dado == valor) {
        /* encontrou: percorre esq e dir sem imprimir o proprio no */
        percorrerEmOrdem(raiz->esq);
        percorrerEmOrdem(raiz->dir);
        return;
    }
    if (valor < raiz->dado)
        imprimirDescendentes(raiz->esq, valor);
    else
        imprimirDescendentes(raiz->dir, valor);
}

/*
 * Conta quantos descendentes o no possui.
 * Conta todos os nos da subarvore enraizada em 'no', exceto ele mesmo.
 */
int contarDescendentes(No *no) {
    if (no == NULL) return 0;
    return contarDescendentes(no->esq) + contarDescendentes(no->dir) + 1;
}


int main() {
    
    return 0;
}