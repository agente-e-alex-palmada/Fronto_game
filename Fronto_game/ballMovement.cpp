#include "ourheader.h"

void ballMovement(Sprite& ball, FloatRect& ballBounds, float dt, Clock clock, float& ballSpeedX, float& ballSpeedY) {
    ballBounds = ball.getGlobalBounds();

    if (ballBounds.left <= 0 || ballBounds.left + ballBounds.width >= XMAX) {
        ballSpeedX = -ballSpeedX;
        if (ballBounds.left <= 0) {
            ball.setPosition(0, ball.getPosition().y);
            ballSpeedX += ballSpeedX * 0.01f;
            ballSpeedY += ballSpeedY * 0.01f;
        }
        if (ballBounds.left + ballBounds.width >= XMAX) {
            ball.setPosition(XMAX - ballBounds.width, ball.getPosition().y);
            ballSpeedX += ballSpeedX * 0.01f;
            ballSpeedY += ballSpeedY * 0.01f;
        }
    }

    if (ballBounds.top <= 0 || ballBounds.top + ballBounds.height >= YMAX) {
        ballSpeedY = -ballSpeedY;
        if (ballBounds.top <= 0) {
            ball.setPosition(ball.getPosition().x, 0);
            ballSpeedX += ballSpeedX * 0.01f;
            ballSpeedY += ballSpeedY * 0.01f;
        }
        if (ballBounds.top + ballBounds.height >= YMAX) {
            cout << "Game over";
            // We need here a function that handles restart and death       
        }
    }
    if (ballSpeedX >= 100.0f) {
        ballSpeedX = 100.0f;
    }
    if (ballSpeedY >= 230.0f) {
        ballSpeedY = 230.0f;
    }
    ball.move(ballSpeedX * dt, ballSpeedY * dt);
}
