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
#include "raquettes.h"
#include "balle.h"

BITMAP* buf;

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
    point* p1 = new point(250,20);
    point* p2 = new point(350,30);
    
    point* p3 = new point(250,670);
    point* p4 = new point(350,680);
    
    point* c = new point(300,660);
    
    raquettes* r1 = new raquettes(*p1,*p2);
    raquettes* r2 = new raquettes(*p3,*p4);
    
    balle* b1 = new balle(*c,10);
    
    do{
        clear_bitmap(buf);
        r1->affiche();
        r2->affiche();
        b1->affiche();
        blit(buf,screen,0,0,0,0,buf->w,buf->h);
        r1->deplacement();
        r2->deplacement();
        
    }
    while(!key[KEY_ESC]);
    
    destroy_bitmap(buf);
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    
    return 0;
}
END_OF_MAIN();

