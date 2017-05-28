/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   brique.h
 * Author: root
 *
 * Created on 28 mai 2017, 11:58
 */

#pragma once

#include "point.h"
#include "brique.h"
#include "balle.h"
#include "rectangle.h"
#include <allegro.h>


class brique : public rectangle {
protected:
    bool visi;
public:
    brique(point,point);
    virtual ~brique();
    bool getvisi();
    void setvisi(bool);
    void collision_mur(balle*,brique*);
};

