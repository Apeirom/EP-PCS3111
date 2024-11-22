#ifndef ALUNO_H
#define ALUNO_H
#include <string>

#include "Usuario.h"

using namespace std;

class Aluno : public Usuario
{
private:
  static int horaFim;
  static int minutoFim;

public:
  static const int HORARIO_INICIO = 6;
  Aluno(int id, string nome);
  virtual ~Aluno();

  static void setHorarioFim(int hora, int minuto);
  static int getHoraFim();
  static int getMinutoFim();

  bool entrar(Data *d);
  bool sair(Data *d);
  bool registrarEntradaManual(Data *d);
  bool registrarSaidaManual(Data *d);
};
#endif