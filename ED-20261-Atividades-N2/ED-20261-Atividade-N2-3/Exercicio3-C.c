// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char origem, char destino, char auxiliar, int nivel) {
    if (n == 0) return;

    /* Indenta conforme a profundidade */
    for (int i = 0; i < nivel * 2; i++) printf(" ");
    printf("[prof. %d] hanoi(%d, %c, %c, %c)\n", nivel, n, origem, destino, auxiliar);

    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);

    for (int i = 0; i < nivel * 2; i++) printf(" ");
    printf("[prof. %d] >>> Mover disco %d: %c --> %c\n", nivel, n, origem, destino);

    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
}

int main(void) {
    printf("=== n = 1 ===\n");
    hanoi(1, 'A', 'C', 'B', 0);

    printf("\n=== n = 3 ===\n");
    hanoi(3, 'A', 'C', 'B', 0);

    printf("\n=== n = 4 ===\n");
    hanoi(4, 'A', 'C', 'B', 0);

    return 0;
}