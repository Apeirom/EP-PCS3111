#include "Catraca.h"
#include "GerenciadorDeUsuario.h"
#include "PersistenciaDeUsuario.h"
#include "Data.h"
#include "Aluno.h"
#include "Funcionario.h"
#include "Visitante.h"
#include <iostream>

using namespace std;

Data* ObterData() {
    int hora, minuto, segundo, dia, mes, ano;

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
    return new Data(hora, minuto, segundo, dia, mes, ano);
}

void PassagemCatraca(Catraca* catraca0, Catraca* catraca1, bool entrada) {
    int numCatraca, id;
    cout << "Catraca: ";
    cin >> numCatraca;
    cout << "Id: ";
    cin >> id;
    Data* data = ObterData();

    bool sucesso = (numCatraca == 0) ? 
        (entrada ? catraca0->entrar(id, data) : catraca0->sair(id, data)) :
        (entrada ? catraca1->entrar(id, data) : catraca1->sair(id, data));

    if(sucesso){}
    cout << (entrada ? "[Entrada] " : "[Saida] ") << "Catraca " << numCatraca;
    if(sucesso){
        cout << " abriu: id " << id << endl;
    } else {
        cout << " travada" << endl;
    }
    delete data;
}

void RegistroManual(GerenciadorDeUsuario* gerenciador) {
    char tipoPassagem;
    int id;
    cout << "Entrada (e) ou Saida (s)? ";
    cin >> tipoPassagem;
    cout << "Id: ";
    cin >> id;
    Data* data = ObterData();

    Usuario* usuario = gerenciador->getUsuario(id);
    if (!usuario) {
        cout << "Usuario nao encontrado.\n";
        delete data;
        return;
    }

    bool sucesso = (tipoPassagem == 'e') ? usuario->entrar(data) : usuario->sair(data);
    cout << (sucesso ? (tipoPassagem == 'e' ? "Entrada" : "Saida") + string(" manual registrada: id ") + to_string(id)
                     : "Erro ao registrar manualmente") << "\n";
    delete data;
}

void CadastroDeUsuario(GerenciadorDeUsuario* gerenciador) {
    char tipoUsuario;
    int id;
    string nome;

    cout << "Tipo (v, a ou f): ";
    cin >> tipoUsuario;
    cout << "Id: ";
    cin >> id;
    cout << "Nome: ";
    cin >> nome;

    Usuario* usuario = nullptr;
    if (tipoUsuario == 'a') {
        usuario = new Aluno(id, nome);
    } else if (tipoUsuario == 'f') {
        usuario = new Funcionario(id, nome);
    } else if (tipoUsuario == 'v') {
        cout << "Data de Inicio:\n";
        Data* inicio = ObterData();
        cout << "Data de Fim:\n";
        Data* fim = ObterData();
        usuario = new Visitante(id, nome, inicio, fim);
    } else {
        cout << "Tipo invalido.\n";
        return;
    }

    try
    {
        gerenciador->adicionar(usuario);
        cout << "Usuario cadastrado com sucesso\n";
    }
    catch(invalid_argument *e)
    {
        cout << "Erro ao cadastrar o usuario\n";
        delete usuario;
    }
}

void Relatorio(GerenciadorDeUsuario* gerenciador) {
    int mes, ano;
    cout << "Mes: ";
    cin >> mes;
    cout << "Ano: ";
    cin >> ano;
    cout << "Relatorio de horas trabalhadas\n";
    for (int i = 0; i < gerenciador->getUsuarios()->size(); i++) {
        Usuario* usuario = gerenciador->getUsuarios()->at(i);
        Funcionario* funcionario = dynamic_cast<Funcionario*>(usuario);
        if (funcionario) {
            cout << funcionario->getNome() << ": " << funcionario->getHorasTrabalhadas(mes, ano) << "\n";
        }
    }
}

void Configuracao(GerenciadorDeUsuario* gerenciador) {
    int hora, minuto;

    cout << "Horario de fim da janela dos Alunos\n";
    cout << "Hora: ";
    cin >> hora;
    cout << "Minuto: ";
    cin >> minuto;

    Aluno::setHorarioFim(hora, minuto);
}

void menu() {
    bool fim = false;
    GerenciadorDeUsuario* gerenciador = nullptr;
    PersistenciaDeUsuario persistencia;
    Catraca* catraca0 = nullptr;
    Catraca* catraca1 = nullptr;

    cout << "Deseja carregar usuarios (s/n): ";
    char opcao;
    cin >> opcao;
    if (opcao == 's') {
        string arquivo;
        cout << "Arquivo: ";
        cin >> arquivo;
        try {
            gerenciador = new GerenciadorDeUsuario(persistencia.carregar(arquivo));
        } catch (...) {
            cout << "Erro ao carregar usuarios.\n";
            return;
        }
    } else {
        gerenciador = new GerenciadorDeUsuario();
    }

    catraca0 = new Catraca(gerenciador);
    catraca1 = new Catraca(gerenciador);

    do {
        cout << "Acesso ao predio\n"
             << "1) Entrada\n"
             << "2) Saida\n"
             << "3) Registro manual\n"
             << "4) Cadastro de usuario\n"
             << "5) Relatorio\n"
             << "6) Configuracao\n"
             << "0) Sair\n"
             << "Escolha uma opcao: ";
        int escolha;
        cin >> escolha;

        switch (escolha) {
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
            case 6:
                Configuracao(gerenciador);
                break;
            case 0:
                fim = true;
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (!fim);

    cout << "Deseja salvar usuarios (s/n): ";
    cin >> opcao;
    if (opcao == 's') {
        string arquivo;
        cout << "Arquivo: ";
        cin >> arquivo;
        try {
            persistencia.salvar(arquivo, gerenciador->getUsuarios());
            cout << "Usuarios salvos com sucesso.\n";
        } catch (...) {
            cout << "Erro ao salvar usuarios.\n";
        }
    }

    delete catraca0;
    delete catraca1;
    delete gerenciador;
}
