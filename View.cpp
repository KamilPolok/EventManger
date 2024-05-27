#include "View.hpp"
#include <limits>
#include <iostream>
#include <sstream>

void clear();
void waitForAnyKey();
void ignoreLine();
int readNumber();

void View::displayInterface(const Timetable& timetable) const
{
    clear();
    std::cout << "-----TIMETABLES MANAGER-----" << std::endl;
    timetable.display();
    std::cout << std::endl;
}

int  View::displayMainMenu(const Timetable& timetable) const
{
    displayInterface(timetable);
    std::cout << "1.MANAGE EVENTS\n2.DISPLAY TOTAL TIME\n3.EXIT" << std::endl;
    return readNumber();
}

int View::displayManageEventsMenu(const Timetable& timetable) const
{
    displayInterface(timetable);
    std::cout << "1.SELECT EVENT\n2.RETURN" << std::endl;
    return readNumber();
}

int View::displayModifyEventMenu(const Timetable& timetable, Time& event) const
{
    displayInterface(timetable);
    std::cout << "Event: ";
    event.display();
    std::cout << "\n";
    std::cout << "1.INCREASE TIME\n2.RETURN" << std::endl;
    return readNumber();
}

int View::displaySelectEventMenu(const Timetable& timetable) const
{
    displayInterface(timetable);
    std::cout << "Select event: ";
    return readNumber();
}

int View::displayincreaseTimeMenu(const Timetable& timetable, Time& event) const
{
    displayInterface(timetable);
    std::cout << "Event: ";
    event.display();
    std::cout << "\n";
    std:: cout << "Seconds by which to increase the event time: ";

    return readNumber();
}

void View::displayTotalTime(const Timetable& timetable) const
{
    displayInterface(timetable);
    std::cout << "Total time: ";
    timetable.getTotalTime().display();
    waitForAnyKey();
}

void View::displayExceptionMessage(const char *excMessage) const
{
    std::cerr << excMessage << std::endl;
}

class EOFException : public std::exception {
public:
    EOFException() noexcept {}

    // Provide a default error message
    virtual const char* what() const noexcept override {
        return "End of File encountered!";
    }
};

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

void waitForAnyKey() {
    std::cout << "Press any key to continue... ";

    // Clear any error flags
    std::cin.clear();

    // Wait for the user to press Enter
    std::cin.get();
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int readNumber()
{
    char input[256];

    std::cin.getline(input, 256); // Read line from standard input

    // Check for end of file (EOF)
    if (std::cin.eof())
    {
        throw EOFException();
    }

    // Use stringstream to parse the number
    std::stringstream ss(input);
    int num;
    char remaining;

    if (ss >> num && !(ss >> remaining))
        return num; // If successful and no extraneous input, return the read number
    else
        return 0; // Indicate failure or invalid input
}
