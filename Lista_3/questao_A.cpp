#include <iostream>
using namespace std;
class node{
        node *left;
        node *right;
        int valor;

}

class treeBinary{
    public:
	    treeBinary();
	    ~treeBinary();

	    void inserir(int key);
	    node *buscar(int key);
	    void liberar_tree();
	    void imprimir_posOrdem();

    private:
        void inserir(int key, node *folha);
        node *buscar(int key, node *folha);
	    void liberar_tree(node *folha);
	    void imprimir_posOrdem(node *folha);
        node *raiz;
}

treeBinary::treeBinary(){
    raiz = NULL;
}

treeBinary::~treeBinary(){
    liberar_tree();
}

void treeBinary::liberar_tree(node *folha){
    if(folha != NULL){
        liberar_tree(folha->left);
        liberar_tree(folha->right);
        delete folha;
    }
}

void treeBinary::adicionar(int key, node *folha){
    if(key < folha->valor){
        if(folha->left != NULL){
            adicionar(key, folha->left);
        }else{
            folha->left = new node;
            node->valor = key;
            node->left = NULL;
            node->right = NULL;
        }

    }else if(key >= folha->valor){
        if(folha->right != NULL){
            adicionar(key, folha->right);
        }else{
            folha->right = new node;
            node->valor = key;
            node->left = NULL;
            node->right = NULL;
        }

    }

}


int main(){




    return 0;
}