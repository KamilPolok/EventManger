#include <algorithm>
#include <iostream>
#include <sstream>
#include <exception>
#include "Timetable.hpp"

Timetable::Timetable()
    : eventsCount(0)
    , events(nullptr)
{
}

Timetable::~Timetable()
{
    delete[] events;
}

void Timetable::resize(size_t newEventsCount)
{
    if (newEventsCount == eventsCount)
        return;

    Time* newEvents = ((newEventsCount) ? new Time[newEventsCount] : nullptr);
    
    if (eventsCount > 0)
        std::copy(events, events + eventsCount, newEvents);

    eventsCount = newEventsCount;
    delete[] events;
    events = newEvents;
}

void Timetable::addEvent(const Time& event)
{
    resize(eventsCount+1);
    events[eventsCount-1] = event;
}

void Timetable::display() const
{
    std::cout << "-----TIMETABLE-----" << std::endl;
    for (ptrdiff_t idx {0}; idx < eventsCount; ++idx)
        events[idx].display();
    std::cout << "-------------------" << std::endl;
}

Time& Timetable::getEvent(ptrdiff_t idx) const
{
    if ((idx < 0) || (idx >= eventsCount))
    {
        std::ostringstream msg;
        msg << "Index out of range. Given index: " << idx << " is out of range.";
        throw std::out_of_range(msg.str());
    }

    return events[idx];
}

Time Timetable::getTotalTime()
{
    Time totalTime;
    for (ptrdiff_t idx {0}; idx < eventsCount; ++idx)
        totalTime += events[idx];

    return totalTime;
}

size_t Timetable::getEventsCount() const
{
    return eventsCount;
}

Time& Timetable::operator[](ptrdiff_t idx) const
{
    return getEvent(idx);
}
