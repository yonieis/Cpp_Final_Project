//
// Created by yonat on 08/02/2026.
//

#include "Controller.h"
void Controller::prosses_line(const std::string & line)
{
    std::string command;
    std::istringstream ss(line);
    if (ss >> command){
    if (command == "exit")
    {
        std::cout<<"exiting"<<std::endl;
        std::exit(0);
    }
    else if (command == "create")
    {
        std::string name,type;
        double x ,y;
        char cleaner;
        int res,other;
        ss >> name;

        if (m.is_there_a_ship_or_a_port(name)=='x')
        {
            ss>>type;
            if (type=="Cruiser" )
            {
               if ( ss>>cleaner>>x>>cleaner>>y>>cleaner>>res>>other)
               {
                   char t='c';
                   std::array<double,2>pos{y,x};
                   m.add_cruiser_or_freighter(name,pos,res,t,other);
               }
                else
                {
                    std::cerr<<"invalid Cruiser"<<std::endl;
                }
            }
            else if (type=="Freighter"){
                if ( ss>>cleaner>>x>>cleaner>>y>>cleaner>>res>>other)
                {
                    char t='f';
                    std::array<double,2>pos{y,x};
                    m.add_cruiser_or_freighter(name,pos,res,t,other);
                }
                else
                {
                    std::cerr<<"invalid Freighter"<<std::endl;
                }
                }
            else if (type=="Patrol")
            {
                if (ss>>cleaner>>x>>cleaner>>y>>cleaner>>res){
                std::array<double,2>pos{y,x};
                m.add_patrol(name,pos,res);
                }
                else
                {
                    std::cerr<<"invalid Patrol"<<std::endl;
                }
            }
            else
            {
                std::cerr<<"invalid Ship type"<<std::endl;
            }
        }
        else
        {
            std::cerr<<"there is an object with that name";
            return;
        }
    }
    else if (command == "default")
    {
        view->change_line_to_show(25);
        view->change_scale(2);
    }
    else if (command == "size")
    {
        int lines;
        if (ss >> lines)
        {
            if (lines >=6&&lines<=30)
            {
                view->change_line_to_show(lines);
            }
            else
            {
                std::cerr<<"invalid size"<<std::endl;
            }
        }
        else
        {
            std::cerr<<"missing size"<<std::endl;
        }
    }
    else if (command == "zoom")
    {
        int scale;
        if (ss >> scale)
        {
            if (scale >0)
            {
                view->change_scale(scale);
            }
            else
            {
                std::cerr<<"invalid scale"<<std::endl;
            }
        }
        else
        {
            std::cerr<<"missing zoom"<<std::endl;
        }

    }
    else if (command == "pan")
    {
        double x,y;
        char cleaner;
        if (ss>>cleaner>>x>>cleaner>>y)
        {
            view->change_start_pos(x,y);
        }
        else
        {
            std::cerr<<"invalid pan"<<std::endl;
        }
    }
    else if (command == "show")
    {
        view->show();
    }
    else if (command == "status")
    {
        m.world_status();
    }
    else if (command == "go")
    {
        m.one_time_step();

    }
    else if (m.is_there_a_ship_or_a_port(command)!='x'&&m.is_there_a_ship_or_a_port(command)!='s')
    {
        std::string com;
        if (ss>>com)
        {
            if (com=="course")
            {
                double deg,speed;
                if (ss>>deg>>speed)
                {
                    if (speed>0)
                    m.do_course_commend(command,deg,speed);
                    else
                    {
                        std::cerr<<"invalid speed"<<std::endl;
                    }
                }
                else
                {
                    std::cerr<<"missing course or speed"<<std::endl;
                }
            }
            else if (com=="position")
            {
                double x,y,speed;
                char cleaner;
                if (ss>>cleaner>>x>>cleaner>>y>>cleaner>>speed)
                {
                    if (speed>0)
                    m.do_position_commend(command,x,y,speed);
                    else
                        std::cerr<<"invalid speed"<<std::endl;
                }
                else
                {
                    std::cerr<<"missing position commands"<<std::endl;
                }
            }
            else if (com=="destination")
            {
                std::string dest;
                double speed;
                if (ss>>dest>>speed)
                {
                    if (m.is_there_a_ship_or_a_port(dest)=='s'){
                    if (speed>0)
                    m.do_destination_commend(command,dest,speed);
                    else
                    {
                        std::cerr<<"invalid speed"<<std::endl;
                    }

                    }
                    else
                    {
                        std::cerr<<"no such port"<<std::endl;
                    }
                }
                else
                {
                    std::cerr<<"missing destination"<<std::endl;
                }

            }
            else if (com=="load_at")
            {
                if (m.is_there_a_ship_or_a_port(command)=='f'){
                std::string load_at;

                if (ss>>load_at)
                {
                    if (m.is_there_a_ship_or_a_port(load_at)=='s'){
                        m.add_load_commend(command,load_at);

                }
                    else
                    {
                        std::cerr<<"no such port"<<std::endl;
                    }
                }
                else
                {
                    std::cerr<<"missing argument for loud at"<<std::endl;
                }
                }
                else
                {
                    std::cerr<<"this ship cant load"<<std::endl;
                }
            }
            else if (com=="unload_at")
            {
                if (m.is_there_a_ship_or_a_port(command)=='f')
                {
                    std::string load_at;
                    int unload_num;
                    if (ss>>load_at>>unload_num)
                    {

                         if (unload_num>0&& unload_num<=m.get_max_load(command))
                         {
                             if (m.is_there_a_ship_or_a_port(load_at)=='s')
                             {
                                 m.add_unload_commend(command,load_at,unload_num);
                             }
                             else
                             {
                                 std::cerr<<"no such port"<<std::endl;
                             }
                         }
                            else
                            {
                                std::cerr<<"invalid load amount"<<std::endl;
                            }

                    }
                }
                else
                {
                    std::cerr<<"this ship cant unload"<<std::endl;
                }
            }
            else if (com=="dock_at")
            {
                std::string dock_at;
                if (ss>>dock_at)
                {
                    if (m.is_there_a_ship_or_a_port(dock_at)=='s')
                    {
                      m.do_dock_commend(dock_at,command);
                    }
                    else
                    {
                        std::cerr<<"no such port"<<std::endl;
                    }
                }
                else
                {
                    std::cerr<<"missing dock location"<<std::endl;
                }
            }
            else if (com=="attack")
            {
                if (m.is_there_a_ship_or_a_port(command)=='c')
                {
                    std::string to_attack;
                    if (ss>>to_attack)
                    {
                        if (m.is_there_a_ship_or_a_port(to_attack)=='f'||m.is_there_a_ship_or_a_port(to_attack)=='p')
                        {
                            m.do_attack_commend(command,to_attack);
                        }
                        else
                        {
                            std::cerr<<"no such ship"<<std::endl;
                        }
                    }
                    else
                    {
                        std::cerr<<"missing attack "<<std::endl;
                    }

                }
            }
            else if (com=="refuel")
            {
                if (m.is_there_a_ship_or_a_port(command)!='c')
                {
                    m.do_refuel_commend(command);
                }
                else
                {
                    std::cerr<<"cruiser cant refuel"<<std::endl;
                }
            }
            else if (com=="stop")
            {
                m.do_stop_commend(command);
            }

        }
        else
        {
            std::cerr<<"no command"<<std::endl;
        }
    }
        else
        {
            std::cerr<<"no command"<<std::endl;
        }
}
    else{
    std::cerr<<"no command "<<std::endl;
}
}
Controller::Controller()
{
    view = std::make_unique<View>();
}
void Controller::ran()
{
    while (true)
    {
        std::cout<<"Time "<<m.get_time()<<": enter command"<<std::endl;
        std::string command;
        std::getline(std::cin,command);
        this->prosses_line(command);
    }
}

