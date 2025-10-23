/*
** EPITECH PROJECT, 2024
** rendu_paint
** File description:
** write
*/

#include "my.h"

void write_to_image(global_t *glob, sfEvent event)
{
    if (event.type == sfEvtTextEntered && event.text.unicode < 128)
            printf("ASCII character entered: %c\n", (char)event.text.unicode)
}
