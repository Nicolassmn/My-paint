/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** animation
*/

#include "my.h"

void create_animation(const char *texture_path, float duration,
    sfVector2f scale, animation_t *animation)
{
    sfVector2u size = {0, 0};

    animation->sprite = sfSprite_create();
    animation->texture = sfTexture_createFromFile(texture_path, NULL);
    size = sfTexture_getSize(animation->texture);
    animation->bounds = (sfIntRect){0, 0, size.y - 12.5, size.y};
    animation->frame_duration = duration;
    animation->seconds = 0;
    animation->end_frame = size.x;
    animation->frame_size = size.y + 25;
    animation->update = &update_animation;
    animation->a = false;
    animation->scale = (sfVector2f){scale.x, scale.y};
    sfSprite_setScale(animation->sprite, animation->scale);
    sfSprite_setTexture(animation->sprite, animation->texture, sfTrue);
}

void update_animation(animation_t *animation, float delta_time)
{
    animation->seconds += delta_time;
    while (animation->seconds >= animation->frame_duration) {
        animation->bounds.left += animation->frame_size;
        if (animation->bounds.left >= animation->end_frame)
            animation->bounds.left = 0;
        animation->seconds -= delta_time;
        if (animation->seconds < animation->frame_duration)
            animation->seconds = 0;
    }
    sfSprite_setTextureRect(animation->sprite, animation->bounds);
}

void sprite_position(sfVector2f pos, animation_t *animation)
{
    animation->pos = (sfVector2f){pos.x, pos.y};
    sfSprite_setPosition(animation->sprite, animation->pos);
}
