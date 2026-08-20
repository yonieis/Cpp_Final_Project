//
// Created by yonat on 08/02/2026.
//

#ifndef UNTITLED5_PORTS_H
#define UNTITLED5_PORTS_H
#include <array>
#include <string>
#include <vector>

class Ports
{
    private:
    std::array<double,2>pos;
    std::string name;
    double fuel;
    double fuel_re_per_h;
    public:
    void one_time_step();

    double get_fuel();
    std::string get_name() const;
    double get_x() const;
    double get_y() const;
    Ports(std::string name,double fuel,double fuel_re_per_h,std::array<double,2> pos);
    double take_fuel(double fuel);
    void  print_status();
};
#endif //UNTITLED5_PORTS_H