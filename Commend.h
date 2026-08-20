//
// Created by yonat on 20/02/2026.
//

#ifndef UNTITLED5_COMMEND_H
#define UNTITLED5_COMMEND_H
#include <string>

class Commend
{
private:

    char type;
    std::string name_of_target;
    double x;
    double y;
    double speed;
    double deg;
    int unload;


public:
    Commend(char type);
    Commend(char type, std::string name_of_target, double x, double y, double speed);
    Commend(char type, double x, double y,double speed);
    Commend(char type,std::string name_of_target);
    Commend(char type,std::string name ,double unload);
    Commend(char type,double deg,double speed );
    double get_x();
    double get_y();
    double get_speed();
    double get_deg();
    int get_unload();
    std::string get_name_of_target();
    char get_type();
    ~Commend()=default;
};
#endif //UNTITLED5_COMMEND_H