//
// Created by Quentin Hautot on 22/01/2026.
//

#ifndef CCRAFT_PLAYER_H
#define CCRAFT_PLAYER_H

#include "raylib.h"
#include "world.h"
#include "controls.h"

typedef struct {
    Vector3 position;
    Vector3 velocity;
    int onGround;
} Player;


void SpawnPlayer(World *world, Player *player);
void UpdatePlayer(World *world, Player *player, ControlInput input);

#endif //CCRAFT_PLAYER_H
