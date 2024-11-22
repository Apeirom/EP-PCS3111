#include "Funcionario.h"
#include "Entrada.h"
#include "Saida.h"


Funcionario::Funcionario(int id, string nome) : Usuario(id, nome)
{
  this->registros = new vector<Registro *>;
}

Funcionario::Funcionario(int id, string nome, vector<Registro *> *registros) : Usuario(id, nome)
{
  this->registros = registros;
}

Funcionario::~Funcionario()
{
  for (int i = 0; i < this->registros->size(); i++)
  {
    delete this->registros->at(i);
  }
  delete this->registros;
}

int Funcionario::getHorasTrabalhadas(int mes, int ano)
{
    int somaHorasTrabalhadas = 0;
    int quantidade = this->registros->size();
    for(int i = 0; i < quantidade; i++)
    {
        if (isRegistroEntrada(i) && i+1 < quantidade)
        {
            Data* dataEntrada = this->registros->at(i)->getData();
            Data* dataSaida = this->registros->at(i+1)->getData();
            if (dataEntrada->getMes() == mes && dataEntrada->getAno() == ano)
            {
                somaHorasTrabalhadas += dataSaida->diferenca(dataEntrada);
            }
        }

    }
    return somaHorasTrabalhadas/3600;
}

vector<Registro *> *Funcionario::getRegistros()
{
  return this->registros;
}

// Metodos privados auxiliares
bool Funcionario::isRegistroEntrada(int index)
{
  return (dynamic_cast<Entrada *>(this->registros->at(index)) != nullptr);
}

bool Funcionario::autorizaRegistro(Data *d, bool entrar)
{
  if (this->registros->empty())
  {
    return true;
  }
  if (isRegistroEntrada(this->registros->size() - 1) == entrar)
  {
    return false;
  }

  if (this->registros->back()->getData()->diferenca(d) > 0)
  {
    return false;
  }
  return true;
}

// Redefinição de metodos publicos da superclasse
bool Funcionario::entrar(Data *d)
{
  bool podeEntrar = this->autorizaRegistro(d, true);
  if (podeEntrar)
  {
    this->registros->push_back(new Entrada(d, false));
  }
  return podeEntrar;
}

bool Funcionario::sair(Data *d)
{
  bool podeSair = this->autorizaRegistro(d, false);
  if (podeSair)
  {
    this->registros->push_back(new Saida(d, false));
  }
  return podeSair;
}

bool Funcionario::registrarEntradaManual(Data *d)
{
  bool podeEntrar = this->autorizaRegistro(d, true);
  if (podeEntrar)
  {
    this->registros->push_back(new Entrada(d, true));
  }
  return podeEntrar;
}

bool Funcionario::registrarSaidaManual(Data *d)
{
  bool podeSair = this->autorizaRegistro(d, false);
  if (podeSair)
  {
    this->registros->push_back(new Saida(d, true));
  }
  return podeSair;
}