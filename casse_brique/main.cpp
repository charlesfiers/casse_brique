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

int main(){
    int x=0,y=0;
    bool ok= false;
    
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode( GFX_AUTODETECT, 800 , 600, 0, 0);

    while(key[KEY_ESC]==0)
    {

       if(key[KEY_A]!=0)
        {
            if (ok==false)
            {
                clear_bitmap(screen);
                textprintf_ex(screen, font, x, y, makecol(255, 0, 0), makecol(0, 0, 0), "Je t'aime Ugo ");
                ok = true;
            }
            else
            {
                clear_bitmap(screen);
                textprintf_ex(screen, font, x, y, makecol(255, 0, 0), makecol(0, 0, 0), "Je t'aime Sahag ");
                ok = false;

            }


       }
    }

    return 0;
}
END_OF_MAIN();

