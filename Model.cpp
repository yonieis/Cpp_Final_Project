//
// Created by yonat on 08/02/2026.
//

#include "Model.h"

#include <float.h>

void Model::add_unload_commend(std::string ship_name, std::string port_name,int load)
{
    if (freighters.find(ship_name)!=freighters.end())
        freighters[ship_name]->add_comand(Commend('u',port_name,load));
}

void Model::add_load_commend(std::string ship_name, std::string port_name)
{
    if (freighters.find(ship_name)!=freighters.end())
        freighters[ship_name]->add_comand(Commend('l',port_name));
}

void Model::add_port(std::string name, std::array<double, 2> pos, double start_fuel, double fuel_per_h)
{
    if (cruisers.find(name) == cruisers.end()&&ports.find(name) == ports.end()&&patrols.find(name)==patrols.end()&&freighters.find(name)==freighters.end())
        ports[name]=std::make_unique<Ports>(name,start_fuel,fuel_per_h,pos);
}
void Model::add_cruiser_or_freighter(std::string name, std::array<double, 2> pos, int power, char type, int carry_or_range)
{
    if (cruisers.find(name) == cruisers.end()&&ports.find(name) == ports.end()&& patrols.find(name) == patrols.end()&& freighters.find(name) == freighters.end())
    {
        if (type=='c')
        {
            cruisers[name]=std::make_unique<Cruiser>(name,power,pos,carry_or_range);
        }
        else if (type=='f')
        {
            freighters[name]=std::make_unique<Freighter>(carry_or_range,name,power,pos);
        }
    }
}
void Model::add_patrol(std::string name, std::array<double, 2> pos, int power)
{
    if (cruisers.find(name) == cruisers.end()&& ports.find(name) == ports.end()&& patrols.find(name) == patrols.end()&& freighters.find(name) == freighters.end())
    {
        patrols[name]=std::make_unique<Patrol>(name,power,pos);
    }
}
double Model::get_ship_y(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        return cruisers[name]->get_y();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_y();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_y();
    }
    return NULL;
}
double Model::get_ship_x(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        return cruisers[name]->get_x();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_x();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_x();
    }
    return NULL;
}
double Model::get_ship_target_y(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        return cruisers[name]->get_rout_y();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_rout_y();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_rout_y();
    }
    return NULL;
}
double Model::get_ship_target_x(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        return cruisers[name]->get_rout_x();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_rout_x();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_rout_x();
    }
    return NULL;
}
double Model::get_ship_course(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        return cruisers[name]->get_course();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_course();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_course();
    }
    return NULL;
}
double Model::get_ship_speed(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
       return  cruisers[name]->get_current_speed();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_current_speed();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_current_speed();
    }
    return -1;
}
double Model::get_ship_fuel(std::string name)
{
    if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_fuel();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_fuel();
    }
    return -1;
}
int Model::get_ship_strenth(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        return cruisers[name]->get_strength();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_strength();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_strength();
    }
    return -1;
}
char Model::get_ship_status(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        return cruisers[name]->get_status();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_status();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_status();
    }
    return NULL;
}
std::string Model::get_ship_target_name(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        cruisers[name]->get_target();
    }
    else if (patrols.find(name) != patrols.end())
    {
        return patrols[name]->get_target();
    }
    else if (freighters.find(name) != freighters.end())
    {
        return freighters[name]->get_target();
    }
    return "";
}
double Model::get_port_fuel(std::string name)
{
    if (ports.find(name) != ports.end())
    {
        ports[name]->get_fuel();
    }
    return NULL;
}
double Model::get_port_x(std::string name)
{
    if (ports.find(name) != ports.end())
    {
        return ports[name]->get_x();
    }
    return NULL;
}
double Model::get_port_y(std::string name)
{
    if (ports.find(name) != ports.end())
    {
        return ports[name]->get_y();
    }
    return NULL;
}
Model::Model()
{
    std::array<double,2> pos{5,50};
this->ports["Nagoya"]=std::make_unique<Ports>("Nagoya",1000000,1000,pos);
}
Model& Model::get_instance()
{
    static Model instance;
    return instance;
}
void Model::print_status()
{
    for  (const auto & p : ports)
    {
        ports[p.first]->print_status();
    }
    for (const auto & p : freighters)
    {
        freighters[p.first]->print_status();
    }
    for (const auto & p : cruisers)
    {
        cruisers[p.first]->print_status();
    }
    for (const auto & p : patrols)
    {
        patrols[p.first]->print_status();
    }

}
void Model::do_attack_commend(std::string ship_name, std::string target)
{
    if (cruisers.find(ship_name) != cruisers.end())
    {
        if (freighters.find(target) != freighters.end())
        {
            if (cruisers[ship_name]->in_range(freighters[target]->get_x(),freighters[target]->get_y()))
            {
                cruisers[ship_name]->fight(freighters[target]->get_strength());
                freighters[target]->fight(cruisers[ship_name]->get_strength());
            }
        }
        else if (patrols.find(target) != patrols.end())
        {
            if (cruisers[ship_name]->in_range(patrols[target]->get_x(),patrols[target]->get_y()))
            {
                cruisers[ship_name]->fight(patrols[target]->get_strength());
                patrols[target]->fight(cruisers[ship_name]->get_strength());
            }
        }
    }
}
void Model::do_course_commend(std::string ship_name, double deg, double speed)
{
    if (cruisers.find(ship_name) != cruisers.end())
    {
        this->cruisers[ship_name]->set_course(deg);
        this->cruisers[ship_name]->set_speed(speed);
    }
    else if (patrols.find(ship_name) != patrols.end())
    {
        std::cerr<<"this ship doesnt saport this kind of oparition"<<std::endl;
    }
    else if (freighters.find(ship_name) != freighters.end())
    {
        this->freighters[ship_name]->set_course(deg);
        this->freighters[ship_name]->set_speed(speed);

    }
}
void Model::do_destination_commend(std::string ship_name, std::string port_name, double speed)
{

    if (cruisers.find(ship_name) != cruisers.end())
    {
        cruisers[ship_name]->set_status('m');
        cruisers[ship_name]->set_direction(port_name);
        cruisers[ship_name]->set_speed(speed);
        cruisers[ship_name]->set_current_rout(ports[port_name]->get_x(),ports[port_name]->get_y());
    }
        else if (patrols.find(ship_name) != patrols.end())
        {
            std::cerr<<"this ship doesnt saport this kind of oparition"<<std::endl;
        }
        else if (freighters.find(ship_name) != freighters.end())
        {
            this->freighters[ship_name]->set_status('m');
            this->freighters[ship_name]->set_direction(port_name);
            this->freighters[ship_name]->set_speed(speed);
            this->freighters[ship_name]->set_current_rout(ports[port_name]->get_x(),ports[port_name]->get_y());
        }
    }

