#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "conta.h"
#define MAX 1000

void Sair(){
system("color 6");
system("cls");
printf("\t\t\t+---------------------------------------+\n");
printf("\t\t\t|             Desenvolvido por:         |\n");
printf("\t\t\t+---------------------------------------+\n");
Sleep(1000);
printf("\t\t\t|              Esther Pedrosa           |\n");
Sleep(1000);
printf("\t\t\t|              Fabio Passos             |\n");
Sleep(1000);
printf("\t\t\t|             jonathan Gonçalvez        |\n");
Sleep(1000);
printf("\t\t\t|             Larissa Gabrielle         |\n");
printf("\t\t\t+---------------------------------------+\n");
Sleep(1000);
printf("\t\t\t                   Saindo ... \n\n");

}

void logo(){
system("color 6");
printf("\n\n\n\n\n");

printf("\t\t BBBBBBBBBBBBBBBBB               AAA               NNNNNNNN        NNNNNNNNKKKKKKKKK    KKKKKKK  \n");
printf("\t\t B::::::::::::::::B             A:::A              N:::::::N       N::::::NK:::::::K    K:::::K  \n");
printf("\t\t B::::::BBBBBB:::::B           A:::::A             N::::::::N      N::::::NK:::::::K    K:::::K  \n");
printf("\t\t BB:::::B     B:::::B         A:::::::A            N:::::::::N     N::::::NK:::::::K   K::::::K  \n");
printf("\t\t   B::::B     B:::::B        A:::::::::A           N::::::::::N    N::::::NKK::::::K  K:::::KKK  \n");
printf("\t\t   B::::B     B:::::B       A:::::A:::::A          N:::::::::::N   N::::::N  K:::::K K:::::K     \n");
printf("\t\t   B::::BBBBBB:::::B       A:::::A A:::::A         N:::::::N::::N  N::::::N  K::::::K:::::K      \n");
printf("\t\t   B:::::::::::::BB       A:::::A   A:::::A        N::::::N N::::N N::::::N  K:::::::::::K       \n");
printf("\t\t   B::::BBBBBB:::::B     A:::::A     A:::::A       N::::::N  N::::N:::::::N  K:::::::::::K       \n");
printf("\t\t   B::::B     B:::::B   A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N  K::::::K:::::K      \n");
printf("\t\t   B::::B     B:::::B  A:::::::::::::::::::::A     N::::::N    N::::::::::N  K:::::K K:::::K     \n");
printf("\t\t   B::::B     B:::::B A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::NKK::::::K  K:::::KKK  \n");
printf("\t\t BB:::::BBBBBB::::::BA:::::A             A:::::A   N::::::N      N::::::::NK:::::::K   K::::::K  \n");
printf("\t\t B:::::::::::::::::BA:::::A               A:::::A  N::::::N       N:::::::NK:::::::K    K:::::K  \n");
printf("\t\t B::::::::::::::::BA:::::A                 A:::::A N::::::N        N::::::NK:::::::K    K:::::K  \n");
printf("\t\t BBBBBBBBBBBBBBBBBAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNNKKKKKKKKK    KKKKKKK  \n");
printf("\n\n");


printf("\t\t\t\t\t\t   Aguarde carregando ...");
Sleep(2000);
system("cls");
system("color 7");



}

void menu(){

        printf("\t\t+===================================================+\n");
        printf("\t\t|                 Cadastro de Contas                |\n");
        printf("\t\t+===================================================+\n");
        printf("\t\t|               1. Cadastrar Conta                  |\n");
        printf("\t\t|               2. Atualizar Conta                  |\n");
        printf("\t\t|               3. Procurar Conta                   |\n");
        printf("\t\t|               4. Listar todas as Contas           |\n");
        printf("\t\t|               5. Depositar                        |\n");
        printf("\t\t|               6. Sacar                            |\n");
        printf("\t\t|               7. Imprimir conta                   |\n");
        printf("\t\t|               8. Saldo geral                      |\n");
        printf("\t\t|               9. Sair                             |\n");
        printf("\t\t+===================================================+\n\n");
        printf(" Digite sua opcao:  ");


}

void comprar(p_conta pConta[1000], int p);

int main() {
    logo();
    setlocale(LC_ALL, "Portuguese");
    p_conta vtrContas[MAX];
    int p = 0;
    inicializar(vtrContas, MAX);
    // Menu
    int opcao;
    do{
        system("cls");
        menu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                cadastrar(vtrContas, p);
                p++;
                break;
            case 2:
                atualizar(vtrContas, p);
                break;
            case 3:
                listarContaUnica(vtrContas, p);
                break;
            case 4:
                imprimir(vtrContas, p);
                break;
            case 5:
                  depositar(vtrContas, p);
                break;
            case 6:
                sacar(vtrContas, p);
                break;
            case 7:
                listarContaUnica(vtrContas, p);
                break;
            case 8:
                imprimirSaldo(vtrContas, p);
                break;
            case 9:
                Sair();
                exit(0);
        }
    }while(opcao!=9);

    return 0;
}
