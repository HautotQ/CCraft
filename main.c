#include "raylib.h"
#include "src/world.h"
#include "src/player.h"
#include "src/controls.h"

int main(void) {
    InitWindow(800, 600, "OBJ Loader - Raylib");
    int gamepad = SetupController();
    SetTargetFPS(60);

    World sample = CreateSampleWorld();

    Player player;
    SpawnPlayer(&sample, &player);

    // Caméra style Minecraft (FPS)
    Camera3D camera = { 0 };
    // après SpawnPlayer
    camera.position = player.position;
    camera.position.y += 1.6f; // hauteur des yeux
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 70.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    // Activer le mode souris invisible pour FPS
    DisableCursor();  // cache le curseur

    while (!WindowShouldClose())
    {
        ControlInput input = GetControls(gamepad);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (IsGamepadAvailable(0)) {
            DrawText("GAMEPAD DETECTED", 10, 40, 20, GREEN);
        } else {
            DrawText("NO GAMEPAD", 10, 40, 20, RED);
        }

        if (IsGamepadAvailable(0)) {
            for (int i = 0; i < 8; i++) {
                float v = GetGamepadAxisMovement(0, i);
                DrawText(TextFormat("AXIS %d = %.2f", i, v),
                         10, 70 + i * 20, 18, DARKGRAY);
            }
        }

        float speed = 0.1f;

        player.position.x += input.moveX * speed;
        player.position.z += input.moveZ * speed;

        // saut
        if (input.jump && player.velocity.y == 0) {
            player.velocity.y = 0.5f;
        }
        // gravité + spawn
        UpdatePlayer(&sample, &player, input);


        // caméra FPS style Minecraft
        camera.position = player.position;
        camera.position.y += 1.6f;
        camera.target = (Vector3){player.position.x, player.position.y + 1.6f, player.position.z + 1.0f};

        BeginMode3D(camera);
        DrawWorld(&sample);
        EndMode3D();

        DrawText("Minecraft Gravity + Spawn", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    UnloadWorld(&sample);
    CloseWindow();
    return 0;
}