void Model::do_dock_commend(std::string port_name, std::string ship_name)
{
    if (ports.find(port_name) != ports.end())
    {
        if (cruisers.find(ship_name) != cruisers.end())
        {
            if (cruisers[ship_name]->get_x()==ports[port_name]->get_x()&&cruisers[ship_name]->get_y()==ports[port_name]->get_y())
            {
                cruisers[ship_name]->dock(port_name);
            }
        }
        else if (patrols.find(ship_name) != patrols.end())
        {
            if (patrols[ship_name]->get_x()==ports[port_name]->get_x()&&patrols[ship_name]->get_y()==ports[port_name]->get_y())
            {
                patrols[ship_name]->dock(port_name);
            }
        }
        else if (freighters.find(ship_name) != freighters.end())
        {
            if (freighters[ship_name]->get_x()==ports[port_name]->get_x()&&freighters[ship_name]->get_y()==ports[port_name]->get_y())
            {
                freighters[ship_name]->dock(port_name);
            }
        }
    }
}
void Model::do_position_commend(std::string name, int x, int y, double speed)
{
    if (cruisers.find(name) != cruisers.end())
    {
        cruisers[name]->set_status('m');
        cruisers[name]->set_current_rout(x,y);
        cruisers[name]->set_speed(speed);
        cruisers[name]->set_direction("");
    }
    else if (patrols.find(name) != patrols.end())
    {
        std::cout<<"this ship doesnt saport this kind of oparition"<<std::endl;
    }
    else if (freighters.find(name) != freighters.end())
    {
        this->freighters[name]->set_status('m');
        this->freighters[name]->set_current_rout(x,y);
        this->freighters[name]->set_speed(speed);
        this->freighters[name]->set_direction("");
    }
}
void Model::do_stop_commend(std::string ship_name)
{
    if (cruisers.find(ship_name) != cruisers.end())
    {
        cruisers[ship_name]->set_status('s');
        cruisers[ship_name]->set_direction("");
        cruisers[ship_name]->set_current_rout(cruisers[ship_name]->get_x(),cruisers[ship_name]->get_y());
        cruisers[ship_name]->set_speed(0);
        cruisers[ship_name]->time_used();
    }
    else if (patrols.find(ship_name) != patrols.end())
    {
        patrols[ship_name]->set_status('s');
        patrols[ship_name]->set_direction("");
        patrols[ship_name]->set_current_rout(patrols[ship_name]->get_x(),patrols[ship_name]->get_y());
        patrols[ship_name]->set_speed(0);
        patrols[ship_name]->time_used();
    }
    else if (freighters.find(ship_name) != freighters.end())
    {
        this->freighters[ship_name]->set_status('s');
        this->freighters[ship_name]->set_direction("");
        freighters[ship_name]->set_current_rout(freighters[ship_name]->get_x(),freighters[ship_name]->get_y());
        this->freighters[ship_name]->set_speed(0);
        freighters[ship_name]->time_used();
    }
}
void Model::do_refuel_commend(std::string ship_name)
{
    if (freighters.find(ship_name) != freighters.end())
    {
        if (freighters[ship_name]->get_status()=='d')
        {
            if (ports[freighters[ship_name]->get_target()]->get_fuel()>freighters[ship_name]->get_fuel_cup()-freighters[ship_name]->get_fuel()){
                freighters[ship_name]->fuel_up(freighters[ship_name]->get_fuel_cup()-freighters[ship_name]->get_fuel());
                ports[freighters[ship_name]->get_target()]->take_fuel(freighters[ship_name]->get_fuel_cup()-freighters[ship_name]->get_fuel());
            }
            else
            {
                freighters[ship_name]->fuel_up(ports[freighters[ship_name]->get_target()]->get_fuel());
                ports[freighters[ship_name]->get_target()]->take_fuel(ports[freighters[ship_name]->get_target()]->get_fuel());
            }
        }
    }
    if (patrols.find(ship_name) != patrols.end())
    {
        if (patrols[ship_name]->get_status()=='d')
        {
            if (ports[patrols[ship_name]->get_target()]->get_fuel()>patrols[ship_name]->get_fuel_cup()-patrols[ship_name]->get_fuel()){
                patrols[ship_name]->fuel_up(patrols[ship_name]->get_fuel_cup()-patrols[ship_name]->get_fuel());
                ports[patrols[ship_name]->get_target()]->take_fuel(patrols[ship_name]->get_fuel_cup()-patrols[ship_name]->get_fuel());
            }
            else
            {
                patrols[ship_name]->fuel_up(ports[patrols[ship_name]->get_target()]->get_fuel());
                ports[patrols[ship_name]->get_target()]->take_fuel(ports[patrols[ship_name]->get_target()]->get_fuel());
            }
        }
    }
}
void Model::one_time_step()
{
    for (auto & cruser :cruisers)
    {
        cruser.second->one_time_step();
    }
    for (auto & patrol :patrols)
    {
        if (patrol.second->get_time_use()==1)
        if (patrol.second->get_status()=='d' || patrol.second->get_status()=='s')
        {
            if (patrol.second->get_visited_length()==ports.size())
            {
                patrol.second->flash_visited();
                patrol.second->add_target_to_visited();
            }
            patrol.second->set_status('m');

            std::string s;
            double d=DBL_MAX;
            for (auto & port :ports)
            {
                if (patrol.second->did_i_visit(port.first)==0)
                {
                    if (d>std::sqrt(std::pow(port.second->get_x()-patrol.second->get_x(),2)
                        +std::pow(port.second->get_y()-patrol.second->get_y(),2)))
                    {
                        d=std::sqrt(std::pow(port.second->get_x()-patrol.second->get_x(),2)
                        +std::pow(port.second->get_y()-patrol.second->get_y(),2));
                        s=port.first;
                    }
                }
            }
            patrol.second->set_direction(s);
            patrol.second->set_speed(patrol.second->get_max_speed());
            patrol.second->set_current_rout(ports[s]->get_x(),ports[s]->get_y());
        }
        patrol.second->one_time_step();
    }
    for (auto & freighter :freighters)
    {
        freighter.second->one_time_step();
    }
    time++;
}


