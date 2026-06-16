#include <stdio.h>
#include <string.h>
#include "cliente.h"

int calcularIdade(char dataNasc[])
{
    int dia, mes, ano;
    int dAtual = 7, mAtual = 6, aAtual = 2026;

    sscanf(dataNasc, "%d/%d/%d", &dia, &mes, &ano);

    int idade = aAtual - ano;

    if (mes > mAtual || (mes == mAtual && dia > dAtual))
    {
        idade--;
    }

    return idade;
}

void cadastrar(Cliente clientes[], int i)
{
    printf("\n--- Cadastro do Cliente %d ---\n", i + 1);

    printf("Insira o CPF do cliente: ");
    fgets(clientes[i].cpf, 20, stdin);
    clientes[i].cpf[strcspn(clientes[i].cpf, "\n")] = 0;

    printf("Insira o nome do cliente: ");
    fgets(clientes[i].nome, 50, stdin);
    clientes[i].nome[strcspn(clientes[i].nome, "\n")] = 0;

    printf("Digite o gênero do cliente (1-fem/2-masc): ");
    do
    {
        scanf("%d", &clientes[i].sexo);
        getchar();
        if (clientes[i].sexo != 1 && clientes[i].sexo != 2)
        {
            printf("Opção invalida. Tente novamente: ");
        }
    } while (clientes[i].sexo != 1 && clientes[i].sexo != 2);

    printf("Insira o email do cliente: ");
    fgets(clientes[i].email, 50, stdin);
    clientes[i].email[strcspn(clientes[i].email, "\n")] = 0;

    printf("Insira a data de nascimento do cliente (dd/mm/aaaa): ");
    fgets(clientes[i].dataNasc, 20, stdin);
    clientes[i].dataNasc[strcspn(clientes[i].dataNasc, "\n")] = 0;

    clientes[i].idade = calcularIdade(clientes[i].dataNasc);

    printf("Insira o telefone do cliente: ");
    fgets(clientes[i].telefone, 20, stdin);
    clientes[i].telefone[strcspn(clientes[i].telefone, "\n")] = 0;

    printf("Quantos dependentes você deseja cadastrar? ");
    scanf("%d", &clientes[i].qtdDependentes);
    getchar();

    for (int j = 0; j < clientes[i].qtdDependentes; j++)
    {

        printf("Insira o CPF do dependente %d: ", j + 1);
        fgets(clientes[i].cpfTerc[j], 20, stdin);
        clientes[i].cpfTerc[j][strcspn(clientes[i].cpfTerc[j], "\n")] = 0;

        printf("Insira o nome do dependente %d: ", j + 1);
        fgets(clientes[i].nomeTerc[j], 50, stdin);
        clientes[i].nomeTerc[j][strcspn(clientes[i].nomeTerc[j], "\n")] = 0;

        printf("Insira a data de nascimento do dependente %d: ", j + 1);
        fgets(clientes[i].dataNascTerc[j], 20, stdin);
        clientes[i].dataNascTerc[j][strcspn(clientes[i].dataNascTerc[j], "\n")] = 0;
    }

    printf("Digite o tipo do plano de saúde (1 - Prata / 2 - Ouro / 3 - Diamante / 4 - Esmeralda): ");
    do
    {
        scanf("%d", &clientes[i].tipoPlano);
        getchar();
        if (clientes[i].tipoPlano < 1 || clientes[i].tipoPlano > 4)
        {
            printf("Opção invalida. Tente novamente: ");
        }
    } while (clientes[i].tipoPlano < 1 || clientes[i].tipoPlano > 4);
    if (clientes[i].tipoPlano == 1)
    {
        clientes[i].valorPlano = 200;
    }
    else if (clientes[i].tipoPlano == 2)
    {
        clientes[i].valorPlano = 300;
    }
    else if (clientes[i].tipoPlano == 3)
    {
        clientes[i].valorPlano = 400;
    }
    else
    {
        clientes[i].valorPlano = 500;
    }

    printf("Insira a data do vencimento do plano de saúde: ");
    fgets(clientes[i].dataVencimento, 20, stdin);
    clientes[i].dataVencimento[strcspn(clientes[i].dataVencimento, "\n")] = 0;

    if (clientes[i].idade < 13)
    {
        clientes[i].valorPlano = clientes[i].valorPlano - (clientes[i].valorPlano * 0.3);
    }
    if (clientes[i].sexo == 1 && clientes[i].idade >= 13 && clientes[i].idade < 35)
    {
        clientes[i].valorPlano = clientes[i].valorPlano + (clientes[i].valorPlano * 0.3);
    }
    if (clientes[i].idade >= 60)
    {
        clientes[i].valorPlano = clientes[i].valorPlano + (clientes[i].valorPlano * 0.4);
    }
    if (clientes[i].qtdDependentes > 1)
    {
        clientes[i].valorPlano = clientes[i].valorPlano - (clientes[i].valorPlano * 0.2);
    }

    printf("\nCliente cadastrado com sucesso!\n");
}

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
        printf("7 - Plano: %d\n", clientes[posicao].tipoPlano == 1 ? "Prata" :
                                  clientes[posicao].tipoPlano == 2 ? "Ouro" :
                                  clientes[posicao].tipoPlano == 3 ? "Diamante" : "Esmeralda");
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
            } while (clientes[posicao].sexo != 1 &&
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

void removerCliente(Cliente clientes[], int *i)
{
    int posicao;

    if (*i <= 0)
    {
        printf("\nSEM CLIENTES CADASTRADOS\n");
        return;
    }

    printf("\n========================================");
    printf("\nREMOVER CLIENTE ");
    printf("\n========================================\n");

    printf("\n--- CLIENTES CADASTRADOS ---\n");

    for (int j = 0; j < *i; j++)
    {
        printf("%d - %s\n", j + 1, clientes[j].nome);
    }

    printf("\nDigite o numero do cliente que deseja remover: \nDigite 0 para voltar\n");
    scanf("%d", &posicao);
    getchar();

    posicao--;

    if (posicao < 0 || posicao >= *i)
    {
        printf("\nCliente Invalido \n");
        return;
    }

    for (int j = posicao; j < *i - 1; j++)
    {
        clientes[j] = clientes[j + 1];
    }

    (*i)--;

    printf("\nCliente removido com sucesso!\n");
}