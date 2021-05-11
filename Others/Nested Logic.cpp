#include <iostream>

using namespace std;

class Date
{
public:
    int date, month, year;
    int finalDay, finalMonth, finalYear;

    Date(int date, int month, int year)
    {
        this->date = date;
        this->month = month;
        this->year = year;
    }
    int compare(Date Due)
    {
        if (year < Due.year)
            return 0;
        int diff = calculateDifferent(Due);
        cout << diff << endl;
        if (diff < 0)
            return 0;
        else
        {
            if (year > Due.year)
                return 10000;
            if (diff < 31)
                return (15 * diff);
            else if (diff > 31 && diff < 366)
                return (500 * finalMonth);
            else if (diff > 365)
                return 10000;
        }
        return 0;
    }

    int calculateDifferent(Date Due)
    {
        int Months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (date < Due.date)
        {
            finalDay = (date + Months[month - 1]) - Due.date;
            month--;
        }
        else
        {

            finalDay = date - Due.date;
        }

        if (month < Due.month)
        {

            finalMonth = (month + 12) - Due.month;
            Due.year++;
        }
        else
        {
            finalMonth = month - Due.month;
        }
        finalYear = year - Due.year;

        return finalDay + (finalMonth * 30) + (finalYear * 365);
    }
};

int main()
{
    int date, month, year;

    cin >> date >> month >> year;
    Date Returned(date, month, year);

    cin >> date >> month >> year;
    Date Due(date, month, year);

    cout << Returned.compare(Due);

    return 0;
}