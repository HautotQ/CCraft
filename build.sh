#!/bin/bash
set -e

cd "$(dirname "$0")"

cc \
src/*.c \
main.c \
-o launcher \
-I./src \
-lraylib \
-lm \
-framework Cocoa \
-framework OpenGL \
-framework IOKit \
-framework CoreVideo

echo "✅ Build terminé → ./launcher"
