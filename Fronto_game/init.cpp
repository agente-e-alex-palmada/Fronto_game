#include "ourheader.h"

// Initialization
void init(Texture blockTextures[], Texture& ballTexture, Texture& barTexture, Texture backgroundTexture[], Texture arrowTexture[], Sprite block[], Sprite& ball, Sprite& bar, Sprite backgrounds[], Sprite arrow[], int randomGenerator, int& xblock, int& yblock, string& arrowPath, string& backgroundPath, string& blockPath, SoundBuffer& selectionBuff, SoundBuffer& colisionBuff, SoundBuffer& blockBuff, Sound& selectionSound, Sound& colisionSound, Sound& blockSound, Music& menuMusic, Music& life1music, Music& life2music, Music& life3music, Clock& clock, Time& deltaTime, float& dt, bool& firstInput, float& flickerTime, float& ballSpeedY, float& ballSpeedX)
{
    // Load block textures into blockTextures array
    for (int i = 0; i < BLOCK_SPRITES; i++) {
        blockPath = "./assets/graphics/sprites/block" + to_string(i) + ".png";
        blockTextures[i].loadFromFile(blockPath);
    } 

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
        arrow[i].setTexture(arrowTexture[i]);
    }

    // Load ball and bar textures
    ballTexture.loadFromFile("./assets/graphics/sprites/ball.png");
    barTexture.loadFromFile("./assets/graphics/sprites/bar.png");

// Set textures for the blocks
    // Assign random textures to blocks
    for (int i = 0; i < BLOCKS; i++) {
        randomGenerator = rand() % BLOCK_SPRITES;
        block[i].setTexture(blockTextures[randomGenerator]);
    }

    // Set textures for ball and bar
    ball.setTexture(ballTexture);
    bar.setTexture(barTexture);

// Set positions
    // Set position for every block calculating the margins (It has to be looked up)
    for (int i = 0; i < BLOCKS; i++) {
        // Starts at offset and assigns to the variable the position
        xblock = XOFFSET + (i % (XMAX / BLOCK_SIZE)) * BLOCK_SIZE;

        // Same with Y position
        yblock = YOFFSET + (i / (XMAX / BLOCK_SIZE)) * BLOCK_SIZE;

        // Checks if the block has arrived the end of the screen
        if (xblock + BLOCK_SIZE > XMAX) {
            xblock = XOFFSET; // If the block arrives the offscreen, resets the x position
        }
        // Set scale and position
        block[i].setScale(0.7, 0.7);
        block[i].setPosition(xblock, yblock);
    }
    arrow[0].setPosition(710, 950);
    arrow[1].setPosition(1080, 950);
    bar.setScale(0.7, 0.2);

    ball.setPosition((XMAX / 2) - (50 / 2), 900);
    bar.setPosition((XMAX / 2) - (268.8 / 2), 1040);

// Load and set sounds
    if (!selectionBuff.loadFromFile("Ruta"))
    {
        cout << "Can't load the file for selectionSound";
    }
    else {
        selectionSound.setBuffer(selectionBuff);
    }
    if (!colisionBuff.loadFromFile("Ruta"))
    {
        cout << "Can't load the file for colisionSound\n";
    }
    else {
        colisionSound.setBuffer(colisionBuff);
    }
    if (!blockBuff.loadFromFile("Ruta"))
    {
        cout << "Can't load the file for blockSound\n";
    }
    else {
        blockSound.setBuffer(blockBuff);
    }
    if (!menuMusic.openFromFile("Ruta")) {
        cout << "Can't load the file for menuMusic\n";
    }
    if (!life1music.openFromFile("Ruta")) {
        cout << "Can't load the file for life1music\n";
    }
    if (!life2music.openFromFile("Ruta")) {
        cout << "Can't load the file for life2music\n";
    }
    if (!life3music.openFromFile("Ruta")) {
        cout << "Can't load the file for life3music\n";
    }

// Init other variables
    firstInput = false;
    ballSpeedX = BALL_SPEED;
    ballSpeedY = -BALL_SPEED; 
    deltaTime = clock.restart();
    dt = deltaTime.asSeconds();
}
