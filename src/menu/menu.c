/*
** EPITECH PROJECT, 2024
** paint
** File description:
** menu
*/

#include "my.h"

void init_menu(global_t *glob)
{
    glob->menu = malloc(sizeof(menu_t));
    glob->menu->but = malloc(sizeof(button_t));
    glob->menu->background = malloc(sizeof(animation_t));
    glob->menu->but->list = NULL;
    glob->menu->but->draw = &draw_button;
    glob->menu->but->destroy = &destroy_button;
    create_animation("assets/background/My_Barbs.png", 0.05,
        (sfVector2f){1, 1}, glob->menu->background);
    add_button(glob->menu->but, paths_to_tab("assets/buttons/starts.png",
    "assets/buttons/starth.png", "assets/buttons/starta.png"),
    (sfVector2f){250, 300}, (sfVector2f){1, 1});
    for (int i = 0; i < 2; i++) {
        create_animation("assets/danse/hips.png", 0.15,
            (sfVector2f){5, 5}, &(glob->menu->hips[i]));
        sprite_position((sfVector2f){150 + (1250 * i), 500},
            &(glob->menu->hips[i]));
    }
}

void update_menu(global_t *glob)
{
    for (int i = 0; i < 2; i++)
        glob->menu->hips[i].update(&(glob->menu->hips[i]), glob->delta_time);
}

static int split_handle(global_t *glob, sfEvent event,
    sfVector2f max, sfVector2f min)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(WINDOW);
    sfFloatRect rect = {max.x, max.y, min.x - max.x, min.y - max.y};

    if (sfFloatRect_contains(&rect, m.x, m.y)) {
        if (event.type == sfEvtMouseButtonReleased) {
            glob->current_scene = PAINT;
            sfRenderWindow_setMouseCursorVisible(WINDOW, false);
            return (ACTIVE);
        } else
            return (HOVER);
    } else
        return (STANDBY);
}

void handle_menu_events(global_t *glob)
{
    list_but_t *t = glob->menu->but->list;
    sfEvent event;

    while (POLLEVENT(WINDOW, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
        if (t == NULL)
            return;
        while (t) {
        t->current = split_handle(glob, event, (sfVector2f){646, 613},
            (sfVector2f){1196, 744});
        t = t->next;
    }
    }
}

void draw_menu(global_t *glob)
{
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfRenderWindow_drawSprite(WINDOW, glob->menu->background->sprite, NULL);
    glob->menu->but->draw(glob, glob->menu->but);
    for (int i = 0; i < 2; i++)
        sfRenderWindow_drawSprite(WINDOW, glob->menu->hips[i].sprite, NULL);
    sfRenderWindow_display(WINDOW);
}

void destroy_menu(global_t *glob)
{
    free(glob->menu->but);
    free(glob->menu->background);
    free(glob->menu);
}
