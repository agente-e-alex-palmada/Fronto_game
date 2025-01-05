#include "ourheader.h"

void ballMovement(Sprite& ball, Vector2f& ballVelocity, Time deltaTime) { 


    // Obtén los límites de la pelota
    FloatRect ballBounds = ball.getGlobalBounds();

    // Colisiones con los límites de la ventana
    if (ballBounds.left <= 0 || ballBounds.left + ballBounds.width >= XMAX) {
        // Cambiar la dirección en el eje X
        ballVelocity.x = -ballVelocity.x;
    }

    if (ballBounds.top <= 0 || ballBounds.top + ballBounds.height >= YMAX) {
        // Cambiar la dirección en el eje Y
        ballVelocity.y = -ballVelocity.y;
    }

    // Detectar "muerte" de la pelota (si cae fuera de la pantalla)
    if (ballBounds.top + ballBounds.height >= YMAX) {
        cout << "Player died" << endl;
    }
    //Check collisions with the blocks
        /*for (auto it = BLOCKS.begin(); it != BLOCKS.end();) {
            if (ballBounds.intersects(it->getGlobalBounds())) {
            Invest ball's Y
            ballVelocity.y = -ballVelocity.y;
            Erase the block that has been hit
            it = BLOCKS.erase(it); }
            else {
                ++it;
            }
        }*/

}



	