/*
** EPITECH PROJECT, 2019
** directory
** File description:
** my_runner
*/

#include "my.h"

sfVector2f sourissprite(sfVector2i vect2i)
{
    sfVector2f vect2f = {0, 0};
    vect2f.x = vect2i.x;
    vect2f.y = vect2i.y;
    return (vect2f);
}

void reduce1(struct prototyp a)
{
    sfSprite_setTexture(a.fond_ecran, a.texture, sfTrue);
    sfText_setString(a.text_hautpage, "My Runner Epitech V1");
    sfText_setString(a.story, "   Ghost Runner");
    sfText_setString(a.play, "Press PLay");
    sfText_setFont(a.text_hautpage, a.font);
    sfText_setFont(a.story, a.stor);
    sfText_setFont(a.play, a.playpolic);
    sfText_setCharacterSize(a.text_hautpage, 50);
    sfText_setCharacterSize(a.story, 120);
    sfText_setCharacterSize(a.play, 200);
    sfText_setColor(a.text_hautpage, sfColor_fromRGB(255, 255, 255));
    sfText_setColor(a.story, sfColor_fromRGB(138, 43, 226));
    sfText_setColor(a.play, sfColor_fromRGB(200, 43, 176));
}

void destroy_fct(struct prototyp a)
{
    sfMusic_destroy(a.music);
    sfText_destroy(a.text_hautpage);
    sfText_destroy(a.play);
    sfText_destroy(a.story);
    sfFont_destroy(a.playpolic);
    sfFont_destroy(a.font);
    sfRenderWindow_destroy(a.window);
}

void fct2(struct prototyp a, sfSprite* cursorsprite)
{
    sfRenderWindow_drawText(a.window, a.text_hautpage, NULL);
    sfRenderWindow_drawText(a.window, a.play, NULL);
    sfRenderWindow_drawText(a.window, a.story, NULL);
    sfRenderWindow_drawSprite(a.window, cursorsprite, NULL);
    sfRenderWindow_display(a.window);
    sfRenderWindow_clear(a.window, sfBlack);
    sfRenderWindow_drawSprite(a.window , a.fond_ecran, NULL);
}

int main(int ac, char **av)
{
    if (ac >= 3)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("Hellx Players !\nHere are the rules :");
        my_putstr("Dxn't hit a wall and an Arrow");
        my_putstr("And the mxst IMPXRTANT thing : HAVE FUN !!");
        my_putstr("PS1 : The maps are in the directory 'Map'");
        my_putstr("PS2 : av[1] = map.txt && every '1' in map == an obstacle");
        return (0);
    }
    char const *filepath = av[1];
    struct stat oct;
    stat(filepath, &oct);
    int size = oct.st_size;
    char *map = malloc(sizeof(char) * size + 1);
    if (map == NULL)
        return 84;
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("No :(\nAv[1] = map.txt !!!!! please");
        return 84;
    }
    int nubr = read(fd, map, size);
    if (nubr == -1)
        return 84;

    struct prototyp a;
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2f titreposition = {740, 000};
    sfVector2f playposition = {500, 705};
    sfVector2f storypos = {160, 428};
    sfVector2f curseur_posit = {1000, 500};
    sfVector2f pos_fant = {810, 100};

    int buffer = 0;
    sfClock *horloge = sfClock_create();
    a.texture = sfTexture_createFromFile("Image/80s.png", NULL);
    a.fond_ecran = sfSprite_create();
    a.window = sfRenderWindow_create(mode, "Error_404", sfResize |
    sfClose, NULL);
    a.font = sfFont_createFromFile("Font/28Later.ttf");
    a.playpolic = sfFont_createFromFile("Font/28Later.ttf");
    a.stor = sfFont_createFromFile("Font/space.ttf");
    a.text_hautpage = sfText_create();
    a.story = sfText_create();
    a.play = sfText_create();
    reduce1(a);
    sfTexture* cursortext = sfTexture_createFromFile("Image/cursorone.png", NULL);
    sfSprite* cursorsprite = sfSprite_create();
    sfSprite_setTexture(cursorsprite, cursortext, sfTrue);
    sfWindow_setMouseCursorVisible((sfWindow *) a.window, sfFalse);
    sfVector2f sca = {1, 1};
    sfSprite_scale(cursorsprite, sca);
    sfSprite_setPosition(cursorsprite, curseur_posit);
    sfText_setPosition(a.text_hautpage, titreposition);
    sfText_setPosition(a.story, storypos);
    sfText_setPosition(a.play, playposition);
    a.vect = sfTexture_createFromFile("layers/fantom1.1.png", NULL);
    a.second = sfTexture_createFromFile("layers/fantom2.2.png", NULL);
    a.third = sfTexture_createFromFile("layers/fantom3.3.png", NULL);
    a.vecteur = sfSprite_create();
    a.music = sfMusic_createFromFile("Music/Lavender.ogg");
    sfMusic_setLoop(a.music, sfTrue);
    sfMusic_play(a.music);

    while (sfRenderWindow_isOpen(a.window)) {
        sfVector2i mouse = sfMouse_getPositionRenderWindow(a.window);
        while (sfRenderWindow_pollEvent(a.window, &a.event)) {
            if (a.event.type == sfEvtClosed)
                sfRenderWindow_close(a.window);
            if (a.event.type == sfEvtMouseMoved) {
                sfVector2f cursor = sourissprite(sfMouse_getPositionRenderWindow(a.window));
                sfSprite_setPosition(cursorsprite, cursor);
            }
            if (a.event.type == sfEvtMouseButtonPressed) {
                if (mouse.x > playposition.x && mouse.x < playposition.x + 950
                && mouse.y > playposition.y && mouse.y < playposition.y + 200) {
                    my_game(a.window, map);
                }
            }
            if (a.event.type == sfEvtClosed ||
                sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(a.window);
        }
        sfSprite_setPosition(a.vecteur, pos_fant);
        sfRenderWindow_drawSprite(a.window, a.vecteur, NULL);
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
        fct2(a, cursorsprite);
    }
    destroy_fct(a);
    return (0);
}