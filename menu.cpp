#include "Catraca.h"
#include "GerenciadorDeUsuario.h"
#include "Data.h"
#include "Usuario.h"
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
    cout << "Id: ";
    cin >> id;
    cout << "Hora: ";
    cin >> hora;
    cout << "Minuto: ";        
    cin >> minuto;
    cout << "Segundo: ";
    cin >> segundo;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Ano: ";
    cin >> ano;
    Data* data = new Data(hora, minuto, segundo, dia, mes, ano);

    if(numCatraca == 0){
        if(entrada == true){
            sucesso = catraca0->entrar(id, data);
        }
        else { //saida
            sucesso = catraca0->sair(id, data);
        }
    }
    else { //numCatraca = 1
        if(entrada == true){
            sucesso = catraca1->entrar(id, data);
        }
        else { //saida
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
    else{ //falha
        cout << "[" << tipoPassagem << "] " << "Catraca " << numCatraca << " travada\n";
    }

}

void RegistroManual(GerenciadorDeUsuario* gerenciador){
    char tipoPassagem;
    int id;
    int hora, minuto, segundo, dia, mes, ano;
    bool sucesso;
    string tipoPassagemString;
    cout << "Entrada (e) ou saida (s)? ";
    cin >> tipoPassagem;
    cout << "Id: ";
    cin >> id;
    cout << "Hora: ";
    cin >> hora;
    cout << "Minuto: ";        
    cin >> minuto;
    cout << "Segundo: ";
    cin >> segundo;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Ano: ";
    cin >> ano;
    Data* data = new Data(hora, minuto, segundo, dia, mes, ano);
    if (tipoPassagem == 'e'){
        sucesso = gerenciador->getUsuario(id)->entrar(data);
        tipoPassagemString = "entrada";
    }
    else { //tipoPassagem == 's'
        sucesso = gerenciador->getUsuario(id)->sair(data);
        tipoPassagemString = "saida";
    }
    if (sucesso = true){
        cout << tipoPassagemString << " manual registra: id " << id << "\n";
    }
    else{ //falha
        cout << "Erro ao registrar " << tipoPassagemString << " manual \n";
    }
}

void CadastroDeUsuario(GerenciadorDeUsuario* gerenciador){
    int id;
    string nome;
    bool sucesso;
    cout << "Id: ";
    cin >> id;
    cout << "Nome: ";
    cin >> nome;
    Usuario* usuario = new Usuario(id, nome, 10);
    sucesso = gerenciador->adicionar(usuario);
    if (sucesso = true){
        cout << "Usuario cadastrado com sucesso\n";
    }
    else{ //falha
        cout << "Erro ao cadastrar o usuario\n";
    }
}

void Relatorio(GerenciadorDeUsuario* gerenciador){
    int mes, ano;
    cout << "Mes: ";
    cin >> mes;
    cout << "Ano: ";
    cin >> ano;
    cout << "Relatorio de horas trabalhadas\n";
    for (int i = 0; i < gerenciador->getQuantidade(); i++){
        cout << gerenciador->getUsuarios()[i]->getNome() << ": " << gerenciador->getUsuarios()[i]->getHorasTrabalhadas(mes, ano) << "\n";
    }
}



void menu() {

bool fim = false;
int opcao;

GerenciadorDeUsuario* gerenciador = new GerenciadorDeUsuario(10);

Catraca* catraca0 = new Catraca(gerenciador);
Catraca* catraca1 = new Catraca(gerenciador);

do {
    cout << "Acesso ao predio\n" << "1) Entrada\n" << "2) Saida\n" << "3) Registro Manual\n" << "4) Cadastro de Usuario\n" << "5) Relatorio\n"
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
            RegistroManual(gerenciador);
            break;
        case 4:
            CadastroDeUsuario(gerenciador);
            break;
        case 5:
            Relatorio(gerenciador);
            break;
        case 0:
            fim = true;
            break;
    }
    cout << "\n";
} while (fim != true);
// nao tenho certeza se precisa desses delete
delete catraca0;
delete catraca1;
delete gerenciador;

}