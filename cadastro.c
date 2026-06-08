#include <stdio.h>
#include <string.h>

void cadastrar(char cpf[][20], char nome[][50], char email[][50],
    char dataNasc[][20], char telefone[][20],
    char cpfTerc[][20], char nomeTerc[][50],
    char dataNascTerc[][20], int sexo[],
    int tipoPlano[], char dataVencimento[][20],
    int i) {
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

            printf("Insira o telefone do cliente: ");
            fgets(telefone[i], 20, stdin);
            telefone[i][strcspn(telefone[i], "\n")] = 0;

            printf("Insira o CPF do terceiro: ");
            fgets(cpfTerc[i], 20, stdin);
            cpfTerc[i][strcspn(cpfTerc[i], "\n")] = 0;

            printf("Insira o nome do terceiro: ");
            fgets(nomeTerc[i], 50, stdin);
            nomeTerc[i][strcspn(nomeTerc[i], "\n")] = 0;

            printf("Insira a data de nascimento do terceiro: ");
            fgets(dataNascTerc[i], 20, stdin);
            dataNascTerc[i][strcspn(dataNascTerc[i], "\n")] = 0;

            printf("Digite o tipo do plano de saúde (1 - Ouro / 2 - Diamante / 3 - Prata / 4 - Esmeralda): ");
            do{
                scanf("%d", &tipoPlano[i]);
                getchar();
                if(tipoPlano[i] < 1 || tipoPlano[i] > 4){
                    printf("Opção invalida. Tente novamente: ");
                }
            } while(tipoPlano[i] < 1 || tipoPlano[i] > 4);

            printf("Insira a data do vencimento do plano de saúde: ");
            fgets(dataVencimento[i], 20, stdin);
            dataVencimento[i][strcspn(dataVencimento[i], "\n")] = 0;
}