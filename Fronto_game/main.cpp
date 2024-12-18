//Including where all is defined
#include "ourheader.h"

// Main function
int main() {
	int score, randomGenerator = 0, xblock, yblock;
	float barSpeed, bar_speed;
	string arrowPath, backgroundPath, blockPath;
	VideoMode vm(XMAX, YMAX);
	RenderWindow window(vm, "Fronto game", Style::Titlebar);
	Texture blockTextures[BLOCKS], ballTexture, barTexture, backgroundTexture[BACKGROUNDS], arrowTexture[ARROWS];
	Sprite block[BLOCKS], ball, bar, arrow[ARROWS], backgrounds[BACKGROUNDS];
	Event event;
	srand(static_cast<unsigned int>(time(0)));
	init(blockTextures, ballTexture, barTexture, backgroundTexture, arrowTexture, block, ball, bar, backgrounds, arrow, randomGenerator, xblock, yblock, arrowPath, backgroundPath, blockPath);
	randomGenerator = rand() % 3;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			draw(window, block, ball, bar, backgrounds, arrow, randomGenerator);
		}
	}
	return 0;-
}