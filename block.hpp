#pragma once


#include<vector>
#include<map>
#include "./position.hpp"
#include "./colors.hpp"

class Block{
    
    public:
    Block();
    void draw();
    void move(int rows, int cols);
    int id;
    std::map<int, std::vector<Position>> cells;
    std::vector<Position> getCellPositions();

    private : int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int colOffset;
};