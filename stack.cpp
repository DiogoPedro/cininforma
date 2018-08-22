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

    int vezes, numero, vetor, *solucao, i, j;

    cin >> vezes;
    solucao = new int[vezes];

    for(i=0, j=0; i<vezes; i++) {
        cin >> vetor;
        if (i == 0){//Começa adicionando na pilha;
            head = adicionar_lista(vetor, head);
        }

        if (vetor > head->val) {
            //cout << "vetor: " << vetor << endl;
            
            while (vetor >= head->val) {
                if(head->pont->val == -1){ // Possivel erro;
                    cout << "Encontrou o vazio" << endl;
                    break;
                }

                //cout << "Tirando da pilha: " << head->val << endl;
                solucao[j] = head->val;
                head = remocao_lista(head);
                j++;
            }

            //a lista ficou vazia ou o elemento já é maior;
            head = adicionar_lista(vetor, head);
            //cout << "Adicionou na pilha: " << head->val << endl;
        }else{
                head = adicionar_lista(vetor, head);
                //cout << "Adicinou direto na pilha: " << head->val << endl;
            }

        if (i == (vezes-1)) {//Condição para esvaziar a pilha, sem novos elementos p add;
            //cout << "Esvaziando" << endl;
            while (head->pont != NULL) {
                //cout << "valor do el com ==: " << head->val << endl;
                solucao[j] = head->val;
                head = remocao_lista(head);
                j++;
            }
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
    }
    
    if(head->pont == NULL){ //sou o ultimo elementod a pilha;
        delete head;
        return NULL;

    }else{
        auxiliar = head->pont;
        delete head;
        return auxiliar;
    }
}