#include <stdio.h>
#include <string.h>
#include "cliente.h"

void cadastrar(Cliente clientes[], int i);
void listagemGeral(Cliente clientes[], int i);
void listarVencimentos(Cliente clientes[], int i);

int main()
{
    Cliente clientes[30];

    int i = 0;
    int escolha = -1;

    while(escolha != 0 && i < 30)
    {
        do{
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

            if(escolha < 0 || escolha > 6)
            {
                printf("Opcao invalida.\n");
            }

        }while(escolha < 0 || escolha > 6);

        if(escolha == 1)
        {
            cadastrar(clientes, i);
            i++;
        }

        else if(escolha == 4)
        {
            if(i == 0)
            {
                printf("Nenhum cliente cadastrado.\n");
            }
            else
            {
                listagemGeral(clientes, i);
            }
        }
        else if(escolha == 6)
        {
            listarVencimentos(clientes, i);
        }
    }

    printf("\nPrograma encerrado. Ate logo!\n");

    return 0;
}