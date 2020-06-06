#include <iostream>

using namespace std;

int main()
{

    struct LISTA
    {
        int num;
        LISTA *prox;
        LISTA *ant;
    };

    LISTA *inicio = NULL;
    LISTA *fim = NULL;
    LISTA *aux;

    int op, numero, achou;

    do
    {

        cout << "\nMENU DE OPCOES:\n";
        cout << "\n1 - inserir no inicio\n";
        cout << "\n2 - inserir no final\n";
        cout << "\n3 - consultar do inicio ao fim\n";
        cout << "\n4 - consultar do fim ao inicio\n";
        cout << "\n5 - remover da lista\n";
        cout << "\n6 - esvaziar\n";
        cout << "\n7 - sair\n";

        cout << "\nDigite sua opcao: \n";
        cin >> op;

        if (op < 1 || op > 7)
            cout << "Opcao invalida!!";

        if (op == 1)
        {
            cout << "Digite o numero a ser inserido no final da lista: ";
            LISTA *novo = new LISTA();
            cin >> novo->num;

            if (inicio == NULL)
            {
                inicio = novo;
                fim = novo;
                novo->prox = NULL;
                novo->ant = NULL;
            }
            else
            {
                novo->prox = inicio;
                inicio->ant = novo;
                novo->ant = NULL;
                inicio = novo;
            }
            cout<<"Numero inserido no inicio da lista.";
        }

        if (op == 2)
        {

            cout << "Digite o numero a ser inserido no final da lista: ";
            LISTA *novo = new LISTA();
            cin >> novo->num;

            if (inicio == NULL)
            {
                inicio = novo;
                fim = novo;
                novo->prox = NULL;
                novo->ant = NULL;
            }
            else
            {
                novo->ant = fim;
                fim->prox = novo;
                novo->prox = NULL;
                fim = novo;
            }
            cout<<"Numero inserido final da lista.";
        }

        if (op == 3)
        {

            if (inicio == NULL)
            {
                cout << "Lista esta vazia.";
            }
            else
            {
                cout << "Consultando a lista do inicio ao fim: ";
                aux = inicio;

                while (aux != NULL)
                {
                    cout<<aux->num<< (aux->prox != NULL ? " => " : " ");
                    aux = aux->prox;
                }
            }
        }

        if (op == 4)
        {

            if (inicio == NULL)
            {
                cout << "Lista esta vazia.";
            }
            else
            {
                cout << "Consultando a lista do fim ao inicio: ";
                aux = fim;

                while (aux != NULL)
                {
                    cout<<aux->num<< (aux->ant != NULL ? " => " : " ");
                    aux = aux->ant;
                }
            }
        }

        if (op == 5) {
            if (inicio == NULL)
            {
                cout << "Lista esta vazia.";
            } else {
                cout<<"Digite o numero a ser removido: ";
                cin>>numero;
                aux = inicio;
                achou = 0;
                while (aux != NULL)
                {
                    if (aux->num == numero) {
                        achou += 1;
                        if (aux == inicio) {
                            inicio = aux->prox;
                            if (inicio != NULL) inicio->ant = NULL;
                            delete(aux);
                            aux = inicio;
                        } else if (aux == fim) {
                            fim = fim->ant;
                            fim->prox = NULL;
                            delete(aux);
                            aux = NULL;
                        } else {
                            aux->ant->prox = aux->prox;
                            aux->prox->ant = aux->ant;
                            LISTA *aux2;
                            aux2 = aux->prox;
                            delete(aux);
                            aux = aux2;
                        }
                    } else {
                        aux = aux->prox;
                    }
                }

                if (achou == 0) {
                    cout<<"Numero não encontrado.";
                } else {
                    cout<<"Numero foi removido " << achou << (achou > 1 ? " vezes" : " vez");
                }
                
            }
        }

        if (op == 6) {
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

    } while (op != 7);

    return 0;
}