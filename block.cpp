#include "./block.hpp"
#include "./colors.hpp"
#include "./position.hpp"
#include<raylib.h>

Block::Block(){
    this->cellSize = 30;
    this->rotationState = 0;
    this->colors = getCellColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::draw(int offSetX, int offSetY){
    std::vector<Position> tiles = getCellPositions();
    for(Position item: tiles){
        DrawRectangle(item.col * cellSize + offSetX, item.row * cellSize + offSetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::move(int rows, int cols){
    rowOffset += rows;
    colOffset += cols;
}


std::vector<Position> Block::getCellPositions(){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;
    for(Position item: tiles){
        Position newPosition = Position(item.row + rowOffset, item.col + colOffset);
        movedTiles.push_back(newPosition);
    }
    return movedTiles;
}


void Block::rotate(){
    rotationState++;
    if(rotationState == (int )cells.size()) rotationState = 0;
}

void Block::undoRotation(){
    rotationState--;
    if(rotationState == -1){
        rotationState = cells.size() - 1;
    }
}