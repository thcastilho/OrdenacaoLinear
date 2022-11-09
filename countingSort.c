#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int *vet, int tam);
void printaVetor(int *vet, int tam);
int* geraVetor(int tam);

int main() {
    int n = 10;

    srand(time(NULL));

    int* vet = geraVetor(n);

    printaVetor(vet, n);
    printf("\n\n");

    countingSort(vet, n);

    printaVetor(vet, n);

    return 0;
}

int* geraVetor(int tam) {
	int i;
	int *vet = (int *) malloc(sizeof(int)*tam);
	
	for (i = 0; i < tam; i++)
		vet[i] = rand() % 10;
	
	return vet;
}

void countingSort(int* vet, int tam) {
    int maior, i;

    maior = vet[0];
    for (i = 1; i < tam; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }

    int* contador = malloc(sizeof(int) * (maior+1));

    for (i = 0; i <= maior; i++) {
        contador[i] = 0;
    }

    for (i = 0; i < tam; i++) {
        contador[vet[i]]++;
    }

    for (i = 1; i <= maior; i++) {
        contador[i] = contador[i] + contador[i - 1];
    }

    int *saida = malloc(sizeof(int) * tam);
    for (i = tam - 1; i >= 0; i--) {
        saida[contador[vet[i]] - 1] = vet[i];
        contador[vet[i]]--;
    }

    for (i = 0; i < tam; i++) {
        vet[i] = saida[i];
    }
}

void printaVetor(int* vet, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
}