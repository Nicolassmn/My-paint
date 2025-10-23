/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** update_colors
*/

#include "my.h"

void update_colors(global_t *glob)
{
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if ((MOUSE.x >= 1342 && MOUSE.x <= 1413) &&
        (MOUSE.y >= 48 && MOUSE.y <= 118)
        && PRESSED(sfMouseLeft)) {
            GRAD->current_gradiant = VR;
    }
}

void update_next_next(global_t *glob)
{
    if ((MOUSE.x >= 1755 && MOUSE.x <= 1796) &&
        (MOUSE.y >= 855 && MOUSE.y <= 892)) {
        GRAD->butt_gradiant = VB;
        if (PRESSED(sfMouseLeft))
            GRAD->current_gradiant = VB;
    }
    if ((MOUSE.x >= 1810 && MOUSE.x <= 1825) &&
        (MOUSE.y >= 593 && MOUSE.y <= 603)) {
        GRAD->butt_gradiant = NONE;
        if (PRESSED(sfMouseLeft))
            GRAD->current_gradiant = NONE;
    }
}

void update_next(global_t *glob)
{
    if ((MOUSE.x >= 1629 && MOUSE.x <= 1668) &&
        (MOUSE.y >= 855 && MOUSE.y <= 892)) {
        GRAD->butt_gradiant = VVBR;
        if (PRESSED(sfMouseLeft))
            GRAD->current_gradiant = VVBR;
    }
    if ((MOUSE.x >= 1695 && MOUSE.x <= 1736) &&
        (MOUSE.y >= 855 && MOUSE.y <= 892)) {
        GRAD->butt_gradiant = MC;
        if (PRESSED(sfMouseLeft))
            GRAD->current_gradiant = MC;
    }
    update_next_next(glob);
}

void update_vr(global_t *glob)
{
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if ((MOUSE.x >= 1342 && MOUSE.x <= 1413) &&
        (MOUSE.y >= 48 && MOUSE.y <= 118)) {
        if (PRESSED(sfMouseLeft))
            GRAD->current_gradiant = VR;
    }
    if ((MOUSE.x >= 1573 && MOUSE.x <= 1610) &&
        (MOUSE.y >= 855 && MOUSE.y <= 892)) {
        GRAD->butt_gradiant = VR;
        if (PRESSED(sfMouseLeft))
            GRAD->current_gradiant = VR;
    }
    update_next(glob);
}
