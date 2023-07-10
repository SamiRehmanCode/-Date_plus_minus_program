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
    Date operator--();
    Date operator-(int numberOfDays);
    bool operator>(Date d);
};

const int Date::daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void Date::display()
{
    std::cout << "Date: " << day << "-" << month << "-" << year << std::endl;
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

bool Date::operator>(Date d)
{
    if (year > d.year) // if year is greater, date is greater
    {
        return true;
    }
    else if (year == d.year) // if years are equal, check month
    {
        if (month > d.month) // if month is greater, date is greater
        {
            return true;
        }
        else if (month == d.month) // if months are equal, check day
        {
            if (day > d.day)
                return true;
            else // otherwise return false
                return false;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
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

    Date date(1, 1, 2024);
    std::cout << "Original date: ";
    date.display(); 
    std::cout << "After prefix decrement (--date): ";
    (--date).display();
    std::cout << "After subtracting 20 days (date - 20): ";
    (date - 20).display();

    Date date1(2023, 7, 10);
    Date date2(2023, 7, 9);

    if (date1 > date2)
    {
        std::cout << "Date 1 is greater than Date 2" << std::endl;
    }
    else
    {
        std::cout << "Date 2 is greater than or equal to Date 1" << std::endl;
    }

    return 0;
}
