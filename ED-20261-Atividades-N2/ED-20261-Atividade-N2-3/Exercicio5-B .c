// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esq;
    struct No *dir;
} No;

/* Insere um valor na ABB e retorna a nova raiz */
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

/*
 * Altura do no: maior caminho do no ate uma folha descendente.
 * Retorna -1 para ponteiro nulo (convenção: no nulo tem altura -1).
 */
int alturaNo(No *no) {
    if (no == NULL) return -1; /* caso base */
    int esq = alturaNo(no->esq);
    int dir = alturaNo(no->dir);
    return 1 + (esq > dir ? esq : dir);
}

/*
 * Profundidade do no: distancia em arestas da raiz ate o no.
 * Retorna -1 se o valor nao existir na arvore.
 */
int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1; /* valor nao encontrado */
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado)
        return profundidadeNo(raiz->esq, valor, prof + 1);
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

/*
 * Grau do no: numero de filhos diretos (0, 1 ou 2).
 */
int grauNo(No *no) {
    if (no == NULL) return 0;
    int g = 0;
    if (no->esq != NULL) g++;
    if (no->dir != NULL) g++;
    return g;
}

/* Percurso em-ordem para imprimir grau de cada no */
void imprimirGrausEmOrdem(No *no) {
    if (no == NULL) return;
    imprimirGrausEmOrdem(no->esq);
    printf("  No %2d: grau = %d\n", no->dado, grauNo(no));
    imprimirGrausEmOrdem(no->dir);
}

/* Libera toda a memoria da arvore */
void liberarArvore(No *no) {
    if (no == NULL) return;
    liberarArvore(no->esq);
    liberarArvore(no->dir);
    free(no);
}

int main(void) {

    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int n = 11;

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, valores[i]);

    /* Parte B-a: Altura dos nos */
    printf("=== Parte B-a: Altura dos nos ===\n");
    int nos_altura[] = {50, 30, 70, 20, 10};
    for (int i = 0; i < 5; i++) {
        /* busca o no para obter a altura */
        int v = nos_altura[i];
        No *ptr = raiz;
        while (ptr && ptr->dado != v)
            ptr = (v < ptr->dado) ? ptr->esq : ptr->dir;
        printf("  alturaNo(%d) = %d\n", v, alturaNo(ptr));
    }

    /* Parte B-b: Profundidade dos nos */
    printf("\n=== Parte B-b: Profundidade dos nos ===\n");
    int nos_prof[] = {50, 30, 70, 45, 10};
    for (int i = 0; i < 5; i++)
        printf("  profundidadeNo(%d) = %d\n", nos_prof[i],
               profundidadeNo(raiz, nos_prof[i], 0));

    /* Parte B-c: Grau de cada no (em-ordem) */
    printf("\n=== Parte B-c: Grau de cada no (em-ordem) ===\n");
    imprimirGrausEmOrdem(raiz);

    /* Parte B-d: Altura total da arvore */
    printf("\n=== Parte B-d: Altura total da arvore ===\n");
    printf("  alturaNo(raiz) = %d\n", alturaNo(raiz));

    liberarArvore(raiz);
    return 0;
}