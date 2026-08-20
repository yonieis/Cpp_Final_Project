//
// Created by yonat on 08/02/2026.
//

#include "View.h"
View::View()
{
    x_to_start=0;
    y_to_start=0;
    line_to_show=25;
    scale=2;
}

void View::change_line_to_show(int line_to_show)
{
    if (30>=line_to_show&&line_to_show>=6)
    this->line_to_show=line_to_show;
}
void View::change_scale(int scale)
{
    this->scale=scale;
}
void View::change_start_pos(int x, int y)
{
    this->x_to_start=x;
    this->y_to_start=y;
}

void View::show()
{
    Model & m=Model:: get_instance();

for (int i=0;i<line_to_show;i++)
{
    if ((line_to_show-1-i)%3==0)
    {

        std::cout<<(y_to_start+(line_to_show-1)*scale-i*scale);
    }
    std::cout<<"\t";
    for (int j=0;j<line_to_show;j++)
    {
       std::cout<< m.get_all_ships_and_ports_in_scale(scale,x_to_start+j*scale,y_to_start+(line_to_show-1)*scale-i*scale);
    }
    std::cout<<std::endl;
}
    std::cout<<"   ";
    for (int i=0;i<line_to_show;i++)
    {
        if ((i)%3==0)
        {
            std::cout<<std::setw(6)<<x_to_start+i*scale;
        }
    }
    std::cout<<std::endl;
}
