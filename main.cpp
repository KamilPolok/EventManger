#include <exception>
#include <iostream>
#include <exception>
#include "Timetable.hpp"
#include "Time.hpp"

int main()
{
    Timetable timetable;

    try
    {
        Time time1(3666);
        Time time2(1,2,3);
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
    }

    timetable.display();
    std::cout << timetable.getEventsCount() << std::endl;

    try
    {
        Time& time6 = timetable[2];
        time6.display();
        time6 += 60;
        time6.display();
        
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Program will terminate" << std::endl;
    }

    timetable.display();

    Time time7 = timetable.getTotalTime();
    time7.display();
}
