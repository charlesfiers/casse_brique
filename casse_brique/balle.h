/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   balle.h
 * Author: root
 *
 * Created on 27 mai 2017, 14:54
 */

#pragma once

#include "point.h"
#include <allegro.h>

class balle 
{
protected:
    point centre;
    float rayon,angle;
public:
    balle(point, float,float);
    ~balle();
    float getx();
    float gety();
    float getrayon();
    float getangle();
    void setcentre(point);
    void setrayon(float);
    void setangle(float);
    virtual void affiche();
    void deplacement_balle();
    void majdir();
    void majdir2();
    void collision_screen();
};


