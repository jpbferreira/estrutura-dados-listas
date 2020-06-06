#include <iostream>

using namespace std;

int main()
{

    struct LISTA
    {
        int num;
        LISTA *prox;
    };

    LISTA *inicio = NULL;
    LISTA *fim = NULL;
    LISTA *aux;
    LISTA *anterior;

    int op, numero, achou;

    do
    {

        cout << "\nMENU DE OPCOES:\n";
        cout << "\n1 - inserir no inicio\n";
        cout << "\n2 - inserir no fim\n";
        cout << "\n3 - consultar\n";
        cout << "\n4 - remover da lista\n";
        cout << "\n5 - esvaziar\n";
        cout << "\n6 - sair\n";

        cout << "\nDigite sua opcao: \n";
        cin >> op;

        if (op < 1 || op > 6)
            cout << "Opcao invalida!!";

        if (op == 1)
        {
            cout << "Digite o numero a ser inserido no inicio: ";
            LISTA *novo = new LISTA();
            cin >> novo->num;

            if (inicio == NULL)
            {
                inicio = novo;
                fim = novo;
                fim->prox = NULL;
            }
            else
            {
                novo->prox = inicio;
                inicio = novo;
                fim->prox = inicio;
            }
            cout << "Numero inserido no inicio da lista.";
        }

        if (op == 2)
        {

            cout << "Digite o numero a ser inserido no fim: ";
            LISTA *novo = new LISTA();
            cin >> novo->num;

            if (inicio == NULL)
            {
                inicio = novo;
                fim = novo;
                fim->prox = NULL;
            }
            else
            {
                fim->prox = novo;
                novo->prox = inicio;
                fim = novo;
            }
            cout << "Numero inserido no fim da lista.";
        }

        if (op == 3)
        {

            if (inicio == NULL)
            {
                cout << "Lista esta vazia.";
            }
            else
            {
                cout << "Consultando a lista: ";
                aux = inicio;

                do
                {
                    cout<<aux->num<< " => ";
                    aux = aux->prox;
                }
                while (aux != NULL && aux != inicio);
            }
        }

        if (op == 4) {
            if (inicio == NULL)
            {
                cout << "Lista esta vazia.";
            } else {
                cout<<"Digite o numero a ser removido: ";
                cin>>numero;
                aux = inicio;
                anterior = NULL;
                achou = 0;
                do {
                    if (inicio == fim && inicio->num == numero) {
                        delete(inicio);
                        inicio = NULL;
                        achou += 1;
                    }
                    else {
                        if (aux->num == numero) {
                            achou += 1;
                            if (aux == inicio) {
                                inicio = aux->prox;
                                fim->prox = inicio;
                                delete(aux);
                                aux = inicio;
                            } else if (aux == fim) {
                                fim = anterior;
                                fim->prox = inicio;
                                delete(aux);
                                aux = NULL;
                            } else {
                                anterior->prox = aux->prox;
                                delete(aux);
                                aux = anterior->prox;
                            }
                        } else {
                            anterior = aux;
                            aux = aux->prox;
                        }
                    }
                }
                while (aux != NULL);

                if (achou == 0) {
                    cout<<"Numero não encontrado.";
                } else {
                    cout<<"Numero foi removido " << achou << (achou > 1 ? " vezes" : " vez");
                }
                
            }
        }

        if (op == 5) {
            if (inicio == NULL)
            {
                cout << "Lista esta vazia.";
            } else {
                aux = inicio;
                while (aux != NULL)
                {
                    inicio = inicio->prox;
                    delete(aux);
                    aux = inicio;
                }
                cout<<"Lista esvaziada";
            }
        }

    } while (op != 6);

    return 0;
}