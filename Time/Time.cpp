#include <iostream>
#include "Time.hpp"

Time::Time()
    : hours(0), minutes(0), seconds(0)
{
}

Time::Time(int _hours, int _minutes, int _seconds)
    : hours(_hours), minutes(_minutes), seconds(_seconds)
{
    setTime(_seconds, _minutes, _hours);
}

bool Time::validate_input(int _input)
{
    return _input >= 0;
}

void Time::display() const
{
    std::cout << "Time: " << hours << ":" << minutes << ":" << seconds << std::endl;
}

unsigned int Time::getSeconds() const
{
    return seconds;
}

unsigned int Time::getMinutes() const
{
    return minutes;
}

unsigned int Time::getHours() const
{
    return hours;
}

void Time::setSeconds(int _seconds)
{
    if (validate_input(_seconds))
    {
        minutes += _seconds / 60;
        seconds = _seconds % 60;

        setMinutes(minutes);
    }
}

void Time::setMinutes(int _minutes)
{
    if (validate_input(_minutes))
    {
        hours += _minutes / 60;
        minutes = _minutes % 60;
    }
}

void Time::setHours(int _hours)
{
    if (validate_input(_hours))
    {
        hours = _hours;
    }
}

void Time::setTime(int _seconds, int _minutes, int _hours)
{
    if (validate_input(_seconds) && validate_input(_minutes) && validate_input(_hours))
    {
        setHours(_hours);
        setMinutes(_minutes  + _seconds / 60);
        setSeconds(_seconds % 60);
    }
}
