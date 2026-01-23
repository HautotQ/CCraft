//
// Created by Quentin Hautot on 22/01/2026.
//

#ifndef CCRAFT_CONTROLS_H
#define CCRAFT_CONTROLS_H
typedef struct {
    float moveX;
    float moveZ;
    int jump;
} ControlInput;

int SetupController(void);
ControlInput GetControls(int gamepad);

#endif //CCRAFT_CONTROLS_H