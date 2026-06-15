#include <stdio.h>
#include "cliente.h"

void listagemGeral(Cliente clientes[], int i){
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
            clientes[j].cpf,
            clientes[j].nome,
            clientes[j].sexo == 1 ? "F" : "M",
            clientes[j].telefone,
            clientes[j].idade,
            clientes[j].tipoPlano == 1 ? "Prata" :
            clientes[j].tipoPlano == 2 ? "Ouro" :
            clientes[j].tipoPlano == 3 ? "Diamante" : "Esmeralda",
            clientes[j].qtdDependentes,
            clientes[j].valorPlano,
            clientes[j].dataVencimento);
    }

    printf("\nTecle ENTER para voltar ao menu...");
    getchar();
    
}