#include "Catraca.h"
#include "GerenciadorDeUsuario.h"
#include "Data.h"
#include <iostream>

using namespace std;

void PassagemCatraca(Catraca* catraca0, Catraca* catraca1, bool entrada){
    int numCatraca;
    int id;
    int hora, minuto, segundo, dia, mes, ano;
    bool sucesso;
    string tipoPassagem;
    cout << "Catraca: ";
    cin >> numCatraca;
    cout << "\nId: ";
    cin >> id;
    cout << "\nHora: ";
    cin >> hora;
    cout << "\nMinuto: ";        
    cin >> minuto;
    cout << "\nSegundo: ";
    cin >> segundo;
    cout << "\nDia: ";
    cin >> dia;
    cout << "\nMes: ";
    cin >> mes;
    cout << "\nAno: ";
    cin >> ano;
    Data* data = new Data(hora, minuto, segundo, dia, mes, ano);

    if(numCatraca = 0){
        if(entrada == true){
            sucesso = catraca0->entrar(id, data);
        }
        else {
            sucesso = catraca0->sair(id, data);
        }
    }
    else {
        if(entrada == true){
            sucesso = catraca1->entrar(id, data);
        }
        else {
            sucesso = catraca1->sair(id, data);
        }
    }

    if (entrada == true){
        tipoPassagem = "Entrada";
    }
    else{
        tipoPassagem = "Saida";
    }

    if (sucesso == true){
        cout << "[" << tipoPassagem << "] " << "Catraca " << numCatraca << " abriu: id " << id << "\n";
    }
    else{
        cout << "[" << tipoPassagem << "] " << "Catraca " << numCatraca << " travada\n";
    }

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
            PassagemCatraca(catraca0, catraca1, true);
            break;
        case 2:
            PassagemCatraca(catraca0, catraca1, false);
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
        default:
            cout << "Opcao invalida\n";
            break;
    }
} while (fim != true);
// nao tenho certeza se precisa desses delete
delete catraca0;
delete catraca1;
delete gerenciador;

}