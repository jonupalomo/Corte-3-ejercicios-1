#pragma once

#include <string>

namespace date_independent {

class clock {
public:
    static clock at(int hours, int minutes = 0); // crea el reloj desde horas y minutos

    clock plus(int minutes) const; // suma minutos
    clock minus(int minutes) const; // resta minutos

    operator std::string() const; // convierte a "HH:MM"

    bool operator==(const clock& other) const; // compara igualdad
    bool operator!=(const clock& other) const; // compara desigualdad

private:
    explicit clock(int total_minutes); // crea desde minutos totales
    int total_minutes_; // minutos normalizados en [0, 1439]
};

} // namespace date_independent