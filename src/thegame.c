/*
** EPITECH PROJECT, 2019
** directory
** File description:
** Lejeu
*/

#include "my.h"

void destroy(struct prototyp a)
{
    sfMusic_destroy(a.music_saut);
    sfSprite_destroy(a.fond_ecran);
    sfSprite_destroy(a.vecteur);
    sfTexture_destroy(a.vect);
    sfTexture_destroy(a.texture);
    sfTexture_destroy(a.texture2);
    sfTexture_destroy(a.texture3);
    sfTexture_destroy(a.texture2_1);
    sfText_destroy(a.text_hautpage);
    sfFont_destroy(a.font);
}

void reduc(sfRenderWindow* window, struct prototyp a)
{
    sfRenderWindow_display(window);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, a.fond_ecran, NULL);
    sfRenderWindow_drawSprite(window, a.fond_ecran, NULL);
    sfRenderWindow_drawSprite(window, a.fond_ecran2, NULL);
    sfRenderWindow_drawSprite(window, a.fond_ecran2_1, NULL);
    sfRenderWindow_drawSprite(window, a.fond_ecran3, NULL);
    sfRenderWindow_drawSprite(window, a.obstacle, NULL);
}

void textur(struct prototyp a)
{
    sfSprite_setTexture(a.fond_ecran, a.texture, sfTrue);
    sfSprite_setTexture(a.fond_ecran2, a.texture2, sfTrue);
    sfSprite_setTexture(a.fond_ecran3, a.texture3, sfTrue);
    sfSprite_setTexture(a.fond_ecran2_1, a.texture2_1, sfTrue);
    sfSprite_setTexture(a.obstacle, a.texture_obstacle, sfTrue);
    sfSprite_setTexture(a.ghost_sprite, a.ghost_textu, sfTrue);
}

