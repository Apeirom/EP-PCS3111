#include "Usuario.h"
#include "Entrada.h"
#include "Saida.h"
Usuario::Usuario(int id, string nome) : id(id), nome(nome){}

Usuario::~Usuario(){}

string Usuario::getNome()
{
    return this->nome;
}

int Usuario::getId()
{
    return this->id;
}
