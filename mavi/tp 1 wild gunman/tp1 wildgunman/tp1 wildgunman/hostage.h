#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
using namespace std;

class hostage
{
public:
	hostage(Vector2f posicion);
	Sprite getSprite();
	float getSeconds();
private:
	Texture texture_hostage;//textura de los villanos
	Sprite sprite_hostage;//sprite de los villanos
	Clock* reloj1;
	Time* tiempo1;
};