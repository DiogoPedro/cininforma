#include <iostream>
#include <string>
using namespace std;

struct Node{
    char val;
    struct Node *pont;
};
typedef struct Node node;

node *adicionar_lista(char x, node *head);
void observar_lista(node *head);
node *remocao_lista(node *head);

int main(){
    string rbs;
    node *head = new node;
    head->pont = NULL;
    head->val = 'x';

    while(getline(cin,rbs)){
        if(rbs == '<' || rbs == '{' || rbs == '['){
            adicionar_lista(rbs, head);
        } else { adicionar_lista(rb)
                left++;
            }
    }

    return 0;
}

node *adicionar_lista(char x, node *head){
    node *novo = new node;
    novo->pont = head;
    novo->val = x;

    return novo;
}

void observar_lista(node *head){
    if(head == NULL){
        cout << "error, lista vazia" << endl;
    } else while(head->pont != NULL){
        cout << head->val << " ";
        head = head->pont;
    }
    cout << endl;
}

node *remocao_lista(node *head){
    node *auxiliar;
    if(head->pont == NULL){ //tentando apagar nada;
        return head;
    } else{
        auxiliar = head->pont;
        delete head;
        return auxiliar;
    }
}