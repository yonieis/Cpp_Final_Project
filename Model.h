//
// Created by yonat on 08/02/2026.
//

#ifndef UNTITLED5_MODEL_H
#define UNTITLED5_MODEL_H
#include "Ship.h"
#include <map>
#include <memory>

#include "Ports.h"
#include "Freighter.h"
#include "Patrol.h"
#include "Cruiser.h"
class Model
{
private:
    std::map<std::string,std::unique_ptr<Patrol>> patrols;
    std::map<std::string,std::unique_ptr<Cruiser>> cruisers;
    std::map<std::string,std::unique_ptr<Freighter>> freighters;
    std::map<std::string,std::unique_ptr<Ports>> ports;
    Model();
    Model(const Model&)=delete;
    Model& operator=(const Model&)=delete;
int time=0;
public:
    static Model& get_instance();
    void add_port(std::string name, std::array<double,2> pos,double start_fuel,double fuel_per_h);
    void add_patrol(std::string name,std::array<double,2> pos,int power);
    void add_cruiser_or_freighter(std::string name,std::array<double,2> pos,int power,char type,int carry_or_range);
    void print_status();
    void do_dock_commend(std::string port_name,std::string ship_name );
    void do_course_commend(std::string ship_name,double deg,double speed);
    void do_position_commend(std::string name,int x,int y,double speed);
    void do_destination_commend(std::string ship_name,std::string port_name,double speed);
    void add_unload_commend(std::string ship_name,std::string port_name,int load);
    void add_load_commend(std::string ship_name,std::string port_name);
    void do_attack_commend(std::string ship_name,std::string target);
    void do_refuel_commend(std::string ship_name);
    void do_stop_commend(std::string ship_name);
    void one_time_step();
    double get_ship_x(std::string name);
    double get_ship_y(std::string name);
    double get_ship_speed(std::string name);
    int get_ship_strenth(std::string name);
    double get_ship_fuel(std::string name);
    char get_ship_status(std::string name);
    double get_ship_course(std::string name);
    double get_ship_target_x(std::string name);
    double get_ship_target_y(std::string name);
    std::string get_ship_target_name(std::string name);
    double get_port_x(std::string name);
    double get_port_y(std::string name);
    double get_port_fuel(std::string name);
    std::string get_all_ships_and_ports_in_scale(int scale,int x, int y);
    char is_there_a_ship_or_a_port(std::string name);
    void world_status();
    int get_max_load(std::string name);
    int get_time();

};
#endif //UNTITLED5_MODEL_H