/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** handle_color
*/

#include "my.h"

void handle_event_vr(global_t *glob)
{
    sfColor pixelColor;

    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if ((MOUSE.x >= 1562 && MOUSE.x <= 1801) &&
        (MOUSE.y >= 607 && MOUSE.y <= 809)
        && PRESSED(sfMouseLeft)) {
        pixelColor = sfImage_getPixel(
        GRAD->gradiant[GRAD->current_gradiant].colors->image, MOUSE.x - 1330,
        MOUSE.y - 550);
        RED = pixelColor.r;
        GREEN = pixelColor.g;
        BLUE = pixelColor.b;
    }
}
