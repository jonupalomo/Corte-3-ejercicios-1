#include "clock.h"
#include <iomanip>
#include <sstream>

namespace date_independent {

namespace {
    constexpr int MINUTES_IN_HOUR = 60; // minutos por hora
    constexpr int MINUTES_IN_DAY = 24 * MINUTES_IN_HOUR; // minutos por día

    int normalize_minutes(int total_minutes) { // deja el valor en el rango válido
        int rem = total_minutes % MINUTES_IN_DAY;
        if (rem < 0) {
            rem += MINUTES_IN_DAY;
        }
        return rem;
    }
}

clock::clock(int total_minutes)
    : total_minutes_(normalize_minutes(total_minutes)) {}

clock clock::at(int hours, int minutes) {
    return clock(hours * MINUTES_IN_HOUR + minutes); // convierte HH:MM a minutos totales
}

clock clock::plus(int minutes) const {
    return clock(total_minutes_ + minutes); // suma y normaliza
}

clock clock::minus(int minutes) const {
    return clock(total_minutes_ - minutes); // resta y normaliza
}

clock::operator std::string() const {
    int hours = total_minutes_ / MINUTES_IN_HOUR; // hora actual
    int minutes = total_minutes_ % MINUTES_IN_HOUR; // minuto actual

    std::ostringstream oss;
    oss << std::setfill('0')
        << std::setw(2) << hours << ":"
        << std::setw(2) << minutes;
    return oss.str();
}

bool clock::operator==(const clock& other) const {
    return total_minutes_ == other.total_minutes_; // compara el total en minutos
}

bool clock::operator!=(const clock& other) const {
    return !(*this == other); // inverso de igualdad
}

} // namespace date_independent