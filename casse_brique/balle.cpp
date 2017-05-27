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
extern BITMAP* buf;
using namespace std;

extern BITMAP *screen;

balle::balle(point pp1,float r):centre(pp1) {
    this->rayon = r;
}

balle::~balle() {
}

void balle::affiche()
{
    circlefill(buf,centre.getx(),centre.gety(),rayon,makecol(255,255,255));
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

int balle::getdir(){
    return this->dir;
}

void balle::setcentre(point pp1){
    this->centre = pp1;
}

void balle::setrayon(float r){
    this->rayon = r;
}

void balle::setdir(int d){
    this->dir = d;
}