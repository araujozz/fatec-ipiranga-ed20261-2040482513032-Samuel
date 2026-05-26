// RA: 2040482513032 - Samuel Goes C. de Araujo
#include <stdio.h>
#include <stdlib.h>

/* Calcula e RETORNA a media aritmetica */
float calcularMedia(float *vet, int n) {
    float soma = 0.0f;
    float *ptr = vet;
    float *fim  = vet + n;

    while (ptr < fim) {
        soma += *ptr; /* desreferencia ptr para acessar o elemento atual */
        ptr++;        /* avanca ptr para o proximo float (4 bytes adiante) */
    }
    return soma / n;
}

/* Encontra o maior e o menor valor;
   armazena nos ponteiros recebidos */
void encontrarExtremos(float *vet, int n, float *maior, float *menor) {
    *maior = *vet; /* desreferencia: inicializa maior com o primeiro elemento */
    *menor = *vet; /* desreferencia: inicializa menor com o primeiro elemento */

    float *ptr = vet + 1;
    float *fim  = vet + n;

    while (ptr < fim) {
        if (*ptr > *maior) /* desreferencia ptr e maior para comparar */
            *maior = *ptr; /* desreferencia: escreve novo maximo no endereco de maior */
        if (*ptr < *menor) /* desreferencia ptr e menor para comparar */
            *menor = *ptr; /* desreferencia: escreve novo minimo no endereco de menor */
        ptr++;
    }
}

/* Normaliza o vetor: cada elemento eh dividido pelo valor maximo */
void normalizar(float *vet, int n) {
    float maior, menor;
    encontrarExtremos(vet, n, &maior, &menor); /* passa enderecos de maior e menor */

    float *ptr = vet;
    float *fim  = vet + n;

    while (ptr < fim) {
        *ptr = *ptr / maior; /* desreferencia ptr: le e escreve o valor normalizado */
        ptr++;
    }
}

/* Imprime o vetor formatado */
void imprimirVetor(float *vet, int n, const char *titulo) {
    printf("\n=== %s ===\n", titulo);
    float *ptr = vet;
    float *fim  = vet + n;

    while (ptr < fim) {
        printf("%.4f ", *ptr); /* desreferencia ptr para imprimir o valor */
        ptr++;
    }
    printf("\n");
}

int main(void) {
    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};
    int n = 6;

    imprimirVetor(notas, n, "Vetor original");

    float media = calcularMedia(notas, n);
    printf("Media: %.4f\n", media);

    float maior, menor;
    encontrarExtremos(notas, n, &maior, &menor); /* & passa o endereco de maior e menor */
    printf("Maior: %.4f\n", maior);
    printf("Menor: %.4f\n", menor);

    normalizar(notas, n);

    imprimirVetor(notas, n, "Vetor apos normalizacao");
    return 0;
}