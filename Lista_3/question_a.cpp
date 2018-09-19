#include <iostream>
#include <cstdlib>
using namespace std;

class node{
    private:
        node *left;
        node *right;
        
    public:
        int long valor;
};

class tree{
    public: 
        node *head;
        
        tree();
        void add_node(int num);
        void printar();
};

tree::tree(){
    this->head = NULL;

}

void tree::add_node(int num){
    node *folha = new node();
    folha->valor = num;
    

}


int main(){
    int num;
    tree *arvore_binaria = new tree(); 

    while(cin >> num){
        arvore_binaria->add_node(num);

    }

    return 0;
}

