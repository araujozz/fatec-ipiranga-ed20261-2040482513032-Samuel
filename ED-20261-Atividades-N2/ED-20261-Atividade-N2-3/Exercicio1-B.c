// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>

int main(){
    int v [] = {10 , 20 , 30 , 40 , 50};
    int n = 5;
    int *p;


    /* a)Impirmindo os elementos do vetores*/
    printf("=== Elementos e enderecos ===\n");

    for(p = v; p < v + n; p++){/* ptr aponta do inicio ao fim */
        printf("Endereco: %p | Valor: %d\n", (void*)p, *p);/* & retorna o endereco de y */
    }

    /*b) somando os elementos*/
    int soma = 0;
    for(p = v; p < v + n; p++){/* ptr aponta do inicio ao fim */
        soma += *p;
    }
    printf("\nA soma do vetor é %d", soma);



    /*c) Inverter o vetor in-place com dois ponteiros*/
    int *ini = v; /*inicio aponta para o primeiro elemento */
    int *fim = v + n-1; /* fim aponta para o ultimo elemento */

    while(ini < fim){
         /* troca os valores apontados por inicio e fim */
        int temp = *ini;/* * desreferencia inicio para ler valor */
        *ini = *fim;/* * desreferencia inicio para escrever valor */
        *fim = temp;/* * desreferencia fim para escrever valor */

        ini++;/* avanca inicio (sizeof(int) bytes a frente)*/
        fim--; /* recua fim (sizeof(int) bytes atras) */
    }
    printf("\nVetor invertido\n");
    for (p = v; p < v + n; p++) {
        printf("%d ", *p); /* * desreferencia ptr para imprimir o valor */
    }
    printf("\n");

    return 0;
}