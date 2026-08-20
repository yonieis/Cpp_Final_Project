//
// Created by yonat on 08/02/2026.
//

#ifndef UNTITLED5_SHIPS_H
#define UNTITLED5_SHIPS_H
#include <array>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <memory>

#include "Commend.h"

class Ship
{

private:
    std::string name;
    char status;
    double max_speed;
    double current_speed;
    std::array<double,2> position;
    int strength;
    std::array<double,2> current_rout;
    std::string current_direction;
    double course;
    std::vector<std::unique_ptr<Commend>> comands;
    int corse_or_rout;
    int time_use;

public:
    void dock(std::string name)
    {
        this->set_speed(0);
        this->set_status('d');
        this->time_use=0;
        this->current_direction=name;
    }
    std::string get_target()
    {
        return current_direction;
    }
    virtual void one_time_step(){}
    void move_to(double x,double y)
    {
        position[1]=x;
        position[0]=y;
    }
    double get_rout_x()
    {
        return current_rout[1];
    }
    double get_rout_y()
    {
        return current_rout[0];
    }
    char get_status()
    {
        return status;
    }
    void set_status(char status)
    {
        this->status = status;
    }
    double get_max_speed()
    {
        return max_speed;
    }
    double get_current_speed()
    {
        return current_speed;
    }
    double get_course()
    {
        return course;
    }
    std::string get_name()
    {
        return name;
    }
    double get_x()
    {
        return position[1];
    }
    double get_y()
    {
        return position[0];
    }
    void set_course(double course)
    {
        if (this->time_use!=0){
        this->course = course;
        this->corse_or_rout=1;
        this->current_direction="";
        }
        else
        {
            std::cerr<<"allready doing a commend in this house"<<std::endl;
        }
    }
    void set_current_rout(double x,double y)
    {
        if (this->time_use!=0){
        current_rout[0] = y;
        current_rout[1] = x;
        double ydel=(this->current_rout[0]-this->position[0]);
        double xdel=(this->current_rout[1]-this->position[1]);
        this->course = std::atan2(ydel,xdel)*180/M_PI;
        this->corse_or_rout=0;
        }
        else
        {
            std::cerr<<"allready doing a commend in this houre"<<std::endl;
        }
    }
    void set_direction(std::string direction)
    {
        this->current_direction = direction;
    }
    int set_speed(double speed)
    {
        if(speed<=max_speed)
        {
            current_speed = speed;
            return 1;
        }
        return 0;
    }
void add_comand(Commend c)
    {
    this->comands.push_back(std::make_unique<Commend>(c.get_type(),c.get_name_of_target(),c.get_x(),c.get_y(),c.get_speed()));
    }
    void up_time()
    {
        this->time_use=1;
    }
    void time_used()
    {
        this->time_use=0;
    }
    int get_time_use()
    {
        return time_use;
    }
   virtual  void fight(int strength){}
    int get_strength()
    {
        return strength;
    }
    double get_commend_x(int i)
    {
        return  comands[i]->get_x();
    }
    double get_commend_y(int i)
    {
        return comands[i]->get_y();
    }
    double get_commend_course(int i)
    {
        return comands[i]->get_deg();
    }
    std::string get_commend_direction(int i)
    {
        return comands[i]->get_name_of_target();
    }
    double get_commend_speed(int i)
    {
        return comands[i]->get_speed();
    }
    int get_commend_unloud(int i){
    return comands[i]->get_unload();
    }
    void do_commend(int i)
    {
        comands.erase(comands.begin()+i);
    }
    int get_commend_langth()
    {
        return comands.size();
    }
    char get_commend_type(int i)
    {
        return comands[i]->get_type();
    }
    int get_course_or_rout()
    {
        return corse_or_rout;
    }
    Ship(std::string name,int power,double max_speed,std::array<double,2> position)
    {
        this->name=std::move(name);
        this->max_speed=max_speed;
        this->position=std::move(position);
        this->strength=power;
        this->current_speed=0;
        this->current_rout[0]=0;
        this->current_rout[1]=0;
        this->course=0;
        this->current_direction="";
        this->status='s';
        this->corse_or_rout=0;
        this->time_use=1;
    }
    void strenth_change(int strength)
    {
        this->strength+=strength;
    }

    virtual ~Ship()=default;
    virtual void print_status(){}
};
#endif //UNTITLED5_SHIPS_H0