# -Date_plus_minus_program
# Date Class

The `Date` class represents a date with day, month, and year components. It provides functionality for setting a date, displaying it, and performing operations such as incrementing the date and adding days to it.

## Class Members

### Private Members

- `day`: An integer representing the day of the date.
- `month`: An integer representing the month of the date.
- `year`: An integer representing the year of the date.
- `daysInMonth[]`: A static array storing the number of days in each month.

### Public Members

- `Date(int d = 1, int m = 1, int y = 1900)`: Constructor to initialize a `Date` object with the specified day, month, and year. If no arguments are provided, the default values are set to January 1, 1900.
- `void setDate(int d, int m, int y)`: Sets the date components to the specified values.
- `void display()`: Displays the date in the format "day-month-year".
- `Date operator++()`: Overloaded pre-increment operator to increment the date by one day.
- `Date operator+(int numberOfDays)`: Overloaded addition operator to add the specified number of days to the date.

### Private Helper Methods

- `daysOfMonth(Date d)`: Returns the number of days in the month of the given date.
- `leapYear(int y)`: Checks if the given year is a leap year.

## Example Usage

```cpp
#include <iostream>

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
