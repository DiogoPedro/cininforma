#include <iostream>
#include <list>

using namespace std;

int main() {
    list <int> aula;
    list<int>::iterator it; //utilizado para interagir;

    for(int i=0; i<10; i++){
        aula.push_front(i); //add na frente;
        //aula.push_back(i); //add no final;
    }

    //
    it = aula.begin(); //coloca no head da lista;
    advance(it, 5); //posicionar o iterator;
    aula.insert(it, 0); //adicionar na posicao do iterator;
    aula.reverse(); //inverte a ordem;
    aula.sort(); //faz a ordenação;
    //

    cout << aula.size() << "\n"; //observamos o tamanho;

    for(int i=0; i<10; i++){
        cout << aula.front() << "\n"; //mostra o primeiro ele;
        aula.pop_front(); // remove o ele da frente;
        //aula.pop_back(); //remove o ultimo elemento;
    }



    return 0;
}