int my_game(sfRenderWindow* window, char *map)
{
    struct prototyp a;
    sfVector2f score = {275, 010};
    sfVector2f vievect = {1850, 000};
    sfVector2f vievectext = {1600, 00};
    sfClock *horloge = sfClock_create();
    int buffer = 0;
    int buffer2 = 0;
    int down = 0;
    float number = 0;
    int intvie = 1;
    sfVector2f pos = {100, 790};
    sfVector2f pos_ghost = {2000, 500};
    sfVector2f pos_obstacle = {2500, 800};
    sfVector2f pos_txt3 = {0, 0};
    sfVector2f pos_txt2 = {0, 0};
    sfVector2f pos_txt2_1 = {0, 0};
    sfVector2f pos_txt = {0, 0};
    sfClock *rect_clock = sfClock_create();
    sfClock *rect_clock_2 = sfClock_create();
    sfClock *rect_clock_21 = sfClock_create();
    sfClock *rect_clock_3 = sfClock_create();
    a.vect = sfTexture_createFromFile("Image/fantom1.png", NULL);
    a.second = sfTexture_createFromFile("Image/fantom2.png", NULL);
    a.third = sfTexture_createFromFile("Image/fantom3.png", NULL);
    a.vecteur = sfSprite_create();
    a.ghost_textu = sfTexture_createFromFile("Image/arrow2.png", NULL);
    a.ghost_sprite = sfSprite_create();
    a.texture = sfTexture_createFromFile("layers/7.png", NULL);
    a.texture2 = sfTexture_createFromFile("layers/4.png", NULL);
    a.texture2_1 = sfTexture_createFromFile("layers/2.png", NULL);
    a.texture3 = sfTexture_createFromFile("layers/1.png", NULL);
    a.texture_obstacle = sfTexture_createFromFile("layers/chinese.png", NULL);
    a.fond_ecran = sfSprite_create();
    a.fond_ecran2 = sfSprite_create();
    a.fond_ecran2_1 = sfSprite_create();
    a.fond_ecran3 = sfSprite_create();
    a.obstacle = sfSprite_create();
    textur(a);
    a.font = sfFont_createFromFile("Font/horrendo.ttf");
    a.text_hautpage = sfText_create();
    sfText_setString(a.text_hautpage, "Distance : ");
    sfText_setFont(a.text_hautpage, a.font);
    sfText_setCharacterSize(a.text_hautpage, 50);
    sfText_setColor(a.text_hautpage, sfBlack);
    a.viefont = sfFont_createFromFile("Font/viefontlol.ttf");
    a.vie = sfText_create();
    sfText_setString(a.vie, nb_tochar(intvie));
    sfText_setFont(a.vie, a.viefont);
    sfText_setPosition(a.vie, vievect);
    sfText_setCharacterSize(a.vie, 100);
    sfText_setColor(a.vie, sfColor_fromRGB(148, 0, 211));
    a.points = sfText_create();
    sfText_setFont(a.points, a.font);
    sfText_setCharacterSize(a.points, 55);
    sfText_setString(a.points, nb_tochar(number));
    sfText_setPosition(a.points, score);
    sfText_setColor(a.points, sfColor_fromRGB(255, 255, 255));
    a.vietext = sfText_create();
    sfText_setFont(a.vietext, a.viefont);
    sfText_setCharacterSize(a.vietext, 90);
    sfText_setString(a.vietext, "Life :");
    sfText_setPosition(a.vietext, vievectext);
    sfText_setColor(a.vietext, sfColor_fromRGB(255, 255, 255));
    a.music_saut = sfMusic_createFromFile("Music/FX.ogg");
    sfRenderWindow_setFramerateLimit(window, 60);
    int m = 0;
    for (int z = 0; map[z] != '\0'; z++) {
        if (map[z] == '1')
            m++;
    }
    if (m == 0)
        m = 200000;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &a.event)) {
            if (a.event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(window);
            if (a.event.type == sfEvtKeyPressed &&
            a.event.key.code == sfKeySpace)
                buffer2 = 1;
        }
        if (intvie == 0) {
            gameover(number, map);
            destroy(a);
            return (0);
        }
        if (number >= 50)
            sfText_setColor(a.points, sfColor_fromRGB(255, 165, 0));
        if (number >= 100)
            sfText_setColor(a.points, sfColor_fromRGB(255, 0, 0));
        sfRenderWindow_drawText(window, a.points, NULL);
        sfRenderWindow_drawText(window, a.text_hautpage, NULL);
        sfRenderWindow_drawText(window, a.vie, NULL);
        sfRenderWindow_drawText(window, a.vietext, NULL);
        sfSprite_setPosition(a.obstacle, pos_obstacle);

        if (m != 0) {
            pos_obstacle.x = pos_obstacle.x - 15;
            if (pos_obstacle.x < -1050) {
                pos_obstacle.x = 2000;
                m--;
            }
            pos_ghost.x = pos_ghost.x - 30;
            if (pos_ghost.x < -1550) {
                pos_ghost.x = 5000;
                pos_ghost.y = rand() % 1000;
            }
        }
        if (m == 0) {
            win(number, map);
            destroy(a);
            return (0);
        }
        for (int i = 0; i < 10; i++) {
            number = number + 0.005;
            sfText_setString(a.points, nb_tochar(number));
        }
        sfSprite_setPosition(a.fond_ecran, pos_txt);
        sfSprite_setPosition(a.fond_ecran2, pos_txt2);
        sfSprite_setPosition(a.fond_ecran2_1, pos_txt2_1);
        sfSprite_setPosition(a.fond_ecran3, pos_txt3);
        reduc(window, a);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(rect_clock)) > 10) {
            pos_txt3.x -= 15;
            if (pos_txt3.x == -1920)
                pos_txt3.x = 0;
            sfClock_restart(rect_clock);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(rect_clock_2)) > 10) {
            pos_txt2.x -= 3;
            if (pos_txt2.x < -1920)
                pos_txt2.x = 0;
            sfClock_restart(rect_clock_2);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(rect_clock_21)) > 10) {
            pos_txt2_1.x -= 4;
            if (pos_txt2_1.x < -1920)
                pos_txt2_1.x = 0;
            sfClock_restart(rect_clock_21);
        }
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(rect_clock_3)) > 10) {
            pos_txt.x -= 1;
            if (pos_txt.x < -1920)
                pos_txt.x = 0;
            sfClock_restart(rect_clock_3);
        }
        if (buffer2 == 1) {
            if (pos.y != 490 && down == 0) {
                pos.y -= 12;
                if (sfTime_asMilliseconds(sfClock_getElapsedTime(horloge)) > 1)
                    sfClock_restart(horloge);
            }
            else if (pos.y == 490 && down == 0)
                down = 1;
            else if (pos.y != 790 && down == 1)
                pos.y += 10;
            else {
                buffer2 = 0;
                down = 0;
            }
        }
        sfSprite_setPosition(a.vecteur, pos);
        sfSprite_setPosition(a.ghost_sprite, pos_ghost);
        sfSprite_getPosition(a.obstacle);
        sfSprite_getPosition(a.vecteur);
        sfSprite_getPosition(a.ghost_sprite);
        if (pos_obstacle.x > pos.x - 100 && pos_obstacle.x < pos.x + 100
        && pos_obstacle.y > pos.y - 50 && pos_obstacle.y < pos.y + 120) {
            intvie = intvie - 1;
            sfMusic_play(a.music_saut);
        }
        if (pos_ghost.x > pos.x-10 && pos_ghost.x < pos.x + 100
        && pos_ghost.y > pos.y-100 && pos_ghost.y < pos.y + 100) {
            intvie = intvie - 1;
            sfMusic_play(a.music_saut);
        }
        sfRenderWindow_drawSprite(window, a.vecteur, NULL);
        sfRenderWindow_drawSprite(window, a.ghost_sprite, NULL);
        if (sfTime_asSeconds(sfClock_getElapsedTime(horloge)) >= 0.3) {
            if (buffer == 0) {
                sfSprite_setTexture(a.vecteur, a.vect, sfTrue);
                buffer = buffer + 1;
            }
            else if (buffer == 1) {
                sfSprite_setTexture(a.vecteur, a.second, sfTrue);
                buffer = buffer + 2;
            }
            else if (buffer == 3) {
                sfSprite_setTexture(a.vecteur, a.third, sfTrue);
                buffer = 0;
            }
            sfClock_restart(horloge);
        }
    }
    destroy(a);
    return 0;
}