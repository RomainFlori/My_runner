/*
** EPITECH PROJECT, 2019
** directory
** File description:
** my
*/

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>

int main(int ac, char **av);
int my_game(sfRenderWindow* window, char *map);
int gameover(int number, char *map);
int win(int number, char *map);//la
char *nb_tochar(int i);
int my_putstr(char const *str);
void my_putchar(char c);
sfVector2f sourissprite(sfVector2i vect2i);

struct prototyp {
    sfMusic* music;
    sfMusic* music_saut;
    sfRenderWindow* window;
    sfTexture* ghost_textu; // new
    sfTexture* texture;
    sfTexture* texture2;
    sfTexture* texture3;
    sfTexture* texture2_1;
    sfTexture* texture_obstacle;
    sfTexture* vect;
    sfSprite* fond_ecran;
    sfSprite* fond_ecran2;
    sfSprite* fond_ecran2_1;
    sfSprite* fond_ecran3;
    sfSprite* obstacle;
    sfSprite* vecteur;
    sfSprite* ghost_sprite;//llaaa
    sfFont* font;
    sfFont* viefont;
    sfFont* playpolic;
    sfFont* stor;
    sfFont* win_font;
    sfText* text_hautpage;
    sfText* story;
    sfText* play;
    sfEvent event;
    sfTexture* second;
    sfTexture* third;
    sfText* points;
    sfText* vie;
    sfText* vietext;
    sfText* win_text;
};