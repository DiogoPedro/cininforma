#include <iostream>
using namespace std;

struct Node{
    int vertice;
    struct Node *next;
    struct Node *list
};
typedef struct Node node;

node *criar_no();
void criar_vertice(node *head, int indice), int indice2;

int main(){
    node *head = new node;
    return 0;
}

node *criar_no(){
    node *novo = new node;
    novo->next = NULL;
    novo->list = NULL;

    return novo;
}

void criar_vertice(node *head, int indice, int indice2){
    node auxiliar = head;
    
    while(auxiliar->list != NULL || auxiliar.vertice != indice)
        auxiliar = auxiliar->list;

    if(auxiliar.vertice == indice){
        auxiliar = auxiliar->next;

        while(auxiliar->next != NULL || auxiliar->vertice != indice2)
            auxiliar = auxiliar->next;

        if(auxiliar->next == NULL){
            node *novo = criar_no();
            auxiliar->next = novo;
            novo->vertice = indice2;
        }

    }else{
        auxiliar->list = elemento;
        elemento->list = NULL;
    }

}