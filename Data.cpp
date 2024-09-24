#include "Data.h"
#include <ctime>

Data::Data(int hora, int minuto, int segundo, int dia, int mes, int ano) :
hora(hora), minuto(minuto), segundo(segundo), dia(dia), mes(mes), ano(ano) {}

Data::~Data(){}

int Data::getHora(){
  return this->hora;
}

int Data::getMinuto(){
  return this->minuto;
}

int Data::getSegundo(){
  return this->segundo;
}

int Data::getDia(){
  return this->dia;
}

int Data::getMes(){
  return this->mes;
}

int Data::getAno(){
  return this->ano;
}

int Data::diferenca(Data* d){
    // Criação das estruturas tm para a data atual e a data fornecida
    tm dataAtual = {};
    dataAtual.tm_hour = this->hora;
    dataAtual.tm_min = this->minuto;
    dataAtual.tm_sec = this->segundo;
    dataAtual.tm_mday = this->dia;
    dataAtual.tm_mon = this->mes - 1;
    dataAtual.tm_year = this->ano - 1900;

    tm dataComparada = {};
    dataComparada.tm_hour = d->getHora();
    dataComparada.tm_min = d->getMinuto();
    dataComparada.tm_sec = d->getSegundo();
    dataComparada.tm_mday = d->getDia();
    dataComparada.tm_mon = d->getMes() - 1;
    dataComparada.tm_year = d->getAno() - 1900;

    // Conversão para time_t para calcular a diferença
    time_t tAtual = mktime(&dataAtual);
    time_t tComparada = mktime(&dataComparada);

    // Calcula a diferença em segundos
    return (int)difftime(tAtual, tComparada);
}