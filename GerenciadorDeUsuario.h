#ifndef GERENCIADOR_DE_USUARIO_H
#define GERENCIADOR_DE_USUARIO_H

#include <vector>
#include <stdexcept>
#include "Usuario.h"

using namespace std;

class GerenciadorDeUsuario {
private:
    vector<Usuario*>* usuarios;

public:
    GerenciadorDeUsuario(); 
    GerenciadorDeUsuario(vector<Usuario*>* usuarios); 
    virtual ~GerenciadorDeUsuario();

    void adicionar(Usuario* u);
    Usuario* getUsuario(int id);
    vector<Usuario*>* getUsuarios();
};

#endif
