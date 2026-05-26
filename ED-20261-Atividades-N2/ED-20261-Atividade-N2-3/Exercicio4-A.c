// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>

int chamadas; /* contador global de chamadas recursivas */

/*
 * Busca Binaria Recursiva.
 *
 * Caso base 1: inicio > fim  -> elemento nao encontrado, retorna -1.
 * Caso base 2: vet[meio] == alvo -> elemento encontrado, retorna meio.
 * Caso recursivo:
 *   - Se alvo < vet[meio]: busca na metade esquerda (fim = meio - 1).
 *   - Se alvo > vet[meio]: busca na metade direita (inicio = meio + 1).
 *
 * Complexidade: O(log n) — o espaco de busca e dividido pela metade a cada chamada.
 */
int buscaBinaria(int *vet, int inicio, int fim, int alvo) {
    chamadas++;

    if (inicio > fim) return -1; /* caso base 1: nao encontrado */

    int meio = (inicio + fim) / 2;

    if (*(vet + meio) == alvo) return meio; /* caso base 2: encontrado */

    if (alvo < *(vet + meio))
        return buscaBinaria(vet, inicio, meio - 1, alvo); /* busca esquerda */
    else
        return buscaBinaria(vet, meio + 1, fim, alvo);    /* busca direita */
}

int main(void) {
    int dados[] = {2, 5, 8, 12, 16, 23, 38, 45, 72, 91};
    int n = 10;

    printf("Vetor: ");
    for (int i = 0; i < n; i++) printf("%d ", dados[i]);
    printf("\n\n");

    /* Busca 1: elemento presente (38) */
    chamadas = 0;
    int idx = buscaBinaria(dados, 0, n - 1, 38);
    printf("Busca por 38: indice = %d | chamadas = %d\n", idx, chamadas);

    /* Busca 2: elemento ausente (99) */
    chamadas = 0;
    idx = buscaBinaria(dados, 0, n - 1, 99);
    printf("Busca por 99: indice = %d | chamadas = %d\n", idx, chamadas);

    /* Busca 3: primeiro elemento (2) */
    chamadas = 0;
    idx = buscaBinaria(dados, 0, n - 1, 2);
    printf("Busca por  2: indice = %d | chamadas = %d\n", idx, chamadas);

    return 0;
}