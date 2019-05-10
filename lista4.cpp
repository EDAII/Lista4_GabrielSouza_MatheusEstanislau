#include <bits/stdc++.h>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEZ 10000
#define CEM 100000
#define UM 1000000

using namespace std;

void menuPrincipal();
void menuOrdenacao();
void tutorialHeapSort();
void tempo(int vetor[], int tamanho);
void heapsort(int *vet, int n);
void peneira(int *vet, int raiz, int fundo);
void populaVetor(int vetor[], int tamanho);
void pause (float delay1);

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
            tutorialHeapSort();
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

void tutorialHeapSort()
{
    char lixo;
    system("clear");
    printf("O algoritmo heapsort é um algoritmo de ordenação\n");
    printf(" O heapsort utiliza o heap que é uma estrutura de dados, para ordenar os elementos à medida que os insere na estrutura.\n"); 
	printf("Assim, ao final das inserções, os elementos podem ser sucessivamente removidos da raiz da heap, na ordem desejada.\n");
	printf("lembrando sempre de manter a propriedade de max-heap.\n");      
    pause(15);
    system("clear");

    printf("o heap pode ser considerado como uma árvore que possui caracteristicas especiais ou como um vetor.\n"); 
    printf("Para ordenar o vetor de forma decrescente, deve ser construída um Heap mínimo, em que o menor número fica na raiz.\n"); 
    printf("Para obter uma ordenação crescente, deve ser construído um Heap máximo em que o maior número fica na raiz).\n");
    printf("O heapsort não é um algoritmo de ordenação estável\n"); 
    printf("Porém, é possível adaptar a estrutura a ser ordenada de forma a tornar a ordenação 	estável.\n"); 
    printf("Cada elemento da estrutura adaptada deve ficar no formato de um par elemento original, índice original.\n"); 
    printf("Assim, caso dois elementos sejam iguais, o desempate ocorrerá pelo índice na estrutura original.\n");      
    pause(20);
    system("clear");

    printf("Imagine um vetor de 10 elementos: Vetor{6,5,3,1,8,7,2,4}\n");
    printf("Agora iremos realizar a construção do Heap máximo\n.");        
    printf("O algoritmo irá percorrer todo o vetor e irá colocar os maiores numeros em cima.\nAcompanhe o exemplo:\n");       
    pause(10);
    system("clear");
    printf("{6,5 ,3 ,1 ,8 ,7 ,2 ,4}\n");
    pause(5);
    printf("Coloca-se o primeiro elemento do vetor no nó raiz.\n");
    pause(5);
    printf("          6          \n");
    printf("\n");
    pause(5);
    printf("{5 ,3 ,1 ,8 ,7 ,2 ,4}\n");
    printf("Coloca-se os elementos filhos 3 e 5.\n");
    pause(5);
    printf("          6          \n");
    printf("         / \\          \n");
    printf("        5   3       \n");
    pause(5);
    printf("{1 ,8 ,7 ,2 ,4}\n");
    printf("\n");
    printf("Coloca-se os elementos filhos do elemento 5 que são 1 e 8.\n");
    pause(5);
    printf("           6          \n");
    printf("          / \\          \n");
    printf("        5     3       \n");
    printf("       / \\           \n");
    printf("      1   8       \n");
    printf("{7 ,2 ,4}\n");
    printf("Quando o elemento 8 é adicionado é feito uma comparação com seu pai, e como 8 > 5 é feita a troca.\n");
    printf("\n");
    pause(5);
    printf("           6          \n");
    printf("          / \\          \n");
    printf("        8     3       \n");
    printf("       / \\           \n");
    printf("      1   5       \n");
    printf("{7 ,2 ,4}\n");
    printf("Para obedecer a regra do max heap sempre é feita a comparação para saber se o elemento pai sempre é maior que seus filhos.\n");
    printf("Como 8 é maior que o nó raiz, é feita a troca.\n");
    printf("\n");
    pause(5);
    printf("           8          \n");
    printf("          / \\          \n");
    printf("        6     3       \n");
    printf("       / \\           \n");
    printf("      1   5       \n");
    printf("{7 ,2 ,4}\n");
    pause(5);
    printf("Agora é colocado os elementos filhos do 3 que são 7 e 2.\n");
    pause(5);
    printf("            8          \n");
    printf("          /    \\          \n");
    printf("        6       3       \n");
    printf("       / \\     / \\       \n");
    printf("      1   5   7   2 \n");
    printf("{,4}\n");
    printf("\n");
    printf("Quando o elemento 7 é adicionado é feito uma comparação com seu pai, e como 7 > 3 é feita a troca.\n");
    pause(5);
    printf("            8          \n");
    printf("          /    \\          \n");
    printf("        6       7       \n");
    printf("       / \\     / \\       \n");
    printf("      1   5   3   2 \n");
    printf("{,4}\n");
    pause(5);
    printf("Agora é colocado o elemento filho do 1 que é o 4.\n");
    printf("            8          \n");
    printf("          /    \\          \n");
    printf("        6       7       \n");
    printf("       / \\     / \\       \n");
    printf("      1   5   3   2 \n");
    printf("     /       \n");
    printf("    4      \n");
    pause(5);
    printf("Quando o elemento 4 é adicionado é feito uma comparação com seu pai, e como 4 > 1 é feita a troca.\n");
    printf("            8          \n");
    printf("          /    \\          \n");
    printf("        6       7       \n");
    printf("       / \\     / \\       \n");
    printf("      4   5   3   2 \n");
    printf("     /       \n");
    printf("    1      \n");
    pause(5);
    printf("Com o Heap construÍdo temos o seguinte vetor: \n");
    printf("{8,6,7,4,5,3,2,1}\n");
    pause(5);
    printf("Para efetuar a ordenação devemos trocar sempre o nó raiz com o elemento do ultimo nó.\n");
    printf("Após a troca retiramos o maior elemento e colocamos no final do vetor.\n");
    printf("Nó raiz = 8, menor elemento do último nó = 1, então é feita a troca e a remoção\n");
    printf("            1          \n");
    printf("          /    \\          \n");
    printf("        6       7       \n");
    printf("       / \\     / \\       \n");
    printf("      4   5   3   2 \n");
    printf("     /       \n");
    printf("    8      \n");
    pause(5);
    printf("            7          \n");
    printf("          /    \\          \n");
    printf("        6       3       \n");
    printf("       / \\     / \\       \n");
    printf("      4   5   1   2 \n");
    printf("{ , , , , , , ,8 }\n");
    printf("Lembrando sempre de garantir o Heap máximo.\n");
    printf("Então teremos que trocar o nó raiz que é igual a 1 com o 7 e o 3 para grantir o Heap Máximo.\n");
    printf("E assim por diante.\n");
    printf("            7          \n");
    printf("          /    \\          \n");
    printf("        6       3       \n");
    printf("       / \\     / \\       \n");
    printf("      4   5   1   2 \n");
    pause(5);
    system("clear");
    printf("            2          \n");
    printf("          /    \\          \n");
    printf("        6       3       \n");
    printf("       / \\     / \\       \n");
    printf("      4   5    1   7 \n");
    pause(5);
    system("clear");
    printf("            6          \n");
    printf("          /    \\          \n");
    printf("        5        3       \n");
    printf("       / \\     /       \n");
    printf("      4   2   1  \n");
    printf("{ , , , , , ,7,8 }\n");
    pause(5);
    system("clear");
    printf("            1          \n");
    printf("          /    \\          \n");
    printf("        5        3       \n");
    printf("       / \\     /       \n");
    printf("      4   2   6  \n");
    printf("{ , , , , , ,7,8 }\n");
    pause(5);
    system("clear");
    printf("            5          \n");
    printf("          /    \\          \n");
    printf("        4        3       \n");
    printf("       / \\     /       \n");
    printf("      1   2     \n");
    printf("{ , , , , ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            2          \n");
    printf("          /    \\          \n");
    printf("        4        3       \n");
    printf("       / \\            \n");
    printf("      1   5     \n");
    printf("{ , , , , ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            4          \n");
    printf("          /    \\          \n");
    printf("        2        3       \n");
    printf("       /             \n");
    printf("      1        \n");
    printf("{ , , , ,5 ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            4          \n");
    printf("          /    \\          \n");
    printf("        2        3       \n");
    printf("       /            \n");
    printf("      1      \n");
    printf("{ , , , ,5 ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            1          \n");
    printf("          /   \\          \n");
    printf("        2       3       \n");
    printf("       /            \n");
    printf("      4      \n");
    printf("{ , , , ,5 ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            3          \n");
    printf("          /   \\          \n");
    printf("        2       1       \n");
    printf("       /           \n");
    printf("     4      \n");
    printf("{ , , , ,5 ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            3          \n");
    printf("          /    \\          \n");
    printf("        2        1       \n");
    printf("                   \n");
    printf("           \n");
    printf("{ , , ,4 ,5 ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            1          \n");
    printf("          /   \\           \n");
    printf("        2       3       \n");
    printf("                   \n");
    printf("            \n");
    printf("{ , , ,3 ,5 ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            2          \n");
    printf("          /              \n");
    printf("        1               \n");
    printf("                   \n");
    printf("            \n");
    printf("{ , , ,3 ,5 ,6 ,7 ,8 }\n");
    pause(5);
    system("clear");
    printf("            1          \n");
    printf("          /              \n");
    printf("        2               \n");
    printf("                   \n");
    printf("            \n");
    printf("{ 1 ,2 ,3 ,5 ,6 ,7 ,8 }\n");
    printf("Pronto ordenamos o vetor!!\n");
    pause(5);
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