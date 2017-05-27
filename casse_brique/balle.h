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
    float rayon;
    int dir;
public:
    balle(point, float);
    ~balle();
    float getx();
    float gety();
    float getrayon();
    int getdir();
    void setcentre(point);
    void setrayon(float);
    void setdir(int);
    virtual void affiche();
    void deplacement_balle();
};


