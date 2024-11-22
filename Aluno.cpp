#include "Aluno.h"
#include "Data.h"
#include <stdexcept>

using namespace std;

// Inicialização de membros estáticos
int Aluno::horaFim = 23;
int Aluno::minutoFim = 0;

Aluno::Aluno(int id, string nome) : Usuario(id, nome) {}

Aluno::~Aluno() {}

void Aluno::setHorarioFim(int hora, int minuto) {
    if (hora < Aluno::HORARIO_INICIO || hora > 23 || minuto < 0 || minuto >= 60) {
        throw new logic_error("Horario invalido");
    }

    Aluno::horaFim = hora;
    Aluno::minutoFim = minuto;
}

int Aluno::getHoraFim() {
    return Aluno::horaFim;
}

int Aluno::getMinutoFim() {
    return Aluno::minutoFim;
}

// Redefinição de métodos da superclasse
bool Aluno::entrar(Data *d) {
    int horaInicio = Aluno::HORARIO_INICIO;
    int horaFim = Aluno::getHoraFim();
    int minutoFim = Aluno::getMinutoFim();

    if (d->getHora() < horaInicio || (d->getHora() > horaFim || 
        (d->getHora() == horaFim && d->getMinuto() > minutoFim))) {
        return false;
    }

    return true;
}

bool Aluno::sair(Data *d) {
    return true; // Por enquanto, sempre permitir a saída
}

bool Aluno::registrarEntradaManual(Data *d) {
    // Sempre retorna false conforme especificado
    return false;
}

bool Aluno::registrarSaidaManual(Data *d) {
    // Sempre retorna true conforme especificado
    return true;
}
