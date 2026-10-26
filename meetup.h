#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

class scheduler {
public:
    scheduler(boost::gregorian::greg_month month, boost::gregorian::greg_year year); // crea el calendario del mes/año

    boost::gregorian::date monteenth() const; // lunes entre 13 y 19
    boost::gregorian::date tuesteenth() const; // martes entre 13 y 19
    boost::gregorian::date wednesteenth() const; // miércoles entre 13 y 19
    boost::gregorian::date thursteenth() const; // jueves entre 13 y 19
    boost::gregorian::date friteenth() const; // viernes entre 13 y 19
    boost::gregorian::date saturteenth() const; // sábado entre 13 y 19
    boost::gregorian::date sunteenth() const; // domingo entre 13 y 19

    boost::gregorian::date first_monday() const; // primer lunes
    boost::gregorian::date first_tuesday() const; // primer martes
    boost::gregorian::date first_wednesday() const; // primera miércoles
    boost::gregorian::date first_thursday() const; // primer jueves
    boost::gregorian::date first_friday() const; // primer viernes
    boost::gregorian::date first_saturday() const; // primer sábado
    boost::gregorian::date first_sunday() const; // primer domingo

    boost::gregorian::date second_monday() const; // segundo lunes
    boost::gregorian::date second_tuesday() const; // segundo martes
    boost::gregorian::date second_wednesday() const; // segunda miércoles
    boost::gregorian::date second_thursday() const; // segundo jueves
    boost::gregorian::date second_friday() const; // segundo viernes
    boost::gregorian::date second_saturday() const; // segundo sábado
    boost::gregorian::date second_sunday() const; // segundo domingo

    boost::gregorian::date third_monday() const; // tercer lunes
    boost::gregorian::date third_tuesday() const; // tercer martes
    boost::gregorian::date third_wednesday() const; // tercera miércoles
    boost::gregorian::date third_thursday() const; // tercer jueves
    boost::gregorian::date third_friday() const; // tercer viernes
    boost::gregorian::date third_saturday() const; // tercer sábado
    boost::gregorian::date third_sunday() const; // tercer domingo

    boost::gregorian::date fourth_monday() const; // cuarto lunes
    boost::gregorian::date fourth_tuesday() const; // cuarto martes
    boost::gregorian::date fourth_wednesday() const; // cuarta miércoles
    boost::gregorian::date fourth_thursday() const; // cuarto jueves
    boost::gregorian::date fourth_friday() const; // cuarto viernes
    boost::gregorian::date fourth_saturday() const; // cuarto sábado
    boost::gregorian::date fourth_sunday() const; // cuarto domingo

    boost::gregorian::date last_monday() const; // último lunes
    boost::gregorian::date last_tuesday() const; // último martes
    boost::gregorian::date last_wednesday() const; // última miércoles
    boost::gregorian::date last_thursday() const; // último jueves
    boost::gregorian::date last_friday() const; // último viernes
    boost::gregorian::date last_saturday() const; // último sábado
    boost::gregorian::date last_sunday() const; // último domingo

private:
    boost::gregorian::date find_nth_weekday(boost::date_time::weekdays target_day, int nth) const; // busca el n-ésimo día
    boost::gregorian::date find_last_weekday(boost::date_time::weekdays target_day) const; // busca el último día
    boost::gregorian::date find_teenth_weekday(boost::date_time::weekdays target_day) const; // busca el día entre 13 y 19

    boost::gregorian::greg_month month_; // mes objetivo
    boost::gregorian::greg_year year_; // año objetivo
};

} // namespace meetup