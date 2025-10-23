/*
** EPITECH PROJECT, 2024
** paint
** File description:
** glob
*/

#include "my.h"

static void init_window(global_t *glob)
{
    WINDOW = SRWC((sfVideoMode) {1920, 1080, 64},
        "My Barb's", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(WINDOW, 120);
    glob->clock = sfClock_create();
    glob->delta_time = 0;
    glob->timer = 0;
}

static void init_glob(global_t *glob)
{
    glob->current_scene = LOAD;
    glob->scenes[LOAD] = (scene_t){&init_load, &handle_load_events,
        &update_load, &draw_load, &destroy_load};
    glob->scenes[MENU] = (scene_t){&init_menu, &handle_menu_events,
        &update_menu, &draw_menu, &destroy_menu};
    glob->scenes[PAINT] = (scene_t){&init_paint, &handle_paint_events,
        &update_paint, &draw_paint, &destroy_paint};
    glob->scenes[LOAD].init(glob);
    glob->scenes[MENU].init(glob);
    glob->scenes[PAINT].init(glob);
    init_color(glob);
    init_gradiant_colors(glob);
    init_circles(glob);
    init_circles_pressed(glob);
}

static float get_delta_time(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float delta_time = time.microseconds / 1000000.0;

    sfClock_restart(clock);
    return (delta_time);
}

void destroy_glob(global_t *glob)
{
    glob->scenes[LOAD].destroy(glob);
    glob->scenes[MENU].destroy(glob);
    glob->scenes[PAINT].destroy(glob);
    free(glob);
}

int main(void)
{
    global_t *glob = malloc(sizeof(global_t));
    sfMusic *music = sfMusic_createFromFile("assets/music/barbiegirl.ogg");

    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
    init_window(glob);
    init_glob(glob);
    while (sfRenderWindow_isOpen(WINDOW)) {
        glob->delta_time = get_delta_time(glob->clock);
        glob->timer += glob->delta_time;
        glob->scenes[glob->current_scene].handle_event(glob);
        glob->scenes[glob->current_scene].update(glob);
        glob->scenes[glob->current_scene].draw(glob);
        GRAD->gradiant[GRAD->current_gradiant].update(glob);
        GRAD->gradiant[GRAD->current_gradiant].handle_event(glob);
    }
    return 0;
}
