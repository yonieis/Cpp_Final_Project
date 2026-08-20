//
// Created by yonat on 09/02/2026.
//

#ifndef UNTITLED5_FREIGHTER_H
#define UNTITLED5_FREIGHTER_H
#include "Ship.h"

class Freighter :public Ship
{
    private:
    int carry_cap;
    int carry;
    double fuel_cap;
    double fuel;
    double fuel_con;
    public:
    void fight(int strength) override;
    Freighter(int carry_cap,std::string name,int power,std::array<double,2> position);
    ~Freighter()=default;

    void upload();
    void download(int to_down);
    void fuel_up(double fuel);
    void one_time_step() override;
    double get_fuel();
    int get_carry();
    double get_fuel_cup();
    int get_carry_cup();
    void print_status() override;


};
#endif //UNTITLED5_FREIGHTER_H