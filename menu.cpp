#include "Catraca.h"
#include "GerenciadorDeUsuario.h"
#include <iostream>

using namespace std;

// falta implementar
void opcao1(){

}
void opcao2(){

}
void opcao3(){
    
}
void opcao4(){
    
}
void opcao5(){
    
}



void menu() {

bool fim = false;
int opcao;

GerenciadorDeUsuario* gerenciador = new GerenciadorDeUsuario(10);

Catraca* catraca0 = new Catraca(gerenciador);
Catraca* catraca1 = new Catraca(gerenciador);

do {
    cout << "Acesso ao predio\n" << "1) Entrada\n" << "2) Saida\n" << "3) Registro Manual\n" << "4) Cadastro de Usuario" << "5) Relatorio\n"
         << "0) Sair\n" << "Escolha uma opcao: ";
    cin >> opcao;
    cout << "\n";
    switch (opcao) {
        case 1:
            opcao1();
            break;
        case 2:
            opcao2();
            break;
        case 3:
            opcao3();
            break;
        case 4:
            opcao4();
            break;
        case 5:
            opcao5();
            break;
        case 0:
            fim = true;
            break;
    }
} while (fim != true);
}