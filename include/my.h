/*
** EPITECH PROJECT, 2023
** header
** File description:
** lol
*/

#pragma once

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>
#include <math.h>
#include "global.h"

#define SRWC sfRenderWindow_create
#define WINDOW glob->window
#define POLLEVENT sfRenderWindow_pollEvent
#define TEXTURE glob->texture
#define SPRITE glob->paint->pic->sprite
#define TCFF sfTexture_createFromFile
#define MOUSE glob->paint->mouse
#define CURSOR glob->paint->type->type[PINCEAU].pinceau
#define VIEW glob->zoom->view
#define KISS1 glob->load->kiss1
#define KISS2 glob->load->kiss2
#define KISS3 glob->load->kiss3
#define BACK glob->load->background
#define HIP glob->load->hips
#define BAL glob->load->balancing
#define CARO glob->load->parrot
#define DOG glob->load->parrot
#define CHOOSE glob->paint->choose_color
#define SIZE glob->paint->pic->size
#define OPACITY glob->paint->pic->opacity
#define RED glob->paint->pic->red
#define GREEN glob->paint->pic->green
#define BLUE glob->paint->pic->blue
#define SETTING glob->paint->option
#define TAILLE glob->paint->size
#define MYPAINT glob->paint
#define PRESSED sfMouse_isButtonPressed
#define DRAWRECTANGLE sfRenderTexture_drawRectangleShape
#define DRAWCIRCLE sfRenderTexture_drawCircleShape
#define RECTANGLEDRAW sfRenderWindow_drawRectangleShape
#define CIRCLEPOS sfCircleShape_setPosition
#define TYPE glob->paint->type->type
#define GRAD glob->gradiants

int description(char *filename);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
void set_sprite(sfSprite *sprite, sfTexture *texture,
    sfVector2f scale, sfVector2f pos);
char *my_strdup(char const *src);
int my_atoi(char *str);
void init_menu(global_t *glob);
void handle_menu_events(global_t *glob);
void update_menu(global_t *glob);
void draw_menu(global_t *glob);
void destroy_menu(global_t *glob);
void init_paint(global_t *glob);
void handle_paint_events(global_t *glob);
void update_paint(global_t *glob);
void draw_paint(global_t *glob);
void destroy_paint(global_t *glob);
void init_load(global_t *glob);
void handle_load_events(global_t *glob);
void update_load(global_t *glob);
void draw_load(global_t *glob);
void destroy_load(global_t *glob);
void destroy_glob(global_t *glob);
void create_animation(const char *texture_path, float duration,
    sfVector2f scale, animation_t *animation);
void update_animation(animation_t *animation, float delta_time);
void sprite_position(sfVector2f pos, animation_t *animation);
void draw_button(global_t *glob, button_t *but);
void destroy_button(button_t *but);
void sound_box(global_t *glob);
char **paths_to_tab(char *standby, char *hover, char *active);
void add_button(button_t *but, char **paths, sfVector2f pos, sfVector2f scale);
char *my_strcpy(char *dest, char const *src);
void handle_writing(global_t *glob, sfEvent event,
    sfVector2f max, sfVector2f min);
sfRectangleShape *sqare_and_rectancle_create(sfVector2f size, sfVector2f pos,
    sfColor color);
sfCircleShape *circle_create(sfVector2f position, float radius, sfColor color,
    bool a);
void standard_image(global_t *glob);
int handle_statue(global_t *glob, sfEvent event);
void handle_settings(global_t *glob, sfEvent event);
void create_texture(global_t *glob);
sfRectangleShape *draw(global_t *glob, sfColor color);
void create_environnement(global_t *glob);
void handle_size_and_opacity(global_t *glob, sfEvent event);
char *put_nbr_to_str(unsigned int nb);
void create_size_and_opacity(global_t *glob);
int drawing(global_t *glob, sfEvent event);
void handle_cursor(global_t *glob, sfEvent event);
void init_cursors(global_t *glob);
void handle_cursor(global_t *glob, sfEvent event);
int cleanup(global_t *glob, sfEvent event);
int form(global_t *glob, sfEvent event);
int pipette(global_t *glob, sfEvent event);
int seal(global_t *glob, sfEvent event);
int sparkling(global_t *glob, sfEvent event);
void save_image(global_t *glob);
void open_file(global_t *glob);
void insert_texture(global_t *glob);
void draw_pinceau_asset(global_t *glob);
void draw_form_asset(global_t *glob);
void draw_gomme_asset(global_t *glob);
void draw_paillette_asset(global_t *glob);
void handle_palette_colors(global_t *glob);
void update_colors(global_t *glob);
void init_gradiant_colors(global_t *glob);
void init_vr(global_t *glob);
void handle_event_vr(global_t *glob);
void update_vr(global_t *glob);
void init_mc(global_t *glob);
void init_vb(global_t *glob);
void init_vvbr(global_t *glob);
void init_gradiant(global_t *glob);
void init_color(global_t *glob);
void handle_outline(global_t *glob);
void init_circles(global_t *glob);
void draw_gomme(global_t *glob, sfEvent event);
void handle_outline_pressed(global_t *glob);
void init_circles_pressed(global_t *glob);
