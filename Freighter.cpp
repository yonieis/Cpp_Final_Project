//
// Created by yonat on 09/02/2026.
//

#include "Freighter.h"

#include <iostream>

Freighter::Freighter(int carry_cap,std::string name,int power,std::array<double,2> position) : Ship(name,power,40,position)
{
    this->carry_cap=carry_cap;
    fuel_cap=500;
    fuel=fuel_cap;
    fuel_con=1;
    this->carry=0;

}

void Freighter::upload()
{
    if (this->get_status()=='d')
    this->carry=this->carry_cap;
    else
    {
        std::cerr<<"not docked "<<std::endl;
    }
    this->time_used();
}
void Freighter::download(int to_down)
{
    if (this->get_status()=='d'){
    if(to_down<=carry)
    this->carry-=to_down;
    else
    {
        this->carry=0;
    }
    }
    else
    {
        std::cerr<<"not docked "<<std::endl;
    }
    this->time_used();
}
void Freighter:: fuel_up(double fuel)
{
if (this->get_time_use()!=0){
    this->fuel+=fuel;
    this->time_used();
}
    else{
    std::cerr<<"allready doing something in this time stemp"<<std::endl;
    }
}
double Freighter::get_fuel()
{
    return this->fuel;
}
int Freighter::get_carry()
{
    return this->carry;
}
int Freighter::get_carry_cup()
{
    return this->carry_cap;
}
double Freighter::get_fuel_cup()
{
    return this->fuel_cap;
}
void Freighter::fight(int strength)
{
    if (strength>this->get_strength())
    {
        carry=0;
    }
    this->set_status('s');
    this->set_speed(0);
    this->set_direction("");
    this->time_used();
}

void Freighter::one_time_step()
{
    if (this->get_time_use()!=0)
    {
        if (this->get_status()=='d')
        {
            for (int i=0;i<this->get_commend_langth();i++)
            {
                if (this->get_commend_direction(i)==this->get_target()){
                if (this->get_commend_type(i)=='l'){
                    this->upload();
                    this->do_commend(i);
            }
                    else if (this->get_commend_type(i)=='u')
                    {
                        this->download(this->get_commend_unloud(i));
                        this->do_commend(i);
                    }
                }
        }
    }
    else if (this->get_status()=='m')
    {
        time_used();
        if (this->get_course_or_rout()==0){
            if (std::sqrt(std::pow((this->get_rout_x()-this->get_x()),2)+std::pow(this->get_rout_y()-this->get_y(),2))>std::sqrt(std::pow( this->get_current_speed()*std::cos(this->get_course()*M_PI/180),2)+std::pow(this->get_current_speed()*std::sin(this->get_course()*M_PI/180),2)))
            {
                if (this->fuel>get_current_speed()*fuel_con)
                {
                    this->move_to(this->get_x()+this->get_current_speed()*std::cos(this->get_course()*M_PI/180),this->get_y()+this->get_current_speed()*std::sin(this->get_course()*M_PI/180));
                    fuel-=fuel_con*get_current_speed();

                }
                else
                {
                    this->move_to(this->get_x()+fuel*std::cos(this->get_course()*M_PI/180),this->get_y()+fuel*std::sin(this->get_course()*M_PI/180));
                    fuel=0;
                    this->set_status('X');
                    this->set_speed(0);
                }
            }
            else
            {
                double dis= std::sqrt(std::pow((this->get_rout_x()-this->get_x()),2)+std::pow(this->get_rout_y()-this->get_y(),2));
                if (this->fuel>= dis*fuel_con)
                {
                    this->move_to(this->get_rout_x(),this->get_rout_y());
                    fuel-=fuel_con*dis;
                    this->set_status('s');
                    this->set_speed(0);
                }
                else
                {
                    this->move_to(this->get_x()+fuel*std::cos(this->get_course()*M_PI/180),this->get_y()+fuel*std::sin(this->get_course()*M_PI/180));
                    fuel=0;
                    this->set_status('X');
                    this->set_speed(0);
                }
            }



        }
        else
        {
            if (fuel>this->get_current_speed()*fuel_con)
            {
                this->move_to(this->get_current_speed()*std::cos(this->get_course()*M_PI/180)+this->get_x(),this->get_current_speed()*std::sin(this->get_course()*M_PI/180)+this->get_y());

                fuel-=fuel_con*this->get_current_speed();
            }
            else
            {
                this->move_to(fuel*std::cos(this->get_course()*M_PI/180)+this->get_x(),fuel*std::sin(this->get_course()*M_PI/180)+this->get_y());
                this->fuel=0;
                this->set_status('X');
            }
        }
    }
    }
    this->up_time();
}
void Freighter::print_status()
{
    std::string s;
    if (this->get_status()=='m')
    {
        s="moving";
        if (this->get_course_or_rout()==0)
        {
            s+=" to "+this->get_target() +" ("+std::to_string(this->get_rout_x())+","+std::to_string(this->get_rout_y())+")";
        }
        else
        {
            s+="on corse"+std::to_string(this->get_course_or_rout());
        }
        s+=", speed "+std::to_string(this->get_current_speed());
    }
    else if (this->get_status()=='d')
    {
        s="docking at "+this->get_target()+".";
    }
    else if (this->get_status()=='s')
    {

        s=" stoped.";
    }
    else if (this->get_status()=='X')
    {
        s= "dead in the water.";
    }
    std::cout<<"Freighter "<<this->get_name()
    <<" at ("<<this->get_x()
    <<", "<<this->get_y()<<"),fuel: "<<fuel
    <<" kl, resistance: "<<this->get_strength()<<", containers: "<<this->carry<<", status: ";
    std::cout<<s<<std::endl;

}

