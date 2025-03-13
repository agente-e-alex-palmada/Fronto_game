#include "ourheader.h"

void barCollisionWithBall(Sprite& ball, Sprite& bar, FloatRect& barBounds, FloatRect& ballBounds, float& ballSpeedX, float& ballSpeedY, float dt) {
    ballBounds = ball.getGlobalBounds();

    // Create a simplified bounds for the bar
    FloatRect simplifiedBarBounds(bar.getPosition().x + 10, bar.getPosition().y + 10, bar.getGlobalBounds().width - 20, bar.getGlobalBounds().height - 10); // Ajusta los valores seg�n tus necesidades

    // Check if the balls touches the bar
    if (simplifiedBarBounds.intersects(ballBounds)) {
        // Invest the Y
        ballSpeedY = -abs(ballSpeedY);

        // Modifies the direction depending where the ball touches de bar
        float barCenter = simplifiedBarBounds.left + simplifiedBarBounds.width / 2;
        float ballCenter = ballBounds.left + ballBounds.width / 2;

        float distanceFromCenter = ballCenter - barCenter;
        ballSpeedX += distanceFromCenter * 0.05f; 

        // Check that's the ball is not stucked in the bar
        if (ballBounds.top + ballBounds.height > simplifiedBarBounds.top) {
            ball.setPosition(ball.getPosition().x, simplifiedBarBounds.top - ballBounds.height);
        }
    }
}



