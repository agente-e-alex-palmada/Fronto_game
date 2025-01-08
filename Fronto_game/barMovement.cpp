#include "ourheader.h"

void barMovement(Sprite& bar, FloatRect xBorders, float dt, bool& firstInput)
{
    xBorders = bar.getGlobalBounds();
    if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && xBorders.left > 0) {
        bar.move(-BAR_SPEED * dt, 0);
        firstInput = true;
    }
    if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && xBorders.left + xBorders.width < XMAX) {
        bar.move(BAR_SPEED * dt, 0);
        firstInput = true;
    }
}



