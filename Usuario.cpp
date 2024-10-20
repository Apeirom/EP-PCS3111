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

bool Usuario::autorizaRegistro(Data *d, bool entrar){
    if (this->quantidade == 0)
    {
        return true;
    }

    if(this->quantidade >= this->maximo)
    {
        return false;
    }
    
    if (!(this->registros[this->quantidade-1]->isEntrada() ^ entrar))
    {
        return false;
    }
    
    if (this->registros[this->quantidade-1]->getData()->diferenca(d) > 0)
    {
        return false;
    }
    return true;
}

bool Usuario::entrar(Data *d){
    bool podeEntrar = this->autorizaRegistro(d,true);
    if(podeEntrar){
        this->registros[quantidade] = new Registro(d,true,false);
        this->quantidade += 1;
    }
    return podeEntrar;
}

bool Usuario::sair(Data *d){
    bool podeSair = this->autorizaRegistro(d,false);
    if(podeSair){
        this->registros[quantidade] = new Registro(d,false,false);
        this->quantidade += 1;
    }
    return podeSair;
}

bool Usuario::registrarEntradaManual(Data *d){
    bool podeEntrar = this->autorizaRegistro(d,true);
    if(podeEntrar){
        this->registros[quantidade] = new Registro(d,true,true);
        this->quantidade += 1;
    }
    return podeEntrar;
}

bool Usuario::registrarSaidaManual(Data* d){
    bool podeSair = this->autorizaRegistro(d,false);
    if(podeSair){
        this->registros[quantidade] = new Registro(d,false,true);
        this->quantidade += 1;
    }
    return podeSair;
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
    return somaHorasTrabalhadas/3600;
}

Registro** Usuario::getRegistros(){
    return this->registros;
}

int Usuario::getQuantidade(){
    return this->quantidade;;
} 