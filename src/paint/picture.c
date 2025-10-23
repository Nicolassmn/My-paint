/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** picture
*/

#include "my.h"

void standard_image(global_t *glob)
{
    glob->texture = sfRenderTexture_create(1152, 720, sfFalse);
    sfRenderTexture_clear(glob->texture, sfWhite);
    SETTING->activation = false;
}

static void get_bound_new_texture(global_t *glob, sfSprite *sprite)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);

    for (float i = 0.1; rect.width > 1152; i += 0.1) {
        sfSprite_setScale(sprite, (sfVector2f){1 - i, 1 - i});
        rect = sfSprite_getGlobalBounds(sprite);
    }
    for (float i = 0.1; rect.height > 720; i += 0.1) {
        sfSprite_setScale(sprite, (sfVector2f){1 - i, 1 - i});
        rect = sfSprite_getGlobalBounds(sprite);
    }
    TEXTURE = sfRenderTexture_create(rect.width, rect.height, sfFalse);
    sfRenderTexture_clear(glob->texture, sfWhite);
}

static void make_sprite(global_t *glob)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    get_bound_new_texture(glob, sprite);
    sfRenderTexture_drawSprite(TEXTURE, sprite, NULL);
    sfRenderTexture_display(TEXTURE);
}

void open_file(global_t *glob)
{
    char *str = NULL;
    size_t size = 0;
    sfTexture *texture;
    char *path = NULL;
    int i = 0;

    write(1, "Veuillez rentrer le chemin vers votre image:\n", 45);
    getline(&str, &size, stdin);
    path = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (; str[i + 1]; i++)
        path[i] = str[i];
    path[i] = '\0';
    texture = sfTexture_createFromFile(path, NULL);
    if (!texture) {
        write(1, "Failed !\n", 9);
    } else
        make_sprite(glob);
    SETTING->activation = false;
}

void save_image(global_t *glob)
{
    sfImage *image;
    const sfTexture* texture = sfRenderTexture_getTexture(TEXTURE);
    size_t size = 0;
    char *str = NULL;
    int i = 0;
    char *path = NULL;

    write(1, "Veuillez donnez le nom à votre image:\n", 37);
    getline(&str, &size, stdin);
    path = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (; str[i + 1]; i++)
        path[i] = str[i];
    path[i] = '\0';
    my_strcat(path, ".png");
    image = sfTexture_copyToImage(texture);
    sfImage_saveToFile(image, path);
    sfImage_destroy(image);
    SETTING->activation = false;
}

void insert_texture(global_t *glob)
{
    SETTING->activation = false;
}
