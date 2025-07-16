#pragma once

#include "./grid.hpp"
#include "./blocks.cpp"

class Game{

    public:
    Game();
    void draw();
    void handleInput();
    void moveBlockDown();
    bool gameOver;
    int score;
    
    private:
    void moveBlockLeft();
    void moveBlockRight();
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    std::vector<Block> blocks;
    Block currBlock;
    Block nextBlock;
    bool isBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();
    void reset();
    void updateScore(int linesCleared, int moveDownPoints);
    Grid grid;
};