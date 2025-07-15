#pragma once

#include "./grid.hpp"
#include "./blocks.cpp"

class Game{

    public:
    Game();
    Grid grid;
    Block getRandomBlock();
    std::vector<Block> getAllBlocks();
    void draw();
    void handleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();

    private:
    std::vector<Block> blocks;
    Block currBlock;
    Block nextBlock;
    bool isBlockOutside();
    void rotateBlock();
    void lockBlock();
    bool blockFits();
};