#include <iostream>
#include <raylib.h>
#include "./game.hpp"

using namespace std;

int main() {
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    Game game = Game();

    while (WindowShouldClose() == false) {

        // Handle inputs
        game.handleInput();


        // Update positions

        // Draw objects
        BeginDrawing();
        ClearBackground(darkBlue);
        game.draw();
        EndDrawing();
    }
    
    CloseWindow();
};