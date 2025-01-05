#include "ourheader.h"

void barMovement(Sprite& bar, Time deltaTime)
{

    // Obtiene los l�mites de la barra para verificar su posici�n
    FloatRect barBounds = bar.getGlobalBounds();

    // No reinicies deltaTime aqu�, ya que es pasado como par�metro

    // Mueve la barra hacia la izquierda
    if (Keyboard::isKeyPressed(Keyboard::Left) && barBounds.left > 0) {
        bar.move(-BAR_SPEED * deltaTime.asSeconds(), 0);
    }

    // Mueve la barra hacia la derecha
    if (Keyboard::isKeyPressed(Keyboard::Right) && barBounds.left + barBounds.width < XMAX) {
        bar.move(BAR_SPEED * deltaTime.asSeconds(), 0);
    }
}



