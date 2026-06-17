#include <stdio.h>
#include "cliente.h"

void listarPorPlano(Cliente clientes[], int i)
{
    int plano;
    int encontrou = 0;

    do
    {
        do
        {

            printf("\n--- LISTAGEM POR PLANO ---\n");
            printf("1 - Prata\n");
            printf("2 - Ouro\n");
            printf("3 - Diamante\n");
            printf("4 - Esmeralda\n");
            printf("0 - Voltar\n");
            printf("Escolha o plano: ");
            scanf("%d", &plano);
            getchar();

            if (plano == 0)
            {
                printf("\nVoltando...\n");
                return;
            }

            if (plano < 0 || plano > 4)
            {
                printf("Opção Invalida. Digite uma opçao correta.\n");
            }

        } while (plano < 0 || plano > 4);

        printf("\n");

        if (plano == 1)
        {
            printf("\n--- CLIENTES PLANO PRATA ---\n\n");
        }
        else if (plano == 2)
        {
            printf("\n--- CLIENTES PLANO OURO ---\n\n");
        }
        else if (plano == 3)
        {
            printf("\n--- CLIENTES PLANO DIAMANTE ---\n\n");
        }
        else
        {
            printf("\n--- CLIENTES PLANO ESMERALDA ---\n\n");
        }

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

        for (int j = 0; j < i; j++)
        {
            if (clientes[j].tipoPlano == plano)
            {
                encontrou = 1;

                printf("%-15s %-25s %-6s %-15s %-6d %-12s %-12d R$%-10.2f %-12s\n",
                       clientes[j].cpf,
                       clientes[j].nome,
                       clientes[j].sexo == 1 ? "F" : "M",
                       clientes[j].telefone,
                       clientes[j].idade,
                       clientes[j].tipoPlano == 1 ? "Prata" : clientes[j].tipoPlano == 2 ? "Ouro"
                                                          : clientes[j].tipoPlano == 3   ? "Diamante"
                                                                                         : "Esmeralda",
                       clientes[j].qtdDependentes,
                       clientes[j].valorPlano,
                       clientes[j].dataVencimento);
            }
        }

        if (encontrou == 0)
        {
            printf("Nenhum cliente encontrado para este plano.\n");
        }

        printf("\nTecle ENTER para voltar ao menu...");
        getchar();
    } while (plano != 0);
}
