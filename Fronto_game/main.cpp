//Including where all is defined
#include "ourheader.h"

// Main function
void main(){
	int score, randomGenerator, xblock, yblock;
	float barSpeed, bar_speed;
	VideoMode vm(XMAX, YMAX);
	RenderWindow window(vm, "Fronto game", Style::Titlebar);
	Texture blockTextures[BLOCKS], ballTexture, barTexture, backgroundTexture[BACKGROUNDS], arrowTexture[ARROWS];
	Sprite block[BLOCKS], ball, bar, arrow, backgrounds[BACKGROUNDS];
	Event event;
	srand(static_cast<unsigned int>(time(0)));
	init(blockTextures, ballTexture, barTexture, backgroundTexture, arrowTexture, block, ball, bar, backgrounds, arrow, randomGenerator, xblock, yblock);
	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
				window.close();
		}
		draw(window, block, ball, bar, backgrounds, arrow);
	}
}