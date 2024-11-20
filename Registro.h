#ifndef REGISTRO_H
#define REGISTRO_H

#include <string>
#include "Data.h"

using namespace std;

class Registro{
private:
  Data* data;
  bool manual;

public:
    Registro(Data* d);
    Registro(Data* d, bool manual);
    virtual ~Registro() = 0;

    Data* getData();
    bool isManual();
};
#endif