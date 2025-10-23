/*
** EPITECH PROJECT, 2024
** paint
** File description:
** load
*/

#include "my.h"

static void init_sprite_split(global_t *glob)
{
    create_animation("assets/load/kiss1.jpg", 0.15,
        (sfVector2f){1, 1}, &(KISS1));
    create_animation("assets/load/kiss2.jpg", 0.15,
        (sfVector2f){0.8, 0.8}, &(KISS2));
    create_animation("assets/load/kiss3.jpg", 0.15,
        (sfVector2f){1, 1}, &(KISS3));
    create_animation("assets/background/load.jpg", 0.15,
        (sfVector2f){0.35, 0.35}, &(BACK));
    sprite_position((sfVector2f){0, 0}, &(KISS1));
    sprite_position((sfVector2f){700, 600}, &(KISS2));
    sprite_position((sfVector2f){650, 0}, &(KISS3));
}

void init_load(global_t *glob)
{
    glob->load = malloc(sizeof(load_t));
    for (int i = 0; i < 12; i++) {
        create_animation("assets/danse/hips.png", 0.15,
            (sfVector2f){5, 5}, &(HIP[i]));
        sprite_position((sfVector2f){0 + (150 * i), 500}, &(HIP[i]));
        create_animation("assets/danse/snap.png", 0.15,
            (sfVector2f){5, 5}, &(BAL[i]));
        sprite_position((sfVector2f){0 + (150 * i), 200},
            &(BAL[i]));
    }
    for (int i = 0; i < 13; i++) {
        create_animation("assets/load/ca.png", 0.15,
            (sfVector2f){2, 2}, &(CARO[i]));
        sprite_position((sfVector2f){0 + (150 * i), 720}, &(CARO[i]));
        create_animation("assets/load/dog.png", 0.15,
            (sfVector2f){2, 2}, &(DOG[i]));
        sprite_position((sfVector2f){0 + (150 * i), 400}, &(DOG[i]));
    }
    init_sprite_split(glob);
}

void handle_load_events(global_t *glob)
{
    sfEvent evt;

    while (POLLEVENT(WINDOW, &evt)) {
        if (evt.type == sfEvtClosed)
            sfRenderWindow_close(WINDOW);
    }
}

void update_load(global_t *glob)
{
    for (int i = 0; i < 12; i++)
        HIP[i].update(&(HIP[i]), glob->delta_time);
    for (int i = 0; i < 12; i++)
        BAL[i].update(&(BAL[i]), glob->delta_time);
}

static void random_draw(global_t *glob)
{
    int i = rand();

    srand(time(0));
    i = i % 12;
    HIP[i].a = true;
    BAL[i].a = true;
}

static void end_an_animation(global_t *glob)
{
    if (glob->timer >= 15) {
        sfRenderWindow_drawSprite(WINDOW,
            KISS2.sprite, NULL);
        sfRenderWindow_drawSprite(WINDOW,
            KISS1.sprite, NULL);
        sfRenderWindow_drawSprite(WINDOW,
            KISS3.sprite, NULL);
    }
    if (glob->timer >= 20)
        glob->current_scene = MENU;
}

void draw_load(global_t *glob)
{
    random_draw(glob);
    sfRenderWindow_clear(WINDOW, sfBlack);
    sfRenderWindow_drawSprite(WINDOW, BACK.sprite, NULL);
    for (int i = 0; i < 12; i++)
        if (HIP[i].a == true)
            sfRenderWindow_drawSprite(WINDOW, HIP[i].sprite, NULL);
    for (int i = 0; i < 12; i++)
        if (BAL[i].a == true)
            sfRenderWindow_drawSprite(WINDOW, BAL[i].sprite, NULL);
    for (int i = 0; i < 13; i++)
        sfRenderWindow_drawSprite(WINDOW, DOG[i].sprite, NULL);
    for (int i = 0; i < 13; i++)
        sfRenderWindow_drawSprite(WINDOW, CARO[i].sprite, NULL);
    end_an_animation(glob);
    sfRenderWindow_display(WINDOW);
}

void destroy_load(global_t *glob)
{
    free(glob->load);
}
