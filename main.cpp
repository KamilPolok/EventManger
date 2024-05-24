#include <exception>
#include <iostream>
#include <exception>
#include "Timetable.hpp"
#include "Time.hpp"

Timetable getFirstNEvents(const Timetable& timetable, size_t numOfFirstEvents)
{
    Timetable newTimetable;
    for (ptrdiff_t idx {0}; idx < numOfFirstEvents; ++idx)
        newTimetable.addEvent(timetable.getEvent(idx));

    return newTimetable;
}

Timetable getEventsWithinTime(const Timetable& timetable, const Time& maxTime)
{
    timetable.display();

    Timetable newTimetable;

    for (ptrdiff_t idx {0}; idx < timetable.getEventsCount(); ++idx)
        if (newTimetable.getTotalTime() + timetable.getEvent(idx) <= maxTime)
            newTimetable.addEvent(timetable.getEvent(idx));
        else
            break;

    return newTimetable;
}

int main()
{
    Timetable timetable;

    try
    {
        Time time1(1,1,4);
        Time time2(54,28, 1);
        Time time3(59,59,3);
        Time time4(6,6,6);
        Time time5(3666);

        timetable.addEvent(time1);
        timetable.addEvent(time2);
        timetable.addEvent(time3);
        timetable.addEvent(time4);
        timetable.addEvent(time5);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Program will terminate";
        return 1;
    }
    timetable.display();

    try
    {
    Timetable another = getFirstNEvents(timetable, 3);
    another.display();
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    Time time6(0, 30, 2);
    time6 = timetable.getEvent(2);

    Timetable another = getEventsWithinTime(timetable, time6);
    another.display();
    another.getTotalTime().display();
}
