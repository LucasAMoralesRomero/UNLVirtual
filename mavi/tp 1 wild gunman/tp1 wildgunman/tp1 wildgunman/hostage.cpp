#include "hostage.h"

using namespace std;
using namespace sf;

hostage::hostage(Vector2f posicion)
{
	texture_hostage.loadFromFile("hostage.png");//asigno el path
	sprite_hostage.setTexture(texture_hostage);//asigno textura a sprite
	sprite_hostage.setPosition(posicion);
	reloj1 = new Clock;
	tiempo1 = new Time;
	*tiempo1 = reloj1->getElapsedTime();

}

Sprite hostage::getSprite()//nos devuelve el sprite de el hostage
{
	return sprite_hostage;
}

float hostage::getSeconds()//obtengo los segundos que pasaron
{
	*tiempo1 = reloj1->getElapsedTime();

	return tiempo1->asSeconds();
}