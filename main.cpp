#include <iostream>
#include <raylib.h>
#include "./game.hpp"
#include "./colors.hpp"

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
    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);
    Game game = Game();

    Font font = LoadFontEx("./rimouski.ttf", 64, 0, 0);

    while (WindowShouldClose() == false) {

        game.handleInput();
        if(eventTriggered(0.2)){
            game.moveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "SCORE", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "NEXT", {370, 175}, 38, 2, WHITE);
        if(game.gameOver){
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {320 + ((170 - textSize.x) / 2), 65}, 38, 2, WHITE);

        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.draw();
        EndDrawing();
    }
    
    CloseWindow();
};