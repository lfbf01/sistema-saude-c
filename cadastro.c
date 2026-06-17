#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

int calcularIdade(char dataNasc[])
{
    int dia, mes, ano;
    int dAtual = 17, mAtual = 6, aAtual = 2026;

    sscanf(dataNasc, "%d/%d/%d", &dia, &mes, &ano);

    int idade = aAtual - ano;

    if (mes > mAtual || (mes == mAtual && dia > dAtual))
    {
        idade--;
    }

    return idade;
}

int validarCPF(char cpf[])
{
    if (strlen(cpf) != 11)
    {
        return 0;
    }

    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(cpf[i]))
        {
            return 0;
        }
    }

    return 1;
}

int verificarNome(char nome[])
{
    for (int i = 0; i < 11; i++)
    {
        if (isdigit(nome[i]))
        {
            return 0;
        }
    }
    return 1;
}

int validarEmail(char email[])
{
    int arroba = 0;
    int posArroba = -1;
    int pontoDepoisArroba = 0;

    int tam = strlen(email);

    if (tam == 0)
        return 0;

    for (int i = 0; i < tam; i++)
    {
        if (email[i] == ' ')
            return 0;

        if (email[i] == '@')
        {
            arroba++;
            posArroba = i;
        }
    }

    if (arroba != 1)
        return 0;

    if (posArroba == 0 || posArroba == tam - 1)
        return 0;

    for (int i = posArroba + 1; i < tam; i++)
    {
        if (email[i] == '.')
        {
            pontoDepoisArroba = 1;
            break;
        }
    }

    if (!pontoDepoisArroba)
        return 0;

    if (email[tam - 1] == '.')
        return 0;

    return 1;
}

int verificarData(char dataNasc[])
{

    int tamdata = strlen(dataNasc);

    if (tamdata != 10)
    {
        printf("Data Invalida.\n");
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
        {
            if (dataNasc[i] != '/')
            {
                printf("Data invalida.\n");
                return 0;
            }
        }
        else
        {
            if (!isdigit(dataNasc[i]))
            {
                printf("Data Invalida. Digite apenas numeros.\n");
                return 0;
            }
        }
    }

    int dia, mes, ano;

    sscanf(dataNasc, "%d/%d/%d", &dia, &mes, &ano);

    if (mes < 1 || mes > 12 || dia < 1 || dia > 31)
    {
        printf("Data Invalida.\n");
        return 0;
    }

    if (ano > 2026 ||
        (ano == 2026 && mes > 6) ||
        (ano == 2026 && mes == 6 && dia > 17))
    {
        printf("Data invalida! Deve ser igual ou anterior a 17/06/2026.\n");
        return 0;
    }

    return 1;
}

int verificarTelefone(char telefone[])
{
    int tamTelefone = strlen(telefone);

    if (tamTelefone < 8)
    {
        return 0;
    }

    for (int i = 0; i < tamTelefone; i++)
    {
        if (!isdigit(telefone[i]))
        {
            return 0;
        }
    }
    return 1;
}

int verificarDataVenc(char dataVenc[])
{

    int tamdata = strlen(dataVenc);

    if (tamdata != 10)
    {
        printf("Data Invalida.\n");
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5)
        {
            if (dataVenc[i] != '/')
            {
                printf("Data Invalida.\n");
                return 0;
            }
        }
        else
        {
            if (!isdigit(dataVenc[i]))
            {
                printf("Data Invalida. Digite apenas numeros.\n");
                return 0;
            }
        }
    }

    int dia, mes, ano;

    sscanf(dataVenc, "%d/%d/%d", &dia, &mes, &ano);

    if (mes < 1 || mes > 12 || dia < 1 || dia > 31)
    {
        printf("Data invalida!\n");
        return 0;
    }

    if (ano < 2026 ||
        (ano == 2026 && mes < 6) ||
        (ano == 2026 && mes == 6 && dia < 17))
    {
        printf("Data invalida! Deve ser igual ou posterior a 17/06/2026.\n");
        return 0;
    }

    return 1;
}

