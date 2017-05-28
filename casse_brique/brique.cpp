/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   brique.cpp
 * Author: root
 * 
 * Created on 28 mai 2017, 11:58
 */

#include "brique.h"
#include "rectangle.h"
#include "point.h"
#include "balle.h"
#include "iostream"
#include "mur.h"

using namespace std;


brique::brique(point pp1, point pp2):rectangle(pp1,pp2) {
}

brique::~brique() {
}

void brique::setvisi(bool v){
    this->visi = v;
}

bool brique::getvisi(){
    return visi;
}

int brique::collision_mur(balle* b1, brique* br,int n){
    float x1,y1,x2,y2,x3,y3,x4,y4,xmax,xmin,ymax,ymin;
    
    xmin = this->p1.getx();
    xmax = this->p2.getx();
    ymin = this->p1.gety();
    ymax = this->p2.gety();
    
    balle* b = new balle(xmin,0,0);
    brique* brik = new brique(ymax,xmax);
    b = b1;
    brik = br;  

    // 1 : point en haut de la balle
    x1 = b->getx();
    y1 = b->gety()-10;
    
    // 2 : point en bas de la balle
    x2 = b->getx();
    y2 = b->gety()+10;
    
    // 3 : point à gauche de la balle
    x3 = b->getx()-10;
    y3 = b->gety();
    
    // 4 : point à droite de la balle
    x4 = b->getx()+10;
    y4 = b->gety();
    
    if ((x1<=xmax) && (x1>=xmin) && (y1>=ymin) && (y1<=ymax)) {
        cout << "Colision 1" << endl;
        cout << "Avant" <<  this->getvisi() << endl;
        brik->setvisi(false);
        n--;
        cout << "Après" <<  this->getvisi() << endl;
        b->majdir();
    }
    if ((x2<=xmax) && (x2>=xmin) && (y2>=ymin) && (y2<=ymax)) {
        cout << "Colision 2" << endl;
        brik->setvisi(false);
        n--;
        b->majdir();
    }
    if ((x3<=xmax) && (x3>=xmin) && (y3>=ymin) && (y3<=ymax)) {
        cout << "Colision 3" << endl;
        brik->setvisi(false);
        n--;
        b->majdir2();
    }
    if ((x4<=xmax) && (x4>=xmin) && (y4>=ymin) && (y4<=ymax)) {
        cout << "Colision 4" << endl;
        brik->setvisi(false);
        n--;
        b->majdir2();
    }
    return n;
}