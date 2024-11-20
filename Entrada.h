#ifndef Entrada_H
#define Entrada_H

#include "registro.h"

class Entrada : public Registro {
public:
    Entrada(Data* d); 
    Entrada(Data* d, bool manual); 
    virtual ~Entrada();
};
#endif
