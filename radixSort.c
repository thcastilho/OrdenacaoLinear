#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void radixSort(int *vet, int tam, int d);
void countingSort(int *vet, int tam, int pos);
void printaVetor(int *vet, int tam);
int* geraVetor(int tam);

int main() {
    int n = 10;
    
    srand(time(NULL));

    int* vet = geraVetor(n);
    printaVetor(vet, n);
    printf("\n\n");

    int d = 3;

    radixSort(vet, n, d);

    return 0;
}

int* geraVetor(int tam) {
	int i;
	int *vet = (int *) malloc(sizeof(int)*tam);
	
	for (i = 0; i < tam; i++)
		vet[i] = (rand() % (999 - 100 + 1)) + 100;
	
	return vet;
}

void printaVetor(int* vet, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
}

void radixSort(int *vet, int tam, int d) {
    int maior = vet[0];

    int i;
    for (i = 0; i < tam; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }

    int pos;
    for (pos = 1; maior / pos > 0; pos *= 10) {
        countingSort(vet, tam, pos);
        printaVetor(vet, tam);
        printf("\n\n");
    }
}

void countingSort(int *vet, int tam, int pos) {
    int maior, i;

    maior = (vet[0] / pos) % 10;

    for (i = 1; i < tam; i++) {
        if (((vet[i] / pos) % 10) > maior) {
            maior = vet[i];
        }
    }

    int* contador = malloc(sizeof(int) * (maior+1));

    for (i = 0; i <= maior; i++) {
        contador[i] = 0;
    }

    for (i = 0; i < tam; i++) {
        contador[(vet[i] / pos) % 10]++;
    }

    for (i = 1; i <= maior; i++) {
        contador[i] = contador[i] + contador[i - 1];
    }

    int *saida = malloc(sizeof(int) * tam);
    for (i = tam - 1; i >= 0; i--) {
        saida[contador[(vet[i] / pos) % 10] - 1] = vet[i];
        contador[(vet[i] / pos) % 10]--;
    }

    for (i = 0; i < tam; i++) {
        vet[i] = saida[i];
    }
}
