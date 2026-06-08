#include <stdio.h>
#include <string.h>

void cadastrar(char cpf[][20], char nome[][50], char email[][50],
    char dataNasc[][20], char telefone[][20],
    char cpfTerc[][20], char nomeTerc[][50],
    char dataNascTerc[][20], int sexo[],
    int tipoPlano[], char dataVencimento[][20],
    int i);

int main() {
    char cpf[30][20], nome[30][50], email[30][50], dataNasc[30][20], telefone[30][20], dataVencimento[30][20];
    char cpfTerc[30][20], nomeTerc[30][50], dataNascTerc[30][20];
    int sexo[30], tipoPlano[30];

    int i = 0;
    int escolha = -1;

    while(escolha != 0 && i < 30){
        do{
            printf("\n--- Núcleo Seguros ---\n");
            printf("1 - Cadastrar Cliente \n");
            printf("2 - Editar Cliente \n");
            printf("3 - Remover Cliente \n");
            printf("4 - Listagem Geral \n");
            printf("5 - Listagem por Plano \n");
            printf("6 - Listagem dos Vencimentos \n");
            printf("0 - Sair \n");
            printf("Escolha uma opção: ");
            scanf("%d", &escolha);
            getchar();

            if (escolha < 0 || escolha > 6){
                printf("Opção invalida. Tente novamente.\n");
            }
        } while(escolha < 0 || escolha > 6);

        if(escolha == 1){
            cadastrar(
                cpf, nome, email,
                dataNasc, telefone,
                cpfTerc, nomeTerc,
                dataNascTerc, sexo,
                tipoPlano, dataVencimento,
                i
            );

            i++;
            printf("\nCliente cadastrado com sucesso!\n");
        } 
        else if (escolha >= 2 && escolha <= 6) {
            printf("\nOpção %d selecionada (Funcionalidade em desenvolvimento...)\n", escolha);
        }
    }

    printf("\nPrograma encerrado. Até logo!\n");
    return 0;
}