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
        cout << "\n1 - inserir na lista\n";
        cout << "\n2 - consultar toda a lista\n";
        cout << "\n3 - remover da lista\n";
        cout << "\n4 - esvaziar\n";
        cout << "\n5 - sair\n";

        cout << "\nDigite sua opcao: \n";
        cin >> op;

        if (op < 1 || op > 5)
            cout << "Opcao invalida!!";

        if (op == 1)
        {
            cout << "Digite o numero a ser inserido na lista: ";
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
                anterior = NULL;
                aux = inicio;

                while (aux != NULL && novo->num > aux->num)
                {
                    anterior = aux;
                    aux = aux->prox;
                }

                if (anterior == NULL)
                {
                    novo->prox = inicio;
                    inicio = novo;
                }
                else if (aux == NULL)
                {
                    fim->prox = novo;
                    fim = novo;
                    fim->prox = NULL;
                }
                else
                {
                    anterior->prox = novo;
                    novo->prox = aux;
                }
            }
            cout << "Numero inserido na lista.";
        }

        if (op == 2)
        {

            if (inicio == NULL)
            {
                cout << "Lista esta vazia.";
            }
            else
            {
                cout << "Consultando a lista: ";
                aux = inicio;
                while (aux != NULL)
                {
                    cout << aux->num << (aux->prox == NULL ? " " : " => ");
                    aux = aux->prox;
                }
            }
        }

        if (op == 3)
        {

            if (inicio == NULL)
            {
                cout << "Lista esta vazia.";
            }
            else
            {

                cout << "Digite o numero a ser removido da lista:";
                cin >> numero;

                aux = inicio;
                anterior = NULL;
                achou = 0;

                while (aux != NULL)
                {

                    if (aux->num == numero)
                    {
                        achou += 1;

                        if (aux == inicio)
                        {
                            inicio = aux->prox;
                            delete (aux);
                            aux = inicio;
                        }
                        else if (aux == fim)
                        {
                            anterior->prox = NULL;
                            fim = anterior;
                            delete (aux);
                            aux = NULL;
                        }
                        else
                        {
                            anterior->prox = aux->prox;
                            delete (aux);
                            aux = anterior->prox;
                        }
                    }
                    else
                    {
                        anterior = aux;
                        aux = aux->prox;
                    }
                }
                if (achou == 0)
                {
                    cout << "Numero não encontrado.";
                }
                else if (achou == 1)
                {
                    cout << "Numero removido 1 vez.";
                }
                else
                {
                    cout << "Numero removido" << achou << "vezes.";
                }
            }
        }

        if (op == 4)
        {

            if (inicio == NULL)
            {
                cout << "Lista vazia.";
            }
            else
            {
                aux = inicio;
                while (aux != NULL)
                {
                    inicio = inicio->prox;
                    delete (aux);
                    aux = inicio;
                }
                cout << "Lista esvaziada";
            }
        }

    } while (op != 5);

    return 0;
}