#include "SFML/Graphics.hpp"
#include <iostream>
#include "juego.h"

using namespace sf;//sf es sfml
using namespace std;
int main(int argc, char* args[])
{
	juego * partida1;
	partida1 = new juego({ 800, 600 }, "TP1 Wild GunMan / Plants Vs Zombies");


	return 0;
}