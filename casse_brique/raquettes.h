/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   raquettes.h
 * Author: root
 *
 * Created on 27 mai 2017, 15:28
 */

#pragma once

#include "point.h"
#include "balle.h"
#include "rectangle.h"
#include <allegro.h>

class raquettes : public rectangle {
    
public:
    raquettes(point,point);
    virtual ~raquettes();
    void deplacement();
    void collision1(balle*);
    void collision2(balle*);
    point getp1();
    point getp2();
};


