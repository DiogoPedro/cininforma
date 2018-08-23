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
    int long i, j;
    char p, q;

    node *left = new node;
    node *right = new node;

    left->pont = NULL; right->pont = NULL;
    left->val = 'x';   right->val = 'y';

    getline(cin,rbs); //pegando caracteres;
    j = rbs.size();

    for(i=0; i < j; i++) {
        p = rbs[i];

        if(p == '<' || p == '{' || p == '[' || p == '('){
            adicionar_lista(p, left);
        }else { adicionar_lista(p, right); }

    }
    observar_lista(left->pont); cout << endl;
    observar_lista(right->pont); cout << endl;

    int long r[5];
    while(left->pont != NULL && right->pont != NULL){
        p = remocao_lista(left);
        q = remocao_lista(right);

        if(p == '<'){ r[0]++;}
        if(q == '>'){ r[0]--;}

        if(p == '{'){ r[1]++;}
        if(q == '}'){ r[1]--;}
        
        if(p == '['){ r[2]++;}
        if(q == ']'){ r[2]--;}

        if(p == '('){ r[3]++;}
        if(q == ')'){ r[3]--;}

    }

    cout << "depois da passarela" << endl;
    observar_lista(left); cout << endl;
    observar_lista(right); cout << endl;

    if(right->pont != NULL || left->pont != NULL){
        cout << "Impossible" << endl;
        while(right->pont != NULL){
            p = remocao_lista(right);
        }

        while(left->pont != NULL){
            p = remocao_lista(left);
        }

        delete left;
        delete right;

        return 0;
    }else 

    r[4] = 0;

    if(r[0] > 0) {r[4] += r[0];}
    if(r[1] > 0) {r[4] += r[1];}
    if(r[2] > 0) {r[4] += r[2];}
    if(r[3] > 0) {r[4] += r[3];}

    cout << r[4] << endl;

    delete left;
    delete right;
    

    return 0;

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