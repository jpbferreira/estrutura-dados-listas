#include <iostream>

struct PILHA {
    int num;
    PILHA *prox;
};

using namespace std;

int main() {


    PILHA *topo = NULL;
    PILHA *aux;
    int op;

    do {
        
        cout << "\nMENU DE OPCOES:\n";
        cout << "\n1 - inserir na pilha\n";
        cout << "\n2 - consultar toda a pilha\n";
        cout << "\n3 - remover da pilha\n";
        cout << "\n4 - esvaziar a pilha\n";
        cout << "\n5 - sair\n";

        cout << "\nDigite dua opcao: ";
        cin>>op;

        if (op < 1 || op > 5) {
            cout<<"opcao invalida.";
        }

        if (op == 1) {
            cout<<"Digite o numero a ser inserido: ";
            
            PILHA *novo = new PILHA();
            cin>>novo->num;
            novo->prox = topo;
            topo = novo;

            cout<<"Numero inserido na pilha.";
        }

        if (op == 2) {

            if (topo == NULL) {
                cout<<"Pilha esta vazia.";
            } else {
                cout<<"Consultando os elementos da pilha: ";

                aux = topo;
                while(aux != NULL) {
                    cout<<aux->num<< " ";
                    aux = aux->prox;
                }
            }
        }

        if (op == 3) {

            if (topo == NULL) {
                cout<<"Pilha esta vazia.";
            } else {

                cout<<"Topo "<<topo->num<<" removido.";
                aux = topo;
                topo = topo->prox;
                delete(aux);
            }
        }

        if (op == 4) {

            if (topo == NULL) {
                cout<<"Pilha esta vazia.";
            } else {
            
                cout<<"Esvaziando a pilha.\n";

                aux = topo;
                while(aux != NULL) {
                    topo = topo->prox;
                    delete(aux);
                    aux = topo;
                }

                cout<<"Pilha esvaziada.";
            } 
        }

    } while(op != 5);

    return 0;
}