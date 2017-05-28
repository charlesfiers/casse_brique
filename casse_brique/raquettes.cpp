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
#include "balle.h"
#include "math.h"

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

void raquettes::collision1(balle* bal){
    float xmax,xmin,ymax,ymin,x1,y1,xinter1,xinter2;
    balle* b =new balle();
    b = bal;
    xmin = this->p1.getx();
    xmax = this->p2.getx();
    ymin = this->p1.gety();
    ymax = this->p2.gety();
    xinter1 = this->p1.getx()+25;
    xinter2 = this->p2.getx()-25;
    
    x1 = b->getx();
    y1 = b->gety()-10;
    
    if (((x1<=xmax) && (x1>=xinter2)) && (y1<=ymax) && (y1>=ymin)) {
        if (b->getangle()==M_PI/3) {
            b->setangle(M_PI/4);
        }
        if (b->getangle()==2*M_PI/3) {
            b->setangle(3*M_PI/4);
        }
        b->majdir();
    }
    
    if (((x1>=xmin) && (x1<=xinter1)) && (y1<=ymax) && (y1>=ymin)) {
        if (b->getangle()==M_PI/3) {
            b->setangle(M_PI/4);
        }
        if (b->getangle()==2*M_PI/3) {
            b->setangle(3*M_PI/4);
        }
        b->majdir();
    }
    
    if ((x1>xinter1) && (x1<xinter2) && (y1<=ymax) && (y1>=ymin)) {
        if (b->getangle()==M_PI/4) {
            b->setangle(M_PI/3);
        }
        if (b->getangle()==3*M_PI/4) {
            b->setangle(2*M_PI/3);
        }
        b->majdir();
    }
}

void raquettes::collision2(balle* bal){
    float xmax,xmin,ymax,ymin,x1,y1,xinter1,xinter2;
    balle* b =new balle();
    b = bal;
    xmin = this->p1.getx();
    xmax = this->p2.getx();
    ymin = this->p1.gety();
    ymax = this->p2.gety();
    xinter1 = this->p1.getx()+25;
    xinter2 = this->p2.getx()-25;
    
    x1 = b->getx();
    y1 = b->gety()+10;
    
    
    if (((x1<=xmax) && (x1>=xinter2)) && (y1<=ymax) && (y1>=ymin)) {
        if (b->getangle()==5*M_PI/3) {
            b->setangle(7*M_PI/4);
        }
        if (b->getangle()==4*M_PI/3) {
            b->setangle(5*M_PI/4);
        }
        b->majdir();
    }
    
    if (((x1>=xmin) && (x1<=xinter1)) && (y1<=ymax) && (y1>=ymin)) {
        if (b->getangle()==5*M_PI/3) {
            b->setangle(7*M_PI/4);
        }
        if (b->getangle()==4*M_PI/3) {
            b->setangle(5*M_PI/4);
        }
        b->majdir();
    }
    
    if ((x1>xinter1) && (x1<xinter2) && (y1<=ymax) && (y1>=ymin)) {
        if (b->getangle()==5*M_PI/4) {
            b->setangle(2*M_PI/3);
        }
        if (b->getangle()==7*M_PI/4) {
            b->setangle(M_PI/3);
        }
        b->majdir();
    }
}

point raquettes::getp1(){
    return p1;
}

point raquettes::getp2(){
    return p2;
}