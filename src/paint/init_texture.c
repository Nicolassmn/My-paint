/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** init_texture
*/

#include "my.h"

static void next_init_over_and_charac(global_t *glob)
{
    MYPAINT->type->primary = sqare_and_rectancle_create((sfVector2f){75, 75},
    (sfVector2f){1580, 657}, MYPAINT->type->basic->color1);
    MYPAINT->type->secondary = sqare_and_rectancle_create((sfVector2f){75, 75},
    (sfVector2f){1700, 657}, sfBlack);
    MYPAINT->type->cleanup->gomme1 = sqare_and_rectancle_create(
    (sfVector2f){75, 75}, (sfVector2f){1700, 800},
    sfColor_fromRGB(115, 102, 189));
    MYPAINT->type->cleanup->gomme2 = circle_create((sfVector2f){1570, 785}, 50,
    sfColor_fromRGB(115, 102, 189), true);
}

static void init_over_and_charac(global_t *glob)
{
    MYPAINT->type->over = malloc(sizeof(animation_t));
    MYPAINT->type->basic = malloc(sizeof(pinceau_t));
    MYPAINT->type->cleanup = malloc(sizeof(gomme_t));
    MYPAINT->type->forms = malloc(sizeof(form_t));
    MYPAINT->type->sceau = malloc(sizeof(sceau_t));
    create_animation("assets/over.png", 0, (sfVector2f){1.6, 1.6},
    MYPAINT->type->over);
    sprite_position((sfVector2f){1150, 480}, MYPAINT->type->over);
    MYPAINT->type->basic->color1 = sfColor_fromRGB(RED, GREEN, BLUE);
    MYPAINT->type->basic->color2 = sfColor_fromRGB(0, 0, 0);
    MYPAINT->type->cleanup->color1 = sfColor_fromRGB(255, 255, 255);
    MYPAINT->type->cleanup->color2 = sfColor_fromRGB(0, 0, 0);
    MYPAINT->type->cleanup->one = false;
    next_init_over_and_charac(glob);
}

static void next_init_cursors(global_t *glob)
{
    sfSprite_setOrigin(TYPE[STAR].sprite, (sfVector2f){333, 187.5});
    sfSprite_setOrigin(TYPE[SCEAU].sprite, (sfVector2f){333, 187.5});
    sfSprite_setOrigin(TYPE[PIPETTE].sprite, (sfVector2f){333, 187.5});
    TYPE[PINCEAU].effet_cursor = &drawing;
    TYPE[GOMME].effet_cursor = &cleanup;
    TYPE[COEUR].effet_cursor = &form;
    TYPE[STAR].effet_cursor = &sparkling;
    TYPE[SCEAU].effet_cursor = &seal;
    TYPE[PIPETTE].effet_cursor = &pipette;
    init_over_and_charac(glob);
}

void init_cursors(global_t *glob)
{
    MYPAINT->type->current_type = PINCEAU;
    CURSOR = circle_create((sfVector2f){MOUSE.x, MOUSE.y}, 5,
        sfColor_fromRGBA(255, 255, 255, 0), true);
    create_animation("assets/curseurs/gomme.png", 0, (sfVector2f){0.5, 0.5},
    &TYPE[GOMME]);
    create_animation("assets/curseurs/coeur.png", 0, (sfVector2f){0.5, 0.5},
    &TYPE[COEUR]);
    create_animation("assets/curseurs/paillettes.png", 0,
    (sfVector2f){0.5, 0.5}, &TYPE[STAR]);
    create_animation("assets/curseurs/seau.png", 0, (sfVector2f){0.5, 0.5},
    &TYPE[SCEAU]);
    create_animation("assets/curseurs/pipette.png", 0, (sfVector2f){0.5, 0.5},
    &TYPE[PIPETTE]);
    sfSprite_setOrigin(TYPE[GOMME].sprite, (sfVector2f){333, 187.5});
    sfSprite_setOrigin(TYPE[COEUR].sprite, (sfVector2f){333, 187.5});
    next_init_cursors(glob);
}

static void next_set_option(global_t *glob)
{
    create_animation("assets/buttons/butt_ouv.png", 0.5,
    (sfVector2f){1.5, 1.5}, &SETTING->hover[1]);
    create_animation("assets/buttons/butt_nv.png", 0.5,
    (sfVector2f){1.5, 1.5}, &SETTING->hover[2]);
    create_animation("assets/buttons/butt_ins.png", 0.5,
    (sfVector2f){1.5, 1.5}, &SETTING->hover[3]);
    sprite_position((sfVector2f){965, 678}, &SETTING->hover[0]);
    sprite_position((sfVector2f){965, 518}, &SETTING->hover[1]);
    sprite_position((sfVector2f){965, 440}, &SETTING->hover[2]);
    sprite_position((sfVector2f){965, 600}, &SETTING->hover[3]);
    for (int i = 0; i < 4; i++) {
        sfSprite_setOrigin(SETTING->hover[i].sprite, (sfVector2f){333, 187});
        SETTING->hover[i].a = false;
    }
    SETTING->activation = false;
}

