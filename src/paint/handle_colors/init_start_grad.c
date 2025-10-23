/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** update_colors
*/

#include "my.h"

void init_butt_two(global_t *glob)
{
    sfSprite_setScale(GRAD->butt[VB].sprite, GRAD->butt[VB].scale);
    sfSprite_setPosition(GRAD->butt[VB].sprite, GRAD->butt[VB].pos);
    GRAD->butt[VR].sprite = sfSprite_create();
    GRAD->butt[VR].texture = sfTexture_createFromFile("assets/buttons/BVR.png",
    NULL);
    GRAD->butt[VR].pos = (sfVector2f){1428, 784};
    GRAD->butt[VR].scale = (sfVector2f){0.5, 0.5};
    sfSprite_setTexture(GRAD->butt[VR].sprite, GRAD->butt[VR].texture, sfTrue);
    sfSprite_setScale(GRAD->butt[VR].sprite, GRAD->butt[VR].scale);
    sfSprite_setPosition(GRAD->butt[VR].sprite, GRAD->butt[VR].pos);
    GRAD->butt[VVBR].sprite = sfSprite_create();
    GRAD->butt[VVBR].texture = sfTexture_createFromFile(
    "assets/buttons/BVVBR.png", NULL);
    GRAD->butt[VVBR].pos = (sfVector2f){1505, 792};
    GRAD->butt[VVBR].scale = (sfVector2f){0.45, 0.45};
    sfSprite_setTexture(GRAD->butt[VVBR].sprite, GRAD->butt[VVBR].texture,
    sfTrue);
    sfSprite_setScale(GRAD->butt[VVBR].sprite, GRAD->butt[VVBR].scale);
    sfSprite_setPosition(GRAD->butt[VVBR].sprite, GRAD->butt[VVBR].pos);
}

void init_butt(global_t *glob)
{
    GRAD->butt[NONE].sprite = sfSprite_create();
    GRAD->butt[NONE].texture = sfTexture_createFromFile(
    "assets/buttons/BMC.png", NULL);
    GRAD->butt[NONE].pos = (sfVector2f){1220, 500};
    GRAD->butt[NONE].scale = (sfVector2f){0.5, 0.5};
    GRAD->butt[MC].sprite = sfSprite_create();
    GRAD->butt[MC].texture = sfTexture_createFromFile("assets/buttons/BMC.png",
    NULL);
    GRAD->butt[MC].pos = (sfVector2f){1570, 792};
    GRAD->butt[MC].scale = (sfVector2f){0.45, 0.45};
    sfSprite_setTexture(GRAD->butt[MC].sprite, GRAD->butt[MC].texture, sfTrue);
    sfSprite_setScale(GRAD->butt[MC].sprite, GRAD->butt[MC].scale);
    sfSprite_setPosition(GRAD->butt[MC].sprite, GRAD->butt[MC].pos);
    GRAD->butt[VB].sprite = sfSprite_create();
    GRAD->butt[VB].texture = sfTexture_createFromFile("assets/buttons/BVB.png",
    NULL);
    GRAD->butt[VB].pos = (sfVector2f){1615, 784};
    GRAD->butt[VB].scale = (sfVector2f){0.5, 0.5};
    sfSprite_setTexture(GRAD->butt[VB].sprite, GRAD->butt[VB].texture, sfTrue);
    init_butt_two(glob);
}

void init_gradiant_colors(global_t *glob)
{
    glob->gradiants = malloc(sizeof(gradiants_t));
    GRAD->current_gradiant = NONE;
    GRAD->butt_gradiant = NONE;
    GRAD->gradiant[NONE].init = &init_gradiant;
    GRAD->gradiant[NONE].init(glob);
    GRAD->gradiant[VR].init = &init_vr;
    GRAD->gradiant[VR].init(glob);
    GRAD->gradiant[MC].init = &init_mc;
    GRAD->gradiant[MC].init(glob);
    GRAD->gradiant[VB].init = &init_vb;
    GRAD->gradiant[VB].init(glob);
    GRAD->gradiant[VVBR].init = &init_vvbr;
    GRAD->gradiant[VVBR].init(glob);
    init_butt(glob);
}
