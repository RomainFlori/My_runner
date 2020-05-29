/*
** EPITECH PROJECT, 2019
** directory
** File description:
** my_hunter
*/

#include "my.h"

void fct_des(struct prototyp a)
{
    sfText_destroy(a.text_hautpage);
    sfText_destroy(a.play);
    sfText_destroy(a.story);
    sfFont_destroy(a.playpolic);
    sfFont_destroy(a.font);
}

void fct1(struct prototyp a)
{
    sfRenderWindow_drawText(a.window, a.text_hautpage, NULL);
    sfRenderWindow_drawText(a.window, a.play, NULL);
    sfRenderWindow_drawText(a.window, a.story, NULL);
    sfRenderWindow_display(a.window);
    sfRenderWindow_clear(a.window, sfBlack);
    sfRenderWindow_drawSprite(a.window , a.fond_ecran, NULL);
}

void fct_2go(struct prototyp a, int number)
{
    sfText_setString(a.text_hautpage, nb_tochar(number));
    sfText_setString(a.story, "Your Score is :");
    sfText_setString(a.play, "Restart Game ?");
    sfText_setFont(a.text_hautpage, a.playpolic);
    sfText_setFont(a.story, a.playpolic);
    sfText_setFont(a.play, a.stor);
    sfText_setCharacterSize(a.text_hautpage, 100);
    sfText_setCharacterSize(a.story, 100);
    sfText_setCharacterSize(a.play, 130);
    sfText_setColor(a.text_hautpage, sfColor_fromRGB(255, 255, 255));
    sfText_setColor(a.story, sfColor_fromRGB(255, 255, 255));
    sfText_setColor(a.play, sfColor_fromRGB(213, 121, 251));
}

int gameover(int number, char *map)
{
    struct prototyp a;
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2f resultscore = {1180, 015};
    sfVector2f playposition = {460, 825};
    sfVector2f storypos = {500, 0};
    a.texture = sfTexture_createFromFile("Image/gm.png", NULL);
    a.fond_ecran = sfSprite_create();
    sfSprite_setTexture(a.fond_ecran, a.texture, sfTrue);
    a.window = sfRenderWindow_create(mode, "Game Over", sfResize |
    sfClose, NULL);
    a.font = sfFont_createFromFile("Font/game_over.ttf");
    a.playpolic = sfFont_createFromFile("Font/Numbers.ttf");
    a.stor = sfFont_createFromFile("Font/horrendo.ttf");
    a.text_hautpage = sfText_create();
    a.story = sfText_create();
    a.play = sfText_create();
    sfText_setPosition(a.text_hautpage, resultscore);
    sfText_setPosition(a.story, storypos);
    sfText_setPosition(a.play, playposition);
    fct_2go(a, number);

    while (sfRenderWindow_isOpen(a.window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(a.window);
        while (sfRenderWindow_pollEvent(a.window, &a.event)) {
            if (a.event.type == sfEvtClosed)
                sfRenderWindow_close(a.window);
            if (a.event.type == sfEvtMouseButtonPressed) {
                if (mouse.x > playposition.x && mouse.x < playposition.x + 950
                && mouse.y > playposition.y && mouse.y < playposition.y + 600) {
                    my_game(a.window, map);
                }
            }
            if (a.event.type == sfEvtClosed ||
                sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(a.window);
        }
        fct1(a);
    }
    fct_des(a);
    return (0);
}