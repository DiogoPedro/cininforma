#include <iostream>
using namespace std;
void fazerleitura(int array[], int qnt);
int *ordenacao_merge(int array*, int auxliar[], int left, int right);
int *merge(int array[], int auxiliar[], int left, int right);

int main(){
    int qnt;
    cin >> qnt;
    
    int *array = new int[qnt];
    int *auxiliar = new int[qnt]; 

    fazerleitura(array, qnt);
    array = ordenacao_merge(array, auxiliar, 0, qnt-1);

    return 0;
}

int *ordenacao_merge(int *array, int auxiliar[], int left, int right){
    if(left == right){
        return array;
    }else 
        int m = (left+right)/2;
        ordenacao_merge(array, auxiliar, left, m);
        ordenacao_merge(array, auxiliar, m+1, right);
        merge(array, auxiliar, left, right);

}

int *merge(int array[], int auxiliar[], int left, int right){
    auxiliar






}

void fazerleitura(int array[], int qnt){
    for(int i=0; i< qnt; i++){
        cin >> array[i]; 
    }

}