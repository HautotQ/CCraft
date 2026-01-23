//
// Created by Quentin Hautot on 22/01/2026.
//

#include "player.h"
#include "controls.h"

#define GRAVITY 0.04f
#define PLAYER_HEIGHT 1.8f

// Vérifie si le bloc est solide
static int IsBlockSolid(World *world, int x, int y, int z) {
    if (x < 0 || x >= 16 || y < 0 || y >= 16 || z < 0 || z >= 16) return 0;
    int type = world->blocks[x][y][z].type;
    return (type == 1 || type == 2); // 1=grass, 2=dirt
}

// Spawn au-dessus du premier bloc solide
void SpawnPlayer(World *world, Player *player) {
    int x = 8; // centre du monde
    int z = 8;

    for (int y = WORLD_SIZE - 1; y >= 0; y--) {
        if (IsBlockSolid(world, x, y, z)) {
            player->position = (Vector3){x + 0.5f, y + 1.5f, z + 0.5f};
            player->velocity = (Vector3){0,0,0};
            return;
        }
    }

    // fallback si aucun bloc solide
    player->position = (Vector3){x + 0.5f, 20.0f, z + 0.5f};
    player->velocity = (Vector3){0,0,0};
}



void UpdatePlayer(World *world, Player *player, ControlInput input)
{
    float speed = 0.1f;

    // mouvement horizontal
    player->velocity.x = input.moveX * speed;
    player->velocity.z = input.moveZ * speed;

    // gravité
    if (!player->onGround)
        player->velocity.y -= 0.03f;

    // saut
    if (input.jump && player->onGround) {
        player->velocity.y = 0.5f;
        player->onGround = 0;
    }

    // appliquer vitesse
    player->position.x += player->velocity.x;
    player->position.y += player->velocity.y;
    player->position.z += player->velocity.z;

    // collision sol simplifiée
    if (player->position.y < 1.0f) {
        player->position.y = 1.0f;
        player->velocity.y = 0;
        player->onGround = 1;
    }
}


