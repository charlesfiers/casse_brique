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



    if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640 , 480, 0, 0)!= 0)
    {
        /* Comme vous avez bien suivi mes explications, vous savez que
        allegro_message s?utilise
        uniquement en mode texte, c?est pour cela que l?on utilise GFX_TEXT, pour ?re
        sur de repasser en mode texte? */
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
    point* p1 = new point(10,10);
    point* p2 = new point(20,20);
    rectangle* r1 = new rectangle(*p1,*p2);
    do{
        clear_bitmap(buf);
        r1->affiche();
        blit(buf,screen,0,0,0,0,buf->w,buf->h);
    }
    while(!key[KEY_ESC]);
    
    destroy_bitmap(buf);
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    
    return 0;
}
END_OF_MAIN();

