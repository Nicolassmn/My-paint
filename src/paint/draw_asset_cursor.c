/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** draw_asset_cursor
*/

#include "my.h"

void draw_pinceau_asset(global_t *glob)
{
    sfRectangleShape_setFillColor(MYPAINT->type->primary,
    MYPAINT->type->basic->color1);
    sfRectangleShape_setOutlineColor(MYPAINT->type->primary, sfBlack);
    sfRectangleShape_setOutlineThickness(MYPAINT->type->primary, 5);
    sfRectangleShape_setFillColor(MYPAINT->type->secondary,
    MYPAINT->type->basic->color2);
    sfRectangleShape_setOutlineColor(MYPAINT->type->secondary, sfBlack);
    sfRectangleShape_setOutlineThickness(MYPAINT->type->secondary, 5);
}

void draw_gomme(global_t *glob, sfEvent event)
{
    if ((MOUSE.x >= 1700 && MOUSE.x <= 1776) &&
        (MOUSE.y >= 798 && MOUSE.y <= 873)) {
            if (event.type == sfEvtMouseButtonPressed && PRESSED(sfMouseLeft))
        MYPAINT->type->cleanup->one = true;
    }
    if ((MOUSE.x >= 1580 && MOUSE.x <= 1660) &&
    (MOUSE.y >= 793 && MOUSE.y <= 878)) {
        if (event.type == sfEvtMouseButtonPressed && PRESSED(sfMouseLeft))
            MYPAINT->type->cleanup->one = false;
    }
}

void draw_gomme_asset(global_t *glob)
{
    sfRectangleShape_setFillColor(MYPAINT->type->primary,
    MYPAINT->type->cleanup->color1);
    sfRectangleShape_setOutlineColor(MYPAINT->type->primary, sfBlack);
    sfRectangleShape_setOutlineThickness(MYPAINT->type->primary, 5);
    sfRectangleShape_setFillColor(MYPAINT->type->secondary,
    MYPAINT->type->cleanup->color2);
    sfRectangleShape_setOutlineColor(MYPAINT->type->secondary, sfBlack);
    sfRectangleShape_setOutlineThickness(MYPAINT->type->secondary, 5);
    sfRenderWindow_drawRectangleShape(WINDOW, MYPAINT->type->primary, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, MYPAINT->type->secondary, NULL);
    sfRenderWindow_drawRectangleShape(WINDOW, MYPAINT->type->cleanup->gomme1,
    NULL);
    sfRenderWindow_drawCircleShape(WINDOW, MYPAINT->type->cleanup->gomme2,
    NULL);
}

static void lin_point(global_t *glob, sfVector2f old, sfColor current)
{
    sfVertexArray *line = sfVertexArray_create();
    sfFloatRect textureBounds = sfSprite_getGlobalBounds(SPRITE);
    sfVector2f pos = (sfVector2f){MOUSE.x - textureBounds.left,
        MOUSE.y - textureBounds.top};
    sfVertex pt1 = {.position = old, .color = current};
    sfVertex pt2 = {.position = pos, .color = current};

    sfVertexArray_append(line, pt1);
    sfVertexArray_append(line, pt2);
    sfVertexArray_setPrimitiveType(line, sfLines);
    sfRenderTexture_drawVertexArray(glob->texture, line, NULL);
}

int sparkling(global_t *glob, sfEvent event)
{
    sfVector2f old;

    sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[STAR]);
    while (PRESSED(sfMouseLeft) && event.type == sfEvtMouseMoved) {
        old = (sfVector2f){MOUSE.x, MOUSE.y};
        MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
        lin_point(glob, old, sfColor_fromRGBA(RED, GREEN, BLUE, OPACITY));
        sfClock_restart(glob->clock);
        POLLEVENT(WINDOW, &event);
        sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[STAR]);
        draw_paint(glob);
    }
    return 0;
}
