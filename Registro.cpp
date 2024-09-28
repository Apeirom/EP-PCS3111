#include "Registro.h"

Registro::Registro(Data* d, bool entrada, bool manual) : data(d), entrada(entrada), manual(manual) {}

Registro::~Registro(){
    delete this->data;
}

Data* Registro::getData(){
    return this->data;
}
bool Registro::isEntrada(){
    return this->entrada;
}
bool Registro::isManual(){
    return this->manual;
}