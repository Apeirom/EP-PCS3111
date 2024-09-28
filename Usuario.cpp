#include "Usuario.h"

Usuario::Usuario(int id, string nome, int maximo) : id(id), nome(nome), maximo(maximo) {
    this->registros = new Registro*[maximo];
}
Usuario::~Usuario(){
    for (int i = 0; i < this->quantidade; i++)
    {
        delete this->registros[i];
    }
    delete[] registros;
}
string Usuario::getNome(){
    return this->nome;
}
int Usuario::getId(){
    return this->id;
}

bool Usuario::entrar(Data *d){
    if (quantidade == 0)
    {
        return true;
    }

    if(this->quantidade >= this->maximo)
    {
        return false;
    }
    
    if (this->registros[this->quantidade-1]->isEntrada())
    {
        return false;
    }
    
    if (this->registros[this->quantidade-1]->getData()->diferenca(d) > 0)
    {
        return false;
    }
    return true;
}

bool Usuario::sair(Data *d){
    if (quantidade == 0)
    {
        return true;
    }

    if(this->quantidade >= this->maximo)
    {
        return false;
    }

    if (!this->registros[this->quantidade-1]->isEntrada())
    {
        return false;
    }
    
    if (this->registros[this->quantidade-1]->getData()->diferenca(d) > 0)
    {
        return false;
    }
    return true;
}

bool Usuario::registrarEntradaManual(Data *d){
    if(this->entrar(d)){
        this->registros[quantidade] = new Registro(d,true,true);
        this->quantidade += 1;
    }
    return this->entrar(d);
}

bool Usuario::registrarSaidaManual(Data* d){
    if(this->sair(d)){
        this->registros[quantidade] = new Registro(d,false,true);
        this->quantidade += 1;
    }
    return this->sair(d);
}

int Usuario::getHorasTrabalhadas(int mes, int ano){
    int somaHorasTrabalhadas = 0;
    for(int i = 0; i < this->quantidade; i++)
    {
        if (this->registros[i]->isEntrada() && i+1 < this->quantidade)
        {
            Data* dataEntrada = this->registros[i]->getData();
            Data* dataSaida = this->registros[i+1]->getData();
            somaHorasTrabalhadas += dataSaida->diferenca(dataEntrada);
        }
        
    }
    return somaHorasTrabalhadas;
}

Registro** Usuario::getRegistros(){
    return this->registros;
}

int Usuario::getQuantidade(){
    return this->quantidade;
} 