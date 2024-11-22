#include "Visitante.h"

Visitante::Visitante(int id, string nome, Data* inicio, Data* fim)
    : Usuario(id, nome), inicio(inicio), fim(fim) {
    if (!inicio || !fim || fim->diferenca(inicio) <= 0) {
        throw new logic_error("Datas de inicio e fim invalidas.");
    }
}

Visitante::~Visitante() {
    delete inicio;
    delete fim;
}

Data* Visitante::getDataInicio() {
    return inicio;
}

Data* Visitante::getDataFim() {
    return fim;
}

bool Visitante::entrar(Data* data) {
    if (!data || data->diferenca(inicio) <= 0 || fim->diferenca(data) <= 0) {
        return false; // Data fora do intervalo
    }
    return true;
}

bool Visitante::sair(Data* data) {
    if (!data || data->diferenca(inicio) <= 0 || fim->diferenca(data) <= 0) {
        return false; // Data fora do intervalo
    }
    return true;
}
