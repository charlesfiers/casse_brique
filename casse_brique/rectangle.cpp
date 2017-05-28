/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rectangle.cpp
 * Author: charles
 * 
 * Created on 23 mai 2017, 17:02
 */

#include "rectangle.h"
#include <allegro.h>
#include <iostream>
#include "point.h"
extern BITMAP* buf;
using namespace std;

extern BITMAP *screen;



rectangle::rectangle(point pp1, point pp2):p1(pp1),p2(pp2) {}

rectangle::~rectangle() {}

void rectangle::init(point pp1, point pp2)
{
    p1.init(pp1);
    p2.init(pp2);
}

void rectangle::init(rectangle pr)
{
    init(pr.p1, pr.p2);
}

void rectangle::affiche(int color)
{
    rectfill(buf,p1.getx(),p1.gety(),p2.getx(),p2.gety(),color);
}