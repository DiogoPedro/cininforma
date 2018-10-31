#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
long numero = 0;
long contador = 0;

pthread_mutex_t mymutex = PTHREAD_MUTEX_INITIALIZER;

void *inc(void *threadid){
    long indice = *((long *)threadid);
    printf("Indice da thread eh:%ld\n", indice);

    for(long i = 0; i < 1000000; i++){
        pthread_mutex_lock(&mymutex); 

        if(contador == 999999){
            printf("Alcançado o número: 1000000 pela thread número: %ld\n", indice);
            exit(1);
        }else 
            contador++;
    
        pthread_mutex_unlock(&mymutex); 
    }
}

int main(){
    printf("Digite o numero de threads: ");
    scanf(" %ld", &numero);     printf("\n");

    pthread_t threadid[numero];
    long *task[numero];

    for(long i=1; i <= numero; i++){
        //printf("error\n");
        task[i] = (long*) malloc(sizeof(long));
        *task[i] = i;

        //printf("Antes de entrar na funcao temos o valor dele: %ld\n", *task[i]);
        pthread_create(&threadid[i], NULL, inc, (void *) task[i]);
    }
    
    pthread_exit(NULL);
    for(long i=0; i<numero; i++){ free(task[i]);}
}