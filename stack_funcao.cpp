#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node *pont;
};
typedef struct Node node;
;

node *adicionar_lista(int x, node *head);
void observar_lista(node *head);
node remocao_lista(node *head);
//void proxima_lista();


int main(){
    node *head = new node;
    head->pont = NULL;
    head->val = 0;

    head = adicionar_lista(5, head);
    head = adicionar_lista(4, head);
    head = adicionar_lista(3, head);
    head = adicionar_lista(2, head);
    head = adicionar_lista(7, head);

    observar_lista(head);

    return 0;
}

node *adicionar_lista(int x, node *head){
    node *novo = new node;
    novo->pont = head;
    novo->val = x;

    return novo;
}

void observar_lista(node *head){
    if(head == NULL){
        cout << "error, lista vazia" << endl;
    } else while(head != NULL){
        cout << head->val << endl;
        head = head->pont;
    }

}

node *remocao_lista(node *head){
    node *auxiliar;
    if(head == NULL){ //tentando apagar nada, da erro;
        return NULL;

    } else if(head->pont == NULL){ //sou o ultimo elementod a pilha;
        delete head;
        return NULL;

    } else {
        auxiliar = head->pont;
        delete head;
        return auxiliar;
    }
}