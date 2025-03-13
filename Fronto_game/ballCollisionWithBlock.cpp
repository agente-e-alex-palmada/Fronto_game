#include "ourheader.h"

void ballCollisionWithBlocks(Sprite& ball, FloatRect& ballBounds, Sprite block[], FloatRect blockBounds[], int& blockCount, float& ballSpeedX, float& ballSpeedY) {
    for (int i = 0; i < BLOCKS; ++i) {
        blockBounds[i] = block[i].getGlobalBounds();

        // Check if the ball touches a block
        if (blockBounds[i].intersects(ballBounds)) {
            // Colision Y
            if (ballBounds.top + ballBounds.height <= blockBounds[i].top + blockBounds[i].height / 2 && ballSpeedY > 0) {
                
                ballSpeedY = -ballSpeedY;
            
                ball.setPosition(ball.getPosition().x, blockBounds[i].top - ballBounds.height);
            }
            else if (ballBounds.top >= blockBounds[i].top + blockBounds[i].height / 2 && ballSpeedY < 0) {
              
                ballSpeedY = -ballSpeedY;
             
                ball.setPosition(ball.getPosition().x, blockBounds[i].top + blockBounds[i].height);
            }

            // Collision X
            if (ballBounds.left + ballBounds.width <= blockBounds[i].left + blockBounds[i].width / 2 && ballSpeedX > 0) {
              
                ballSpeedX = -ballSpeedX;
               
                ball.setPosition(blockBounds[i].left - ballBounds.width, ball.getPosition().y);
            }
            else if (ballBounds.left >= blockBounds[i].left + blockBounds[i].width / 2 && ballSpeedX < 0) {
             
                ballSpeedX = -ballSpeedX;
              
                ball.setPosition(blockBounds[i].left + blockBounds[i].width, ball.getPosition().y);
            }

            // Erase the block moving it out the screen
            block[i].setPosition(-1000, -1000); 
            blockCount--; 
            break; // Exit from the loop
        }
    }
}



