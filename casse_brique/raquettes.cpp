/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   raquettes.cpp
 * Author: root
 * 
 * Created on 27 mai 2017, 15:28
 */


#include "raquettes.h"
#include "rectangle.h"
#include "point.h"
#include <allegro.h>

raquettes::raquettes(point pp1, point pp2):rectangle(pp1,pp2){}

raquettes::~raquettes() {}

void raquettes::deplacement(){
    install_mouse();
    point* p = new point((float)mouse_x,this->p1.gety());
    this->p1.init(*p);
    float x1,y1;
    x1 = p->getx();
    x1 = x1+100;
    y1 = p->gety();
    y1 = y1+10;
    point* pp = new point(x1,y1);
    this->p2.init(*pp);
}

