//
// Created by Quentin Hautot on 22/01/2026.
//

#include "controls.h"
#include "raylib.h"
#include "math.h"

#if defined(RAYLIB_VERSION_MAJOR) && RAYLIB_VERSION_MAJOR >= 4
    #define BUTTON_A GAMEPAD_BUTTON_LEFT_FACE_DOWN
#else
    #define BUTTON_A GAMEPAD_BUTTON_A
#endif

int SetupController(void) {
    if (IsGamepadAvailable(0)) return 0;
    return -1;
}

ControlInput GetControls(int gamepad) {
    ControlInput input = {0};

    if (gamepad >= 0 && IsGamepadAvailable(gamepad)) {

        float moveX = GetGamepadAxisMovement(gamepad, 0); // AXIS 0
        float moveZ = GetGamepadAxisMovement(gamepad, 1); // AXIS 1

        float deadzone = 0.15f;

        if (fabsf(moveX) > deadzone) input.moveX = moveX;
        if (fabsf(moveZ) > deadzone) input.moveZ = moveZ;

        if (IsGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
            input.jump = 1;

    } else {
        if (IsKeyDown(KEY_W)) input.moveZ = -1.0f;
        if (IsKeyDown(KEY_S)) input.moveZ =  1.0f;
        if (IsKeyDown(KEY_A)) input.moveX = -1.0f;
        if (IsKeyDown(KEY_D)) input.moveX =  1.0f;
        if (IsKeyPressed(KEY_SPACE)) input.jump = 1;
    }

    return input;
}



