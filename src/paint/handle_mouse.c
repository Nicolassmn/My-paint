/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** handle_mouse
*/

#include "my.h"

static void link_point(global_t *glob, sfVector2f old, sfColor current)
{
    sfVertexArray *line = sfVertexArray_create();
    sfFloatRect textureBounds = sfSprite_getGlobalBounds(SPRITE);
    sfVector2f old_pos = (sfVector2f){old.x - textureBounds.left,
        old.y - textureBounds.top};
    sfVector2f pos = (sfVector2f){MOUSE.x - textureBounds.left,
        MOUSE.y - textureBounds.top};
    sfVertex pt1 = {.position = old_pos, .color = current};
    sfVertex pt2 = {.position = pos, .color = current};

    sfVertexArray_append(line, pt1);
    sfVertexArray_append(line, pt2);
    sfVertexArray_setPrimitiveType(line, sfLines);
    sfRenderTexture_drawVertexArray(glob->texture, line, NULL);
}

int drawing(global_t *glob, sfEvent event)
{
    sfColor color = sfColor_fromRGBA(RED, GREEN, BLUE, OPACITY);
    sfVector2f old;

    CIRCLEPOS(CURSOR, (sfVector2f){MOUSE.x, MOUSE.y});
    sfCircleShape_setOutlineColor(CURSOR, (sfColor){RED, GREEN, BLUE, 255});
    while (PRESSED(sfMouseLeft) && event.type == sfEvtMouseMoved) {
        DRAWRECTANGLE(glob->texture, draw(glob, color), NULL);
        old = (sfVector2f){MOUSE.x, MOUSE.y};
        MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
        link_point(glob, old, sfColor_fromRGBA(RED, GREEN, BLUE, OPACITY));
        sfClock_restart(glob->clock);
        POLLEVENT(WINDOW, &event);
        CIRCLEPOS(CURSOR, (sfVector2f){MOUSE.x, MOUSE.y});
        draw_paint(glob);
    }
    if (event.type == sfEvtMouseButtonPressed && PRESSED(sfMouseLeft))
        DRAWRECTANGLE(glob->texture, draw(glob, color), NULL);
    draw_pinceau_asset(glob);
    return 0;
}

static void clear_image(global_t *glob)
{
    sfFloatRect textureBounds = sfSprite_getGlobalBounds(SPRITE);
    sfVector2f pos = (sfVector2f){MOUSE.x - textureBounds.left,
            MOUSE.y - textureBounds.top};

    if (MYPAINT->type->cleanup->one == true)
        DRAWRECTANGLE(glob->texture, draw(glob, sfWhite), NULL);
    else
        DRAWCIRCLE(glob->texture,
            circle_create(pos, SIZE, sfWhite, false), NULL);
}

int cleanup(global_t *glob, sfEvent event)
{
    sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[GOMME]);
    while (PRESSED(sfMouseLeft) && event.type == sfEvtMouseMoved) {
        clear_image(glob);
        MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
        sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[GOMME]);
        sfClock_restart(glob->clock);
        POLLEVENT(WINDOW, &event);
        CIRCLEPOS(CURSOR, (sfVector2f){MOUSE.x, MOUSE.y});
        draw_paint(glob);
    }
    if (event.type == sfEvtMouseButtonPressed && PRESSED(sfMouseLeft))
        clear_image(glob);
    draw_gomme_asset(glob);
    return 0;
}

int form(global_t *glob, sfEvent event)
{
    sfVector2f pos;
    sfFloatRect textureBounds = sfSprite_getGlobalBounds(SPRITE);

    sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[COEUR]);
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    pos = (sfVector2f){MOUSE.x - textureBounds.left,
        MOUSE.y - textureBounds.top};
    if (event.type == sfEvtMouseButtonPressed && PRESSED(sfMouseLeft)) {
        sprite_position(pos, &TYPE[COEUR]);
        sfRenderTexture_drawSprite(TEXTURE, TYPE[COEUR].sprite, NULL);
    }
    return 0;
}

static void mirror_point(global_t *glob, sfVector2f old,
    sfVector2f new, sfColor current)
{
    sfVertexArray *line = sfVertexArray_create();
    sfVertex pt1[SIZE];
    sfVertex pt2[SIZE];

    for (int i = 0; i < SIZE; i++) {
        pt1[i].color = current;
        pt1[i].color = current;
        pt1[i].position = (sfVector2f){old.x + i, old.y + i};
        pt2[i].position = (sfVector2f){new.x + i, new.y + i};
        sfVertexArray_append(line, pt1[i]);
        sfVertexArray_append(line, pt2[i]);
        sfVertexArray_setPrimitiveType(line, sfLines);
        sfRenderTexture_drawVertexArray(glob->texture, line, NULL);
    }
}

int pipette(global_t *glob, sfEvent event)
{
    sfVector2f old;
    sfVector2f pos;

    sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[PIPETTE]);
    while (PRESSED(sfMouseLeft) && event.type == sfEvtMouseMoved) {
        old = (sfVector2f){MOUSE.x, MOUSE.y};
        MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
        pos = (sfVector2f){MOUSE.x, MOUSE.y};
        mirror_point(glob, old, pos,
            sfColor_fromRGBA(RED, GREEN, BLUE, OPACITY));
        sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[PIPETTE]);
        sfClock_restart(glob->clock);
        POLLEVENT(WINDOW, &event);
        CIRCLEPOS(CURSOR, (sfVector2f){MOUSE.x, MOUSE.y});
        draw_paint(glob);
    }
    draw_pinceau_asset(glob);
    return 0;
}

int seal(global_t *glob, sfEvent event)
{
    sfColor color = sfColor_fromRGBA(RED, GREEN, BLUE, OPACITY);
    int tmp = SIZE;

    SIZE = 10000;
    sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[SCEAU]);
    CIRCLEPOS(CURSOR, (sfVector2f){MOUSE.x, MOUSE.y});
    sfCircleShape_setOutlineColor(CURSOR, (sfColor){RED, GREEN, BLUE, 255});
    while (PRESSED(sfMouseLeft) && event.type == sfEvtMouseMoved) {
        sprite_position((sfVector2f){MOUSE.x, MOUSE.y}, &TYPE[SCEAU]);
        DRAWRECTANGLE(glob->texture, draw(glob, color), NULL);
        MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
        sfClock_restart(glob->clock);
        POLLEVENT(WINDOW, &event);
        CIRCLEPOS(CURSOR, (sfVector2f){MOUSE.x, MOUSE.y});
        draw_paint(glob);
    }
    if (event.type == sfEvtMouseButtonPressed && PRESSED(sfMouseLeft))
        DRAWRECTANGLE(glob->texture, draw(glob, color), NULL);
    SIZE = tmp;
    return 0;
}
