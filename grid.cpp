#include "./grid.hpp"
#include "./colors.hpp"
#include <iostream>

Grid::Grid(){
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    colors = getCellColors();
    initialize();
}


void Grid::initialize(){
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            grid[i][j] = 0;
        }
    }
}

void Grid::print(){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}



void Grid::draw(){
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            int cellValue = grid[i][j];
            DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int col){
    if(row >= 0 && row < numRows && col >= 0 && col < numCols) return false;
    return true;
}

bool Grid::isCellEmpty(int row, int col){
    if(grid[row][col] == 0) return true;
    else return false;
}