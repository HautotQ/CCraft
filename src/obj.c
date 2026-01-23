//
// Created by Quentin Hautot on 22/01/2026.
//

#include "obj.h"
#include "raylib.h"

Model Load3DModel(const char *path) {
    Model model = LoadModel(path);

    if (model.meshCount == 0)
    {
        TraceLog(LOG_ERROR, "Impossible de charger le modèle OBJ");
    }

    return model;
}
