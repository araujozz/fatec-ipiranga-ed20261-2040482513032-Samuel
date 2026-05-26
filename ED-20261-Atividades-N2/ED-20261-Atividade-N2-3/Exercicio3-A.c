// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>
int contador = 0; /* contador global de movimentos (Parte B) */

void hanoi(int n, char origem, char destino, char auxiliar, int nivel) {
    if (n == 0) return; /* caso base: sem discos, nada a fazer */

    /* Parte C: indentacao proporcional ao nivel atual */
    for (int i = 0; i < nivel * 2; i++) printf(" ");
    printf("[nivel %d] Movendo %d disco(s) de %c para %c (aux: %c)\n", nivel, n, origem, destino, auxiliar);

    /* Caso recursivo 1: move n-1 discos de origem para auxiliar */
    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    /* Move o disco maior */
    for (int i = 0; i < nivel * 2; i++) printf(" ");
    printf("[nivel %d] >>> Mover disco %d: %c -> %c\n", nivel, n, origem, destino);
    contador++;

    /* Caso recursivo 2: move n-1 discos de auxiliar para destino */
    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main(void) {
    int ns[] = {1, 3, 4};
    int qtd  = 3;

    for (int i = 0; i < qtd; i++) {
        int n = ns[i];
        contador = 0;
        printf("\n========================================\n");
        printf("Torres de Hanoi com n = %d\n", n);
        printf("========================================\n");
        hanoi(n, 'A', 'C', 'B', 0);
        printf("Total de movimentos: %d\n", contador);
    }

    /*
     * Parte B — Tabela de movimentos:
     *
     * n | Movimentos (contado) | 2^n - 1 (esperado)
     * --+---------------------+-------------------
     * 1 |          1          |         1
     * 2 |          3          |         3
     * 3 |          7          |         7
     * 4 |         15          |        15
     * 5 |         31          |        31
     * 6 |         63          |        63
     *
     * Conclusao: o numero de movimentos e exatamente 2^n - 1,
     * confirmando a complexidade exponencial O(2^n).
     */

    return 0;
}