#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class cowboy
{
public:
	cowboy(Vector2f posicion);
	Sprite getSprite();
	float getSeconds();
private:
	Texture texture_cowboy;//textura de los villanos
	Sprite sprite_cowboy;//sprite de los villanos

	Clock* reloj1;
	Time* tiempo1;
};