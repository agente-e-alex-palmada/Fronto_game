#include "ourheader.h"

// Initialization
void init(Texture blockTextures[], Texture& ballTexture, Texture& barTexture, Texture backgroundTexture[], Texture arrowTexture[], Sprite block[], Sprite& ball, Sprite& bar, Sprite backgrounds[], Sprite& arrow, int randomGenerator, int& xblock, int& yblock, string& arrowPath, string& backgroundPath, string& blockPath){
    
    // Load block textures into blockTextures array
    for (int i = 0; i < BLOCK_SPRITES; i++) {
        blockPath = "./assets/graphics/sprites/block" + to_string(i) + ".png";
        blockTextures[i].loadFromFile(blockPath);
    }

    // Load ball and bar textures
    ballTexture.loadFromFile("./assets/graphics/sprites/ball.png");
    barTexture.loadFromFile("./assets/graphics/sprites/bar.png");   

    // Load background textures
    for (int i = 0; i < BACKGROUNDS; i++) {
        backgroundPath = "./assets/graphics/backgrounds/background" + to_string(i) + ".png";
        backgroundTexture[i].loadFromFile(backgroundPath);
        backgrounds[i].setTexture(backgroundTexture[i]);
    }

    // Load arrow textures
    for (int i = 0; i < ARROWS; i++) {
        arrowPath = "./assets/graphics/icons/arrow" + to_string(i) + ".png";
        arrowTexture[i].loadFromFile(arrowPath);
        arrow.setTexture(arrowTexture[i]);
    }
    
    // Assign random textures to blocks
    for (int i = 0; i < BLOCKS; i++) {
        randomGenerator = rand() % BLOCK_SPRITES;
        block[i].setTexture(blockTextures[randomGenerator]);
    }

    // Set position for every block calculating the margins
    for (int i = 0; i < BLOCKS; i++) {
        // Ajustar X para que no empiece en 0 y no salga de la pantalla
        xblock = XOFFSET + (i % (XMAX / BLOCK_SIZE)) * BLOCK_SIZE;

        // Ajustar Y para que no se salga de la pantalla (usando YMAX)
        yblock = 80 + (i / (XMAX / BLOCK_SIZE)) * BLOCK_SIZE;

        // Asegurarse de que el bloque no se salga de la pantalla en Y
        if (xblock + BLOCK_SIZE > XMAX) {
            xblock = XOFFSET; // Si el bloque se sale de la pantalla, termina el bucle
        }
        // Aplicar escala y posición
        block[i].setScale(0.7, 0.7);
        block[i].setPosition(xblock, yblock);
    }
    // Set textures for ball and bar
    ball.setTexture(ballTexture);
    bar.setTexture(barTexture);
}