std::string Model::get_all_ships_and_ports_in_scale(int scale, int x, int y)
{
    int total=0;
    std::string s=". ";

               for (auto & port :ports)
               {
                   if (port.second->get_x()>=x&&port.second->get_x()<x+scale && port.second->get_y()>=y&&port.second->get_y()<y+scale){
                   if (total==0)
                   {
                       s=port.first.substr(0,2);
                       total+=1;
                   }
                       else
                       {
                           total+=1;
                           s="o"+std::to_string(total);
                       }
                   }
               }
               for (auto & patrol :patrols)
               {
                   if (patrol.second->get_x()>=x&&patrol.second->get_x()<x+scale && patrol.second->get_y()>=y&&patrol.second->get_y()<y+scale){
                   if (total==0)
                   {
                       s=patrol.first.substr(0,2);
                       total+=1;
                   }
                   else
                   {
                       total+=1;
                       s="o"+std::to_string(total);
                   }
                   }
               }
           for (auto & fre :freighters)
           {
               if (fre.second->get_x()>=x&&fre.second->get_x()<x+scale && fre.second->get_y()>=y&&fre.second->get_y()<y+scale){
               if (total==0)
               {
                   s=fre.first.substr(0,2);
                   total+=1;
               }
               else
               {
                   total+=1;
                   s="o"+std::to_string(total);
               }
               }
           }
            for (auto & cru :cruisers)
            {
                if (cru.second->get_x()>=x && cru.second->get_x()<x+scale&& cru.second->get_y()>=y&&cru.second->get_y()<y+scale)
                {
                    if (total==0)
                    {
                        s=cru.first.substr(0,2);
                        total+=1;
                    }
                    else
                    {
                        total+=1;
                        s="O"+std::to_string(total);
                    }
                }
            }
    if (total>9)
    {
        s="+9";
    }
    return s;
        }



char Model::is_there_a_ship_or_a_port(std::string name)
{
    if (cruisers.find(name) != cruisers.end())
    {
        return 'c';
    }
    else if (patrols.find(name) != patrols.end())
    {
        return 'p';
    }
    else if (freighters.find(name) != freighters.end())
    {
        return 'f';
    }
    else if (ports.find(name) != ports.end())
    {
        return 's';
    }
    return 'x';
}
void Model::world_status()
{
    for (auto & port :ports)
    {
        port.second->print_status();
    }
    for (auto & fri :freighters)
    {
        fri.second->print_status();
    }
    for (auto & cru :cruisers)
    {
        cru.second->print_status();
    }
    for (auto & patrol :patrols)
    {
        patrol.second->print_status();
    }
}
int Model::get_max_load(std::string name)
{
    if (freighters.find(name) != freighters.end())
    {
        return  freighters[name]->get_fuel_cup();
    }
}
int Model::get_time()
{
    return time;
}


