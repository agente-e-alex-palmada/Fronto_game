//Including where all is defined
#include "ourheader.h"


// Main function
void main() {
	VideoMode vm(XMAX, YMAX);
	RenderWindow window(vm, "Fronto game", Style::Titlebar);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	int score, randomGenerator = 0, xblock, yblock, lives;
	float dt, flickerTime;
	bool firstInput;
	string arrowPath, backgroundPath, blockPath;
	Texture blockTextures[BLOCKS], ballTexture, barTexture, backgroundTexture[BACKGROUNDS], arrowTexture[ARROWS];
	Sprite block[BLOCKS], ball, bar, arrow[ARROWS], backgrounds[BACKGROUNDS];
	SoundBuffer selectionBuff, colisionBuff, blockBuff;
	Sound selectionSound, colisionSound, blockSound;
	Music menuMusic, life1music, life2music, life3music;
	Clock clock;
	Time deltaTime;
	FloatRect xBorders;
	srand(static_cast<unsigned int>(time(0)));
	init(blockTextures, ballTexture, barTexture, backgroundTexture, arrowTexture, block, ball, bar, backgrounds, arrow, randomGenerator, xblock, yblock, arrowPath, backgroundPath, blockPath, selectionBuff, colisionBuff, blockBuff, selectionSound, colisionSound, blockSound, menuMusic, life1music, life2music, life3music, clock, deltaTime, dt, firstInput, flickerTime);
	randomGenerator = rand() % BACKGROUNDS;
	while (window.isOpen()) {
		Event ingame;
		while (window.pollEvent(ingame)) {
			if (ingame.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
				window.close();
			}
		}
		barMovement(bar, xBorders, dt, firstInput);
		ballMovement(ball, deltaTime, clock);
		draw(window, block, ball, bar, backgrounds, arrow, randomGenerator, firstInput, flickerTime, dt);
		deltaTime = clock.restart();
	}
}