#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H
#include "Usuario.h"

class GerenciadorDeUsuario{
private:
    int maximo;
    int quantidade;
    Usuario** usuarios;

public:
GerenciadorDeUsuario(int maximo); 
virtual ~GerenciadorDeUsuario(); 
bool adicionar(Usuario* u); 
Usuario* getUsuario(int id); 
Usuario** getUsuarios(); 
int getQuantidade(); 
};
#endif