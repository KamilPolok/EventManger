#include "Time.hpp"

int main()
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
