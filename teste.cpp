#include "Data.h"
#include "Registro.h"
#include "Usuario.h"

#include <iostream>
#include <string>

using namespace std;

void testeData(){
    Data* data1 = new Data(4,20,0,27,9,2024);
    Data* data2 = new Data(6,20,0,27,9,2024);

    cout << data2->diferenca(data1);
}

void testeRegistro(){}

void testeUsuário(){}