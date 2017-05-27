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
#include "../iostream"

using namespace std;

raquettes::raquettes(point pp1, point pp2):rectangle(pp1,pp2){}

raquettes::~raquettes() {}

void raquettes::deplacement(){
    install_mouse();
    point* p = new point((float)mouse_x-50,this->p1.gety());
    float x1,y1;
    x1 = p->getx();
    x1 = x1+100;
    y1 = p->gety();
    y1 = y1+10;
    point* pp = new point(x1,y1);
    this->p1.init(*p);
    this->p2.init(*pp);
}

bool raquettes::collision(float x1, float y1){
    float xmax,xmin,ymax,ymin;
    xmin = this->p1.getx();
    xmax = this->p2.getx();
    ymin = this->p1.gety();
    ymax = this->p2.gety();
    
    if ((x1<=xmax) && (x1>=xmin) && (y1<=ymax) && (y1>=ymin)) {
        return true;
    } else {
        return false;
    }
}

point raquettes::getp1(){
    return p1;
}

point raquettes::getp2(){
    return p2;
}