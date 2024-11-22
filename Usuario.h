#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "Registro.h"

using namespace std;

class Usuario{
private:
  string nome = "";
  int id = 0;
  int maximo;
  int quantidade = 0;
  // Registro** registros;
  // bool isRegistroEntrada(int i);
  // bool autorizaRegistro(Data *d, bool entrar);

public:
    Usuario(int id, string nome);
    virtual ~Usuario();

    string getNome();
    int getId();

    virtual bool entrar(Data *d) = 0;
    virtual bool sair(Data *d) = 0;
    virtual bool registrarEntradaManual(Data *d) = 0;
    virtual bool registrarSaidaManual(Data* d) = 0;
    // int getHorasTrabalhadas(int mes, int ano);
    // Registro** getRegistros();
    // int getQuantidade(); 
};
#endif