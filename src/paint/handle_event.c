/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** handle_event
*/

#include "my.h"

void handle_cursor(global_t *glob, sfEvent event)
{
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if (PRESSED(sfMouseLeft) && event.type == sfEvtMouseButtonPressed
        && (MOUSE.y >= 48 && MOUSE.y <= 120)) {
        if ((MOUSE.x >= 1161 && MOUSE.x <= 1184))
            glob->paint->type->current_type = PINCEAU;
        if ((MOUSE.x >= 699 && MOUSE.x <= 754))
            glob->paint->type->current_type = GOMME;
        if ((MOUSE.x >= 937 && MOUSE.x <= 1003))
            glob->paint->type->current_type = COEUR;
        if ((MOUSE.x >= 816 && MOUSE.x <= 880))
            glob->paint->type->current_type = STAR;
        if ((MOUSE.x >= 1059 && MOUSE.x <= 1116))
            glob->paint->type->current_type = SCEAU;
        if ((MOUSE.x >= 603 && MOUSE.x <= 648))
            glob->paint->type->current_type = PIPETTE;
    }
    draw_gomme(glob, event);
}

static int split_handle_statue(global_t *glob, sfEvent event,
    sfVector2f max, sfVector2f min)
{
    sfFloatRect rect = {max.x, max.y, min.x - max.x, min.y - max.y};

    if (sfFloatRect_contains(&rect, MOUSE.x, MOUSE.y)) {
        if (event.type == sfEvtMouseButtonPressed) {
            return (ACTIVE);
            glob->current_scene = PAINT;
        } else
            return (HOVER);
    } else
        return (STANDBY);
}

int handle_statue(global_t *glob, sfEvent event)
{
    list_but_t *t = MYPAINT->but->list;

    while (t) {
        t->current = split_handle_statue(glob, event, (sfVector2f){646, 613},
        (sfVector2f){1196, 744});
    t = t->next;
    }
    return 0;
}

void handle_writing(global_t *glob, sfEvent event,
    sfVector2f max, sfVector2f min)
{
    sfFloatRect rect = {max.x, max.y, min.x - max.x, min.y - max.y};

    if (sfFloatRect_contains(&rect, MOUSE.x, MOUSE.y) &&
        (event.type == sfEvtMouseButtonPressed)) {
    }
}

static void handle_hover_button(global_t *glob)
{
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if (MOUSE.x >= 790 && MOUSE.x <= 1121) {
        if ((MOUSE.y >= 416 && MOUSE.y <= 462))
            SETTING->hover[2].a = true;
        else
            SETTING->hover[2].a = false;
        if (MOUSE.y >= 487 && MOUSE.y <= 533)
            SETTING->hover[1].a = true;
        else
            SETTING->hover[1].a = false;
        if ((MOUSE.y >= 568 && MOUSE.y <= 621))
            SETTING->hover[3].a = true;
        else
            SETTING->hover[3].a = false;
        if (MOUSE.y >= 657 && MOUSE.y <= 703)
            SETTING->hover[0].a = true;
        else
            SETTING->hover[0].a = false;
        }
}

void handle_settings(global_t *glob, sfEvent event)
{
    handle_hover_button(glob);
    if (PRESSED(sfMouseLeft) && event.type == sfEvtMouseButtonPressed &&
    ((MOUSE.x >= 28 && MOUSE.x <= 92) && (MOUSE.y >= 62 && MOUSE.y <= 130)))
            SETTING->activation = true;
    if (SETTING->activation == true && (MOUSE.x >= 790 && MOUSE.x <= 1121)
        && (PRESSED(sfMouseLeft) && event.type == sfEvtMouseButtonPressed)) {
        if (MOUSE.y >= 381 && MOUSE.y <= 398)
            SETTING->activation = false;
        if ((MOUSE.y >= 416 && MOUSE.y <= 462))
            standard_image(glob);
        if (MOUSE.y >= 487 && MOUSE.y <= 533)
            open_file(glob);
        if ((MOUSE.y >= 568 && MOUSE.y <= 621))
            insert_texture(glob);
        if (MOUSE.y >= 657 && MOUSE.y <= 703)
            save_image(glob);
        }
}

static void handle_size(global_t *glob, sfEvent event)
{
    int i = 0;
    char *text = NULL;

    while (PRESSED(sfMouseLeft) && event.type == sfEvtMouseMoved) {
        MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
        if ((MOUSE.x >= 1580 && MOUSE.x <= 1780) &&
            (MOUSE.y >= 348 && MOUSE.y <= 352))
            MYPAINT->taile->pos = (sfVector2f){MOUSE.x, MOUSE.y};
        CIRCLEPOS(MYPAINT->taile->point, MYPAINT->taile->pos);
        CIRCLEPOS(CURSOR, (sfVector2f){MOUSE.x, MOUSE.y});
        for (i = 0; 1580 + i != MOUSE.x && 1580 + i < 1780; i++);
        SIZE = i / 2;
        text = malloc(sizeof(char) * 6);
        my_strcpy(text, put_nbr_to_str(SIZE));
        my_strcat(text, "px");
        sfText_setString(MYPAINT->taile->data, text);
        draw_paint(glob);
        POLLEVENT(WINDOW, &event);
        free(text);
    }
}

static void handle_opacity(global_t *glob, sfEvent event)
{
    int i = 0;
    char *text = NULL;

    while (PRESSED(sfMouseLeft) && event.type == sfEvtMouseMoved) {
        MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
        if ((MOUSE.x >= 1480 && MOUSE.x <= 1780) &&
            (MOUSE.y >= 499 && MOUSE.y <= 502))
            MYPAINT->opacity->pos = (sfVector2f){MOUSE.x, MOUSE.y};
        CIRCLEPOS(MYPAINT->opacity->point, MYPAINT->opacity->pos);
        CIRCLEPOS(CURSOR, (sfVector2f){MOUSE.x, MOUSE.y});
        for (i = 0; 1580 + i != MOUSE.x && 1580 + i < 1780; i++);
        OPACITY = (int)((i * 100 / 200) * 255 / 100);
        text = malloc(sizeof(char) * 6);
        my_strcpy(text, put_nbr_to_str((int)((i * 100 / 200))));
        my_strcat(text, "%");
        sfText_setString(MYPAINT->opacity->data, text);
        draw_paint(glob);
        POLLEVENT(WINDOW, &event);
        free(text);
    }
}

static void handle_quit(global_t *glob)
{
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    if ((MOUSE.x >= 30 && MOUSE.x <= 54) &&
        (MOUSE.y >= 40 && MOUSE.y <= 63)
        && PRESSED(sfMouseLeft)) {
        sfRenderWindow_close(WINDOW);
    }
}

void handle_size_and_opacity(global_t *glob, sfEvent event)
{
    if ((MOUSE.x + 5 >= MYPAINT->taile->pos.x &&
            MOUSE.x - 5 <= MYPAINT->taile->pos.x)
        && (MOUSE.y + 5 >= MYPAINT->taile->pos.y &&
            MOUSE.y - 5 <= MYPAINT->taile->pos.y))
        handle_size(glob, event);
    if ((MOUSE.x + 5 >= MYPAINT->opacity->pos.x &&
            MOUSE.x - 5 <= MYPAINT->opacity->pos.x)
        && (MOUSE.y + 5 >= MYPAINT->opacity->pos.y &&
            MOUSE.y - 5 <= MYPAINT->opacity->pos.y))
        handle_opacity(glob, event);
    handle_quit(glob);
    handle_outline(glob);
    handle_outline_pressed(glob);
}
