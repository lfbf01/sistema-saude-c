#include <stdio.h>
#include <string.h>
#include "cliente.h"


int calcularIdade(char dataNasc[])
{
    int dia, mes, ano;
    int dAtual = 7, mAtual = 6, aAtual = 2026;

    sscanf(dataNasc, "%d/%d/%d", &dia, &mes, &ano);

    int idade = aAtual - ano;

    if (mes > mAtual || (mes == mAtual && dia > dAtual)) {
        idade--;
    }

    return idade;
}

void cadastrar(Cliente clientes[], int i) {
            printf("\n--- Cadastro do Cliente %d ---\n", i + 1);
            
            printf("Insira o CPF do cliente: ");
            fgets(clientes[i].cpf, 20, stdin);
            clientes[i].cpf[strcspn(clientes[i].cpf, "\n")] = 0;

            printf("Insira o nome do cliente: ");
            fgets(clientes[i].nome, 50, stdin);
            clientes[i].nome[strcspn(clientes[i].nome, "\n")] = 0;

            printf("Digite o gênero do cliente (1-fem/2-masc): ");
            do{
                scanf("%d", &clientes[i].sexo);
                getchar();
                if(clientes[i].sexo != 1 && clientes[i].sexo != 2){
                    printf("Opção invalida. Tente novamente: ");
                }
            } while(clientes[i].sexo != 1 && clientes[i].sexo != 2);

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

            for(int j = 0; j < clientes[i].qtdDependentes; j++){

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
            do{
                scanf("%d", &clientes[i].tipoPlano);
                getchar();
                if(clientes[i].tipoPlano < 1 || clientes[i].tipoPlano > 4){
                    printf("Opção invalida. Tente novamente: ");
                }
            } while(clientes[i].tipoPlano < 1 || clientes[i].tipoPlano > 4);
            if(clientes[i].tipoPlano == 1){
                clientes[i].valorPlano = 200;
            }
            else if(clientes[i].tipoPlano == 2){
                clientes[i].valorPlano = 300;
            }
            else if(clientes[i].tipoPlano == 3){
                clientes[i].valorPlano = 400;
            }
            else{
                clientes[i].valorPlano = 500;
            }
            
            printf("Insira a data do vencimento do plano de saúde: ");
            fgets(clientes[i].dataVencimento, 20, stdin);
            clientes[i].dataVencimento[strcspn(clientes[i].dataVencimento, "\n")] = 0;

            if(clientes[i].idade < 13){
                clientes[i].valorPlano = clientes[i].valorPlano - (clientes[i].valorPlano * 0.3);
            }
            if(clientes[i].sexo == 1 && clientes[i].idade >= 13 && clientes[i].idade < 35){
                clientes[i].valorPlano = clientes[i].valorPlano + (clientes[i].valorPlano * 0.3);
            }
            if(clientes[i].idade >= 60){
                clientes[i].valorPlano = clientes[i].valorPlano + (clientes[i].valorPlano * 0.4);
            }
            if(clientes[i].qtdDependentes > 1){
            clientes[i].valorPlano = clientes[i].valorPlano - (clientes[i].valorPlano * 0.2);
            }

            printf("\nCliente cadastrado com sucesso!\n");


}