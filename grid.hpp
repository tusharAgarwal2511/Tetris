#pragma once

#include <vector>
#include <raylib.h>
class Grid{

    public:

    Grid();
    int grid[20][10];
    void initialize();
    void print();
    bool isCellOutside(int row, int col);
    void draw();
    bool isCellEmpty(int row, int col);
    int clearFullRows();


    private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
    void clearRow(int row);
    bool isRowFull(int row);
    void moveRowsDown(int row, int rows);
}; 