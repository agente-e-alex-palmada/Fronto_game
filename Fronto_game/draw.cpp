#include "ourheader.h"
//Drawing what's on scene
void draw(RenderWindow& window, Sprite block[], Sprite& ball, Sprite& bar, Sprite backgrounds[], Sprite arrow[], int randomGenerator, bool firstInput, float flickerTime, float dt){
	window.clear();
	window.draw(backgrounds[randomGenerator]);
	for (int i = 0; i < BLOCKS; i++)
	{
		window.draw(block[i]);
	}

	if (!firstInput) {
		for (int i = 0; i < ARROWS; i++)
		{
			window.draw(arrow[i]);
		}
	}
	window.draw(ball);
	window.draw(bar);
	window.display();
}
