/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   balle.cpp
 * Author: root
 * 
 * Created on 27 mai 2017, 14:54
 */

#include "balle.h"
#include <allegro.h>
#include <iostream>
#include "point.h"
#include "math.h"

extern BITMAP* buf;
using namespace std;

extern BITMAP *screen;

balle::balle(point pp1,float r,float ang):centre(pp1) {
    this->rayon = r;
    this->angle = ang;
}

balle::~balle() {
}

void balle::affiche()
{
    circlefill(buf,this->centre.getx(),this->centre.gety(),this->rayon,makecol(255,255,255));
}

float balle::getx(){
    return this->centre.getx();
}

float balle::gety(){
    return this->centre.gety();
}

float balle::getrayon(){
    return this->rayon;
}

float balle::getangle(){
    return this->angle;
}

void balle::setcentre(point pp1){
    this->centre = pp1;
}

void balle::setrayon(float r){
    this->rayon = r;
}

void balle::setangle(float a){
    this->angle = a;
}

void balle::deplacement_balle(){
    float pasx,pasy;
    pasx = 0.1*cos(this->angle);
    pasy = 0.1*(-sin(this->angle));
    point* p = new point(this->getx()+pasx,this->gety()+pasy);
    this->setcentre(*p);
}

void balle::collision_screen(){
    if ((this->getx()>=590) || (this->getx()<=10)) {
        this->majdir2();
    }
    if ((this->gety() <= 10) || (this->gety() >= 690)){
        destroy_bitmap(buf);
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        END_OF_MAIN();
    }

}

void balle::majdir(){
    this->angle = -(this->angle);
}

void balle::majdir2(){
    this->angle = (this->angle)+30;
}