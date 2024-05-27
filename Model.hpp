#pragma once
#include "View.hpp"
#include "Timetable.hpp"
#include "Time.hpp"

class Model
{
private:
    Timetable timetable;
    const View& view;

    Timetable getFirstNEvents(size_t);
    Timetable getEventsWithinTime(const Time&);
public:
    Model(const View&);

    void run();
    void manageEvents();
    void modifyEvent(Time&);
    void increaseEventTime(Time&);

    Time& selectEvent();
};
