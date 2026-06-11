#include <stdio.h>
#include <string.h>

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

void cadastrar(char cpf[][20], char nome[][50], char email[][50],
    char dataNasc[][20], char telefone[][20],
    char cpfTerc[][10][20], char nomeTerc[][10][50],
    char dataNascTerc[][10][20], int sexo[],
    int tipoPlano[], char dataVencimento[][20],
    float valorPlano[], int idade[], int qtdDependentes[], int i) {
            printf("\n--- Cadastro do Cliente %d ---\n", i + 1);
            
            printf("Insira o CPF do cliente: ");
            fgets(cpf[i], 20, stdin);
            cpf[i][strcspn(cpf[i], "\n")] = 0;

            printf("Insira o nome do cliente: ");
            fgets(nome[i], 50, stdin);
            nome[i][strcspn(nome[i], "\n")] = 0;

            printf("Digite o gênero do cliente (1-fem/2-masc): ");
            do{
                scanf("%d", &sexo[i]);
                getchar();
                if(sexo[i] != 1 && sexo[i] != 2){
                    printf("Opção invalida. Tente novamente: ");
                }
            } while(sexo[i] != 1 && sexo[i] != 2);

            printf("Insira o email do cliente: ");
            fgets(email[i], 50, stdin);
            email[i][strcspn(email[i], "\n")] = 0;

            printf("Insira a data de nascimento do cliente (dd/mm/aaaa): ");
            fgets(dataNasc[i], 20, stdin);
            dataNasc[i][strcspn(dataNasc[i], "\n")] = 0;

            idade[i] = calcularIdade(dataNasc[i]);

            printf("Insira o telefone do cliente: ");
            fgets(telefone[i], 20, stdin);
            telefone[i][strcspn(telefone[i], "\n")] = 0;

            printf("Quantos dependentes você deseja cadastrar? ");
            scanf("%d", &qtdDependentes[i]);
            getchar();

            for(int j = 0; j < qtdDependentes[i]; j++){

                printf("Insira o CPF do dependente %d: ", j + 1);
                fgets(cpfTerc[i][j], 20, stdin);
                cpfTerc[i][j][strcspn(cpfTerc[i][j], "\n")] = 0;

                printf("Insira o nome do dependente %d: ", j + 1);
                fgets(nomeTerc[i][j], 50, stdin);
                nomeTerc[i][j][strcspn(nomeTerc[i][j], "\n")] = 0;

                printf("Insira a data de nascimento do dependente %d: ", j + 1);
                fgets(dataNascTerc[i][j], 20, stdin);
                dataNascTerc[i][j][strcspn(dataNascTerc[i][j], "\n")] = 0;
            }

            printf("Digite o tipo do plano de saúde (1 - Prata / 2 - Ouro / 3 - Diamante / 4 - Esmeralda): ");
            do{
                scanf("%d", &tipoPlano[i]);
                getchar();
                if(tipoPlano[i] < 1 || tipoPlano[i] > 4){
                    printf("Opção invalida. Tente novamente: ");
                }
            } while(tipoPlano[i] < 1 || tipoPlano[i] > 4);
            if(tipoPlano[i] == 1){
                valorPlano[i] = 200;
            }
            else if(tipoPlano[i] == 2){
                valorPlano[i] = 300;
            }
            else if(tipoPlano[i] == 3){
                valorPlano[i] = 400;
            }
            else{
                valorPlano[i] = 500;
            }
            
            printf("Insira a data do vencimento do plano de saúde: ");
            fgets(dataVencimento[i], 20, stdin);
            dataVencimento[i][strcspn(dataVencimento[i], "\n")] = 0;

            if(idade[i] < 13){
                valorPlano[i] = valorPlano[i] - (valorPlano[i] * 0.3);
            }
            if(sexo[i] == 1 && idade[i] >= 13 && idade[i] < 35){
                valorPlano[i] = valorPlano[i] + (valorPlano[i] * 0.3);
            }
            if(idade[i] >= 60){
                valorPlano[i] = valorPlano[i] + (valorPlano[i] * 0.4);
            }
            if(qtdDependentes[i] > 1){
            valorPlano[i] = valorPlano[i] - (valorPlano[i] * 0.2);
            }


}