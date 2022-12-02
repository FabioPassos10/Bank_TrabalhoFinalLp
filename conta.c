#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "conta.h"


struct Conta{
    int numero;
    char cliente[51];
    int especial;
    double saldo;
};

void inicializar(p_conta pConta[], int tamanho){
    for(int i=0; i<tamanho; i++){
        pConta[i] = NULL;
    }
}

void cadastrar(p_conta pConta[], int posicao){

    pConta[posicao] = (p_conta) malloc(sizeof(struct Conta));//?
    printf("\n Digite o codigo da Conta: ");
    scanf("%d", & pConta[posicao]->numero);

    fflush(stdin);
    printf(" Digite o nome do cliente: ");
    gets(pConta[posicao]->cliente);

    printf("\n Digite o tipo da Conta: \n");
    printf("   +-------------------------+\n");
    printf("   |    0 - Conta Normal     |\n");
    printf("   |    1 - Conta Especial   |\n");
    printf("   +-------------------------+\n");
    printf("-->  ");
    scanf("%d", &pConta[posicao]->especial);

    printf("+--------------------------------------------------------------------+\n");
    printf("|              Cadastro do produto efetuado com sucesso.             |\n");
    printf("+--------------------------------------------------------------------+\n");
    system("pause");


    pConta[posicao]->saldo = 0;


}

void imprimir(p_conta pConta[], int tamanho){

    for(int i=0; i<tamanho; i++){
        printf("\n");
        imprimirConta(pConta, i);

    }
    system("pause");
}

void imprimirSaldo(p_conta pConta[], int tamanho){

    for(int i=0; i<tamanho; i++){
        printf("\n");
        saldoGeral(pConta, i);

    }
    system("pause");
}


void atualizar(p_conta pConta[], int tamanho){
    int codProcurado = procurarConta();
    for(int i = 0; i< tamanho; i++){
        if(codProcurado == pConta[i]->numero){
            printf("\n\t\t+=============================+\n");
            printf("\t\t|      Atualizando conta      |\n");
            printf("\t\t+=============================+\n");
            fflush(stdin);
            printf("\n Digite o novo nome: ");
            gets(pConta[i]->cliente);
            printf("\n\n+---------------------------------------+\n");
            printf("|       Conta Atualizada com sucesso    |\n");
            printf("+---------------------------------------+\n");
            system("pause");
            return;
        }
    }
    printf("\nConta nao encontrada\n");
    system("pause");
}




void depositar(p_conta pConta[], int tamanho) {
    int codProcurado = procurarConta();
    system("cls");
    printf("\n\t\t+=============================+\n");
    printf("\t\t|         Deposito            |\n");
    printf("\t\t+=============================+\n");
    for(int i = 0; i<tamanho; i++){
        if(codProcurado == pConta[i]->numero){
            fflush(stdin);
            printf(" Digite o valor que deseja depositar: ");
            int qtd;
            scanf("%d", &qtd);
            if(qtd <=0 ){
                printf("\nValor indevido. Informar corretamente\n");
                system("pause");
                return;
            }
            pConta[i]-> saldo += qtd;
            printf("\nDeposito realizado com sucesso.\n");
            system("pause");
            return;
        }
    }
    printf("\nConta nao encontrada\n");
    system("pause");
}
void saldoGeral(p_conta const *pConta, int i) {

    printf("\n\n+------------------------------------------------+\n");
    printf(" Nº Conta: %d \n", pConta[i]->numero);
    printf(" Saldo: %f \n", pConta[i]->saldo);
    printf("\n+------------------------------------------------+\n");

}



void sacar(p_conta pConta[], int tamanho) {
    int codProcurado = procurarConta();
    system("cls");
    printf("\n\t\t+=============================+\n");
    printf("\t\t|            Saque            |\n");
    printf("\t\t+=============================+\n");
    for(int i = 0; i<tamanho; i++){
        if(codProcurado == pConta[i]->numero){
            fflush(stdin);
            printf(" Digite a que deseja sacar: ");
            int qtd;
            scanf("%d", &qtd);
            if(qtd > pConta[i]->saldo){
                printf("Quantidade indisponivel para saque... \n");
                system("pause");
                return;
            }
            pConta[i]->saldo -= qtd;
            printf("\nSaque realizado com sucesso.\n");
            system("pause");
            return;
        }
    }
    printf("\nConta nao encontrada\n");
    system("pause");
}



void listarContaUnica(p_conta pConta[], int tamanho){
    int codProcurado = procurarConta();
    for(int i = 0; i<tamanho; i++){
        if(codProcurado == pConta[i]->numero){
            imprimirConta(pConta, i);
            system("pause");
            return;
        }
    }
    printf("\nConta não encontrada\n");
    system("pause");
}


void imprimirConta(p_conta const *pConta, int i) {

    printf("\n+------------------------------------------------+\n");
    printf(" Numero da conta: %d \n", pConta[i]->numero);
    printf(" Cliente: %s \n", pConta[i]->cliente);
    if(pConta[i]->especial == 1){
     printf(" Tipo de conta: %d Especial \n", pConta[i]->especial);
    }else{
     printf(" Tipo de conta: %d Normal \n", pConta[i]->especial);
    }
    printf(" Saldo: %f \n", pConta[i]->saldo);
    printf("\n+------------------------------------------------+\n");

}

int procurarConta() {
    int codProcurado;
    printf(" Digite o codigo da conta a ser procurada: ");
    scanf("%d", &codProcurado);
    return codProcurado;
}

