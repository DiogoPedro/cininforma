    #include <iostream>
    #include <stdio.h>
    using namespace std;

    void leitura(int long long armazenamento[], int long long qnt);
    int long long busca_binaria(int long long armazenamento[], int long long valor, int long long l, int long long r);

    int main(){
        int long long array, buscas, valor, i;
        scanf(" %lld %lld", &array, &buscas); //armazena tamanho do array, e quantidade de buscas;

        int long long *armazenamento = new int long long[array]; //alocando o vetor;
        leitura(armazenamento, array);  //o vetor esta preenchido com os valores;

        for(i=0; i < buscas; i++){
            scanf(" %lld", &valor);   //recebe o valor procurado;
            valor = busca_binaria(armazenamento, valor, 0, array-1); //retorna a posicao do valor encontrado, se não retorna -1;
            printf("%lld\n", valor);
        }

        delete armazenamento; //ñ esquecer;
        return 0;
    }

    int long long busca_binaria(int long long armazenamento[], int long long valor, int long long l, int long long r){
        int long long m, reserve = -1;

        do{
            m = (l+r)/2;    //metade do vetor;
            if(armazenamento[m] == valor){  //encontrou o valor;
                reserve = m;    //coloca o ultimo valor encontrado;
                r = m-1; // decrementa, encontra o primeiro valor e nao faz um loop;

            }else if(valor < armazenamento[m]){ //o valor eh menor, entao procure a esquerda;
                r = m-1;

            }else l = m+1; // o valor eh maior, entao procure a direita;

        }while(l <= r); //entao ta procurando ainda;

        return reserve; // ja retorna com -1, se nao encontrar;
    }

    void leitura(int long long armazenamento[], int long long qnt){
        int long long i, j;
        
        for(i=0; i < qnt ; i++){
            scanf(" %lld", &j);
            armazenamento[i] = j;
        }
    }