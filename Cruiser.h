//
// Created by yonat on 18/02/2026.
//

#ifndef UNTITLED5_CRUISER_H
#define UNTITLED5_CRUISER_H
#include "Ship.h"

class Cruiser :public Ship
{
    int range;
    public:
    Cruiser(std::string name,int power,std::array<double,2> position,int range);
    int in_range(double x, double y);
    void fight(int strength) override;
    void one_time_step() override;
    void print_status() override;
    ~Cruiser()=default;
};
#endif //UNTITLED5_CRUISER_H