//
// Created by yonat on 17/02/2026.
//
#include "Ship.h"
#ifndef UNTITLED5_PATROL_H
#define UNTITLED5_PATROL_H
class Patrol:public Ship
{
    private:
    double fuel_cap;
    double fuel;
    double fuel_con;
    std::vector<std::string> visited;
    public:
    Patrol(std::string name,int power,std::array<double,2> position);
    ~Patrol()=default;
    void fuel_up(double fuel);
    void one_time_step() override;
    void add_target_to_visited();
    void flash_visited();
    int get_visited_length();
    int did_i_visit(std::string name);
    double get_fuel();
    double get_fuel_cup();

    void fight(int strength) override;
    void print_status() override;

};
#endif //UNTITLED5_PATROL_H