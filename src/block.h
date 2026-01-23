//
// Created by Quentin Hautot on 22/01/2026.
//

#ifndef CCRAFT_BLOCK_H
#define CCRAFT_BLOCK_H
#include "raylib.h"

#define BLOCK_AIR 0
#define BLOCK_GRASS 1
#define BLOCK_DIRT 2
#define BLOCK_STONE 3

typedef struct {
    Vector3 position;
    int type;
} Block;


#endif //CCRAFT_BLOCK_H