#include <iostream>
using namespace std;

struct Node{
    int val;
    struct Node *pont;
};
typedef struct Node node;

node *adicionar_lista(int x, node *head);
void observar_lista(node *head);
node *remocao_lista(node *head);


int main(){
    node *head = new node;
    head->pont = NULL;
    head->val = -1;

    int vezes, numero, *vetor, *solucao, i, j;

    cin >> vezes;
    vetor = new int[vezes];
    solucao = new int[vezes];

    for(i=0, j=0; i<vezes; i++) {
        cin >> vetor[i];
        if (i == 0){//Começa adicionando na pilha;
            head = adicionar_lista(vetor[i], head);
        }

        if (i == vezes) {//Condição para esvaziar a pilha;
            cout << "Esvaziar tudo" << endl;
            while (head->val != -1) {
                cout << "valor do el com ==: " << head->val << endl;
                solucao[j] = head->val;
                head = remocao_lista(head);
                j++;
            }
        }

        if (vetor[i] > head->val) {
            while (vetor[i] <= head->val || head->val != -1) {
                cout << "valor do el no loop: " << head->val << endl;
                solucao[j] = head->val;
                head = remocao_lista(head);
                j++;
            }
            head = adicionar_lista(vetor[i], head);
            cout << "valor do el depois do loop: " << head->val << endl;
        }

        else {
            head = adicionar_lista(vetor[i], head);
            cout << "valor do caso no prim: " << head->val << endl;
        }

    }

    for(i=0; i<vezes; i++){
        cout << solucao[i] << " ";
    } cout << endl;
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