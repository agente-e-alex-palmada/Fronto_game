#include "ourheader.h"

void barMovement(Sprite& bar, FloatRect& barBounds, float dt, bool& firstInput)
{
    barBounds = bar.getGlobalBounds();
    if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && barBounds.left > 0) {
        bar.move(-BAR_SPEED * dt, 0);
        firstInput = true;
    }
    if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && barBounds.left + barBounds.width < XMAX) {
        bar.move(BAR_SPEED * dt, 0);
        firstInput = true;
    }
}



