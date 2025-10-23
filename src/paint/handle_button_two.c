/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** handle_button
*/

#include "my.h"

static void nextnext_init_circles(global_t *glob, sfColor color)
{
    glob->circles_pressed[PO].circle = sfCircleShape_create();
    glob->circles_pressed[PO].position = (sfVector2f){1054, 50};
    sfCircleShape_setRadius(glob->circles_pressed[PO].circle, 40);
    sfCircleShape_setPosition(glob->circles_pressed[PO].circle,
    glob->circles_pressed[PO].position);
    sfCircleShape_setFillColor(glob->circles_pressed[PO].circle,
    sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles_pressed[PO].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles_pressed[PO].circle, 3.0f);
    glob->circles_pressed[S].circle = sfCircleShape_create();
    glob->circles_pressed[S].position = (sfVector2f){1140, 50};
    sfCircleShape_setRadius(glob->circles_pressed[S].circle, 40);
    sfCircleShape_setPosition(glob->circles_pressed[S].circle,
    glob->circles_pressed[S].position);
    sfCircleShape_setFillColor(glob->circles_pressed[S].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles_pressed[S].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles_pressed[S].circle, 3.0f);
}

static void next_init_circles(global_t *glob, sfColor color)
{
    sfCircleShape_setOutlineThickness(glob->circles_pressed[G].circle, 3.0f);
    glob->circles_pressed[C].circle = sfCircleShape_create();
    glob->circles_pressed[C].position = (sfVector2f){937, 52};
    sfCircleShape_setRadius(glob->circles_pressed[C].circle, 40);
    sfCircleShape_setPosition(glob->circles_pressed[C].circle,
    glob->circles_pressed[C].position);
    sfCircleShape_setFillColor(glob->circles_pressed[C].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles_pressed[C].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles_pressed[C].circle, 3.0f);
    glob->circles_pressed[PA].circle = sfCircleShape_create();
    glob->circles_pressed[PA].position = (sfVector2f){816, 48};
    sfCircleShape_setRadius(glob->circles_pressed[PA].circle, 42);
    sfCircleShape_setPosition(glob->circles_pressed[PA].circle,
    glob->circles_pressed[PA].position);
    sfCircleShape_setFillColor(glob->circles_pressed[PA].circle,
    sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles_pressed[PA].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles_pressed[PA].circle, 3.0f);
    glob->current_cpressed = S;
    nextnext_init_circles(glob, color);
}

void init_circles_pressed(global_t *glob)
{
    sfColor color = sfColor_fromRGB(255, 50, 180);

    glob->circles_pressed[N].circle = sfCircleShape_create();
    glob->circles_pressed[N].position = (sfVector2f){0, 0};
    glob->circles_pressed[M].circle = sfCircleShape_create();
    glob->circles_pressed[M].position = (sfVector2f){592, 50};
    sfCircleShape_setRadius(glob->circles_pressed[M].circle, 40);
    sfCircleShape_setPosition(glob->circles_pressed[M].circle,
    glob->circles[M].position);
    sfCircleShape_setFillColor(glob->circles_pressed[M].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles_pressed[M].circle, color);
    sfCircleShape_setOutlineThickness(glob->circles_pressed[M].circle, 3.0f);
    glob->circles_pressed[G].circle = sfCircleShape_create();
    glob->circles_pressed[G].position = (sfVector2f){690, 52};
    sfCircleShape_setRadius(glob->circles_pressed[G].circle, 40);
    sfCircleShape_setPosition(glob->circles_pressed[G].circle,
    glob->circles_pressed[G].position);
    sfCircleShape_setFillColor(glob->circles_pressed[G].circle, sfTransparent);
    sfCircleShape_setOutlineColor(glob->circles_pressed[G].circle, color);
    next_init_circles(glob, color);
}

void handle_outline_pressed(global_t *glob)
{
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if ((MOUSE.y >= 48 && MOUSE.y <= 120)) {
        if ((MOUSE.x >= 1161 && MOUSE.x <= 1184) && PRESSED(sfMouseLeft))
            glob->current_cpressed = S;
        if ((MOUSE.x >= 699 && MOUSE.x <= 754) && PRESSED(sfMouseLeft))
            glob->current_cpressed = G;
        if ((MOUSE.x >= 937 && MOUSE.x <= 1003) && PRESSED(sfMouseLeft))
            glob->current_cpressed = C;
        if ((MOUSE.x >= 816 && MOUSE.x <= 880) && PRESSED(sfMouseLeft))
            glob->current_cpressed = PA;
        if ((MOUSE.x >= 1059 && MOUSE.x <= 1116) && PRESSED(sfMouseLeft))
            glob->current_cpressed = PO;
        if ((MOUSE.x >= 603 && MOUSE.x <= 648) && PRESSED(sfMouseLeft))
            glob->current_cpressed = M;
    }
}
