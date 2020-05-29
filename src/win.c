/*
** EPITECH PROJECT, 2019
** directory
** File description:
** my_hunter
*/

#include "my.h"

void fct_des_win(struct prototyp a)
{
    sfText_destroy(a.text_hautpage);
    sfText_destroy(a.play);
    sfText_destroy(a.story);
    sfFont_destroy(a.playpolic);
    sfFont_destroy(a.font);
}

void fct1_win(struct prototyp a)
{
    sfRenderWindow_drawText(a.window, a.text_hautpage, NULL);
    sfRenderWindow_drawText(a.window, a.win_text, NULL);
    sfRenderWindow_drawText(a.window, a.play, NULL);
    sfRenderWindow_drawText(a.window, a.story, NULL);
    sfRenderWindow_display(a.window);
    sfRenderWindow_clear(a.window, sfBlack);
    sfRenderWindow_drawSprite(a.window , a.fond_ecran, NULL);
}

void fct_2go_win(struct prototyp a, int number)
{
    sfText_setString(a.text_hautpage, nb_tochar(number));
    sfText_setString(a.story, "Your Score is :");
    sfText_setString(a.play, "Restart Game ?");
    sfText_setString(a.win_text, "You Win");
    sfText_setFont(a.win_text, a.win_font);
    sfText_setFont(a.text_hautpage, a.playpolic);
    sfText_setFont(a.story, a.stor);
    sfText_setFont(a.play, a.playpolic);
    sfText_setCharacterSize(a.text_hautpage, 100);
    sfText_setCharacterSize(a.win_text, 200);
    sfText_setCharacterSize(a.story, 80);
    sfText_setCharacterSize(a.play, 100);
    sfText_setColor(a.text_hautpage, sfColor_fromRGB(255, 255, 255));
    sfText_setColor(a.story, sfColor_fromRGB(138, 43, 226));
    sfText_setColor(a.play, sfColor_fromRGB(200, 43, 176));
}

int win(int number, char *map)
{
    struct prototyp a;
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2f resultscore = {1200, 000};
    sfVector2f playposition = {580, 805};
    sfVector2f win_positi = {450, 455};
    sfVector2f storypos = {650, 0};
    a.texture = sfTexture_createFromFile("Image/win_image.jpg", NULL);
    a.fond_ecran = sfSprite_create();
    sfSprite_setTexture(a.fond_ecran, a.texture, sfTrue);
    a.window = sfRenderWindow_create(mode, "WIN", sfResize |
    sfClose, NULL);
    a.font = sfFont_createFromFile("Font/game_over.ttf");
    a.playpolic = sfFont_createFromFile("Font/horrendo.ttf");
    a.stor = sfFont_createFromFile("Font/horrendo.ttf");
    a.win_font = sfFont_createFromFile("Font/Insomnia.ttf");
    a.text_hautpage = sfText_create();
    a.story = sfText_create();
    a.play = sfText_create();
    a.win_text = sfText_create();
    sfText_setPosition(a.win_text, win_positi);
    sfText_setPosition(a.text_hautpage, resultscore);
    sfText_setPosition(a.story, storypos);
    sfText_setPosition(a.play, playposition);
    fct_2go_win(a, number);

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
        fct1_win(a);
    }
    fct_des_win(a);
    return (0);
}