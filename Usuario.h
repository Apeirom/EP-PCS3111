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
  Registro** registros;
  bool isRegistroEntrada(int i);
  bool autorizaRegistro(Data *d, bool entrar);

public:
    Usuario(int id, string nome, int maximo);
    virtual ~Usuario();
    string getNome();
    int getId();
    bool entrar(Data *d);
    bool sair(Data *d);
    bool registrarEntradaManual(Data *d);
    bool registrarSaidaManual(Data* d);
    int getHorasTrabalhadas(int mes, int ano);
    Registro** getRegistros();
    int getQuantidade(); 
};
#endif