#include <iostream>
#include <raylib.h>
#include "./grid.hpp"
#include "./blocks.cpp"

using namespace std;

int main() {
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid g;
    g.print();

    LBlock block = LBlock();

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(darkBlue);
        g.draw();
        block.draw();
        EndDrawing();
    }
    
    CloseWindow();
};