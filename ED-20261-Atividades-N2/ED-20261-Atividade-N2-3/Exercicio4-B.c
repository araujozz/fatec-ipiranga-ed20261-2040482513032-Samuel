// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>
int chamadas_rapida;  /* contador para potencia rapida */
int chamadas_ingenua; /* contador para potencia ingenua */

/*
 * Potenciacao Rapida (Fast Exponentiation) — O(log exp).
 *
 * Caso base:  exp == 0 -> qualquer numero elevado a 0 eh 1.
 * Caso recursivo:
 *   - exp par:  base^exp = (base^(exp/2))^2
 *   - exp impar: base^exp = base * base^(exp-1)
 *
 * A cada chamada exp e reduzido pela metade (quando par), entao
 * a altura da arvore de recursao e O(log exp).
 */
long long potenciaRapida(long long base, int exp) {
    chamadas_rapida++;

    if (exp == 0) return 1LL; /* caso base */

    if (exp % 2 == 0) {
        long long meio = potenciaRapida(base, exp / 2); /* caso recursivo par */
        return meio * meio;
    } else {
        return base * potenciaRapida(base, exp - 1); /* caso recursivo impar */
    }
}

/*
 * Potenciacao Ingenua — O(exp).
 *
 * Caso base:  exp == 0 -> retorna 1.
 * Caso recursivo: base^exp = base * base^(exp-1).
 * Faz exatamente 'exp' chamadas recursivas.
 */
long long potenciaIngenua(long long base, int exp) {
    chamadas_ingenua++;

    if (exp == 0) return 1LL; /* caso base */
    return base * potenciaIngenua(base, exp - 1); /* caso recursivo */
}

int main(void) {
    printf("%-15s %-15s %-15s %-15s %-15s\n",
        "Expressao", "Resultado", "Chamadas(rap)", "Chamadas(ing)", "Reducao");
    printf("%-15s %-15s %-15s %-15s %-15s\n",
           "----------", "---------", "-------------", "-------------", "-------");

    long long bases[] = {2,  3,  5,  7};
    int       exps[]  = {10, 7,  0, 12};
    int testes = 4;

    for (int i = 0; i < testes; i++) {
        chamadas_rapida  = 0;
        chamadas_ingenua = 0;

        long long r1 = potenciaRapida (bases[i], exps[i]);
        long long r2 = potenciaIngenua(bases[i], exps[i]);
        (void)r2; /* suprime warning de variavel nao usada */

        printf("%lld^%-10d %-15lld %-15d %-15d %.1fx mais rapida\n",bases[i], exps[i], r1,chamadas_rapida, chamadas_ingenua,(float)chamadas_ingenua / chamadas_rapida);
    }

    /*
     * Comparacao de chamadas recursivas (exemplo 2^10):
     *
     * Potenciacao Rapida (O(log n)):
     *   2^10 -> 2^5 -> 2^4 -> 2^2 -> 2^1 -> 2^0
     *   Aproximadamente log2(10) + 1 = ~5 chamadas
     *
     * Potenciacao Ingenua (O(n)):
     *   2^10 -> 2^9 -> 2^8 -> ... -> 2^0
     *   Exatamente 11 chamadas (exp + 1)
     *
     * Para exp=10: rapida usa ~5 chamadas vs ingenua usa 11 — 2x mais eficiente.
     * Para exp=12: a diferenca cresce ainda mais (log2(12) ≈ 4 vs 13 chamadas).
     * Em grandes exponentes (ex: 2^1000), a diferenca e dramatica:
     *   rapida: ~10 chamadas | ingenua: 1001 chamadas.
     */

    return 0;
}