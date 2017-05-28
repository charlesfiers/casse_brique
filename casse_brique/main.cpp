/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: charles
 *
 * Created on 17 mai 2017, 18:01
 */

#include <allegro.h>

#include "rectangle.h"
#include "mur.h"
#include "point.h"
#include "raquettes.h"
#include "balle.h"
#include "../iostream"
#include "math.h"

BITMAP* buf;

using namespace std;

void init_window()
{
    allegro_init();
    install_keyboard();
    if (install_mouse()==-1)
    {
        allegro_message("Erreur : %s\n",allegro_error);
        return;
    }
    set_color_depth(16);



    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600 , 700, 0, 0)!= 0)
    {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0); /* voil?la commande pour le mode texte */
        allegro_message("Impossible d?initialiser le mode vid? !\n%s\n", allegro_error);
        return; //et on oublie pas de quitter?
    }
    set_mouse_sprite(NULL);
    set_keyboard_rate(0,0);

    buf = create_bitmap(SCREEN_W,SCREEN_H);
    if(!buf)
    {
        allegro_message("Probleme BITMAP");
        allegro_exit();
        return;
    }
}

int main(){
    init_window();
    mur* m = new mur();
    point* p1 = new point(250,20);
    point* p2 = new point(350,30);
    
    point* p3 = new point(250,670);
    point* p4 = new point(350,680);
    
    point* c = new point(300,660);
    
    raquettes* r1 = new raquettes(*p1,*p2);
    raquettes* r2 = new raquettes(*p3,*p4);
    
    balle* b1 = new balle(*c,10,M_PI/3);
    do{
        clear_bitmap(buf);
        int i=0;
        r1->affiche(makecol(255,0,0));
        r2->affiche(makecol(255,0,0));
        b1->affiche(makecol(255,255,255));
        r1->deplacement();
        r2->deplacement();
        point* p = new point(r2->getp1().getx()+50,r2->getp2().gety()-20);
        b1->setcentre(*p);
        while(i<30){
            if (m->gettab(i)->getvisi()==true) {
                m->gettab2(i).affiche(makecol(0,230,0));
            }
            i++;
        }
        textout_centre_ex(buf,font, "Cliquez pour commencer", 300, 350,makecol(255,255,255),makecol(0,0,0));
        textout_centre_ex(buf,font, "ESC pour quitter", 300, 400,makecol(255,255,255),makecol(0,0,0));
        blit(buf,screen,0,0,0,0,buf->w,buf->h);
    }
    while(!(mouse_b & 1) && !(key[KEY_ESC]));
    
    do{
        int i=0;
        clear_bitmap(buf);
        r1->affiche(makecol(255,0,0));
        r2->affiche(makecol(255,0,0));
        while(i<30){
            if (m->gettab(i)->getvisi()==true) {
                m->nbvisi = m->gettab(i)->collision_mur(b1,m->gettab(i),m->nbvisi);
                m->gettab2(i).affiche(makecol(0,240,0));
            }
            i++;
        }
        b1->affiche(makecol(255,255,255));
        blit(buf,screen,0,0,0,0,buf->w,buf->h);
        r1->deplacement();
        r2->deplacement();
        for(int i=1; i<=10;i++){
            b1->deplacement_balle();
            r1->collision1(b1);
            r2->collision2(b1);           
            b1->collision_screen();
        }
    }
    while((!key[KEY_ESC]) && (m->nbvisi!=0)); 
    
    
    destroy_bitmap(buf);
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    
    return 0;
}
END_OF_MAIN();

