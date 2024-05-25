#include <iostream>
#include <sstream>
#include <exception>
#include "Time.hpp"

Time::Time(int _seconds, int _minutes, int _hours)
    : hours(_hours), minutes(_minutes), seconds(_seconds)
{
    setTime(_seconds, _minutes, _hours);
}

bool Time::isNonNegative(int _num)
{
    return _num >= 0;
}

void Time::validateInput(int _input)
{
    if (!isNonNegative(_input))
    {
        std::ostringstream msg;
        msg << "Invalid time value: " << _input <<  " .Expected positive number.";
        throw std::invalid_argument(msg.str());
    }
}

void Time::display() const
{
    std::cout  << hours << ":" << minutes << ":" << seconds << std::endl;
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
    validateInput(_seconds);

    minutes += _seconds / 60;
    seconds = _seconds % 60;

    setMinutes(minutes);
}

void Time::setMinutes(int _minutes)
{
    validateInput(_minutes);
    
    hours += _minutes / 60;
    minutes = _minutes % 60;
}

void Time::setHours(int _hours)
{
    validateInput(_hours);

    hours = _hours;
}

void Time::setTime(int _seconds, int _minutes, int _hours)
{
    validateInput(_seconds);
    validateInput(_minutes);
    validateInput(_hours);

    setHours(_hours);
    setMinutes(_minutes + _seconds / 60);
    setSeconds(_seconds % 60);
}

Time Time::operator+(const Time& _other) const
{
    Time temp;
    temp.setTime(seconds + _other.seconds, minutes + _other.minutes, hours + _other.hours);

    return temp;
}

Time& Time::operator+=(int _seconds)
{
    validateInput(_seconds);

    setSeconds(seconds + _seconds);
    
    return *this;
}

Time& Time::operator+=(const Time& _other)
{
    
    setTime(seconds + _other.seconds, minutes + _other.minutes, hours + _other.hours);
    
    return *this;
}

bool Time::operator==(const Time& _other) const
{
    return ((hours == _other.hours) && (minutes == _other.minutes) && (minutes == _other.minutes));
}

bool Time::operator!=(const Time& _other) const
{
    return (!(*this == _other));
}

bool Time::operator<(const Time& _other) const
{
    return (hours * 3600 + minutes * 60 + seconds < _other.hours * 3600 + _other.minutes * 60 + _other.seconds);
}

bool Time::operator<=(const Time& _other) const
{
    return ((*this < _other) || (*this == _other));
}

bool Time::operator>(const Time& _other) const
{
    return (!(*this <= _other));
}

bool Time::operator>=(const Time& _other) const
{
    return (!(*this < _other));
}
