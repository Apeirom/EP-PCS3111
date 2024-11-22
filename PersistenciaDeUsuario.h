#ifndef PERSISTENCIADEUSUARIO_H
#define PERSISTENCIADEUSUARIO_H

#include <vector>
#include <string>
#include "Usuario.h"
#include "Funcionario.h"
#include "Aluno.h"
#include "Visitante.h"

using namespace std;

class PersistenciaDeUsuario
{
public:
  PersistenciaDeUsuario();
  virtual ~PersistenciaDeUsuario();

  vector<Usuario *> *carregar(string arquivo);
  void salvar(string arquivo, vector<Usuario *> *v);
};

#endif
