#include "cowboy.h"
#include <stdlib.h>

using namespace std;
using namespace sf;

cowboy::cowboy(Vector2f posicion)
{
	int numeroCowboy;
	numeroCowboy = rand() % 3 + 1;//random de 1 a 3 para asignar enemigo
	string path; //direccion donde tengo las imagenes del juego

	path = "cowboy" + to_string(numeroCowboy) + ".png";//cargo el nombre de la textura
	texture_cowboy.loadFromFile(path);//asigno el path
	sprite_cowboy.setTexture(texture_cowboy);//asigno textura a sprite
	sprite_cowboy.setPosition(posicion);
	reloj1 = new Clock;
	tiempo1 = new Time;
	*tiempo1 = reloj1->getElapsedTime();
	}	

Sprite cowboy::getSprite()//nos devuelve el sprite de el cowboy
{
	return sprite_cowboy;
}

float cowboy::getSeconds()//obtengo los segundos que pasaron
{
	*tiempo1 = reloj1->getElapsedTime();

	return tiempo1->asSeconds();
}