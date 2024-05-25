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


void waitForAnyKey() {
    std::cout << "Press any key to continue...";

    // Clear any error flags
    std::cin.clear();

    // Ignore any characters in the input buffer until an Enter is detected
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Wait for the user to press Enter
    std::cin.get();
}

void clear()
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    //system("clear");
    std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readNumber()
{
    int num {};
    while(true) //Loop until the user enters valid number
    {
        std::cin >> num;

        // Chceck for failed extraction
        if (std::cin.fail())    // If the previous extraction failed
        {    
            if (std::cin.eof()) // If the stream was closed
            {
                std::cerr << "\nStream was closed" << std::endl;
                return(1);   // Exit the program immediately
            }

            // Handle failure
            std::cin.clear();   // Clear the state of input back to normal
            ignoreLine();       // Skip the incorrect input
            continue;
        }

        // Check for extraneous input
        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            ignoreLine();
            continue;
        }

        return num;
    }
}

void displayInterface(const Timetable& timetable)
{   
    clear();
    std::cout << "-----TIMETABLES MANAGER-----" << std::endl;
    timetable.display();
    std::cout << std::endl;
}

void displayTotalTime(const Timetable& timetable)
{
    displayInterface(timetable);
    std::cout << "Total time: ";
    timetable.getTotalTime().display();
    waitForAnyKey();
}

void increaseTime(const Timetable& timetable, Time& event)
{
    while(true)
    {
        try
        {
            displayInterface(timetable);
            std::cout << "Event: ";
            event.display();
            std::cout << "\n";
            std:: cout << "Seconds by which to increase the event time: ";
            int num = readNumber();
            event += num;
            break;

        }
        catch(const std::invalid_argument& e)
        {
            continue;
        }
    }
}

Time& selectEvent(Timetable& timetable)
{
    while(true)
    {
        char selection {};
        displayInterface(timetable);
        std::cout << "Select event: ";
        selection = readNumber();
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

void modifyEvent(Timetable& timetable, Time& event)
{
    char selection {};
    displayInterface(timetable);

    std::cout << "Event: ";
    event.display();
    std::cout << "\n";
    std::cout << "1.INCREASE TIME\n2.RETURN" << std::endl;
    selection = readNumber();
    switch(selection)
    {
        case 1: 
            increaseTime(timetable, event);
            break;
        case 2: break;
    }

}

void manageEvents(Timetable& timetable)
{
    char selection {};
    while(selection != 2)
    {
        displayInterface(timetable);
        std::cout << "1.SELECT EVENT\n2.RETURN" << std::endl;
        selection = readNumber();
        switch(selection)
        {
            case 1: 
                modifyEvent(timetable, selectEvent(timetable));
                break;
            case 2: break;
        }

    }
    
}

int main()
{
    Timetable timetable;

    timetable.addEvent(Time(1, 2, 3));
    timetable.addEvent(Time(3, 2, 1));
    timetable.addEvent(Time(3661));
    timetable.addEvent(Time(6, 6, 6));
    timetable.addEvent(Time(1, 2, 3));
    
    char selection {};

    while(selection != 3)
    {
        displayInterface(timetable);
        std::cout << "1.MANAGE EVENTS\n2.DISPLAY TOTAL TIME\n3.EXIT" << std::endl;
        selection = readNumber();
        switch(selection)
        {
            case 1: 
                manageEvents(timetable);
                break;
            case 2: 
                displayTotalTime(timetable); 
                break;
            case 3: break;
        }
    }
    
}
