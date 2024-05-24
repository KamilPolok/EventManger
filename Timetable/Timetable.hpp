#pragma once
#include <stddef.h>
#include "Time.hpp"

class Timetable
{
private:
    size_t eventsCount;
    Time* events;

    void resize(size_t);
public:
    Timetable();
    ~Timetable();

    void addEvent(const Time&);
    void display() const;

    Time& getEvent(ptrdiff_t) const;
    Time getTotalTime();
    size_t getEventsCount() const;

    Time& operator[](ptrdiff_t) const;
};
