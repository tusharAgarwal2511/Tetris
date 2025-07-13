#include <iostream>
#include <raylib.h>
#include "./grid.hpp"

using namespace std;

int main() {
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid g;
    g.grid[0][0] = 1;
    g.grid[3][5] = 4;
    g.grid[17][8] = 7;
    g.print();
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(darkBlue);
        g.draw();
        EndDrawing();
    }
    
    CloseWindow();
}