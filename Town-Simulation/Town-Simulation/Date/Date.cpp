#include <stdio.h>
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

std::string Date::get_current_date() {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", year, month, day);
    return std::string(buffer);
}

bool Date::update_and_check_month_change() {
    int currentYear, currentMonth, currentDay;
    fetch_system_date(currentYear, currentMonth, currentDay);

    if (currentMonth != month || currentYear != year) {
        year = currentYear;
        month = currentMonth;
        day = currentDay;
        return true;
    }
    return false;
}
