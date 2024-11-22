#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <string>
#include <vector>

#include "Registro.h"
#include "Usuario.h"

using namespace std;

class Funcionario : public Usuario {

private:
    bool isRegistroEntrada(int i);
    bool autorizaRegistro(Data *d, bool entrar);

  protected:
    vector<Registro *> *registros;

  public:
    Funcionario(int id, string nome);
    Funcionario(int id, string nome, vector<Registro *> *registros);
    virtual ~Funcionario();

    int getHorasTrabalhadas(int mes, int ano);
    vector<Registro *> *getRegistros();

    bool entrar(Data *d);
    bool sair(Data *d);
    bool registrarEntradaManual(Data *d);
    bool registrarSaidaManual(Data *d);
};
#endif