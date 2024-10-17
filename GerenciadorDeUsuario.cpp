#include <GerenciadorDeUsuario.h>

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo) 
    : maximo(maximo), quantidade(0), usuarios(new Usuario*[maximo]) {}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    for (int i = 0; i < quantidade; i++) {
        delete usuarios[i];
    }
    delete[] usuarios;
}

bool GerenciadorDeUsuario::adicionar(Usuario* u) {
    if (quantidade >= maximo || getUsuario(u->getId()) != nullptr) {
        return false;
    }
    usuarios[quantidade++] = u;
    return true;
}

Usuario* GerenciadorDeUsuario::getUsuario(int id) {
    for (int i = 0; i < quantidade; i++) {
        if (usuarios[i]->getId() == id) {
            return usuarios[i];
        }
    }
    return nullptr;
}

Usuario** GerenciadorDeUsuario::getUsuarios() {
    return usuarios;
}

int GerenciadorDeUsuario::getQuantidade() {
    return quantidade;
}