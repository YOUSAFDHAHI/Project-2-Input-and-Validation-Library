#pragma once
#include <iostream>
#include "clsString.h"
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class clsDate
{

private:
    short _year;
    short _month;
    short _day;

public:
    clsDate()
    {
        getSystemDate();
    }

    clsDate(string fullDate)
    {
        vector<string> vDate = clsString::Split(fullDate, "/");
        _day = stoi(vDate[0]);
        _month = stoi(vDate[1]);
        _year = stoi(vDate[2]);
    }

    clsDate(short day, short month, short year)
    {
        _day = day;
        _month = month;
        _year = year;
    }

    clsDate(short numberOfDays, short year)
    {
        _year = year;
        getDateOfDayFromTheBeginningOfTheYear(numberOfDays);
    }

    void setDay(short day)
    {
        _day = day;
    }

    short getDay()
    {
        return _day;
    }

    void setMonth(short month)
    {
        _month = month;
    }

    short getMonth()
    {
        return _month;
    }

    void setYear(short year)
    {
        _year = year;
    }

    short getYear()
    {
        return _year;
    }

    //   void getSystemDate()
    //{
    //	time_t t = time(0);

    //	tm* local = localtime(&t);

    //	_year = local->tm_year + 1900;
    //	_month = local->tm_mon + 1;
    //	_day = local->tm_mday;
    //}

    static clsDate getSystemDate(clsDate date)
    {
        time_t t = time(0);

        tm *local = localtime(&t);

        date._year = local->tm_year + 1900;
        date._month = local->tm_mon + 1;
        date._day = local->tm_mday;

        return date;
    }

    void getSystemDate()
    {
        clsDate date = getSystemDate(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static bool isLeapYear(short year)
    {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

    bool isLeapYear()
    {
        return isLeapYear(_year);
    }

    static short numberOfDaysInYear(short year)
    {
        return (isLeapYear(year)) ? 366 : 365;
    }

    short numberOfDaysInYear()
    {
        return numberOfDaysInYear(_year);
    }

    static short numberOfHoursInYear(short year)
    {
        return numberOfDaysInYear(year) * 24;
    }

    short numberOfHoursInYear()
    {
        return numberOfHoursInYear(_year);
    }

    static int numberOfMinutesInYear(short year)
    {
        return numberOfHoursInYear(year) * 60;
    }

    int numberOfMinutesInYear()
    {
        return numberOfMinutesInYear(_year);
    }

    static int numberOfSecondsInYear(short year)
    {
        return numberOfMinutesInYear(year) * 60;
    }

    int numberOfSecondsInYear()
    {
        return numberOfSecondsInYear(_year);
    }

    static short numberOfDaysInMonth(short year, short month)
    {
        if (month < 1 || month > 12)
            return 0;

        bool is30Days = (month == 4 || month == 6 || month == 9 || month == 11);

        return (month == 2) ? (isLeapYear(year)) ? 29 : 28 : (is30Days) ? 30
                                                                        : 31;
    }

    short numberOfDaysInMonth()
    {
        return numberOfDaysInMonth(_year, _month);
    }

    static short numberOfHoursInMonth(short year, short month)
    {
        return numberOfDaysInMonth(year, month) * 24;
    }

    short numberOfHoursInMonth()
    {
        return numberOfHoursInMonth(_year, _month);
    }

    static int numberOfMinutesInMonth(short year, short month)
    {
        return numberOfHoursInMonth(year, month) * 60;
    }

    int numberOfMinutesInMonth()
    {
        return numberOfMinutesInMonth(_year, _month);
    }

    static int numberOfSecondsInMonth(short year, short month)
    {
        return numberOfMinutesInMonth(year, month) * 60;
    }

    int numberOfSecondsInMonth()
    {
        return numberOfSecondsInMonth(_year, _month);
    }

    short numberOfHoursInDay()
    {
        return 24;
    }

    short numberOfMinutesInDay()
    {
        return numberOfHoursInDay() * 60;
    }

    int numberOfSecondsInDay()
    {
        return numberOfMinutesInDay() * 60;
    }

    static bool IsValidDate(clsDate date)
    {
        return (date._month >= 1 && date._month <= 12) && (date._day <= date.numberOfDaysInMonth(date._year, date._month));
    }

    bool IsValid()
    {
        return IsValidDate(*this);
    }

    static bool isLastDayInMonth(clsDate date)
    {
        return date._day == numberOfDaysInMonth(date._year, date._month);
    }

    bool isLastDayInMonth()
    {
        return isLastDayInMonth(*this);
    }

    static bool isLastMonthInYear(short month)
    {
        return month == 12;
    }

    bool isLastMonthInYear()
    {
        return isLastMonthInYear(_month);
    }

    static bool IsDate1BeforeDate2(clsDate date1, clsDate date2)
    {
        return (date1._year < date2._year) ? true : ((date1._year == date2._year) ? (date1._month < date2._month) ? true : ((date1._month == date2._month) ? date1._day < date2._day : false) : false);
    }

    bool IsDateBeforeDate2(clsDate date)
    {
        return IsDate1BeforeDate2(*this, date);
    }

    static bool IsDate1EqualDate2(clsDate date1, clsDate date2)
    {
        return ((date1._year == date2._year) ? ((date1._month == date2._month) ? (date1._day == date2._day) : false) : false);
    }

    bool IsDateEqualDate2(clsDate date)
    {
        return IsDate1EqualDate2(*this, date);
    }

    static bool IsDate1AfterDate2(clsDate date1, clsDate date2)
    {
        return !(IsDate1BeforeDate2(date1, date2) || IsDate1EqualDate2(date1, date2));
    }

    bool IsDate1AfterDate2(clsDate date)
    {
        return IsDate1AfterDate2(*this, date);
    }

    static short dayFromBeginningOfTheYear(clsDate date)
    {
        short daysCounter = 0;

        for (short i = 1; i < date._month; i++)
        {
            daysCounter += numberOfDaysInMonth(date._year, i);
        }

        return daysCounter + date._day;
    }

    short dayFromBeginningOfTheYear()
    {
        return dayFromBeginningOfTheYear(*this);
    }

    static clsDate getDateOfDayFromTheBeginningOfTheYear(short dayYearOrder, short year)
    {
        short remainingDays = dayYearOrder;
        clsDate date;
        date._year = year;
        date._month = 1;

        while (true)
        {
            short monthDays = numberOfDaysInMonth(date._year, date._month);
            if (remainingDays >= monthDays)
            {
                remainingDays -= monthDays;

                date._month++;
            }
            else
            {
                date._day = remainingDays;
                break;
            }
        }

        return date;
    }

    void getDateOfDayFromTheBeginningOfTheYear(short numberOfDays)
    {
        clsDate date = getDateOfDayFromTheBeginningOfTheYear(numberOfDays, _year);

        this->_year = date._year;
        this->_month = date._month;
        this->_day = date._day;
    }

    static string getMonthShortName(short month)
    {
        string monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

        return monthNames[month - 1];
    }

    string getMonthShortName()
    {
        return getMonthShortName(_month);
    }

    static string getDayShortName(short day)
    {
        string dayNames[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

        return dayNames[day];
    }

    string getDayShortName()
    {
        return getDayShortName(dayOfWeekOrder());
    }

    static void printMonthCalender(short year, short month)
    {

        cout << "\n __________________" << getMonthShortName(month) << "__________________\n";

        cout << "   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        short i;

        short currentDay = dayOfWeekOrder(year, month, 1);

        for (i = 0; i < currentDay; i++)
            cout << "     ";

        short monthDays = numberOfDaysInMonth(year, month);
        for (short j = 1; j <= monthDays; j++)
        {
            cout << setw(5) << j;

            if (++i == 7)
            {
                i = 0;
                cout << "\n";
            }
        }

        cout << "\n _______________________________________\n";
    }

    void printMonthCalender()
    {
        printMonthCalender(_year, _month);
    }

    static void printYearCalender(short year)
    {
        for (short i = 1; i <= 12; i++)
        {
            printMonthCalender(year, i);
        }
    }

    void printYearCalender()
    {
        printYearCalender(_year);
    }

    static short dayOfWeekOrder(short year, short month, short day)
    {
        short d, m, y, a;

        a = (14 - month) / 12;
        y = year - a;

        m = month + (12 * a) - 2;

        d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((m * 31) / 12)) % 7;

        return d;
    }

    static short dayOfWeekOrder(clsDate date)
    {
        return dayOfWeekOrder(date._year, date._month, date._day);
    }

    static clsDate addOneDay(clsDate date)
    {
        if (isLastDayInMonth(date))
        {
            if (isLastMonthInYear(date._month))
            {
                date._year++;
                date._month = 1;
                date._day = 1;
            }

            else
            {
                date._month++;
                date._day = 1;
            }
        }

        else
        {
            date._day++;
        }

        return date;
    }

    void addOneDay()
    {
        clsDate date = addOneDay(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate addDays(clsDate date, int days)
    {

        for (int i = 1; i <= days; i++)
        {
            date = addOneDay(date);
        }

        return date;
    }

    void addDays(int days)
    {
        clsDate date = addDays(*this, days);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByOneWeek(clsDate date)
    {
        for (short i = 1; i <= 7; i++)
        {
            date = addOneDay(date);
        }

        return date;
    }

    void increaseDateByOneWeek()
    {
        clsDate date = increaseDateByOneWeek(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByWeeks(clsDate date, short weeks)
    {
        for (short i = 1; i <= weeks; i++)
        {
            date = increaseDateByOneWeek(date);
        }

        return date;
    }

    void increaseDateByWeeks(short weeks)
    {
        clsDate date = increaseDateByWeeks(*this, weeks);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByOneMonth(clsDate date)
    {
        short monthDays = numberOfDaysInMonth(date._year, date._month + 1);

        if (date.isLastMonthInYear())
        {
            date._year++;
            date._month = 1;
        }

        else if (date._day > monthDays)
        {
            date._month++;
            date._day = date.numberOfDaysInMonth();
        }

        else
        {
            date._month++;
        }

        return date;
    }

    void increaseDateByOneMonth()
    {
        clsDate date = increaseDateByOneMonth(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByMonths(clsDate date, short months)
    {
        for (short i = 1; i <= months; i++)
        {
            date.increaseDateByOneMonth();
        }

        return date;
    }

    void increaseDateByMonths(short months)
    {
        clsDate date = increaseDateByMonths(*this, months);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByOneYear(clsDate date)
    {
        date._year++;

        return date;
    }

    void increaseDateByOneYear()
    {
        clsDate date = increaseDateByOneYear(*this);

        this->_year = date._year;
    }

    static clsDate increaseDateByYears(clsDate date, short years)
    {
        for (short i = 1; i <= years; i++)
        {
            date.increaseDateByOneYear();
        }

        return date;
    }

    void increaseDateByYears(short years)
    {
        clsDate date = increaseDateByYears(*this, years);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByOneDecade(clsDate date)
    {
        for (short i = 1; i <= 10; i++)
        {
            date.increaseDateByOneYear();
        }

        return date;
    }

    void increaseDateByOneDecade()
    {
        clsDate date = increaseDateByOneDecade(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByDecades(clsDate date, short decades)
    {
        for (short i = 1; i <= decades; i++)
        {
            date.increaseDateByOneDecade();
        }

        return date;
    }

    void increaseDateByDecades(short decades)
    {
        clsDate date = increaseDateByDecades(*this, decades);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByOneCentury(clsDate date)
    {
        date._year += 100;

        return date;
    }

    void increaseDateByOneCentury()
    {
        clsDate date = increaseDateByOneCentury(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate increaseDateByOneMillennium(clsDate date)
    {
        date._year += 1000;

        return date;
    }

    void increaseDateByOneMillennium()
    {
        clsDate date = increaseDateByOneMillennium(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByOneDay(clsDate date)
    {
        if (date._day == 1)
        {
            if (date._month == 1)
            {
                date._year--;
                date._month = 12;
                date._day = 31;
            }
            else
            {
                date._month--;
                date._day = date.numberOfDaysInMonth();
            }
        }

        else
        {
            date._day--;
        }

        return date;
    }

    void decreaseDateByOneDay()
    {
        clsDate date = decreaseDateByOneDay(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    clsDate decreaseDateByDays(clsDate date, int days)
    {
        for (int i = 1; i <= days; i++)
        {
            date.decreaseDateByOneDay();
        }

        return date;
    }

    void decreaseDateByDays(int days)
    {
        clsDate date = decreaseDateByDays(*this, days);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByOneWeek(clsDate date)
    {
        for (short i = 1; i <= 7; i++)
        {
            date = decreaseDateByOneDay(date);
        }

        return date;
    }

    void decreaseDateByOneWeek()
    {
        clsDate date = decreaseDateByOneWeek(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByWeeks(clsDate date, short weeks)
    {
        for (short i = 1; i <= weeks; i++)
        {
            date = decreaseDateByOneWeek(date);
        }

        return date;
    }

    void decreaseDateByWeeks(short weeks)
    {
        clsDate date = decreaseDateByWeeks(*this, weeks);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByOneMonth(clsDate date)
    {
        short monthDays = date.numberOfDaysInMonth(date._year, date._month - 1);

        if (date._month == 1)
        {
            date._year--;
            date._month = 12;
        }

        else if (date._day > monthDays)
        {
            date._month--;
            date._day = date.numberOfDaysInMonth();
        }

        else
        {
            date._month--;
        }

        return date;
    }

    void decreaseDateByOneMonth()
    {
        clsDate date = decreaseDateByOneMonth(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByMonths(clsDate date, short months)
    {
        for (short i = 1; i <= months; i++)
        {
            date.decreaseDateByOneMonth();
        }

        return date;
    }

    void decreaseDateByMonths(short months)
    {
        clsDate date = decreaseDateByMonths(*this, months);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByOneYear(clsDate date)
    {
        date._year--;

        return date;
    }

    void decreaseDateByOneYear()
    {
        clsDate date = decreaseDateByOneYear(*this);

        this->_year = date._year;
    }

    static clsDate decreaseDateByYears(clsDate date, short years)
    {
        for (short i = 1; i <= years; i++)
        {
            date.decreaseDateByOneYear();
        }

        return date;
    }

    void decreaseDateByYears(short years)
    {
        clsDate date = decreaseDateByYears(*this, years);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByOneDecade(clsDate date)
    {
        for (short i = 1; i <= 10; i++)
        {
            date.decreaseDateByOneYear();
        }

        return date;
    }

    void decreaseDateByOneDecade()
    {
        clsDate date = decreaseDateByOneDecade(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByDecades(clsDate date, short decades)
    {
        for (short i = 1; i <= decades; i++)
        {
            date.decreaseDateByOneDecade();
        }

        return date;
    }

    void decreaseDateByDecades(short decades)
    {
        clsDate date = decreaseDateByDecades(*this, decades);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByOneCentury(clsDate date)
    {
        date._year -= 100;

        return date;
    }

    void decreaseDateByOneCentury()
    {
        clsDate date = decreaseDateByOneCentury(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static clsDate decreaseDateByOneMillennium(clsDate date)
    {
        date._year -= 1000;

        return date;
    }

    void decreaseDateByOneMillennium()
    {
        clsDate date = decreaseDateByOneMillennium(*this);

        this->_day = date._day;
        this->_month = date._month;
        this->_year = date._year;
    }

    static int calculateMyAgeInDays(clsDate date, bool includeEndDay = false)
    {

        clsDate localTime;

        return date.getDifferenceInDays(date, localTime, includeEndDay);
    }

    int calculateMyAgeInDays(bool includeEndDay = false)
    {
        return calculateMyAgeInDays(*this, includeEndDay);
    }

    static int getDifferenceInDays(clsDate date1, clsDate date2, bool includeEndDay = false)
    {
        int countDays = 0;

        short swapFlag = 1;

        if (IsDate1AfterDate2(date1, date2))
        {
            SwapDates(date1, date2);

            swapFlag = -1;
        }

        while (IsDate1BeforeDate2(date1, date2))
        {
            countDays++;

            date1 = addOneDay(date1);
        }

        return (includeEndDay) ? ++countDays * swapFlag : countDays * swapFlag;
    }

    int getDifferenceInDays(clsDate date, bool includeEndDay = true)
    {
        return getDifferenceInDays(*this, date, includeEndDay);
    }

    short dayOfWeekOrder()
    {
        return dayOfWeekOrder(*this);
    }

    static bool isEndOfTheWeek(clsDate date)
    {
        return date.dayOfWeekOrder() == 6;
    }

    bool isEndOfTheWeek()
    {
        return isEndOfTheWeek(*this);
    }

    static bool isWeekEnd(clsDate date)
    {
        short dayWeekOrder = date.dayOfWeekOrder();

        return (dayWeekOrder == 5 || dayWeekOrder == 6);
    }

    bool isWeekEnd()
    {
        return isWeekEnd(*this);
    }

    static bool isBusinessDay(clsDate date)
    {
        return !isWeekEnd(date);
    }

    bool isBusinessDay()
    {
        return isBusinessDay(*this);
    }

    static short calculateBusinessDay(clsDate dateFrom, clsDate dateTo)
    {
        short daysCounter = 0;

        while (dateFrom.IsDateBeforeDate2(dateTo))
        {
            if (dateFrom.isBusinessDay())
            {
                daysCounter++;
            }

            dateFrom.addOneDay();
        }

        return daysCounter;
    }

    short calculateBusinessDay(clsDate dateTo)
    {
        return calculateBusinessDay(*this, dateTo);
    }

    static short calculateWeekendDays(clsDate dateFrom, clsDate dateTo)
    {
        short daysCounter = 0;

        while (dateFrom.IsDateBeforeDate2(dateTo))
        {
            if (dateFrom.isWeekEnd())
            {
                daysCounter++;
            }

            dateFrom.addOneDay();
        }

        return daysCounter;
    }

    short calculateWeekendDays(clsDate dateTo)
    {
        return calculateWeekendDays(*this, dateTo);
    }

    static short dayUntilTheEndOfTheYear(clsDate date)
    {
        clsDate endOfYearDate;

        endOfYearDate._year = date._year;
        endOfYearDate._month = 12;
        endOfYearDate._day = 31;

        return date.getDifferenceInDays(endOfYearDate, true);
    }

    short dayUntilTheEndOfTheYear()
    {
        return dayUntilTheEndOfTheYear(*this);
    }

    static short dayUntilTheEndOfTheMonth(clsDate date)
    {
        clsDate endOfMonthDate;

        endOfMonthDate._year = date._year;
        endOfMonthDate._month = date._month;
        endOfMonthDate._day = endOfMonthDate.numberOfDaysInMonth();

        return date.getDifferenceInDays(endOfMonthDate, true);
    }

    short dayUntilTheEndOfTheMonth()
    {
        return dayUntilTheEndOfTheMonth(*this);
    }

    static short dayUntilTheEndOfTheWeek(clsDate date)
    {
        return 6 - date.dayOfWeekOrder();
    }

    short dayUntilTheEndOfTheWeek()
    {
        return dayUntilTheEndOfTheWeek(*this);
    }

    static void SwapDates(clsDate &date1, clsDate &date2)
    {
        clsDate temp;

        temp = date1;
        date1 = date2;
        date2 = temp;
    }

    enum enCompareDate
    {
        Before = -1,
        Equal,
        After
    };

    static enCompareDate compareDates(clsDate date1, clsDate date2)
    {
        if (IsDate1AfterDate2(date1, date2))
            return enCompareDate::After;

        if (IsDate1BeforeDate2(date1, date2))
            return enCompareDate::Before;

        else
            return enCompareDate::Equal;
    }

    enCompareDate compareDates(clsDate date)
    {
        return compareDates(*this, date);
    }

    static void Print(short day, short month, short year)
    {
        cout << day << "/" << month << "/" << year << endl;
    }

    void Print()
    {
        cout << _day << "/" << _month << "/" << _year << endl;
    }
    static string DateToString(clsDate Date)
    {
        return to_string(Date._day) + "/" + to_string(Date._month) + "/" + to_string(Date._year);
    }
    string DateToString()
    {
        return DateToString(*this);
    }
    static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
    {
        bool Status;
        Status = !(compareDates(Date, DateFrom) ==
                       enCompareDate::Before ||
                   compareDates(Date, DateTo) ==
                       enCompareDate::After);

        if (!Status)
        {
            SwapDates(DateTo, DateFrom);

            Status = !(compareDates(Date, DateFrom) ==
                           enCompareDate::Before ||
                       compareDates(Date, DateTo) ==
                           enCompareDate::After);
        }
        return Status;
    }
};
