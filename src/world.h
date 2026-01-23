//
// Created by Quentin Hautot on 22/01/2026.
//

#ifndef CCRAFT_WORLD_H
#define CCRAFT_WORLD_H

#include "block.h"    // uniquement ce dont on a besoin
#include "raylib.h"   // pour Model, Vector3, etc.

#define WORLD_SIZE 16
#define GRAVITY 0.04f

typedef struct {
    Block blocks[WORLD_SIZE][WORLD_SIZE][WORLD_SIZE];
    Model grassModel;
    Model dirtModel;
    Model stoneModel;
} World;

World CreateSampleWorld(void);
void DrawWorld(World *world);
void UnloadWorld(World *world);

#endif //CCRAFT_WORLD_H
