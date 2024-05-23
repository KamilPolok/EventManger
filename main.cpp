#include <exception>
#include <iostream>
#include "Time.hpp"

int main()
{
    try
    {
    Time time1;
    Time time2(1, 2, 3);

    time2.display();
    time1.display();
    time1.setTime(40, 182, 140);
    time1.setTime(3662, 3, 2);
    time1.setHours(-2);
    time1.display();
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << "Program will terminate" << std::endl;
    }
}
