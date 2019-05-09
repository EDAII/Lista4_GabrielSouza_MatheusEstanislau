#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void menuPrincipal();
void menuOrdenacao();
void tempoDez();
void tempoCem();
void tempoUm();

int main()
{
    system("clear");
    menuPrincipal();

    return 0;
}

void menuPrincipal()
{

    int opcao;

    do
    {
        cout << "=========  Menu  =========" << endl;
        cout << "| 1 - Tutorial           |" << endl;
        cout << "| 2 - Ordenação em vetor |" << endl;
        cout << "| 3 - Lista de terefas   |" << endl;
        cout << "| 0 - Sair               |" << endl;
        cout << "==========================" << endl;

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("clear");
            //Tutorial
            break;
        case 2:
            system("clear");
            menuOrdenacao();
            break;
        case 3:
            system("clear");
            //Tarefas
            break;
        case 0:
            system("clear");
            break;

        default:
            system("clear");
            cout << "Alternativa incorreta" << endl;
            break;
        }
    } while (opcao);
}

void menuOrdenacao()
{
    int opcao;

    do
    {
        cout << "=========  Tempo  =========" << endl;
        cout << "| 1 - Vetor com    10.000 |" << endl;
        cout << "| 2 - Vetor com   100.000 |" << endl;
        cout << "| 3 - Vetor com 1.000.000 |" << endl;
        cout << "| 0 - Voltar              |" << endl;
        cout << "===========================" << endl;

        cin >> opcao;

        switch (opcao)
        {
        case 1:
            system("clear");
            tempoDez();
            break;
        case 2:
            system("clear");
            tempoCem();
            break;
        case 3:
            system("clear");
            tempoUm();
            break;
        case 0:
            system("clear");
            break;
        default:
            system("clear");
            cout << "Tente novamente" << endl;
            break;
        }
    } while (opcao);
}

void tempoDez()
{
}

void tempoCem()
{
}

void tempoUm()
{
}