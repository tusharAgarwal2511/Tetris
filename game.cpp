#include "./game.hpp"
// #include "./grid.hpp"
// #include "./blocks.cpp"
#include <random>


Game::Game(){
    grid = Grid();
    blocks = getAllBlocks();
    currBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}


Block Game::getRandomBlock(){
    if(blocks.empty()){
        blocks = getAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::getAllBlocks(){
    return {IBlock(), JBlock(), LBlock(), OBlock(), TBlock(), SBlock(), ZBlock()};
}

void Game::draw(){
    grid.draw();
    currBlock.draw();
}

void Game::handleInput(){
    int keyPressed = GetKeyPressed();
    switch(keyPressed){
        case KEY_LEFT:
            moveBlockLeft();
            break;

        case KEY_RIGHT:
            moveBlockRight();
            break;

        case KEY_DOWN:
            moveBlockDown();
            break;
    }
}


void Game::moveBlockLeft(){
    currBlock.move(0, -1);
    if(isBlockOutside()){
        currBlock.move(0, 1);
    }
}

void Game::moveBlockRight(){
    currBlock.move(0, 1);
    if (isBlockOutside()){
        currBlock.move(0, -1);
    }
}

void Game::moveBlockDown(){
    currBlock.move(1, 0);
    if (isBlockOutside()){
        currBlock.move(-1, 0);
    }
}

bool Game::isBlockOutside(){
    std::vector<Position> tiles = currBlock.getCellPositions();
    for(Position item: tiles){
        if(grid.isCellOutside(item.row, item.col)){
            return true;
        }
    }
    return false;
}