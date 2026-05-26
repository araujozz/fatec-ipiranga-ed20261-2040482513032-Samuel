// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>

void trocar(int *a, int *b) {
    *a = *a + *b;/* desreferencia a e b, soma e armazena em *a */
    *b = *a - *b;/* desreferencia: *b recebe o valor original de *a */
    *a = *a - *b;/* desreferencia: *a recebe o valor original de *b */
}

int main(){
int x = 10;
int y = 20;

trocar(&x, &y);/* passa os enderecos de x e y para a funcao */

printf("\nDepois da troca:\n");
printf("Endereco de x: %p | Valor: %d\n", (void*)&x, x);/* & retorna o endereco de x */
printf("Endereco de y: %p | Valor: %d\n", (void*)&y, y);/* & retorna o endereco de y */

    return 0;
}