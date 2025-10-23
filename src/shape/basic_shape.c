/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** sqares_forms
*/

#include "my.h"

sfRectangleShape *draw(global_t *glob, sfColor color)
{
    sfRectangleShape *square = sfRectangleShape_create();
    sfFloatRect textureBounds = sfSprite_getGlobalBounds(SPRITE);
    sfVector2f pos = (sfVector2f){MOUSE.x - textureBounds.left,
        MOUSE.y - textureBounds.top};
    int size = glob->paint->pic->size;

    sfRectangleShape_setSize(square, (sfVector2f){size, size});
    sfRectangleShape_setFillColor(square, color);
    sfRectangleShape_setPosition(square, pos);
    return square;
}

sfCircleShape *circle_create(sfVector2f position, float radius, sfColor color,
    bool a)
{
    sfCircleShape* circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setPosition(circle, position);
    sfCircleShape_setFillColor(circle, color);
    if (a) {
        sfCircleShape_setOutlineColor(circle, sfBlack);
        sfCircleShape_setOutlineThickness(circle, 3);
    }
    return circle;
}

sfRectangleShape *sqare_and_rectancle_create(sfVector2f size, sfVector2f pos,
    sfColor color)
{
    sfRectangleShape *square = sfRectangleShape_create();

    sfRectangleShape_setSize(square, size);
    sfRectangleShape_setFillColor(square, color);
    sfRectangleShape_setPosition(square, pos);
    sfRectangleShape_setOutlineThickness(square, 5);
    sfRectangleShape_setOutlineColor(square, sfBlack);
    return square;
}
