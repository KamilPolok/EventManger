#pragma once
#include "Timetable.hpp"
#include "Time.hpp"

class View
{
    void displayInterface(const Timetable&) const;
public:
    int displayMainMenu(const Timetable&) const;
    int displayManageEventsMenu(const Timetable&) const;
    int displayModifyEventMenu(const Timetable&, Time&) const;
    int displaySelectEventMenu(const Timetable&) const;
    int displayincreaseTimeMenu(const Timetable&, Time&) const;

    void displayTotalTime(const Timetable&) const;
    void displayExceptionMessage(const char*) const;
};
