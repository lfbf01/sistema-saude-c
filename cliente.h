#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct{
    char cpf[20];
    char nome[50];
    char email[50];
    char dataNasc[20];
    char telefone[20];

    int sexo;
    int idade;

    int qtdDependentes;

    char cpfTerc[10][20];
    char nomeTerc[10][50];
    char dataNascTerc[10][20];

    int tipoPlano;
    float valorPlano;

    char dataVencimento[20];

} Cliente;

#endif