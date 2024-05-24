#include <exception>
#include <iostream>
#include <exception>
#include "Timetable.hpp"
#include "Time.hpp"

int main()
{
    try
    {
        Time time1(3666);
        Time time2(1,2,3);
        Time time3;

        time1.display();
        time2.display();
        time3.display();

        time3 = time1 + time2;
        time3.display();

        time3 = Time(59, 59, 1) + Time(1);
        time3.display();

        time3 = Time(100) + 145;
        time3.display();

        time3 += Time(3722);
        time3.display();

        time3.setTime(3666);

        std::cout << (time1 > time2) << std::endl;
        std::cout << (time1 < time2) << std::endl;
        std::cout << (time1 >= time2) << std::endl;
        std::cout << (time1 <= time2) << std::endl;

        std::cout << (time2 > time1) << std::endl;
        std::cout << (time2 < time1) << std::endl;
        std::cout << (time2 >= time1) << std::endl;
        std::cout << (time2 <= time1) << std::endl;

        std::cout << (time1 == time2) << std::endl;
        std::cout << (time1 != time2) << std::endl;
        
        std::cout << (time1 == time3) << std::endl;
        std::cout << (time1 != time3) << std::endl;
        std::cout << (time1 >= time3) << std::endl;
        std::cout << (time1 <= time3) << std::endl;

    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
