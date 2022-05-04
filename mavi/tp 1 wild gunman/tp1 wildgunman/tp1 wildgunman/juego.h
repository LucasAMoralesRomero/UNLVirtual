#pragma once
#include "SFML/Graphics.hpp"
#include "cowboy.h"
#include "hostage.h"
using namespace sf;
using namespace std;
class juego
{

public:
	juego(Vector2f resolucion, string titulo);
	void dibujar();
	void gameLoop();//loop de juego
	void loadGraphics();//cargar los graficos
	void eventListener();
	void checkCowboys();
	void checkHostages();
	void checkGameOver();
private:

	bool game_over;
	RenderWindow* ventana;
	int fps;//frames x segundo

	Texture texture_hostage;//textura de rehen
	Sprite sprite_hostage;//sprite de rehen

	Texture texture_background;//textura del fondo
	Sprite sprite_background;//sprite del fondo

	Texture texture_mira;//textura de la mira
	Sprite sprite_mira;//sprite de la mira
	bool puertas_cowboy[5];//puertas donde aparecen cowboys
	Event* eventos;//procesaador de eventos

	cowboy* cowboys[5];//array de cowboys
	hostage* hostages[5];//array de hostages

	Clock* clock1;
	Time* time1;
	float time2;
};