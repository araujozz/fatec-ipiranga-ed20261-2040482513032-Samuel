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

int alturaNo(No *no) {
    if (no == NULL) return -1;
    int esq = alturaNo(no->esq);
    int dir = alturaNo(no->dir);
    return 1 + (esq > dir ? esq : dir);
}

int profundidadeNo(No *raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    if (valor < raiz->dado)
        return profundidadeNo(raiz->esq, valor, prof + 1);
    return profundidadeNo(raiz->dir, valor, prof + 1);
}

int grauNo(No *no) {
    if (no == NULL) return 0;
    int g = 0;
    if (no->esq != NULL) g++;
    if (no->dir != NULL) g++;
    return g;
}

No *buscarNo(No *raiz, int valor) {
    if (raiz == NULL) return NULL;
    if (raiz->dado == valor) return raiz;
    if (valor < raiz->dado) return buscarNo(raiz->esq, valor);
    return buscarNo(raiz->dir, valor);
}

int imprimirAncestral(No *raiz, int valor) {
    if (raiz == NULL) return 0;
    if (raiz->dado == valor) return 1;
    int achou = 0;
    if (valor < raiz->dado)
        achou = imprimirAncestral(raiz->esq, valor);
    else
        achou = imprimirAncestral(raiz->dir, valor);
    if (achou) printf("%d ", raiz->dado);
    return achou;
}

void percorrerEmOrdem(No *no) {
    if (no == NULL) return;
    percorrerEmOrdem(no->esq);
    printf("%d ", no->dado);
    percorrerEmOrdem(no->dir);
}

void imprimirDescendentes(No *raiz, int valor) {
    if (raiz == NULL) return;
    if (raiz->dado == valor) {
        percorrerEmOrdem(raiz->esq);
        percorrerEmOrdem(raiz->dir);
        return;
    }
    if (valor < raiz->dado)
        imprimirDescendentes(raiz->esq, valor);
    else
        imprimirDescendentes(raiz->dir, valor);
}

int contarDescendentes(No *no) {
    if (no == NULL) return 0;
    return contarDescendentes(no->esq) + contarDescendentes(no->dir) + 1;
}

void liberarArvore(No *no) {
    if (no == NULL) return;
    liberarArvore(no->esq);
    liberarArvore(no->dir);
    free(no);
}

void relatorioNo(No *raiz, int valor) {
    No *no = buscarNo(raiz, valor);

    if (no == NULL) {
        printf("+----------------------------------+\n");
        printf("| ERRO: No %d nao encontrado       |\n", valor);
        printf("+----------------------------------+\n\n");
        return;
    }

    int prof = profundidadeNo(raiz, valor, 0);
    int alt  = alturaNo(no);
    int grau = grauNo(no);
    int qtd  = contarDescendentes(no->esq) + contarDescendentes(no->dir);

    printf("+----------------------------------+\n");
    printf("| RELATORIO DO NO: %-15d|\n", valor);
    printf("+----------------------------------+\n");
    printf("| Profundidade : %-17d|\n", prof);
    printf("| Altura       : %-17d|\n", alt);
    printf("| Grau         : %-17d|\n", grau);

    printf("| Ancestrais   : ");
    if (prof == 0)
        printf("(raiz, sem ancestrais)  ");
    else
        imprimirAncestral(raiz, valor);
    printf("\n");

    printf("| Descendentes : ");
    if (qtd == 0)
        printf("(folha, sem descend.)   ");
    else
        imprimirDescendentes(raiz, valor);
    printf("\n");

    printf("| Qtd Descend. : %-17d|\n", qtd);
    printf("+----------------------------------+\n\n");
}

/*  Parte C — Teste sistematico com os 4 nos pedidos pelo enunciado    */

int main(void) {
    /*
     * ABB resultante apos inserir: 50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65
     *
     *                  50              <- raiz
     *               /      \
     *             30        70         <- nos intermediarios
     *            /  \      /  \
     *          20   40    60   80
     *         /  \    \    \
     *        10  25   45   65          <- 10 e folha
     *
     * Verificacao manual dos 4 nos testados:
     *
     *  No 50 (raiz):
     *    - Prof=0, Alt=3, Grau=2
     *    - Sem ancestrais; todos os outros 10 nos sao descendentes
     *
     *  No 30 (intermediario esquerdo):
     *    - Prof=1, Alt=2, Grau=2
     *    - Ancestral: 50
     *    - Descendentes: 10, 20, 25, 40, 45  (5 nos)
     *
     *  No 10 (folha):
     *    - Prof=3, Alt=0, Grau=0
     *    - Ancestrais: 20, 30, 50
     *    - Sem descendentes
     *
     *  No 70 (intermediario direito):
     *    - Prof=1, Alt=2, Grau=2
     *    - Ancestral: 50
     *    - Descendentes: 60, 65, 80  (3 nos)
     */

    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    int n = 11;

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, valores[i]);

    /* Teste sistematico: raiz, no intermediario, folha, no intermediario */
    relatorioNo(raiz, 50); /* raiz */
    relatorioNo(raiz, 30); /* no intermediario esquerdo */
    relatorioNo(raiz, 10); /* folha */
    relatorioNo(raiz, 70); /* no intermediario direito */

    liberarArvore(raiz);
    return 0;
}