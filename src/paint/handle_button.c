/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** handle_button
*/

#include "my.h"

static void nextnext_init_circles(global_t *glob, sfColor color)
{
    glob->circles[PO].circle = sfCircleShape_create();
    glob->circles[PO].position = (sfVector2f){1054, 50};
    sfCircleShape_setRadius(glob->circles[PO].circle, 40);
    sfCircleShape_setPosition(glob->circles[PO].circle,
    glob->circles[PO].position);
    sfCircleShape_setFillColor(glob->circles[PO].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles[PO].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles[PO].circle, 3.0f);
    glob->circles[S].circle = sfCircleShape_create();
    glob->circles[S].position = (sfVector2f){1140, 50};
    sfCircleShape_setRadius(glob->circles[S].circle, 40);
    sfCircleShape_setPosition(glob->circles[S].circle,
    glob->circles[S].position);
    sfCircleShape_setFillColor(glob->circles[S].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles[S].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles[S].circle, 3.0f);
}

static void next_init_circles(global_t *glob, sfColor color)
{
    sfCircleShape_setOutlineThickness(glob->circles[G].circle, 3.0f);
    glob->circles[C].circle = sfCircleShape_create();
    glob->circles[C].position = (sfVector2f){937, 52};
    sfCircleShape_setRadius(glob->circles[C].circle, 40);
    sfCircleShape_setPosition(glob->circles[C].circle,
    glob->circles[C].position);
    sfCircleShape_setFillColor(glob->circles[C].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles[C].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles[C].circle, 3.0f);
    glob->circles[PA].circle = sfCircleShape_create();
    glob->circles[PA].position = (sfVector2f){816, 48};
    sfCircleShape_setRadius(glob->circles[PA].circle, 42);
    sfCircleShape_setPosition(glob->circles[PA].circle,
    glob->circles[PA].position);
    sfCircleShape_setFillColor(glob->circles[PA].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles[PA].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles[PA].circle, 3.0f);
    glob->current_cursor = N;
    nextnext_init_circles(glob, color);
}

void init_circles(global_t *glob)
{
    sfColor color = sfColor_fromRGB(255, 102, 196);

    glob->circles[N].circle = sfCircleShape_create();
    glob->circles[N].position = (sfVector2f){0, 0};
    glob->circles[M].circle = sfCircleShape_create();
    glob->circles[M].position = (sfVector2f){592, 50};
    sfCircleShape_setRadius(glob->circles[M].circle, 40);
    sfCircleShape_setPosition(glob->circles[M].circle,
    glob->circles[M].position);
    sfCircleShape_setFillColor(glob->circles[M].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles[M].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles[M].circle, 3.0f);
    glob->circles[G].circle = sfCircleShape_create();
    glob->circles[G].position = (sfVector2f){690, 52};
    sfCircleShape_setRadius(glob->circles[G].circle, 40);
    sfCircleShape_setPosition(glob->circles[G].circle,
    glob->circles[G].position);
    sfCircleShape_setFillColor(glob->circles[G].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles[G].circle, color);
    next_init_circles(glob, color);
}

void handle_outline(global_t *glob)
{
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if ((MOUSE.y >= 48 && MOUSE.y <= 120)) {
        if ((MOUSE.x >= 1161 && MOUSE.x <= 1184))
            glob->current_cursor = S;
        if ((MOUSE.x >= 699 && MOUSE.x <= 754))
            glob->current_cursor = G;
        if ((MOUSE.x >= 937 && MOUSE.x <= 1003))
            glob->current_cursor = C;
        if ((MOUSE.x >= 816 && MOUSE.x <= 880))
            glob->current_cursor = PA;
        if ((MOUSE.x >= 1059 && MOUSE.x <= 1116))
            glob->current_cursor = PO;
        if ((MOUSE.x >= 603 && MOUSE.x <= 648))
            glob->current_cursor = M;
    } else
        glob->current_cursor = N;
}
