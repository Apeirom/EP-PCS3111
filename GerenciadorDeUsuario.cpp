#include "GerenciadorDeUsuario.h"

GerenciadorDeUsuario::GerenciadorDeUsuario() : usuarios(new vector<Usuario*>()) {}

GerenciadorDeUsuario::GerenciadorDeUsuario(vector<Usuario*>* usuarios) : usuarios(usuarios) {}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    for (int i = 0; i < this->usuarios->size(); i++)
    {
        delete this->usuarios->at(i);
    }
    delete usuarios;
}

void GerenciadorDeUsuario::adicionar(Usuario* u) {
    for (int i = 0; i < this->usuarios->size(); i++) {
        if (this->usuarios->at(i)->getId() == u->getId()) {
            throw invalid_argument("Usuario com este ID ja foi adicionado.");
        }
    }
    usuarios->push_back(u);
}

Usuario* GerenciadorDeUsuario::getUsuario(int id) {
    for (int i = 0; i < this->usuarios->size(); i++) {
        if (this->usuarios->at(i)->getId() == id) {
            return this->usuarios->at(i);
        }
    }
    return nullptr;
}

vector<Usuario*>* GerenciadorDeUsuario::getUsuarios() {
    return usuarios;
}
