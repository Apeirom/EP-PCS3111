#include "Registro.h"
#include <stdexcept>
Registro::Registro(Data* d, bool manual){
    if (d == nullptr){
        throw invalid_argument("Data nula");
    }
    this->data = d;
    this->manual = manual;
}

Registro::Registro(Data* d){
    if (d == nullptr){
        throw invalid_argument("Data nula");
    }
    this->data = d;
    this->manual = false;
}

Registro::~Registro(){
    delete this->data;
}

Data* Registro::getData(){
    return this->data;
}

bool Registro::isManual(){
    return this->manual;
}