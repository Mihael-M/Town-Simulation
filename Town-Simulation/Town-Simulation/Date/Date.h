#ifndef Date_h
#define Date_h

#include <string>

class Date {
public:
    Date();

    std::string get_current_date();

    bool update_and_check_month_change();

private:
    int year;
    int month;
    int day;

    void fetch_system_date(int& y, int& m, int& d);
};

#endif /* Date_h */
