#include <iostream>

struct FILA {
    int num;
    FILA *prox;
};

using namespace std;

int main() {


    FILA *inicio = NULL;
    FILA *fim = NULL;
    FILA *aux;

    int op;

    do {
        
        cout << "\nMENU DE OPCOES:\n";
        cout << "\n1 - inserir na fila\n";
        cout << "\n2 - consultar toda a fila\n";
        cout << "\n3 - remover da fila\n";
        cout << "\n4 - esvaziar a fila\n";
        cout << "\n5 - sair\n";

        cout << "\nDigite dua opcao: ";
        cin>>op;

        if (op < 1 || op > 5) {
            cout<<"opcao invalida.";
        }

        if (op == 1) {
            cout<<"Digite o numero a ser inserido: ";
            
            FILA *novo = new FILA();
            cin>>novo->num;
            novo->prox = NULL;
            
            if (inicio == NULL) {
                inicio = novo;
                fim = novo;
            } else {
                fim->prox = novo;
                fim = novo;
            }

            cout<<"Numero inserido na fila.";
        }

        if (op == 2) {

            if (inicio == NULL) {
                cout<<"Fila esta vazia.";
            } else {
                cout<<"Consultando os elementos da fila: ";

                aux = inicio;
                while(aux != NULL) {
                    cout<<aux->num<< (aux->prox != NULL ? " -> " : " ");
                    aux = aux->prox;
                }
            }
        }

        if (op == 3) {

            if (inicio == NULL) {
                cout<<"Fila esta vazia.";
            } else {

                cout<<"Inicio "<<inicio->num<<" removido.";
                aux = inicio;
                inicio = inicio->prox;
                delete(aux);
            }
        }

        if (op == 4) {

            if (inicio == NULL) {
                cout<<"Fila esta vazia.";
            } else {
            
                cout<<"Esvaziando a fila.\n";

                aux = inicio;
                while(aux != NULL) {
                    inicio = inicio->prox;
                    delete(aux);
                    aux = inicio;
                }

                cout<<"Fila esvaziada.";
            } 
        }

    } while(op != 5);

    return 0;
}