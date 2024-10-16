#include "Catraca.h"
#include <iostream>

using namespace std;

Catraca::Catraca(GerenciadorDeUsuario* g){
    this->g = g;
}

bool Catraca::entrar(int id, Data* d){
    if(this->g->getUsuario(id) != nullptr){
        if(this->g->getUsuario(id)->entrar(d)){
            this->g->getUsuario(id)->getRegistros()[this->g->getUsuario(id)->getQuantidade()] = new Registro(d, true, false);
            return true;
        }
    }
    return false;
}

bool Catraca::sair(int id, Data* d){
    if(this->g->getUsuario(id) != nullptr){
        if(this->g->getUsuario(id)->sair(d)){
            this->g->getUsuario(id)->getRegistros()[this->g->getUsuario(id)->getQuantidade()] = new Registro(d, false, false);
            return true;
        }
    }
    return false;
}