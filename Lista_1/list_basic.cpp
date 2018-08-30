#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node *pont;
};
typedef struct Node node;

node *criar_no(int x);
void adicionar_lista(int x, node *head);
/*
void procurar_lista();
void remocao_lista();
void permutar_lista();
*/

int main(){
    node *head = new node();

    adicionar_lista(0, head);
    adicionar_lista(1, head);
    adicionar_lista(2, head);
    adicionar_lista(3, head);

    cout << "O valor das listas sao " << head->val << endl;
    head= head->pont;

    cout << "O valor das listas sao " << head->val << endl;
    head= head->pont;

    cout << "O valor das listas sao " << head->val << endl;
    head= head->pont;

    cout << "O valor das listas sao " << head->val << endl;
    head= head->pont;

    cout << "aguardo lixo de memoria " << head->val << endl;
    head= head->pont;

    return 0;
}

node *criar_no(int x){//Faz uma alocação dinamica de um novo node,
    node *novo;		//E retorna o endereço desse node;
    novo = new node();
    novo->pont = NULL;
    novo->val = x;

    return novo;
}

void adicionar_lista(int x, node *head){
    node *el_novo = criar_no(x);
    node *percussor->pont = head->pont;

    while(percussor->pont != NULL){
        percussor = percussor->pont;
    }

    el_novo->pont = percussor->pont;
}

