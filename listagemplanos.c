#include <stdio.h>
#include "cliente.h"

void listarPorPlano(Cliente clientes[], int qtdClientes)
{
    int plano;
    int encontrou = 0;

    printf("\n--- LISTAGEM POR PLANO ---\n");
    printf("1 - Prata\n");
    printf("2 - Ouro\n");
    printf("3 - Diamante\n");
    printf("4 - Esmeralda\n");
    printf("Escolha o plano: ");
    scanf("%d", &plano);
    getchar();

    printf("\n");

    printf("%-15s %-25s %-6s %-15s %-6s %-12s %-12s %-12s %-12s\n",
           "CPF",
           "NOME",
           "SEXO",
           "FONE",
           "IDADE",
           "PLANO",
           "DEPEND.",
           "VALOR",
           "VENCIMENTO");

    for(int i = 0; i < qtdClientes; i++)
    {
        if(clientes[i].tipoPlano == plano)
        {
            encontrou = 1;

            printf("%-15s %-25s %-6s %-15s %-6d %-12s %-12d R$%-10.2f %-12s\n",
                   clientes[i].cpf,
                   clientes[i].nome,
                   clientes[i].sexo == 1 ? "F" : "M",
                   clientes[i].telefone,
                   clientes[i].idade,
                   clientes[i].tipoPlano == 1 ? "Prata" :
                   clientes[i].tipoPlano == 2 ? "Ouro" :
                   clientes[i].tipoPlano == 3 ? "Diamante" : "Esmeralda",
                   clientes[i].qtdDependentes,
                   clientes[i].valorPlano,
                   clientes[i].dataVencimento);
        }
    }

    if(!encontrou)
    {
        printf("Nenhum cliente encontrado para este plano.\n");
    }

    printf("\nTecle ENTER para voltar ao menu...");
    getchar();
}
