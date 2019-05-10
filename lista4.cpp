#include <bits/stdc++.h>
#include <time.h>
#include <iostream>
#define DEZ 10000
#define CEM 100000
#define UM 1000000

using namespace std;

void menuPrincipal();
void menuOrdenacao();
void tempo(int vetor[], int tamanho);
void heapsort(int *vet, int n);
void peneira(int *vet, int raiz, int fundo);
void populaVetor(int vetor[], int tamanho);

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
    int vetorDez[DEZ],
        vetorCem[CEM],
        vetorUm[UM];

    populaVetor(vetorDez, DEZ);
    populaVetor(vetorCem, CEM);
    populaVetor(vetorUm, UM);

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
            tempo(vetorDez, DEZ);
            break;
        case 2:
            system("clear");
            tempo(vetorCem, CEM);
            break;
        case 3:
            system("clear");
            tempo(vetorUm, UM);
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

void tempo(int vetor[], int tamanho)
{
    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    heapsort(vetor, tamanho);
    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    cout << "Tempo: " << tempo << "ns" << endl;
}

void peneira(int *vet, int raiz, int fundo);

void heapsort(int *vet, int n)
{
    int i, tmp;

    for (i = (n / 2); i >= 0; i--)
    {
        peneira(vet, i, n - 1);
    }

    for (i = n - 1; i >= 1; i--)
    {
        tmp = vet[0];
        vet[0] = vet[i];
        vet[i] = tmp;
        peneira(vet, 0, i - 1);
    }
}

void peneira(int *vet, int raiz, int fundo)
{
    int pronto, filhoMax, tmp;

    pronto = 0;
    while ((raiz * 2 <= fundo) && (!pronto))
    {
        if (raiz * 2 == fundo)
        {
            filhoMax = raiz * 2;
        }
        else if (vet[raiz * 2] > vet[raiz * 2 + 1])
        {
            filhoMax = raiz * 2;
        }
        else
        {
            filhoMax = raiz * 2 + 1;
        }

        if (vet[raiz] < vet[filhoMax])
        {
            tmp = vet[raiz];
            vet[raiz] = vet[filhoMax];
            vet[filhoMax] = tmp;
            raiz = filhoMax;
        }
        else
        {
            pronto = 1;
        }
    }
}

void populaVetor(int vetor[], int tamanho)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % tamanho;
    }
}