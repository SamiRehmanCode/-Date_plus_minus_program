#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;
    static const int daysInMonth[];

    int daysOfMonth(Date d);
    bool leapYear(int y);

public:
    Date(int d = 1, int m = 1, int y = 1900);
    void display();

    Date operator--();
    Date operator-(int numberOfDays);
};

const int Date::daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::display()
{
    std::cout << "Date: " << day << "-" << month << "-" << year << std::endl;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

int Date::daysOfMonth(Date d)
{
    if (d.month == 2 && leapYear(d.year))
        return 29;
    else
        return daysInMonth[d.month];
}

bool Date::leapYear(int y)
{
    if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
        return true;
    else
        return false;
}

Date Date::operator--()
{
    if (day == 1 && month == 1) {
        day = 31;
        month = 12;
        --year;
    } else if (day == 1) {
        --month;
        day = daysOfMonth(*this);
    } else {
        --day;
    }
    return *this;
}

Date Date::operator-(int numberOfDays)
{
    for (int i = 1; i <= numberOfDays; i++) {
        --(*this);
    }
    return *this;
}

int main()
{
    Date date(1, 1, 2024);

    std::cout << "Original date: ";
    date.display(); 
    

    std::cout << "After prefix decrement (--date): ";
    (--date).display();

    std::cout << "After subtracting 20 days (date - 20): ";
    (date - 20).display();

    return 0;
}


