#include <iostream>
using namespace std;

struct Node{
    int vertice;
    struct Node *next;
    struct Node *list
};
typedef struct Node node;

void adicionar_vertice(node *head, int valor);

int main(){
    node *head = new node;


    return 0;
}

void adicionar_vertice(node *head, int valor){
    node auxiliar = head->list;
    node *elemento = new node;

    elemento->vertice = valor;
    elemento->next = NULL;
    
    while(auxiliar != NULL || auxiliar.vertice != valor)
        auxiliar = auxiliar->list;

    if(auxiliar.vertice == valor){
        while(auxiliar.next != NULL)
            auxiliar = auxiliar->next;

        auxiliar = elemento;
    }else{

    }

}