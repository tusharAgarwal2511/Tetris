#include <iostream>
#include <raylib.h>
#include "./game.hpp"

using namespace std;

double lastUpdateTime = 0;


bool eventTriggered(double interval){
    double currTime = GetTime();
    if(currTime - lastUpdateTime >= interval){
        lastUpdateTime = currTime;
        return true;
    }
    return false;
}

int main() {
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);
    Game game = Game();

    while (WindowShouldClose() == false) {

        // Handle inputs
        game.handleInput();
        if(eventTriggered(0.3)){
            game.moveBlockDown();
        }

        // Update positions

        // Draw objects
        BeginDrawing();
        ClearBackground(darkBlue);
        game.draw();
        EndDrawing();
    }
    
    CloseWindow();
};