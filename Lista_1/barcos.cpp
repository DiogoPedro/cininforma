#include <iostream>
#include <string>
using namespace std;
#define ptrnull NULL

struct Node{
    int val;
    struct Node *pont;
};
typedef struct Node node;

void adicionar_lista(int x, node *head);
void observar_lista(node *head);
int remocao_lista(node *head);

int main(){
    int tamanho, qnt_carros, size_car, contador=0, variavel;
    string posicao;

    node *posicao_esquerda = new node();    posicao_esquerda->pont = NULL;
    node *posicao_direita = new node();     posicao_direita->pont = NULL;

    cin >> tamanho >> qnt_carros;

    tamanho *= 100;
    do{
        cin >> size_car; //tamanho do carro;
        cin >> posicao;  //posicao para o carro;
        
        if(posicao == "left"){//adicionando na posicao esquerda;
            adicionar_lista(size_car, posicao_esquerda);
        }else{ //adicionando na posicao da direita;
            adicionar_lista(size_car, posicao_direita);
        }

        qnt_carros--;
    }while(qnt_carros != 0);//funcionando numa boa;

    while((posicao_esquerda->pont || posicao_direita->pont) != NULL ){
        variavel = tamanho;

        contador++;
        while((variavel >= 0) && (posicao_esquerda->pont != NULL)){
            if((variavel - posicao_esquerda->val) >= 0){
                variavel -= remocao_lista(posicao_esquerda);
            }else variavel = -1;

        }

        variavel = tamanho;
        contador++;
        while((variavel >= 0) && (posicao_direita->pont != NULL)){
            if((variavel - posicao_direita->val) >= 0){
                variavel -= remocao_lista(posicao_direita);
            }else variavel = -1;

        }
    
    }

    contador++;
    cout << contador;
    return 0;
}

void adicionar_lista(int x, node *head){
    node *novo = new node;
    novo->pont = NULL;
    novo->val = x;

    node *cursor = head; //assim nao perderei o head;

    while(cursor->pont != NULL){
        cursor = cursor->pont;
    }
    cursor->pont = novo;
}

void observar_lista(node *head){
    node *cursor = head;

    if(cursor == NULL){
        cout << "error, lista vazia" << endl;
    } else while(cursor->pont != NULL){
        cout << cursor->val << endl;
        cursor = cursor->pont;
    }

    cout << cursor->val << endl;;
}

int remocao_lista(node *head) {
    node *cursor = head;
    int valor;

    if(cursor->pont == NULL){//Proximo NO eh vazio
        cout << "Sem nada para remover" << endl;
        return 0;
    }else{
        cursor = cursor->pont;
        valor = cursor->val;
        head->pont = cursor->pont; //apontando para o prx cara que eu deletei;
        delete cursor;
        return valor;
    }
    
}