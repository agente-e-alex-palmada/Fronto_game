#include "ourheader.h"
//Drawing what's on scene
void draw(RenderWindow& window, Sprite block[], Sprite& ball, Sprite& bar, Sprite backgrounds[], Sprite& arrow) {
	for (int i = 0; i < BLOCKS; i++)
	{
		window.draw(block[i]);
	}
	window.display();
}