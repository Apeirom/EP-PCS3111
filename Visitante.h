#ifndef VISITANTE_H
#define VISITANTE_H

#include "Usuario.h"
#include "Data.h"

#include <string>
#include <stdexcept>

class Visitante : public Usuario {
private:
    Data* inicio; // Data de início do período permitido
    Data* fim;    // Data de término do período permitido

public:
    Visitante(int id, string nome, Data* inicio, Data* fim);
    virtual ~Visitante();

    Data* getDataInicio();
    Data* getDataFim();

    bool entrar(Data* data) override;
    bool sair(Data* data) override;
    bool registrarEntradaManual(Data* data) override { return false; }
    bool registrarSaidaManual(Data* data) override { return false; }
};

#endif
