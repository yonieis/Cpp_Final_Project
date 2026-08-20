//
// Created by yonat on 08/02/2026.
//

#include "Ports.h"

#include <iostream>

Ports::Ports(std::string name, double fuel, double fuel_re_per_h, std::array  <double, 2>pos)
{
    this->name = name;
    this->fuel = fuel;
    this->fuel_re_per_h = fuel_re_per_h;
    this->pos=std::move(pos);
}


void Ports::one_time_step()
{
    fuel+=fuel_re_per_h;
}
std::string Ports::get_name() const
{
    return name;
}
double Ports::get_fuel()
{
    return fuel;
}
double Ports::take_fuel(double fuel)
{
    if (fuel>this->fuel)
    {
        this->fuel=0;
        return this->fuel;
    }
    this->fuel-=fuel;
    return fuel;
}
double Ports::get_x() const
{
    return pos[1];
}
double Ports::get_y() const
{
    return pos[0];
}
void Ports::print_status()
{
    std::cout<<"Port "<<name<<" at ("<<this->get_x()<<", "<<this->get_y()<<"), Fuel available: "<<fuel<<" kl"<<std::endl;
}

