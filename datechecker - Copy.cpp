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
    void setDate(int d, int m, int y);
    void display();

    Date operator++();
    Date operator+(int numberOfDays);
};

const int Date::daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::display()
{
    std::cout << "Date: " << day << "-" << month << "-" << year;
}

Date::Date(int d, int m, int y)
{
    setDate(d, m, y);
}

void Date::setDate(int d, int m, int y)
{
    year = y;

    if (m < 1 || m > 12)
        month = 1;
    else
        month = m;

    if (month == 2 && leapYear(y)) {
        if (d >= 1 && d <= 29)
            day = d;
        else
            day = 1;
    } else {
        if (d >= 1 && d <= daysInMonth[month])
            day = d;
        else
            day = 1;
    }
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

Date Date::operator++()
{
    if (day == daysOfMonth(*this) && month == 12) {
        day = 1;
        month = 1;
        ++year;
    } else if (day == daysOfMonth(*this)) {
        day = 1;
        ++month;
    } else {
        ++day;
    }
    return *this;
}

Date Date::operator+(int numberOfDays)
{
    for (int i = 1; i <= numberOfDays; i++) {
        ++(*this);
    }
    return *this;
}

int main()
{
    Date d1(26, 12, 2002), d2(28, 2, 2000), d3;
    d1.display();
    ++d1;
    std::cout << "\nAfter adding 1 day, the date is ";
    d1.display();
    std::cout << std::endl;
    d2.display();
    d2 = d2 + 5;
    std::cout << "\nAfter adding 5 days to the above date";
    d2.display();

    return 0;
}
