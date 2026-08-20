//
// Created by yonat on 17/02/2026.
//

#include "Patrol.h"
Patrol::Patrol(std::string name, int power, std::array<double, 2> position):Ship(name,power,15,position)
{
    fuel_cap=900;
    fuel=fuel_cap;
    fuel_con=2;
}
void Patrol::flash_visited()
{
    this->visited.clear();
}
void Patrol::fuel_up(double fuel)
{
    if (this->get_time_use()!=0){
    fuel_cap+=fuel;
    time_used();
    }
}
void Patrol::add_target_to_visited()
{
    this->visited.push_back(this->get_target());
}

void Patrol::one_time_step()
{
    if (this->get_time_use()==1){
   if (this->get_status()=='m'){
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
          this->move_to(this->get_x()+fuel*std::cos(this->get_course()*M_PI/180)/fuel_con,this->get_y()+fuel*std::sin(this->get_course()*M_PI/180)/fuel_con);
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
            this->add_target_to_visited();
            if (fuel==0)
            {
                this->set_status('X');
            }
        }
        else
        {
            this->move_to(this->get_x()+fuel*std::cos(this->get_course()*M_PI/180)/fuel_con,this->get_y()+fuel*std::sin(this->get_course()*M_PI/180)/fuel_con);
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
            this->move_to(fuel*std::cos(this->get_course()*M_PI/180)/fuel_con+this->get_x(),fuel*std::sin(this->get_course()*M_PI/180)/fuel_con+this->get_y());
            this->fuel=0;
            this->set_status('X');
        }
    }
   }
    }
    this->up_time();
}
double Patrol::get_fuel()
{
    return fuel;
}
int Patrol::get_visited_length()
{
    return this->visited.size();
}

void Patrol::fight(int strength)
{
    if (this->get_strength()>=strength)
    {
        this->strenth_change(1);
    }
    else
    {
        this->strenth_change(-1);
    }
    this->set_status('s');
    this->set_speed(0);
    this->set_direction("");
    time_used();
}
double Patrol::get_fuel_cup()
{
    return fuel_cap;
}

void Patrol::print_status()
{
    std::string s;
    if (this->get_status()=='m')
    {
        s="moving";
        if (this->get_course_or_rout()==0)
        {
            s+=" to "+this->get_target() +" ("+std::to_string(this->get_rout_x())+","+std::to_string(this->get_rout_y())+").";
        }
        else
        {
            s+="on corse"+std::to_string(this->get_course_or_rout());
        }
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
    std::cout<<"Patrol "<<this->get_name()
    <<" at ("<<this->get_x()
    <<", "<<this->get_y()<<"),fuel: "<<fuel
    <<" kl, resistance: "<<this->get_strength()<<", status: ";
    std::cout<<s<<std::endl;

}
int Patrol::did_i_visit(std::string name)
{
    for (int i=0;i<this->visited.size();i++)
    {
        if (this->visited[i]==name)
        {
            return 1;
        }
    }
        return 0;
}





