/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   point.cpp
 * Author: charles
 * 
 * Created on 17 mai 2017, 16:57
 */

#include "point.h"
#include "../math.h"
#include "../iostream"
#include "allegro.h"

using namespace std;

point::point(){
x = 0;
y = 0;
carttopolaire();
}
point::point(float XY){
x = XY;
y = XY;
carttopolaire();
}
point::point(float X, float Y){
x = X;
y = Y;
carttopolaire();
}
point::~point(){
cout << "destructeur" << endl;
}
//void point::initialise()
//{
//cout << endl << "Position en X : ";
//cin >> x;
//cout << endl << "Position en Y : ";
//cin >> y;
//cout << endl;
//carttopolaire();

//}
void point::affiche(){
cout << "(" << x << ", " << y << ")";
cout << "(" << rho << ", " << theta << ")";
}
void point::deplace(float dx, float dy){
x += dx;
y += dy;
carttopolaire();
}
void point::homothetie(float coef){
x *= coef;
y *= coef;
carttopolaire();
}
void point::rotation(float dtheta){
theta += dtheta;
polairetocart();
}
void point::carttopolaire(){
rho = sqrt(x*x + y*y);
theta = atan(y/x);
}
void point::polairetocart(){
x = rho * cos(theta);
y = rho * sin(theta);
}
float point::getx()
{
return x;
}
float point::gety()
{
return y;
}

