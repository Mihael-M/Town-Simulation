#include "Date.h"
#include <ctime>

Date::Date() {
    fetch_system_date(year, month, day);
}

void Date::fetch_system_date(int& y, int& m, int& d) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    y = now->tm_year + 1900;
    m = now->tm_mon + 1;
    d = now->tm_mday;
}

std::string Date::get_current_date() const {
    std::string yStr = std::to_string(year);

    std::string mStr = (month < 10 ? "0" : "") + std::to_string(month);
    std::string dStr = (day < 10 ? "0" : "") + std::to_string(day);

    return yStr + "-" + mStr + "-" + dStr;
}

int Date::get_day() const {
    return day;
}

int Date::get_month() const {
    return month;
}



bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int days_in_month(int y, int m) {
    switch (m) {
        case 2: return isLeapYear(y) ? 29 : 28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}

void Date::increment_day() {
    int dim = days_in_month(year, month);
    day++;
    if (day > dim) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}

void Date::decrement_day() {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = days_in_month(year, month);
    }
}

bool Date::check_month_change() {
       int dim = days_in_month(year, month);

       if (day == dim) {
           return true;
       }
       return false;
}
