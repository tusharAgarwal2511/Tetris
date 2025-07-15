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
            DrawRectangle(j * cellSize + 11, i * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
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

bool Grid::isRowFull(int row){
    for(int i = 0; i < numCols; i++){
        if(grid[row][i] == 0){
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row){
    for(int i = 0; i < numCols; i++){
        grid[row][i] = 0;
    }
}

void Grid::moveRowsDown(int row, int rows){
    for(int i = 0; i < numCols; i++){
        grid[row + rows][i] = grid[row][i];
        grid[row][i] = 0;
    }
}

int Grid::clearFullRows(){
    int completed = 0;
    for(int i = numRows - 1; i >= 0; i--){
        if(isRowFull(i)){
            clearRow(i);
            completed++;
        }
        else if(completed > 0){
            moveRowsDown(i, completed);
        }
    }
    return completed;
}