#pragma once

class Time
{
private:
    unsigned short seconds;
    unsigned short minutes;
    unsigned hours;

    bool isNonNegative(int);
    void validateInput(int);
public:
    Time(int=0, int=0, int=0);

    void display() const;

    unsigned getSeconds() const;
    unsigned getMinutes() const;
    unsigned getHours() const;

    void setSeconds(int);
    void setMinutes(int);
    void setHours(int);
    void setTime(int, int=0, int=0);

    Time operator+(const Time&) const;

    Time& operator+=(int);
    Time& operator+=(const Time&);

    bool operator==(const Time&) const;
    bool operator!=(const Time&) const;
    bool operator<(const Time&) const;
    bool operator<=(const Time&) const;
    bool operator>(const Time&) const;
    bool operator>=(const Time&) const;
};
