/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mur.h
 * Author: root
 *
 * Created on 28 mai 2017, 12:08
 */

#pragma once

#include "point.h"
#include "mur.h"
#include "brique.h"
#include "balle.h"
#include "rectangle.h"
#include <allegro.h>

class mur{
public:
    mur();
    int nbvisi;
    brique* tab[30];  
    virtual ~mur();
    brique* gettab(int);
    brique gettab2(int);   
};


