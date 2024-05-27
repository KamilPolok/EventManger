#include "Model.hpp"
#include "View.hpp"
#include "Timetable.hpp"
#include "Time.hpp"

int main()
{
    View view;
    Model model(view);

    model.run();
}
