#include <iostream>
using namespace std;

no *criar_no(int x);
/*
void adicionar_lista();
void procurar_lista();
void remocao_lista();
void permutar_lista();
*/

struct Node{
	int valor;
	struct Node *pont;
};
typedef struct Node node;

int main(){
	node *novo;
	novo = new node();
	novo->pont = NULL;
	novo->valor = x;

	return novo;

}

no *criar_no(int x){
	node *novo;
	novo = new node();
	novo->pont = NULL;
	novo->valor = x;

	return novo;
}
