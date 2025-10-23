/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** update_colors
*/

#include "my.h"

static int condition_mouse(global_t *glob, int i, int j)
{
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if ((MOUSE.x >= glob->my_int->length_one[i] &&
        MOUSE.x <= glob->my_int->length_two[i]) &&
        (MOUSE.y >= glob->my_int->width_one[j] &&
        MOUSE.y <= glob->my_int->width_two[j])
        && PRESSED(sfMouseLeft))
        return 1;
    return 0;
}

void handle_palette_colors(global_t *glob)
{
    int i = 0;
    int j = 0;
    int c = 0;
    sfColor pixelColor;

    while (c < 31) {
        if (condition_mouse(glob, i, j) == 1) {
            pixelColor = sfImage_getPixel(MYPAINT->background->image,
            MOUSE.x, MOUSE.y);
            RED = pixelColor.r;
            GREEN = pixelColor.g;
            BLUE = pixelColor.b;
        }
        i++;
        if (c == 10 || c == 20) {
            i = 0;
            j++;
        }
        c++;
    }
}

static void length_one(global_t *glob)
{
    glob->my_int->length_one[0] = 1790;
    glob->my_int->length_one[1] = 1750;
    glob->my_int->length_one[2] = 1706;
    glob->my_int->length_one[3] = 1670;
    glob->my_int->length_one[4] = 1636;
    glob->my_int->length_one[5] = 1595;
    glob->my_int->length_one[6] = 1555;
    glob->my_int->length_one[7] = 1510;
    glob->my_int->length_one[8] = 1477;
    glob->my_int->length_one[9] = 1436;
    glob->my_int->length_one[10] = 0;
}

static void length_two(global_t *glob)
{
    glob->my_int->length_two[0] = 1817;
    glob->my_int->length_two[1] = 1770;
    glob->my_int->length_two[2] = 1739;
    glob->my_int->length_two[3] = 1710;
    glob->my_int->length_two[4] = 1662;
    glob->my_int->length_two[5] = 1628;
    glob->my_int->length_two[6] = 1582;
    glob->my_int->length_two[7] = 1545;
    glob->my_int->length_two[8] = 1504;
    glob->my_int->length_two[9] = 1467;
    glob->my_int->length_two[10] = 0;
}

void width_one(global_t *glob)
{
    glob->my_int->width_one[0] = 37;
    glob->my_int->width_one[1] = 80;
    glob->my_int->width_one[2] = 110;
    glob->my_int->width_one[3] = 0;
}

void width_two(global_t *glob)
{
    glob->my_int->width_two[0] = 60;
    glob->my_int->width_two[1] = 97;
    glob->my_int->width_two[2] = 137;
    glob->my_int->width_two[3] = 0;
}

void init_color(global_t *glob)
{
    glob->my_int = malloc(sizeof(my_int_t));
    length_one(glob);
    length_two(glob);
    width_one(glob);
    width_two(glob);
}
