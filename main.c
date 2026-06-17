#include <stdio.h>
#include <string.h>
#include "cliente.h"

void cadastrar(Cliente clientes[], int i);
void listagemGeral(Cliente clientes[], int i);
void listarVencimentos(Cliente clientes[], int i);
void editarCliente(Cliente clientes[], int i);
void removerCliente(Cliente clientes[], int *i);
void listarPorPlano(Cliente clientes[], int i);

int main()
{
    Cliente clientes[30];

    int i = 0; //Quantidade de clientes
    int escolha = -1;

    do
    {

        printf("\n--- Núcleo Seguros ---\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Editar Cliente\n");
        printf("3 - Remover Cliente\n");
        printf("4 - Listagem Geral\n");
        printf("5 - Listagem por Plano\n");
        printf("6 - Listagem dos Vencimentos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &escolha);
        getchar();

        switch (escolha)
        {
        case 1:
            if (i >= 30)
            {
                printf("\nLimite maximo de clientes atingido (30 clientes).\n");
                printf("Nao e possivel cadastrar novos clientes.\n");
            }
            else
            {
                cadastrar(clientes, i);
                i++;
            }
            break;

        case 2:
            editarCliente(clientes, i);
            break;

        case 3:
            removerCliente(clientes, &i);
            break;

        case 4:
            if (i == 0)
            {
                printf("Nenhum cliente cadastrado.\n");
            }
            else
            {
                listagemGeral(clientes, i);
            }
            break;

        case 5:
            listarPorPlano(clientes, i);
            break;

        case 6:
            listarVencimentos(clientes, i);
            break;

        case 0:
            printf("\nPrograma encerrado. Ate logo!\n");
            break;

        default:
            printf("Opção invalida\n");
        }

    } while (escolha != 0);

    return 0;
}