void cadastrar(Cliente clientes[], int i)
{
    printf("\n--- Cadastro do Cliente %d ---\n", i + 1);

    do
    {
        printf("Insira o CPF do cliente (11 numeros): ");

        fgets(clientes[i].cpf, 20, stdin);
        clientes[i].cpf[strcspn(clientes[i].cpf, "\n")] = 0;

        if (!validarCPF(clientes[i].cpf))
        {
            printf("CPF invalido! Digite exatamente 11 numeros.\n");
        }

    } while (!validarCPF(clientes[i].cpf));

    do
    {
        printf("Insira o nome do cliente: ");
        fgets(clientes[i].nome, 50, stdin);
        clientes[i].nome[strcspn(clientes[i].nome, "\n")] = 0;

        if (!verificarNome(clientes[i].nome))
        {
            printf("Nome invalido! Digite apenas letras.\n");
        }

    } while (!verificarNome(clientes[i].nome));

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

    do
    {
        printf("Insira o email do cliente: ");

        fgets(clientes[i].email, 50, stdin);
        clientes[i].email[strcspn(clientes[i].email, "\n")] = 0;

        if (!validarEmail(clientes[i].email))
        {
            printf("Email invalido!\n");
        }

    } while (!validarEmail(clientes[i].email));

    do
    {
        printf("Insira a data de nascimento do cliente (dd/mm/aaaa): ");
        fgets(clientes[i].dataNasc, 20, stdin);
        clientes[i].dataNasc[strcspn(clientes[i].dataNasc, "\n")] = 0;

    } while (!verificarData(clientes[i].dataNasc));

    clientes[i].idade = calcularIdade(clientes[i].dataNasc);

    do
    {
        printf("Insira o telefone do cliente: ");
        fgets(clientes[i].telefone, 20, stdin);
        clientes[i].telefone[strcspn(clientes[i].telefone, "\n")] = 0;

        if (!verificarTelefone(clientes[i].telefone))
        {
            printf("Telefone Invalido. Digite novamente.\n");
        }

    } while (!verificarTelefone(clientes[i].telefone));

    printf("Quantos dependentes você deseja cadastrar? ");
    scanf("%d", &clientes[i].qtdDependentes);
    getchar();

    for (int j = 0; j < clientes[i].qtdDependentes; j++)
    {
        do
        {
            printf("Insira o CPF do dependente %d: ", j + 1);
            fgets(clientes[i].cpfTerc[j], 20, stdin);
            clientes[i].cpfTerc[j][strcspn(clientes[i].cpfTerc[j], "\n")] = 0;

            if (!validarCPF(clientes[i].cpfTerc[j]))
            {
                printf("CPF invalido! Digite exatamente 11 numeros.\n");
            }

        } while (!validarCPF(clientes[i].cpfTerc[j]));

        do
        {
            printf("Insira o nome do dependente %d: ", j + 1);
            fgets(clientes[i].nomeTerc[j], 50, stdin);
            clientes[i].nomeTerc[j][strcspn(clientes[i].nomeTerc[j], "\n")] = 0;

            if (!verificarNome(clientes[i].nomeTerc[j]))
            {
                printf("Nome invalido! Digite apenas letras.\n");
            }

        } while (!verificarNome(clientes[i].nomeTerc[j]));

        do
        {
            printf("Insira a data de nascimento do dependente %d: ", j + 1);
            fgets(clientes[i].dataNascTerc[j], 20, stdin);
            clientes[i].dataNascTerc[j][strcspn(clientes[i].dataNascTerc[j], "\n")] = 0;

        } while (!verificarData(clientes[i].dataNascTerc[j]));
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

    do
    {
        printf("Insira a data do vencimento do plano de saúde (dd/mm/aaaa): ");
        fgets(clientes[i].dataVencimento, 20, stdin);
        clientes[i].dataVencimento[strcspn(clientes[i].dataVencimento, "\n")] = 0;

    } while (!verificarDataVenc(clientes[i].dataVencimento));

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

    printf("\nDigite o numero do cliente que deseja editar(Digite 0 para voltar): ");
    scanf("%d", &posicao);
    getchar();

    if (posicao == 0)
    {
        printf("\nVoltando...\n");
        return;
    }

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
        printf("7 - Plano: %s\n", clientes[posicao].tipoPlano == 1 ? "Prata" : clientes[posicao].tipoPlano == 2 ? "Ouro"
                                                                           : clientes[posicao].tipoPlano == 3   ? "Diamante"
                                                                                                                : "Esmeralda");
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

            do
            {
                printf("Novo CPF: ");

                fgets(clientes[posicao].cpf, 20, stdin);
                clientes[posicao].cpf[strcspn(clientes[posicao].cpf, "\n")] = 0;

                if (!validarCPF(clientes[posicao].cpf))
                {
                    printf("CPF invalido! Digite exatamente 11 numeros.\n");
                }

            } while (!validarCPF(clientes[posicao].cpf));
            break;

        case 2:

            do
            {
                printf("Novo nome: ");
                fgets(clientes[posicao].nome, 50, stdin);
                clientes[posicao].nome[strcspn(clientes[posicao].nome, "\n")] = 0;

                if (!verificarNome(clientes[posicao].nome))
                {
                    printf("Nome invalido! Digite apenas letras.\n");
                }

            } while (!verificarNome(clientes[posicao].nome));
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

            do
            {
                printf("Insira o email do cliente: ");

                fgets(clientes[posicao].email, 50, stdin);
                clientes[posicao].email[strcspn(clientes[posicao].email, "\n")] = 0;

                if (!validarEmail(clientes[posicao].email))
                {
                    printf("Email invalido!\n");
                }

            } while (!validarEmail(clientes[posicao].email));
            break;

        case 5:

            do
            {
                printf("Nova data de nascimento (dd/mm/aaaa): ");
                fgets(clientes[posicao].dataNasc, 20, stdin);
                clientes[posicao].dataNasc[strcspn(clientes[posicao].dataNasc, "\n")] = 0;

            } while (!verificarData(clientes[posicao].dataNasc));

            clientes[posicao].idade =
                calcularIdade(clientes[posicao].dataNasc);

            break;

        case 6:

            do
            {
                printf("Novo telefone: ");
                fgets(clientes[posicao].telefone, 20, stdin);
                clientes[posicao].telefone[strcspn(clientes[posicao].telefone, "\n")] = 0;

                if (!verificarTelefone(clientes[posicao].telefone))
                {
                    printf("Telefone Invalido. Digite novamente.\n");
                }

            } while (!verificarTelefone(clientes[posicao].telefone));
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

            do
            {
                printf("Nova data do vencimento do plano de saúde (dd/mm/aaaa): ");
                fgets(clientes[posicao].dataVencimento, 20, stdin);
                clientes[posicao].dataVencimento[strcspn(clientes[posicao].dataVencimento, "\n")] = 0;

            } while (!verificarDataVenc(clientes[posicao].dataVencimento));

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

                do
                {
                    printf("Insira o CPF do dependente: ");
                    fgets(clientes[posicao].cpfTerc[posdep], 20, stdin);
                    clientes[posicao].cpfTerc[posdep][strcspn(clientes[posicao].cpfTerc[posdep], "\n")] = 0;

                    if (!validarCPF(clientes[posicao].cpfTerc[posdep]))
                    {
                        printf("CPF invalido! Digite exatamente 11 numeros.\n");
                    }

                } while (!validarCPF(clientes[posicao].cpfTerc[posdep]));

                do
                {
                    printf("Insira o nome do dependente: ");
                    fgets(clientes[posicao].nomeTerc[posdep], 50, stdin);
                    clientes[posicao].nomeTerc[posdep][strcspn(clientes[posicao].nomeTerc[posdep], "\n")] = 0;

                    if (!verificarNome(clientes[posicao].nomeTerc[posdep]))
                    {
                        printf("Nome invalido! Digite apenas letras.\n");
                    }

                } while (!verificarNome(clientes[posicao].nomeTerc[posdep]));

                do
                {
                    printf("Insira a data de nascimento do dependente: ");
                    fgets(clientes[posicao].dataNascTerc[posdep], 20, stdin);
                    clientes[posicao].dataNascTerc[posdep][strcspn(clientes[posicao].dataNascTerc[posdep], "\n")] = 0;

                } while (!verificarData(clientes[posicao].dataNascTerc[posdep]));

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

                int opcoes;

                do
                {

                    printf("\n========================================");
                    printf("\nEDITANDO DEPENDENTE: %s", clientes[posicao].nomeTerc[dep]);
                    printf("\n========================================\n");

                    printf("1 - CPF: %s\n", clientes[posicao].cpfTerc[dep]);
                    printf("2 - Nome: %s\n", clientes[posicao].nomeTerc[dep]);
                    printf("3 - Data de Nascimento: %s\n", clientes[posicao].dataNascTerc[dep]);
                    printf("0 - Voltar\n");
                    printf("Escolha um número de 1 a 3 (0 para voltar):");

                    scanf("%d", &opcoes);
                    getchar();

                    switch (opcoes)
                    {
                    case 0:
                        printf("\nVoltando...\n");
                        break;

                    case 1:
                        do
                        {
                            printf("Novo CPF do dependente: ");
                            fgets(clientes[posicao].cpfTerc[dep], 20, stdin);
                            clientes[posicao].cpfTerc[dep][strcspn(clientes[posicao].cpfTerc[dep], "\n")] = 0;

                            if (!validarCPF(clientes[posicao].cpfTerc[dep]))
                            {
                                printf("CPF invalido! Digite exatamente 11 numeros.\n");
                            }

                        } while (!validarCPF(clientes[posicao].cpfTerc[dep]));
                        break;
                    case 2:
                        do
                        {
                            printf("Novo nome do dependente: ");
                            fgets(clientes[posicao].nomeTerc[dep], 50, stdin);
                            clientes[posicao].nomeTerc[dep][strcspn(clientes[posicao].nomeTerc[dep], "\n")] = 0;

                            if (!verificarNome(clientes[posicao].nomeTerc[dep]))
                            {
                                printf("Nome invalido! Digite apenas letras.\n");
                            }

                        } while (!verificarNome(clientes[posicao].nomeTerc[dep]));
                        break;
                    case 3:
                        do
                        {
                            printf("Nova data de nascimento do dependente: ");
                            fgets(clientes[posicao].dataNascTerc[dep], 20, stdin);
                            clientes[posicao].dataNascTerc[dep][strcspn(clientes[posicao].dataNascTerc[dep], "\n")] = 0;

                        } while (!verificarData(clientes[posicao].dataNascTerc[dep]));
                        break;

                    default:
                    printf("\nOpção Invalida.\n");
                        break;
                    }
                } while (opcoes != 0);

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

    printf("\nDigite o numero do cliente que deseja remover (0 para voltar): \n");
    scanf("%d", &posicao);
    getchar();

    if (posicao == 0)
    {
        printf("\nVoltando...\n");
        return;
    }

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