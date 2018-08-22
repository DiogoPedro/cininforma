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
int enfileirar(int vezes);

int main(){
    int vezes, j;
    cin >> vezes;

    while(vezes != 0) {
        j = enfileirar(vezes);
        if(j == 0){
            cout << "no" << endl;
        } else {cout << "yes" << endl;}
        cin >> vezes;
    }
    
}

int enfileirar(int vezes){
    node *head = new node;
    head->pont = NULL;
    head->val = -1;

    int numero, vetor, *solucao, i, j;
    solucao = new int[vezes+5];

    for(i=0, j=0; i<vezes; i++) {
        cin >> vetor;
        if (i == 0){//Começa adicionando na pilha;
            head = adicionar_lista(vetor, head);
        }

        if (vetor > head->val) {
            //cout << "vetor: " << vetor << endl;
            
            while (vetor > head->val) {
                if(head->val == (-1)){ // Possivel erro;
                    break;
                    //cout << "Encontrou o vazio" << endl;
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
            while (head->val != (-1)) {
                //cout << "valor do el com ==: " << head->val << endl;
                solucao[j] = head->val;
                head = remocao_lista(head);
                j++;
            }
        }

    }

    for(i=0, j=1; i<(vezes-1); i++){
        if(solucao[i] > solucao[i+1]){
            j = 0; 
            break;
        }
    }

    delete head;
    delete solucao;
    return j;
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
    if(head->val == -1){ //tentando apagar nada;
        return head;
    } else{
        auxiliar = head->pont;
        delete head;
        return auxiliar;
    }
}