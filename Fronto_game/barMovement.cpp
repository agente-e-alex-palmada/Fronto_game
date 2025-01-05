#include "ourheader.h"

void barMovement(Sprite& bar, Time deltaTime)
{

    // Obtiene los límites de la barra para verificar su posición
    FloatRect barBounds = bar.getGlobalBounds();

    // No reinicies deltaTime aquí, ya que es pasado como parámetro

    // Mueve la barra hacia la izquierda
    if (Keyboard::isKeyPressed(Keyboard::Left) && barBounds.left > 0) {
        bar.move(-BAR_SPEED * deltaTime.asSeconds(), 0);
    }

    // Mueve la barra hacia la derecha
    if (Keyboard::isKeyPressed(Keyboard::Right) && barBounds.left + barBounds.width < XMAX) {
        bar.move(BAR_SPEED * deltaTime.asSeconds(), 0);
    }
}



