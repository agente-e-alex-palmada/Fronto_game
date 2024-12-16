#include "ourheader.h"

// Initialization
void init(Texture blockTextures[], Texture& ballTexture, Texture& barTexture, Texture backgroundTexture[], Texture arrowTexture[], Sprite block[], Sprite& ball, Sprite& bar, Sprite backgrounds[], Sprite& arrow, int& randomGenerator, int& xblock, int& yblock) {
    // Load block textures into blockTextures array
    for (int i = 0; i < BLOCK_SPRITES; i++) {
        string blockPath = "./assets/graphics/sprites/block" + to_string(i) + ".png";
        blockTextures[i].loadFromFile(blockPath);
    }

    // Load ball and bar textures
    ballTexture.loadFromFile("./assets/graphics/sprites/ball.png");
    barTexture.loadFromFile("./assets/graphics/sprites/bar.png");   

    // Load background textures
    for (int i = 0; i < BACKGROUNDS; i++) {
        string backgroundPath = "./assets/graphics/backgrounds/background" + to_string(i) + ".png";
        backgroundTexture[i].loadFromFile(backgroundPath);
        backgrounds[i].setTexture(backgroundTexture[i]);
    }

    // Load arrow textures
    for (int i = 0; i < ARROWS; i++) {
        string arrowPath = "./assets/graphics/icons/arrow" + to_string(i) + ".png";
        arrowTexture[i].loadFromFile(arrowPath);
    }
    arrow.setTexture(arrowTexture[0]); // Example: set the first arrow texture

    // Assign random textures to blocks
    for (int i = 0; i < BLOCKS; i++) {
        randomGenerator = rand() % BLOCK_SPRITES;
        block[i].setTexture(blockTextures[randomGenerator]);
        xblock = (i % (XMAX / 128)) * 128;
        yblock = 0 + (i / (XMAX / 128)) * 128;
        block[i].setPosition(xblock, yblock);
    }

    // Set textures for ball and bar
    ball.setTexture(ballTexture);
    bar.setTexture(barTexture);
}
