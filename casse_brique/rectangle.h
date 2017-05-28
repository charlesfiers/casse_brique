/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rectangle.h
 * Author: charles
 *
 * Created on 23 mai 2017, 17:02
 */

#pragma once

#include "point.h"
#include <allegro.h>

class rectangle
{
protected:
    point p1, p2;
    int compteur;

public:
    rectangle(point, point);
    virtual ~rectangle();
    void init(point, point);
    void init(rectangle);
    void collision(int, int);
    void casse();
    virtual void affiche(int);
};

