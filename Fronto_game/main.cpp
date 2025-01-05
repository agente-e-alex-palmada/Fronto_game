//Including where all is defined
#include "ourheader.h"


// Main function
void main() {
	VideoMode vm(XMAX, YMAX);
	RenderWindow window(vm, "Fronto game", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	int score, randomGenerator = 0, xblock, yblock, lives;
	float barSpeed, bar_speed;
	bool validinput;
	string arrowPath, backgroundPath, blockPath;
	Texture blockTextures[BLOCKS], ballTexture, barTexture, backgroundTexture[BACKGROUNDS], arrowTexture[ARROWS];
	Sprite block[BLOCKS], ball, bar, arrow[ARROWS], backgrounds[BACKGROUNDS];
	SoundBuffer selectionBuff, colisionBuff, blockBuff;
	Sound selectionSound, colisionSound, blockSound;
	Music menuMusic, life1music, life2music, life3music;
	Event ingame;
	Clock clock;
	Vector2f ballVelocity(200.0f, 150.0f);
	Time deltaTime;
	srand(static_cast<unsigned int>(time(0)));
	init(blockTextures, ballTexture, barTexture, backgroundTexture, arrowTexture, block, ball, bar, backgrounds, arrow, randomGenerator, xblock, yblock, arrowPath, backgroundPath, blockPath, selectionBuff, colisionBuff, blockBuff, selectionSound, colisionSound, blockSound, menuMusic, life1music, life2music, life3music);
	randomGenerator = rand() % 3;
	window.setKeyRepeatEnabled(false);
	while (window.isOpen()) {
		
		while (window.pollEvent(ingame)) {
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			barMovement(bar, deltaTime);
			ballMovement(ball, ballVelocity, deltaTime); //BLOCKS
			draw(window, block, ball, bar, backgrounds, arrow, randomGenerator);
			deltaTime = clock.restart();
		}
	}
}