#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Dados
int numero = 0;
int qnt_equecoes = 2;   //Se a quantidade de equacoes for menor que threads, então thredas tenderam a fica inativas;
int p = 10;
pthread_barrier_t paradinha;

//Matriz
int A[2][2];
int B[2][1];
char X[2][1];

void atribuindoA(int matriz[][2]);
void atribuindoB(int matriz[][1]);
void atribuindoX(char matriz[][1]);

/*
void desalocar(int *head){
    for(int i=0; i < numero; i++){
        free(head[i]);
    }
}
*/

void *numsei(void *indice){
    int i = *((int *)indice);
    int j = 1;
    
    for(int k=0; k < p; k++){
        for(j=0; j< )
        

    }

}

int main(){
    atribuindoA(A); atribuindoB(B); atribuindoX(X);

    printf("Digite o número de threads: ");
    scanf(" %d", &numero);   printf("\n");

    pthread_t threads[numero];
    int *indice[numero];

    pthread_barrier_init(&paradinha, NULL, numero);

    for(int i=0; i < numero; i++){
        indice[i] = (int*) malloc(sizeof(int));
        *indice[i] = i;

        if(i < qnt_equecoes){
            printf("Criada a thread#%d\n", *indice[i]+1);
            pthread_create(&threads[i], NULL, numsei, (void*) indice[i]);
        }

    }

    pthread_exit(NULL);

    //desalocar(&indice);
    pthread_barrier_destroy(&paradinha);
    
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
