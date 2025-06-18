#ifndef Date_h
#define Date_h

#include <string>

class Date {
public:
    Date();

    std::string get_current_date() const;
    
    int get_day() const;
    
    int get_month() const;
    
    void increment_day();

    bool check_month_change();
    
    void decrement_day();

private:
    int year;
    int month;
    int day;

    void fetch_system_date(int& y, int& m, int& d);
};

#endif /* Date_h */
