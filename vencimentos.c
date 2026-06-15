#include <stdio.h>
#include "cliente.h"

void listarVencimentos(Cliente clientes[], int qtdClientes)
{
    int mes;

    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);
    getchar();

    printf("\n--- CLIENTES COM VENCIMENTO NO MES %d ---\n\n", mes);

    printf("%-25s %-15s\n", "NOME", "VENCIMENTO");

    for(int i = 0; i < qtdClientes; i++)
    {
        int dia, mesV, ano;

        sscanf(clientes[i].dataVencimento,
               "%d/%d/%d",
               &dia, &mesV, &ano);

        if(mesV == mes)
        {
            printf("%-25s %-15s\n",
                   clientes[i].nome,
                   clientes[i].dataVencimento);
        }
    }

    printf("\nTecle ENTER para voltar ao menu...");
    getchar();
}