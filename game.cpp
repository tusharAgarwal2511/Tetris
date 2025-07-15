#include "./game.hpp"
// #include "./grid.hpp"
// #include "./blocks.cpp"
#include <random>


Game::Game(){
    grid = Grid();
    blocks = getAllBlocks();
    currBlock = getRandomBlock();
    nextBlock = getRandomBlock();
    gameOver = false;
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
    if(keyPressed != 0 && gameOver){
        gameOver = false;
        reset();
    }
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
    if(!gameOver){
        currBlock.move(0, -1);
        if (isBlockOutside() || blockFits() == false){
            currBlock.move(0, 1);
        }
    }
}

void Game::moveBlockRight(){
    if (!gameOver){
        currBlock.move(0, 1);
        if (isBlockOutside() || blockFits() == false){
            currBlock.move(0, -1);
        }
    }
}

void Game::moveBlockDown(){
    if (!gameOver){
        currBlock.move(1, 0);
        if (isBlockOutside() || blockFits() == false){
            currBlock.move(-1, 0);
            lockBlock();
        }
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
    if (!gameOver){
        currBlock.rotate();
        if (isBlockOutside() || blockFits() == false){
            currBlock.undoRotation();
        }
    }
}


void Game::lockBlock(){
    std::vector<Position> tiles = currBlock.getCellPositions();
    for(Position item: tiles){
        grid.grid[item.row][item.col] = currBlock.id;
    }
    currBlock = nextBlock;
    if(blockFits() == false){
        gameOver = true;
    }
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

void Game::reset(){
    grid.initialize();
    blocks = getAllBlocks();
    currBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}