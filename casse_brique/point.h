/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   point.h
 * Author: charles
 *
 * Created on 17 mai 2017, 16:57
 */

#ifndef POINT_H
#define POINT_H

class point {
protected:
float x,y;
float rho,theta; 
void majpol();
void majcart();
public:
//surdéfinition du constructeur : c'est le nombre et le type qui permettent de définir une surdéfinition.
point();
point(float);
point(float,float);
~point();
void affiche();
void init(point);
void init(float,float);
void deplace(float,float);
void homothetie(float);
void rotation(float);
void carttopolaire();
void polairetocart();
float getx();
float gety();
};

#endif /* POINT_H */

