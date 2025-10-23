/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** update_colors
*/

#include "my.h"

void init_gradiant(global_t *glob)
{
    GRAD->gradiant[NONE].handle_event = &update_colors;
    GRAD->gradiant[NONE].update = &update_colors;
    GRAD->gradiant[NONE].colors = malloc(sizeof(sprite_t));
    GRAD->gradiant[NONE].colors->sprite = sfSprite_create();
    GRAD->gradiant[NONE].colors->texture = sfTexture_createFromFile(
    "assets/couleurs/VR.png", NULL);
    GRAD->gradiant[NONE].colors->pos = (sfVector2f){1, 1};
    GRAD->gradiant[NONE].colors->scale = (sfVector2f){1, 1};
}

void init_vr(global_t *glob)
{
    GRAD->gradiant[VR].handle_event = &handle_event_vr;
    GRAD->gradiant[VR].update = &update_vr;
    GRAD->gradiant[VR].colors = malloc(sizeof(sprite_t));
    GRAD->gradiant[VR].colors->sprite = sfSprite_create();
    GRAD->gradiant[VR].colors->texture = sfTexture_createFromFile(
    "assets/couleurs/VR.png", NULL);
    GRAD->gradiant[VR].colors->pos = (sfVector2f){1220, 500};
    GRAD->gradiant[VR].colors->scale = (sfVector2f){1.4, 1.4};
    sfSprite_setTexture(GRAD->gradiant[VR].colors->sprite,
    GRAD->gradiant[VR].colors->texture, sfTrue);
    sfSprite_setScale(GRAD->gradiant[VR].colors->sprite,
    GRAD->gradiant[VR].colors->scale);
    sfSprite_setPosition(GRAD->gradiant[VR].colors->sprite,
    GRAD->gradiant[VR].colors->pos);
    GRAD->gradiant[VR].colors->image = sfTexture_copyToImage(
    GRAD->gradiant[VR].colors->texture);
}

void init_mc(global_t *glob)
{
    GRAD->gradiant[MC].handle_event = &handle_event_vr;
    GRAD->gradiant[MC].update = &update_vr;
    GRAD->gradiant[MC].colors = malloc(sizeof(sprite_t));
    GRAD->gradiant[MC].colors->sprite = sfSprite_create();
    GRAD->gradiant[MC].colors->texture = sfTexture_createFromFile(
        "assets/couleurs/MC.png", NULL);
    GRAD->gradiant[MC].colors->pos = (sfVector2f){1220, 500};
    GRAD->gradiant[MC].colors->scale = (sfVector2f){1.4, 1.4};
    sfSprite_setTexture(GRAD->gradiant[MC].colors->sprite,
    GRAD->gradiant[MC].colors->texture, sfTrue);
    sfSprite_setScale(GRAD->gradiant[MC].colors->sprite,
    GRAD->gradiant[MC].colors->scale);
    sfSprite_setPosition(GRAD->gradiant[MC].colors->sprite,
    GRAD->gradiant[MC].colors->pos);
    GRAD->gradiant[MC].colors->image = sfTexture_copyToImage(
    GRAD->gradiant[MC].colors->texture);
}

void init_vb(global_t *glob)
{
    GRAD->gradiant[VB].handle_event = &handle_event_vr;
    GRAD->gradiant[VB].update = &update_vr;
    GRAD->gradiant[VB].colors = malloc(sizeof(sprite_t));
    GRAD->gradiant[VB].colors->sprite = sfSprite_create();
    GRAD->gradiant[VB].colors->texture = sfTexture_createFromFile(
    "assets/couleurs/VB.png", NULL);
    GRAD->gradiant[VB].colors->pos = (sfVector2f){1220, 500};
    GRAD->gradiant[VB].colors->scale = (sfVector2f){1.4, 1.4};
    sfSprite_setTexture(GRAD->gradiant[VB].colors->sprite,
    GRAD->gradiant[VB].colors->texture, sfTrue);
    sfSprite_setScale(GRAD->gradiant[VB].colors->sprite,
    GRAD->gradiant[VB].colors->scale);
    sfSprite_setPosition(GRAD->gradiant[VB].colors->sprite,
    GRAD->gradiant[VB].colors->pos);
    GRAD->gradiant[VB].colors->image = sfTexture_copyToImage(
    GRAD->gradiant[VB].colors->texture);
}

void init_vvbr(global_t *glob)
{
    GRAD->gradiant[VVBR].handle_event = &handle_event_vr;
    GRAD->gradiant[VVBR].update = &update_vr;
    GRAD->gradiant[VVBR].colors = malloc(sizeof(sprite_t));
    GRAD->gradiant[VVBR].colors->sprite = sfSprite_create();
    GRAD->gradiant[VVBR].colors->texture = sfTexture_createFromFile(
    "assets/couleurs/VVBR.png", NULL);
    GRAD->gradiant[VVBR].colors->pos = (sfVector2f){1220, 500};
    GRAD->gradiant[VVBR].colors->scale = (sfVector2f){1.4, 1.4};
    sfSprite_setTexture(GRAD->gradiant[VVBR].colors->sprite,
    GRAD->gradiant[VVBR].colors->texture, sfTrue);
    sfSprite_setScale(GRAD->gradiant[VVBR].colors->sprite,
    GRAD->gradiant[VVBR].colors->scale);
    sfSprite_setPosition(GRAD->gradiant[VVBR].colors->sprite,
    GRAD->gradiant[VVBR].colors->pos);
    GRAD->gradiant[VVBR].colors->image = sfTexture_copyToImage(
    GRAD->gradiant[VVBR].colors->texture);
}
