#include <stdio.h>

void listagemGeral(
    char cpf[][20], char nome[][50], char telefone[][20],
    int sexo[], int idade[], int tipoPlano[],
    int qtdDependentes[], float valorPlano[],
    char dataVencimento[][20], int i)
{
    for(int k = 0; k < 130; k++){
        printf("=");
    }

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

    for(int j = 0; j < i; j++){

        printf("%-15s %-25s %-6s %-15s %-6d %-12s %-12d R$%-10.2f %-12s\n",
            cpf[j],
            nome[j],
            sexo[j] == 1 ? "F" : "M",
            telefone[j],
            idade[j],
            tipoPlano[j] == 1 ? "Prata" :
            tipoPlano[j] == 2 ? "Ouro" :
            tipoPlano[j] == 3 ? "Diamante" : "Esmeralda",
            qtdDependentes[j],
            valorPlano[j],
            dataVencimento[j]);
    }
    
}