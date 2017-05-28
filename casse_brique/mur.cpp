/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mur.cpp
 * Author: root
 * 
 * Created on 28 mai 2017, 12:08
 */

#include "mur.h"
#include "brique.h"
#include "rectangle.h"
#include "point.h"
#include "stdlib.h"
#include "time.h"

mur::mur() {
    srand(time(NULL));
    int pos_x, pos_y;
    nbvisi=0;
    pos_x = 40;
    pos_y = 300;
    point* pp1 = new point(pos_x,pos_y);
    point* pp2 = new point(pos_x+50,pos_y+25);
    for(int i=1;i<30;i++){
        tab[i] = new brique(*pp1,*pp2);
        pos_x += 52;
        if (pos_x>510) {
            pos_x = 40;
            pos_y += 35;
        }
        int rnd = rand() % 5;
        if (rnd == 0) {
            tab[i]->setvisi(false);
        } else {
            tab[i]->setvisi(true);
            nbvisi++;
        }
        pp1->init(pos_x,pos_y);
        pp2->init(pos_x+50,pos_y+25);
    }
}

mur::~mur() {
}

brique* mur::gettab(int i){
    return tab[i];
}

brique mur::gettab2(int i){
    return *tab[i];
}

