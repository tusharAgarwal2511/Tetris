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

        case KEY_UP:
            rotateBlock();
            break;
        case KEY_SPACE:
            rotateBlock();
            break;
        }
}


void Game::moveBlockLeft(){
    currBlock.move(0, -1);
    if (isBlockOutside() || blockFits() == false){
        currBlock.move(0, 1);
    }
}

void Game::moveBlockRight(){
    currBlock.move(0, 1);
    if (isBlockOutside() || blockFits() == false){
        currBlock.move(0, -1);
    }
}

void Game::moveBlockDown(){
    currBlock.move(1, 0);
    if (isBlockOutside() || blockFits() == false){
        currBlock.move(-1, 0);
        lockBlock();
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

void Game::rotateBlock(){
    currBlock.rotate();
    if (isBlockOutside() || blockFits() == false){
        currBlock.undoRotation();
    }
}


void Game::lockBlock(){
    std::vector<Position> tiles = currBlock.getCellPositions();
    for(Position item: tiles){
        grid.grid[item.row][item.col] = currBlock.id;
    }
    currBlock = nextBlock;
    nextBlock = getRandomBlock();
    grid.clearFullRows();
}


bool Game::blockFits(){
    std::vector<Position> tiles = currBlock.getCellPositions();
    for(Position item: tiles){
        if(grid.isCellEmpty(item.row, item.col) == false){
            return false;
        }
    }
    return true;
}