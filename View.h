//
// Created by yonat on 08/02/2026.
//

#ifndef UNTITLED5_VIEW_H
#define UNTITLED5_VIEW_H
#include "Model.h"

class View
{
    private:
    int line_to_show ;
    int scale;
    int x_to_start;
    int y_to_start;

    public:
    View();
    ~View()=default;
    void show();
    void change_scale(int scale);
    void change_line_to_show(int line_to_show);
    void change_start_pos(int x,int y);
};

#endif //UNTITLED5_VIEW_H