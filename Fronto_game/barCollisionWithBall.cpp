#include "ourheader.h"

void barCollisionWithBall(Sprite& ball, Sprite& bar, FloatRect& barBounds, FloatRect& ballBounds, float& ballSpeedX, float& ballSpeedY, float dt) {
    ballBounds = ball.getGlobalBounds();
    barBounds = bar.getGlobalBounds();
    
    if (barBounds.intersects(ballBounds))
    {
        ballSpeedY = -ballSpeedY * dt;
    }
}
