#include "meetup.h"

namespace meetup {

using namespace boost::gregorian;

scheduler::scheduler(greg_month month, greg_year year)
    : month_(month), year_(year) {}

date scheduler::find_nth_weekday(boost::date_time::weekdays target_day, int nth) const {
    date d(year_, month_, 1); // primer día del mes
    int count = 0; // días coincidentes
    while (d.month() == month_) {
        if (d.day_of_week() == target_day) {
            count++;
            if (count == nth) {
                return d;
            }
        }
        d += days(1);
    }
    return d;
}

date scheduler::find_last_weekday(boost::date_time::weekdays target_day) const {
    date d = date(year_, month_, 1).end_of_month(); // último día del mes
    while (d.day_of_week() != target_day) {
        d -= days(1);
    }
    return d;
}

date scheduler::find_teenth_weekday(boost::date_time::weekdays target_day) const {
    for (int day = 13; day <= 19; ++day) { // busca entre 13 y 19
        date d(year_, month_, day);
        if (d.day_of_week() == target_day) {
            return d;
        }
    }
    return date(year_, month_, 13);
}

// Teenth
date scheduler::monteenth() const   { return find_teenth_weekday(boost::date_time::Monday); }
date scheduler::tuesteenth() const  { return find_teenth_weekday(boost::date_time::Tuesday); }
date scheduler::wednesteenth() const { return find_teenth_weekday(boost::date_time::Wednesday); }
date scheduler::thursteenth() const { return find_teenth_weekday(boost::date_time::Thursday); }
date scheduler::friteenth() const   { return find_teenth_weekday(boost::date_time::Friday); }
date scheduler::saturteenth() const { return find_teenth_weekday(boost::date_time::Saturday); }
date scheduler::sunteenth() const   { return find_teenth_weekday(boost::date_time::Sunday); }

// First
date scheduler::first_monday() const    { return find_nth_weekday(boost::date_time::Monday, 1); }
date scheduler::first_tuesday() const   { return find_nth_weekday(boost::date_time::Tuesday, 1); }
date scheduler::first_wednesday() const { return find_nth_weekday(boost::date_time::Wednesday, 1); }
date scheduler::first_thursday() const  { return find_nth_weekday(boost::date_time::Thursday, 1); }
date scheduler::first_friday() const    { return find_nth_weekday(boost::date_time::Friday, 1); }
date scheduler::first_saturday() const  { return find_nth_weekday(boost::date_time::Saturday, 1); }
date scheduler::first_sunday() const    { return find_nth_weekday(boost::date_time::Sunday, 1); }

// Second
date scheduler::second_monday() const    { return find_nth_weekday(boost::date_time::Monday, 2); }
date scheduler::second_tuesday() const   { return find_nth_weekday(boost::date_time::Tuesday, 2); }
date scheduler::second_wednesday() const { return find_nth_weekday(boost::date_time::Wednesday, 2); }
date scheduler::second_thursday() const  { return find_nth_weekday(boost::date_time::Thursday, 2); }
date scheduler::second_friday() const    { return find_nth_weekday(boost::date_time::Friday, 2); }
date scheduler::second_saturday() const  { return find_nth_weekday(boost::date_time::Saturday, 2); }
date scheduler::second_sunday() const    { return find_nth_weekday(boost::date_time::Sunday, 2); }

// Third
date scheduler::third_monday() const    { return find_nth_weekday(boost::date_time::Monday, 3); }
date scheduler::third_tuesday() const   { return find_nth_weekday(boost::date_time::Tuesday, 3); }
date scheduler::third_wednesday() const { return find_nth_weekday(boost::date_time::Wednesday, 3); }
date scheduler::third_thursday() const  { return find_nth_weekday(boost::date_time::Thursday, 3); }
date scheduler::third_friday() const    { return find_nth_weekday(boost::date_time::Friday, 3); }
date scheduler::third_saturday() const  { return find_nth_weekday(boost::date_time::Saturday, 3); }
date scheduler::third_sunday() const    { return find_nth_weekday(boost::date_time::Sunday, 3); }

// Fourth
date scheduler::fourth_monday() const    { return find_nth_weekday(boost::date_time::Monday, 4); }
date scheduler::fourth_tuesday() const   { return find_nth_weekday(boost::date_time::Tuesday, 4); }
date scheduler::fourth_wednesday() const { return find_nth_weekday(boost::date_time::Wednesday, 4); }
date scheduler::fourth_thursday() const  { return find_nth_weekday(boost::date_time::Thursday, 4); }
date scheduler::fourth_friday() const    { return find_nth_weekday(boost::date_time::Friday, 4); }
date scheduler::fourth_saturday() const  { return find_nth_weekday(boost::date_time::Saturday, 4); }
date scheduler::fourth_sunday() const    { return find_nth_weekday(boost::date_time::Sunday, 4); }

// Last
date scheduler::last_monday() const    { return find_last_weekday(boost::date_time::Monday); }
date scheduler::last_tuesday() const   { return find_last_weekday(boost::date_time::Tuesday); }
date scheduler::last_wednesday() const { return find_last_weekday(boost::date_time::Wednesday); }
date scheduler::last_thursday() const  { return find_last_weekday(boost::date_time::Thursday); }
date scheduler::last_friday() const    { return find_last_weekday(boost::date_time::Friday); }
date scheduler::last_saturday() const  { return find_last_weekday(boost::date_time::Saturday); }
date scheduler::last_sunday() const    { return find_last_weekday(boost::date_time::Sunday); }

} // namespace meetup