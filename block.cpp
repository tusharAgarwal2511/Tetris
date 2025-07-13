#include "./block.hpp"
#include "./colors.hpp"
#include "./position.hpp"
#include<raylib.h>

Block::Block(){
    this->cellSize = 30;
    this->rotationState = 0;
    this->colors = getCellColors();
}


void Block::draw(){
    std::vector<Position> tiles = cells[rotationState];
    for(Position item: tiles){
        DrawRectangle(item.col * cellSize + 1, item.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}