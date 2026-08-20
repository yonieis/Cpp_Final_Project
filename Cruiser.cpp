//
// Created by yonat on 18/02/2026.
//

#include "Cruiser.h"
Cruiser::Cruiser(std::string name, int power, std::array<double, 2> position, int range):Ship(name,power,75,position)
{
    this->range=range;
}
int Cruiser::in_range(double x, double y)
{
    if (std::sqrt(pow(x-this->get_x(),2)+pow(y-this->get_y(),2)) <= range)
    {
        return 1;
    }
    return 0;
}
void Cruiser::fight(int strength)
{
    if (strength < this->get_strength())
    {
        this->strenth_change(-1);
    }
    else
    {
        this->strenth_change(1);
    }
    this->set_status('s');
    this->set_speed(0);
    this->set_direction("");
    this->time_used();
}
void Cruiser::one_time_step()
{
    if (this->get_time_use()!=0)
    if (this->get_status()=='m')
    {
        this->move_to(this->get_current_speed()*std::cos(this->get_course()*M_PI/180)+this->get_x(),this->get_current_speed()*std::sin(this->get_course()*M_PI/180)+this->get_y());
    }
    this->up_time();
}

void Cruiser::print_status()
{
std::cout<<"Cruiser "<<this->get_name()
    <<" at (" <<this->get_x()<<", "<<this->get_y()<<") force: "
    <<this->get_strength()<<"moving on cource "
    <<this->get_course() <<"deg, speed "<<this->get_current_speed()
    <<"nm/hr" <<std::endl ;
}



