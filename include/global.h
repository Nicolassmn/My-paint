/*
** EPITECH PROJECT, 2023
** myhunter
** File description:
** mystruct
*/

#pragma once
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include "button.h"

#define SCENES 3
#define CURSORS 6
#define GRADIANTS 5

typedef struct global_s global_t;

typedef enum SCENE {
    LOAD,
    MENU,
    PAINT
} SCENE_E;

typedef enum GRADIANT {
    NONE,
    MC,
    VB,
    VR,
    VVBR
} GRADIANT_E;

typedef enum CURSOR {
    N,
    M,
    G,
    C,
    PA,
    PO,
    S
} CURSOR_E;

typedef enum TYPE {
    PINCEAU,
    GOMME,
    COEUR,
    STAR,
    SCEAU,
    PIPETTE,
} TYPE_E;

typedef struct my_int_s {
    int length_one[10];
    int length_two[10];
    int width_one[4];
    int width_two[4];
} my_int_t;

typedef struct circle_s {
    sfCircleShape *circle;
    sfVector2f position;
} circle_t;

typedef struct sprites_s {
    sfVector2f scale;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *texture;
    sfImage* image;
} sprites_t;

typedef struct scene_s {
    void (*init)(global_t *global);
    void (*handle_event)(global_t *global);
    void (*update)(global_t *global);
    void (*draw)(global_t *global);
    void (*destroy)(global_t *global);
} scene_t;

typedef struct gradiant_s {
    void (*init)(global_t *global);
    void (*handle_event)(global_t *global);
    void (*update)(global_t *global);
    sprites_t *colors;
} gradiant_t;

typedef struct gradiants_s {
    GRADIANT_E current_gradiant;
    gradiant_t gradiant[GRADIANTS];
    GRADIANT_E butt_gradiant;
    sprites_t butt[GRADIANTS];
    sprites_t *VB;
    sprites_t *VVBR;
    sprites_t *VR;
    sprites_t *MC;
} gradiants_t;

typedef struct animation_s {
    sfCircleShape *pinceau;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f origin;
    float frame_duration;
    float seconds;
    int frame_size;
    int end_frame;
    sfIntRect bounds;
    sfSprite *sprite;
    sfTexture *texture;
    sfBool a;
    int (*effet_cursor)(global_t *glob, sfEvent event);
    void (*update)(struct animation_s *this, float delta_time);
    sfImage* image;
} animation_t;

typedef struct pinceau_s {
    sfColor color1;
    sfColor color2;
} pinceau_t;

typedef struct gomme_s {
    sfColor color1;
    sfColor color2;
    sfRectangleShape *gomme1;
    bool one;
    sfCircleShape *gomme2;
} gomme_t;

typedef struct sceau_s {

} sceau_t;

typedef struct form_s {
    animation_t *coeur;
} form_t;

typedef struct picture_s {
    sfSprite *sprite;
    sfRectangleShape *image;
    int size;
    int opacity;
    int red;
    int green;
    int blue;
} picture_t;

typedef struct handle_s {
    sfVector2f pos;
    sfCircleShape *point;
    sfFont *font;
    sfRectangleShape *primary;
    sfText *data;
} handle_t;

typedef struct cursor_s {
    animation_t *over;
    TYPE_E current_type;
    animation_t type[6];
    pinceau_t *basic;
    gomme_t *cleanup;
    form_t *forms;
    sceau_t *sceau;
    sfRectangleShape *primary;
    sfRectangleShape *secondary;
} cursor_t;

typedef struct menu_s {
    button_t *but;
    animation_t hips[2];
    animation_t *background;
} menu_t;

typedef struct load_s {
    animation_t hips[12];
    animation_t balancing[12];
    animation_t plant_dog[13];
    animation_t parrot[13];
    animation_t kiss1;
    animation_t kiss2;
    animation_t kiss3;
    animation_t background;
} load_t;

typedef struct setting_s {
    animation_t *handle;
    animation_t *file;
    sfRectangleShape *background;
    bool activation;
    animation_t hover[4];
} setting_t;

typedef struct outline_s {
    sfCircleShape *hover_curs;
    sfCircleShape *active_curs;
    sfCircleShape *hover_color;
    sfCircleShape *active_color;
} outline_t;

typedef struct paint_s {
    outline_t *outl;
    cursor_t *type;
    picture_t *pic;
    sfVector2i mouse;
    button_t *but;
    animation_t *background;
    sfColor color[2];
    handle_t *taile;
    handle_t *opacity;
    animation_t *size;
    setting_t *option;
} paint_t;

typedef struct focus_s {
    float zoomAmout;
    sfView *view;
} focus_t;

typedef struct global_s {
    bool open;
    sfRenderWindow *window;
    sfRenderTexture *texture;
    SCENE_E current_scene;
    CURSOR_E current_cursor;
    CURSOR_E current_cpressed;
    scene_t scenes[SCENES];
    circle_t circles[7];
    circle_t circles_pressed[7];
    gradiants_t *gradiants;
    sfClock *clock;
    float timer;
    float delta_time;
    focus_t *zoom;
    menu_t *menu;
    load_t *load;
    paint_t *paint;
    my_int_t *my_int;
} global_t;
