#include "PersistenciaDeUsuario.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "Entrada.h"
#include "Saida.h"

using namespace std;

PersistenciaDeUsuario::PersistenciaDeUsuario() {}

PersistenciaDeUsuario::~PersistenciaDeUsuario() {}

vector<Usuario *> *PersistenciaDeUsuario::carregar(string arquivo)
{
  ifstream inputFile(arquivo);
  if (!inputFile.is_open())
  {
    throw logic_error("Arquivo nao encontrado ou inacessivel.");
  }

  vector<Usuario *> *usuarios = new vector<Usuario *>;
  char tipoUsuario;

  while (inputFile >> tipoUsuario)
  { // Lê o tipo de usuário
    if (inputFile.eof())
    {
      break;
    }

    int id;
    string nome;
    inputFile >> id >> nome;

    if (tipoUsuario == 'A')
    {
      // Criar um Aluno
      Aluno *aluno = new Aluno(id, nome);
      usuarios->push_back(aluno);
    }
    else if (tipoUsuario == 'F')
    {
      // Criar um Funcionario
      int quantidadeRegistros;
      inputFile >> quantidadeRegistros;

      Funcionario *funcionario = new Funcionario(id, nome);

      for (int i = 0; i < quantidadeRegistros; ++i)
      {
        char tipoRegistro;
        int hora, minuto, segundo, dia, mes, ano, manual;
        inputFile >> tipoRegistro >> hora >> minuto >> segundo >> dia >> mes >> ano >> manual;

        Data *dataRegistro = new Data(hora, minuto, segundo, dia, mes, ano);

        if (tipoRegistro == 'E')
        {
          funcionario->entrar(dataRegistro);
        }
        else if (tipoRegistro == 'S')
        {
          funcionario->sair(dataRegistro);
        }
      }
      usuarios->push_back(funcionario);
    }
    else if (tipoUsuario == 'V')
    {
      // Criar um Visitante
      int horaInicio, minutoInicio, segundoInicio, diaInicio, mesInicio, anoInicio;
      int horaFim, minutoFim, segundoFim, diaFim, mesFim, anoFim;

      inputFile >> horaInicio >> minutoInicio >> segundoInicio >> diaInicio >> mesInicio >> anoInicio >> horaFim >> minutoFim >> segundoFim >> diaFim >> mesFim >> anoFim;

      Data *inicio = new Data(horaInicio, minutoInicio, segundoInicio, diaInicio, mesInicio, anoInicio);
      Data *fim = new Data(horaFim, minutoFim, segundoFim, diaFim, mesFim, anoFim);

      Visitante *visitante = new Visitante(id, nome, inicio, fim);
      usuarios->push_back(visitante);
    }
    else
    {
      throw logic_error("Tipo de usuario desconhecido no arquivo.");
    }
  }

  inputFile.close();
  return usuarios;
}

void PersistenciaDeUsuario::salvar(string arquivo, vector<Usuario *> *usuarios)
{
  ofstream outputFile(arquivo);
  if (!outputFile.is_open())
  {
    throw logic_error("Nao foi possivel salvar no arquivo.");
  }

  for (int i = 0; i < usuarios->size(); i++)
  {
    Usuario* usuario = usuarios->at(i);
    if (dynamic_cast<Aluno *>(usuario))
    {
      // Salvar Aluno
      outputFile << "A " << usuario->getId() << " " << usuario->getNome() << "\n";
    }
    else if (Funcionario *funcionario = dynamic_cast<Funcionario *>(usuario))
    {
      // Salvar Funcionario
      outputFile << "F " << funcionario->getId() << " " << funcionario->getNome() << "\n";
      outputFile << funcionario->getRegistros()->size() << "\n";

      for (int j = 0; j < funcionario->getRegistros()->size(); j++)
      {
        Registro* registro = funcionario->getRegistros()->at(j);
        Data *data = registro->getData();
        outputFile << (dynamic_cast<Entrada *>(registro) ? "E" : "S") << " "
                   << data->getHora() << " " << data->getMinuto() << " " << data->getSegundo() << " "
                   << data->getDia() << " " << data->getMes() << " " << data->getAno() << " "
                   << (registro->isManual() ? 1 : 0) << "\n";
      }
    }
    else if (Visitante *visitante = dynamic_cast<Visitante *>(usuario))
    {
      // Salvar Visitante
      Data *inicio = visitante->getDataInicio();
      Data *fim = visitante->getDataFim();

      outputFile << "V " << visitante->getId() << " " << visitante->getNome() << " "
                 << inicio->getHora() << " " << inicio->getMinuto() << " " << inicio->getSegundo() << " "
                 << inicio->getDia() << " " << inicio->getMes() << " " << inicio->getAno() << " "
                 << fim->getHora() << " " << fim->getMinuto() << " " << fim->getSegundo() << " "
                 << fim->getDia() << " " << fim->getMes() << " " << fim->getAno() << "\n";
    }
  }

  outputFile.close();
}
