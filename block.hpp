#pragma once


#include<vector>
#include<map>
#include "./position.hpp"
#include "./colors.hpp"

class Block{
    
    public:
    int id;
    std::map<int, std::vector<Position>> cells;
    Block();
    void draw(int offSetX, int offSetY);
    void move(int rows, int cols);
    std::vector<Position> getCellPositions();
    void rotate();
    void undoRotation();

    private : int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int colOffset;
};