#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Model.hpp"

Model::Model(const View& _view)
    : view(_view)
{
    //  Initialize timetable with 5 events times
    srand(time(0));

    for (int i {}; i < 5; ++i)
            timetable.addEvent(Time(rand() % 10000 + 1));
}

void Model::run()
{
    try
    {
        int selection {};
        while(selection != 3)
        {
            selection = view.displayMainMenu(timetable);
            switch(selection)
            {
                case 1: 
                    manageEvents();
                    break;
                case 2: 
                    view.displayTotalTime(timetable); 
                    break;
                case 3: break;
            }
        }
    }
    catch(const std::exception& e)
    {
        view.displayExceptionMessage(e.what());
        timetable.~Timetable();
        exit(1);
    }
}

void Model::manageEvents()
{
    int selection {};
    while(selection != 2)
    {
        selection = view.displayManageEventsMenu(timetable);
        switch(selection)
        {
            case 1: 
                modifyEvent(selectEvent());
                break;
            case 2: break;
        }

    }
}

void Model::modifyEvent(Time& event)
{
    int selection {};
    while (selection != 2)
    {
        selection = view.displayModifyEventMenu(timetable, event);
        switch(selection)
        {
            case 1: 
                increaseEventTime(event);
                break;
            case 2: break;
        }
    }
}

void Model::increaseEventTime(Time& event)
{
    while(true)
    {
        try
        {
            int num = view.displayincreaseTimeMenu(timetable, event);
            event += num;
            break;

        }
        catch(const std::invalid_argument& e)
        {
            continue;
        }
    }
}

Time& Model::selectEvent()
{
    while(true)
    {
        int selection {};
        selection = view.displaySelectEventMenu(timetable);
        try
        {
            return timetable.getEvent(selection-1);
        }
        catch(const std::out_of_range& e)
        {
         continue;   
        }
    }
}

Timetable Model::getFirstNEvents(size_t numOfFirstEvents)
{
    Timetable newTimetable;
    for (ptrdiff_t idx {0}; idx < numOfFirstEvents; ++idx)
        newTimetable.addEvent(timetable.getEvent(idx));

    return newTimetable;
}

Timetable Model::getEventsWithinTime(const Time& maxTime)
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