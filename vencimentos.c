#include <stdio.h>
#include "cliente.h"

void listarVencimentos(Cliente clientes[], int i)
{
    int mes, ano;
    int encontrou = 0;

    do {
    do
        {
            printf("Digite o ano (2026 ou superior): ");
            printf("\n(Digite 0 para voltar)\n");
            scanf("%d", &ano);

            if (ano == 0)
            {
                printf("\nVoltando...\n");
                return;
            }
            

            while(getchar() != '\n');

            if(ano < 2026)
            {
                printf("Ano invalido! Digite um ano igual ou superior a 2026.\n");
            }

        }while(ano < 2026);
    
    do
    {
        printf("Digite o mes (1-12): ");
        scanf("%d", &mes);

        while(getchar() != '\n');

        if(mes < 1 || mes > 12)
        {
            printf("Mes invalido! Digite um valor entre 1 e 12.\n");
        }

    }while(mes < 1 || mes > 12);


    printf("\n--- CLIENTES COM VENCIMENTO EM %02d/%d ---\n\n", mes, ano);

    printf("%-25s %-15s\n", "NOME", "VENCIMENTO");
    printf("---------------------------------------------\n");

    for(int j = 0; j < i; j++)
    {
        int dia, mesV, anoV;

        sscanf(clientes[j].dataVencimento,
               "%d/%d/%d",
               &dia, &mesV, &anoV);

        if(mesV == mes && anoV == ano)
        {
            encontrou = 1;

            printf("%-25s %-15s\n",
                   clientes[j].nome,
                   clientes[j].dataVencimento);
        }
    }

    if(encontrou == 0)
    {
        printf("\nNenhum cliente possui vencimento em %02d/%d.\n", mes, ano);
    }

    printf("\nTecle ENTER para voltar ao menu...");
    getchar();
}while(ano != 0);
}