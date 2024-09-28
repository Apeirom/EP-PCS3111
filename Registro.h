#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include "Data.h"

using namespace std;

class Registro{
private:
  Data* data;
  bool entrada;
  bool manual;

public:
    Registro(Data* d, bool entrada, bool manual);

    virtual ~Registro();
    Data* getData();
    bool isEntrada();
    bool isManual();
};
#endif