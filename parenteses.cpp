#include <iostream>
#include <string>
using namespace std;
#define ptrnull NULL

struct Node{
    char val;
    struct Node *pont;
};
typedef struct Node node;

void adicionar_lista(char x, node *head);
void observar_lista(node *head);
char remocao_lista(node *head);

int main(){
    string rbs;
    int possibilidade = 1;
    int long i, j;
    char p, q;

    node *left = new node;
    node *right = new node;
    node *left2 = new node;

    left->pont = NULL; right->pont = NULL; left2->pont = NULL; 
    left->val = 'x';   right->val = 'y'; left2->val = 'z';
    getline(cin,rbs); //pegando caracteres;
    j = rbs.size();

    for(i=0; i < j; i++) {
        p = rbs[i];

        if(p == '<' || p == '{' || p == '[' || p == '('){
            adicionar_lista(p, left);
            adicionar_lista(p, left2);
        }else {
            adicionar_lista(p, right); 
            if(left->pont == NULL){
                possibilidade = 0;
                break;
            }else p = remocao_lista(left); /********/
        }

    }

    int long r[5]; r[0]= 0; r[1]= 0; r[2]= 0; r[3]= 0;
    while(left2->pont != NULL){
        p = remocao_lista(left2);

        if(p == '<'){ r[0]++;}
        if(p == '{'){ r[1]++;}
        if(p == '['){ r[2]++;}
        if(p == '('){ r[3]++;}

    }

    while(left->pont != NULL){
        p = remocao_lista(left);    
    }

    while(right->pont != NULL){
        p = remocao_lista(right);

        if(p == '>'){ r[0]--;}
        if(p == '}'){ r[1]--;}
        if(p == ']'){ r[2]--;}
        if(p == ')'){ r[3]--;}
    }

    r[4] = 0;
    if(r[0] > 0) {r[4] += r[0];}
    if(r[1] > 0) {r[4] += r[1];}
    if(r[2] > 0) {r[4] += r[2];}
    if(r[3] > 0) {r[4] += r[3];}

    if(possibilidade == 0 || (r[0] + r[1] + r[2] + r[3]) != 0){
        cout << "Impossible" << endl;

        delete left;
        delete left2;
        delete right;

    }else{

    cout << r[4] << endl;

    delete left;
    delete right;
    delete left2;
    
    return 0;
    }


}

void adicionar_lista(char x, node *head){
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
        cout << cursor->val << '-';
        cursor = cursor->pont;
    }

    cout << cursor->val << endl;;
}

char remocao_lista(node *head) {
    node *cursor = head;
    char sinal;

    if(cursor->pont == NULL){//Proximo NO eh vazio
        cout << "Sem nada para remover" << endl;
        return head->val;
    }
    
    cursor = cursor->pont;
    sinal = cursor->val;
        
    head->pont = cursor->pont; //apontando para o prx cara que eu deletei;
    delete cursor;
    return sinal;
    
}