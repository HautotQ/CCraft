//
// Created by Quentin Hautot on 22/01/2026.
//

#include "world.h"
#include "raylib.h"


World CreateSampleWorld(void)
{
    World world = { 0 };

    // Charger les modèles UNE SEULE FOIS
    world.grassModel = LoadModel("assets/3d_models/grass/grass.obj");
    world.dirtModel  = LoadModel("assets/3d_models/dirt/dirt.obj");
    world.stoneModel = LoadModel("assets/3d_models/stone/stone.obj");

    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            for (int z = 0; z < 16; z++) {

                world.blocks[x][y][z].position = (Vector3){
                    (float)x,
                    (float)y,
                    (float)z
                };

                // Simple terrain
                if (y == 15)
                    world.blocks[x][y][z].type = 1; // grass
                else
                    world.blocks[x][y][z].type = 2; // dirt
            }
        }
    }

    return world;
}

void DrawWorld(World *world)
{
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 16; y++) {
            for (int z = 0; z < 16; z++) {

                Block *b = &world->blocks[x][y][z];

                if (b->type == 1)
                    DrawModel(world->grassModel, b->position, 1.0f, WHITE);
                else if (b->type == 2)
                    DrawModel(world->dirtModel, b->position, 1.0f, WHITE);

            }
        }
    }
}

void UnloadWorld(World *world)
{
    UnloadModel(world->grassModel);
    UnloadModel(world->dirtModel);
}

