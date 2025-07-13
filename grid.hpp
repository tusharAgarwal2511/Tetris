#pragma once

#include <vector>
#include <raylib.h>
class Grid{

    public:

    int grid[20][10];
    void initialize();
    void print();
    Grid();
    void draw();


    private:

    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
}; 