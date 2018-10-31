#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Dados
pthread_barrier_t aguardando;
int qnt_equecoes = 8;   //Se a quantidade de equacoes for menor que threads, entao threads tenderam a fica inativas;
int numero = 0;
int p = 10;

//Matriz
char X[2][1];
int  A[2][2];
int  B[2][1];

void atribuindoA(int  matriz[][2]);
void atribuindoB(int  matriz[][1]);
void atribuindoX(char matriz[][1]);

void *fun_soluc(void *indice){
    int i = *((int *)indice);
    int j = 1;
    
    printf("Indice: %d\n", i);
}

int main(){
    atribuindoA(A); atribuindoB(B); atribuindoX(X);

    printf("Digite o número de threads: ");
    scanf(" %d", &numero);   printf("\n");

    pthread_t threads[numero];
    int *indice[numero];

    //Criacao de uma barreira//
    pthread_barrier_init(&aguardando, NULL, numero);

    for(int i=0, j=0; i < qnt_equecoes; i++, j++){
        indice[i] = (int*) malloc(sizeof(int));
        *indice[i] = i;

        if(j == numero){
        //Eh necessario antes de enviar as threads, verificalas se já terminaram suas funções para usalas de novo//

            while(j>0){//Não sei se essa paradinha vai da certo//
                printf("Esperando a thread, terminar: %d\n", i-j);
                pthread_join(threads[i-j], NULL);
                j--;
            }

        }

        if(i < qnt_equecoes){
            printf("Criada a thread#%d\n", *indice[i]+1);   //O +1 representa que a thread 0 é a main;//
            pthread_create(&threads[j], NULL, fun_soluc, (void*) indice[i]);    //A variável j representa o indice do
        }

    }

    pthread_exit(NULL);
    //desalocar(&indice);
    pthread_barrier_destroy(&aguardando);
    
    return 0;
}


/********************************/
void atribuindoA(int matriz[][2]){
    matriz[0][0] = 2;
    matriz[0][1] = 1;
    matriz[1][0] = 5;
    matriz[1][1] = 7;

}

void atribuindoB(int matriz[][1]){
    matriz[0][0] = 11;
    matriz[1][0] = 13;

}

void atribuindoX(char matriz[][1]){
    matriz[0][0] = 'X';
    matriz[1][0] = 'Y';

}
