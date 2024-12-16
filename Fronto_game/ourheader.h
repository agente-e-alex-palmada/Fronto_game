#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;

//Declaring gobal variables
const int XMAX = 1920, YMAX = 1080, BLOCK_SPRITES = 5, BLOCKS = 44, BACKGROUNDS = 3, ARROWS = 2, BLOCK_SIZE = 128, XOFFSET = 80, YOFFSET = 80;

void init(Texture blockTextures[], Texture& ballTexture, Texture& barTexture, Texture backgroundTexture[], Texture arrowTexture[], Sprite block[], Sprite& ball, Sprite& bar, Sprite backgrounds[], Sprite arrow[], int randomGenerator, int& xblock, int& yblock, string& arrowPath, string& backgroundPath, string& blockPath);
void draw(RenderWindow& window, Sprite block[], Sprite& ball, Sprite& bar, Sprite backgrounds[], Sprite arrow[], int randomGenerator);