static void set_option(global_t *glob)
{
    SETTING->handle = malloc(sizeof(animation_t));
    SETTING->file = malloc(sizeof(animation_t));
    create_animation("assets/option.png", 0.5, (sfVector2f){0.1, 0.1},
    SETTING->handle);
    create_animation("assets/File.png", 0.5, (sfVector2f){1, 1},
    SETTING->file);
    sprite_position((sfVector2f){25, 90}, SETTING->handle);
    sprite_position((sfVector2f){960, 540}, SETTING->file);
    sfSprite_setOrigin(SETTING->file->sprite, (sfVector2f){666, 325});
    SETTING->background = sqare_and_rectancle_create((sfVector2f){1920, 1080},
    (sfVector2f){0, 0}, sfColor_fromRGBA(0, 0, 0, 120));
    create_animation("assets/buttons/butt_sauv.png", 0.5,
    (sfVector2f){1.5, 1.5}, &SETTING->hover[0]);
    next_set_option(glob);
}

void create_texture(global_t *glob)
{
    create_animation("assets/background/Barbs.png", 0.05,
        (sfVector2f){1, 0.94}, MYPAINT->background);
    MYPAINT->background->image =
        sfTexture_copyToImage(MYPAINT->background->texture);
    create_animation("assets/Size.png", 0.05, (sfVector2f){0.8, 0.8}, TAILLE);
    sprite_position((sfVector2f){1150, 100}, TAILLE);
    MYPAINT->taile->point = circle_create((sfVector2f){1580, 350}, 5,
        sfColor_fromRGB(255, 192, 203), true);
    MYPAINT->opacity->point = circle_create((sfVector2f){1780, 498}, 5,
        sfColor_fromRGB(255, 192, 203), true);
    MYPAINT->taile->primary = sqare_and_rectancle_create((sfVector2f){40, 20},
        (sfVector2f){1665, 305}, sfColor_fromRGB(255, 192, 203));
    MYPAINT->opacity->primary = sqare_and_rectancle_create(
        (sfVector2f){40, 20}, (sfVector2f){1665, 450},
        sfColor_fromRGB(255, 192, 203));
    MYPAINT->taile->pos = (sfVector2f){1580, 350};
    MYPAINT->opacity->pos = (sfVector2f){1780, 498};
    set_option(glob);
}

static void set_text(global_t *glob)
{
    char *size = malloc(sizeof(char) * 10);
    char *opacity = malloc(sizeof(char) * 10);

    my_strcpy(size, put_nbr_to_str(SIZE));
    my_strcat(size, "px");
    sfText_setString(MYPAINT->taile->data, size);
    sfText_setPosition(MYPAINT->taile->data, (sfVector2f){1665, 305});
    sfText_setScale(MYPAINT->taile->data, (sfVector2f){0.6, 0.6});
    my_strcpy(opacity, "100%");
    sfText_setString(MYPAINT->opacity->data, opacity);
    sfText_setPosition(MYPAINT->opacity->data, (sfVector2f){1665, 450});
    sfText_setScale(MYPAINT->opacity->data, (sfVector2f){0.6, 0.6});
    free(size);
    free(opacity);
}

void create_size_and_opacity(global_t *glob)
{
    MYPAINT->taile->font = sfFont_createFromFile("assets/font/Cabolafe.otf");
    MYPAINT->taile->data = sfText_create();
    MYPAINT->opacity->font = sfFont_createFromFile("assets/font/Cabolafe.otf");
    MYPAINT->opacity->data = sfText_create();
    sfText_setFont(MYPAINT->taile->data, MYPAINT->taile->font);
    sfText_scale(MYPAINT->taile->data, (sfVector2f){1.2, 1.2});
    sfText_setFillColor(MYPAINT->taile->data, sfBlack);
    sfText_setPosition(MYPAINT->taile->data, (sfVector2f){1550, 35});
    sfText_setFont(MYPAINT->opacity->data, MYPAINT->opacity->font);
    sfText_scale(MYPAINT->opacity->data, (sfVector2f){1.2, 1.2});
    sfText_setFillColor(MYPAINT->opacity->data, sfBlack);
    sfText_setPosition(MYPAINT->opacity->data, (sfVector2f){1550, 35});
    set_text(glob);
}

void create_environnement(global_t *glob)
{
    MYPAINT->pic->sprite = sfSprite_create();
    MYPAINT->but->list = NULL;
    MYPAINT->but->draw = &draw_button;
    MYPAINT->but->destroy = &destroy_button;
    SIZE = 10;
    OPACITY = 255;
    RED = 255;
    GREEN = 192;
    BLUE = 203;
    MYPAINT->type->current_type = PINCEAU;
    MOUSE = sfMouse_getPositionRenderWindow(WINDOW);
    VIEW = sfView_create();
    sfView_setSize(VIEW, (sfVector2f){1920, 1080});
    sfView_setCenter(VIEW, (sfVector2f){940, 540});
}
