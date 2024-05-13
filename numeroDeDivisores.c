#include <stdio.h>

#define MAX_TAMANHO 10000

int calculaNumeroDeDivisores(int n) {
    int quantidadeDeDivisores = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            quantidadeDeDivisores++;
        }
    }
    return quantidadeDeDivisores;
}

int acharIndice(int k, int tamanho, int sequencia[]) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;



    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if(sequencia[meio] == k){
            return meio;
        }

        if (sequencia[meio] <= k) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return inicio;
}

int calculaQuantidadeDaSequencia(int inicio, int fim, int sequencia[]){
    int contador = 0;
    
    int indice = acharIndice(inicio, MAX_TAMANHO, sequencia);

    int i = indice;

    while(1){
        if(sequencia[i] > fim){
            break;
        }
        contador++;
        i++;
    }

    return contador;

}

int main() {
    int sequencia[MAX_TAMANHO];
    int quantidadeDeTestes;

    sequencia[0] = 1;
    
    for(int i = 1;i < MAX_TAMANHO; i++) {
        int elementoAnterior = sequencia[i - 1];
        int novoElemento = elementoAnterior + calculaNumeroDeDivisores(elementoAnterior);
        sequencia[i] = novoElemento;
    }

    sequencia[MAX_TAMANHO] = sequencia[MAX_TAMANHO - 1] + calculaNumeroDeDivisores(sequencia[MAX_TAMANHO - 1]);

    
    printf("Digite a quantidade de testes: ");
    
    scanf("%d", &quantidadeDeTestes);

    if(quantidadeDeTestes > 1000){
        printf("O limite de testes é 1000.\n");
        return 0;
    }
    
    int vetorTestes[quantidadeDeTestes * 2];

    printf("Digite o intervalo dos testes separados por espaço: \n");

    int auxContador = 0;
    for(int i = 0; i < quantidadeDeTestes; i++){
        printf("Caso %d: ", i + 1);
        scanf("%d %d", &vetorTestes[auxContador], &vetorTestes[auxContador + 1]);
        auxContador += 2;
    }

    for(int i = 0; i < quantidadeDeTestes * 2; i+= 2){
        printf("Resultado do teste %d com intervalo %d %d: ", i/2 + 1, vetorTestes[i], vetorTestes[i + 1]);
        printf("%d \n", calculaQuantidadeDaSequencia(vetorTestes[i], vetorTestes[i + 1], sequencia));
    }

    return 0;
}
    