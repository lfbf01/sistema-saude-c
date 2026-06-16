#include <stdio.h>
#include <string.h>
#include "cliente.h"

void editarCliente(Cliente clientes[], int i)
{
    int posicao;
    int opcao;

    if (i <= 0)
    {
        printf("\n--- Nenhum cliente cadastrado! ---\n");
        return;
    }

    printf("\n--- CLIENTES CADASTRADOS ---\n");

    for (int j = 0; j < i; j++)
    {
        printf("%d - %s\n", j + 1, clientes[j].nome);
    }

    printf("\nDigite o numero do cliente que deseja editar: ");
    scanf("%d", &posicao);
    getchar();

    posicao--;

    if (posicao < 0 || posicao >= i)
    {
        printf("\nCliente nao encontrado!\n");
        return;
    }

    do
    {
        printf("\n========================================");
        printf("\nEDITANDO CLIENTE: %s", clientes[posicao].nome);
        printf("\n========================================\n");

        printf("1 - CPF: %s\n", clientes[posicao].cpf);
        printf("2 - Nome: %s\n", clientes[posicao].nome);
        printf("3 - Sexo: %s\n",
               clientes[posicao].sexo == 1 ? "Feminino" : "Masculino");
        printf("4 - Email: %s\n", clientes[posicao].email);
        printf("5 - Data de Nascimento: %s\n", clientes[posicao].dataNasc);
        printf("6 - Telefone: %s\n", clientes[posicao].telefone);
        printf("7 - Plano: %d\n", clientes[posicao].tipoPlano);
        printf("8 - Data de Vencimento: %s\n",
               clientes[posicao].dataVencimento);
        printf("9 - Dependentes\n");
        printf("0 - Finalizar Edicao\n");

        printf("\nEscolha o campo que deseja editar: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:

            printf("Novo CPF: ");
            fgets(clientes[posicao].cpf, 20, stdin);
            clientes[posicao].cpf[strcspn(clientes[posicao].cpf, "\n")] = 0;
            break;

        case 2:

            printf("Novo Nome: ");
            fgets(clientes[posicao].nome, 50, stdin);
            clientes[posicao].nome[strcspn(clientes[posicao].nome, "\n")] = 0;
            break;

        case 3:

            do
            {
                printf("Sexo (1-Feminino / 2-Masculino): ");
                scanf("%d", &clientes[posicao].sexo);
                getchar();
            }
            while (clientes[posicao].sexo != 1 &&
                   clientes[posicao].sexo != 2);

            break;

        case 4:

            printf("Novo Email: ");
            fgets(clientes[posicao].email, 50, stdin);
            clientes[posicao].email[strcspn(clientes[posicao].email, "\n")] = 0;
            break;

        case 5:

            printf("Nova Data de Nascimento: ");
            fgets(clientes[posicao].dataNasc, 20, stdin);
            clientes[posicao].dataNasc[strcspn(clientes[posicao].dataNasc, "\n")] = 0;

            clientes[posicao].idade =
                calcularIdade(clientes[posicao].dataNasc);

            break;

        case 6:

            printf("Novo Telefone: ");
            fgets(clientes[posicao].telefone, 20, stdin);
            clientes[posicao].telefone[strcspn(clientes[posicao].telefone, "\n")] = 0;
            break;

        case 7:

            printf("Plano (1-Prata / 2-Ouro / 3-Diamante / 4-Esmeralda): ");
            scanf("%d", &clientes[posicao].tipoPlano);
            getchar();

            switch (clientes[posicao].tipoPlano)
            {
            case 1:
                clientes[posicao].valorPlano = 200;
                break;
            case 2:
                clientes[posicao].valorPlano = 300;
                break;
            case 3:
                clientes[posicao].valorPlano = 400;
                break;
            case 4:
                clientes[posicao].valorPlano = 500;
                break;
            }

            break;

        case 8:

            printf("Nova Data de Vencimento: ");
            fgets(clientes[posicao].dataVencimento, 20, stdin);
            clientes[posicao].dataVencimento[strcspn(clientes[posicao].dataVencimento, "\n")] = 0;

            break;

        case 9:
        {
            int opdep;

            printf("\nDEPENDENTES ATUAIS\n");

            if (clientes[posicao].qtdDependentes == 0)
            {
                printf("Nenhum dependente cadastrado.\n");
            }
            else
            {
                for (int i = 0; i < clientes[posicao].qtdDependentes; i++)
                {
                    printf("%d - %s\n",
                           i + 1,
                           clientes[posicao].nomeTerc[i]);
                }
            }

            printf("\n1 - Adicionar Dependente\n");
            printf("2 - Editar Dependente\n");
            printf("0 - Voltar\n");

            scanf("%d", &opdep);
            getchar();

            if (opdep == 1)
            {
                int posdep = clientes[posicao].qtdDependentes;

                if (posdep >= 10)
                {
                    printf("\nLimite de dependentes atingido!\n");
                    break;
                }

                printf("CPF do Dependente: ");
                fgets(clientes[posicao].cpfTerc[posdep], 20, stdin);
                clientes[posicao].cpfTerc[posdep][strcspn(clientes[posicao].cpfTerc[posdep], "\n")] = 0;

                printf("Nome do Dependente: ");
                fgets(clientes[posicao].nomeTerc[posdep], 50, stdin);
                clientes[posicao].nomeTerc[posdep][strcspn(clientes[posicao].nomeTerc[posdep], "\n")] = 0;

                printf("Nascimento do Dependente: ");
                fgets(clientes[posicao].dataNascTerc[posdep], 20, stdin);
                clientes[posicao].dataNascTerc[posdep][strcspn(clientes[posicao].dataNascTerc[posdep], "\n")] = 0;

                clientes[posicao].qtdDependentes++;

                printf("\nDependente adicionado com sucesso!\n");
            }
            else if (opdep == 2)
            {
                int dep;

                if (clientes[posicao].qtdDependentes == 0)
                {
                    printf("\nNao existem dependentes cadastrados.\n");
                    break;
                }

                printf("\nEscolha o dependente:\n");

                for (int i = 0; i < clientes[posicao].qtdDependentes; i++)
                {
                    printf("%d - %s\n",
                           i + 1,
                           clientes[posicao].nomeTerc[i]);
                }

                scanf("%d", &dep);
                getchar();

                dep--;

                if (dep < 0 ||
                    dep >= clientes[posicao].qtdDependentes)
                {
                    printf("\nDependente invalido!\n");
                    break;
                }

                printf("Novo CPF: ");
                fgets(clientes[posicao].cpfTerc[dep], 20, stdin);
                clientes[posicao].cpfTerc[dep][strcspn(clientes[posicao].cpfTerc[dep], "\n")] = 0;

                printf("Novo Nome: ");
                fgets(clientes[posicao].nomeTerc[dep], 50, stdin);
                clientes[posicao].nomeTerc[dep][strcspn(clientes[posicao].nomeTerc[dep], "\n")] = 0;

                printf("Nova Data de Nascimento: ");
                fgets(clientes[posicao].dataNascTerc[dep], 20, stdin);
                clientes[posicao].dataNascTerc[dep][strcspn(clientes[posicao].dataNascTerc[dep], "\n")] = 0;

                printf("\nDependente atualizado com sucesso!\n");
            }

            break;
        }

        case 0:
            printf("\nEdicao finalizada!\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
        }

        

        if (opcao != 0)
        {
            switch (clientes[posicao].tipoPlano)
            {
            case 1:
                clientes[posicao].valorPlano = 200;
                break;
            case 2:
                clientes[posicao].valorPlano = 300;
                break;
            case 3:
                clientes[posicao].valorPlano = 400;
                break;
            case 4:
                clientes[posicao].valorPlano = 500;
                break;
            }

            if (clientes[posicao].idade < 13)
                clientes[posicao].valorPlano *= 0.7;

            if (clientes[posicao].sexo == 1 &&
                clientes[posicao].idade >= 13 &&
                clientes[posicao].idade < 35)
                clientes[posicao].valorPlano *= 1.3;

            if (clientes[posicao].idade >= 60)
                clientes[posicao].valorPlano *= 1.4;

            if (clientes[posicao].qtdDependentes > 1)
                clientes[posicao].valorPlano *= 0.8;
        }

    } while (opcao != 0);
}