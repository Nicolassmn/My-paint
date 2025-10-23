/*
** EPITECH PROJECT, 2024
** paint
** File description:
** paint
*/

#include "my.h"

void init_paint(global_t *glob)
{
    MYPAINT = malloc(sizeof(paint_t));
    MYPAINT->pic = malloc(sizeof(picture_t));
    MYPAINT->but = malloc(sizeof(button_t));
    glob->zoom = malloc(sizeof(focus_t));
    MYPAINT->type = malloc(sizeof(cursor_t));
    MYPAINT->background = malloc(sizeof(animation_t));
    MYPAINT->option = malloc(sizeof(setting_t));
    MYPAINT->size = malloc(sizeof(animation_t));
    MYPAINT->taile = malloc(sizeof(handle_t));
    MYPAINT->opacity = malloc(sizeof(handle_t));
    MYPAINT->outl = malloc(sizeof(outline_t));
    create_environnement(glob);
    init_cursors(glob);
    standard_image(glob);
    create_texture(glob);
    create_size_and_opacity(glob);
}

void handle_paint_events(global_t *glob)
{
    sfEvent event;

    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    while (POLLEVENT(WINDOW, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        handle_cursor(glob, event);
        handle_size_and_opacity(glob, event);
        handle_palette_colors(glob);
        handle_statue(glob, event);
        handle_settings(glob, event);
        TYPE[MYPAINT->type->current_type].effet_cursor(glob, event);
    }
}

void update_paint(global_t *glob)
{
    (void)glob;
}

static void if_cs(global_t *glob, int i)
{
    if (SETTING->hover[i].a == true)
        sfRenderWindow_drawSprite(WINDOW, SETTING->hover[i].sprite, NULL);
}

static void show_setting(global_t *glob)
{
    sfRenderWindow_drawSprite(WINDOW, SETTING->handle->sprite, NULL);
    if (SETTING->activation == true) {
        sfRenderWindow_drawRectangleShape(WINDOW, SETTING->background, NULL);
        sfRenderWindow_drawSprite(WINDOW, SETTING->file->sprite, NULL);
        for (int i = 0; i < 4; i++) {
            if_cs(glob, i);
        }
    }
    if (MYPAINT->type->current_type == PINCEAU)
        sfRenderWindow_drawCircleShape(WINDOW, CURSOR, NULL);
    else
        sfRenderWindow_drawSprite(WINDOW,
        TYPE[MYPAINT->type->current_type].sprite, NULL);
}

static void draw_asset(global_t *glob)
{
    if (glob->paint->type->current_type == PINCEAU)
        draw_pinceau_asset(glob);
    if (glob->paint->type->current_type == GOMME)
        draw_gomme_asset(glob);
}

static void next_draw(global_t *glob)
{
    sfRenderWindow_drawSprite(WINDOW,
    GRAD->gradiant[GRAD->current_gradiant].colors->sprite, NULL);
    sfRenderWindow_drawSprite(WINDOW, GRAD->butt[GRAD->butt_gradiant].sprite,
    NULL);
    sfRenderWindow_drawSprite(WINDOW, SPRITE, NULL);
    draw_asset(glob);
    show_setting(glob);
    sfRenderWindow_drawCircleShape(WINDOW,
    glob->circles[glob->current_cursor].circle, NULL);
    sfRenderWindow_drawCircleShape(WINDOW,
    glob->circles_pressed[glob->current_cpressed].circle, NULL);
    sfRenderWindow_display(WINDOW);
}

void draw_paint(global_t *glob)
{
    const sfTexture* texture = sfRenderTexture_getTexture(TEXTURE);

    sfSprite_setTexture(SPRITE, texture, sfTrue);
    sfSprite_setPosition(SPRITE, (sfVector2f){250, 230});
    sfRenderTexture_display(TEXTURE);
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfRenderWindow_drawSprite(WINDOW, MYPAINT->background->sprite, NULL);
    MYPAINT->but->draw(glob, MYPAINT->but);
    sfRenderWindow_drawSprite(WINDOW, MYPAINT->size->sprite, NULL);
    RECTANGLEDRAW(WINDOW, MYPAINT->taile->primary, NULL);
    RECTANGLEDRAW(WINDOW, MYPAINT->opacity->primary, NULL);
    sfRenderWindow_drawText(WINDOW, MYPAINT->opacity->data, NULL);
    sfRenderWindow_drawText(WINDOW, MYPAINT->taile->data, NULL);
    sfRenderWindow_drawCircleShape(WINDOW, MYPAINT->taile->point, NULL);
    sfRenderWindow_drawCircleShape(WINDOW, MYPAINT->opacity->point, NULL);
    sfRenderWindow_drawSprite(WINDOW, MYPAINT->type->over->sprite, NULL);
    next_draw(glob);
}

void destroy_paint(global_t *glob)
{
    free(MYPAINT->background);
    free(glob->zoom);
    free(MYPAINT->pic);
    free(MYPAINT->but);
    free(MYPAINT->size);
    free(MYPAINT);
}
