#include "Catraca.h"
#include <iostream>

using namespace std;

Catraca::Catraca(GerenciadorDeUsuario* g){
    this->g = g;
}

Catraca::~Catraca(){}

bool Catraca::entrar(int id, Data* d){
    if(this->g->getUsuario(id) != nullptr){
        return this->g->getUsuario(id)->entrar(d);
    }
    return false;
}

bool Catraca::sair(int id, Data* d){
    if(this->g->getUsuario(id) != nullptr){
        return this->g->getUsuario(id)->sair(d);
    }
    return false;
}