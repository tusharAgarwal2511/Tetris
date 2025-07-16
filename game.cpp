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
    score = 0;
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
    currBlock.draw(11, 11);
    switch(nextBlock.id){
        case 3:
            nextBlock.draw(255, 290);
            break;
        case 4:
            nextBlock.draw(255, 280);
            break;
        default:
            nextBlock.draw(270, 270);
    }
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
            updateScore(0, 1);
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
    int rowsCleared = grid.clearFullRows();
    updateScore(rowsCleared, 0);
    
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
    score = 0;
}

void Game::updateScore(int linesCleared, int moveDownPoints){
    switch(linesCleared){
        case 1:
            score += 10;
            break;
        case 2:
            score += 40;
            break;
        case 3:
            score += 60;
            break;
        case 4:
            score += 100;
            break;
        default:
            break;
    }
    score += moveDownPoints;
}