#include <stdio.h>


typedef struct {
    int *array;
    int tamanho;
} MeuVetor;


MeuVetor* inicializarVetor(int capacidade) {
    MeuVetor *vetor = (MeuVetor*)malloc(sizeof(MeuVetor));
    vetor->array = (int*)malloc(sizeof(int) * capacidade);
    vetor->tamanho = 0;
    return vetor;
}


void travessia(MeuVetor *vetor) {
    for (int i = 0; i < vetor->tamanho; i++) {
        printf("%d ", vetor->array[i]);
    }
    printf("\n");
}


void inserir(MeuVetor *vetor, int elemento) {
    vetor->array[vetor->tamanho] = elemento;
    vetor->tamanho++;
}


void excluir(MeuVetor *vetor, int elemento) {
    int i;
    for (i = 0; i < vetor->tamanho; i++) {
        if (vetor->array[i] == elemento) {
            break;
        }
    }
    
    if (i == vetor->tamanho) {
        printf("Elemento não encontrado\n");
    } else {
        for (int j = i; j < vetor->tamanho - 1; j++) {
            vetor->array[j] = vetor->array[j + 1];
        }
        vetor->tamanho--;
    }
}


int pesquisar(MeuVetor *vetor, int elemento) {
    for (int i = 0; i < vetor->tamanho; i++) {
        if (vetor->array[i] == elemento) {
            return 1; 
        }
    }
    return 0;
}


void liberarVetor(MeuVetor *vetor) {
    free(vetor->array);
    free(vetor);
}

int main() {
    MeuVetor *meuVetor = inicializarVetor(10);

    inserir(meuVetor, 6);
    inserir(meuVetor, 7);
    inserir(meuVetor, 8);

    printf("Vetor: ");
    travessia(meuVetor);

    excluir(meuVetor, 2);

    printf("Vetor após exclusão: ");
    travessia(meuVetor);

    if (pesquisar(meuVetor, 1)) {
        printf("O elemento 1 está no Vetor.\n");
    } else {
        printf("O elemento 1 não encontrado.\n");
    }

    if (pesquisar(meuVetor, 4)) {
        printf("O elemento 4 está no vetor.\n");
    } else {
        printf("O elemento 4 não encontrado.\n");
    }

    liberarVetor(meuVetor);

    return 0;
}
