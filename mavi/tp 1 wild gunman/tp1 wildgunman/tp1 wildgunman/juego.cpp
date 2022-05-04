#include "juego.h"
#include <iostream>


using namespace std;
using namespace sf;

int puntaje = 0;
int cowboysAbatidos = 0;
int hostagesAbatidos = 0;

int puerta_x[5]{130, 580, 100, 350, 600};//posicion en x de la puerta
int puerta_y[5]{150, 150, 380, 380,380};//posicion en y de la puerta
int vidas = 3;

juego::juego(Vector2f resolucion, string titulo)
{
	fps = 30;
	ventana = new RenderWindow(VideoMode(resolucion.x,resolucion.y), titulo);
	ventana->setFramerateLimit(fps);
	ventana->setMouseCursorVisible(false);//ocultamos el mouse
	for (int i = 0; i<5; i++)
	{
		puertas_cowboy[i] = false;
	}
	eventos = new Event;
	loadGraphics();

	clock1 = new Clock;
	time1 = new Time;
	time2 = 0;
		gameLoop();
}

void juego::dibujar()
{
	*time1 = clock1->getElapsedTime();//obtenemos el tiempo que transcurre
	if (time1->asSeconds() > 5 + time2)
	{
		time2 = time1->asSeconds();
		int probabilidad;
		probabilidad = rand() % 100 + 1;


		if (probabilidad < 30)
		{
			//creo un hostage

			while (1)
			{
				int resultado = rand() % 5 + 0;
				if (!puertas_cowboy[resultado])
				{
					puertas_cowboy[resultado] = true;
					hostages[resultado] = new hostage({ (float)(puerta_x[resultado]),(float)(puerta_y[resultado]) });
					break;
				}

			}
		}


		else
		{
			//creo un cowboy
			bool puerta_libre = false;
			for (int i = 0; i < 5; i++)
			{
				if (!puertas_cowboy[i])
				{
					puerta_libre = true;
					break;
				}

			}

			if (puerta_libre)
			{
				while (1)
				{
					int resultado = rand() % 5 + 0;
					if (!puertas_cowboy[resultado])
					{
						puertas_cowboy[resultado] = true;
						cowboys[resultado] = new cowboy({ (float)(puerta_x[resultado]),(float)(puerta_y[resultado]) });
						break;
					}

				}
			}
		}

	}
		checkCowboys();
		checkHostages();


		ventana->clear();

		eventListener();

		ventana->draw(sprite_background);

		for (int i = 0; i < 5; i++)
		{
			if (cowboys[i] != NULL)
			{
				ventana->draw(cowboys[i]->getSprite());
			}

		}

		
		for (int i = 0; i < 5; i++)
		{
			if (hostages[i] != NULL)
			{
				ventana->draw(hostages[i]->getSprite());
			}

		}
		ventana->draw(sprite_mira);
		ventana->display();
	}


void juego::gameLoop()
{
	

	while (!game_over)
	{
		dibujar();
		checkGameOver();
	}
	if (game_over)
	{
		cout << "Game Over!!" << endl;
		cout << "puntos obtenidos: " << (cowboysAbatidos - hostagesAbatidos) * 10 << endl;
		exit(1);
	}
}

void juego::loadGraphics()
{
	

	texture_background.loadFromFile("saloon.jpg");//cargo la textura del fondo
	sprite_background.setTexture(texture_background);//asigno textura al fondo

	sprite_background.setScale((float)(ventana->getSize().x) / texture_background.getSize().x, (float)(ventana->getSize().y) / texture_background.getSize().y); //escalamos el fondo

	texture_mira.loadFromFile("mira.png");//cargo textura de mira
	sprite_mira.setTexture(texture_mira);//asigno textura a la mira
}

void juego::eventListener()
{
	
	Vector2f mouse = ventana->mapPixelToCoords(Mouse::getPosition(*ventana));//obtengo la posicion del mouse y la guardo en un vector 2f

	while (ventana->pollEvent(*eventos))
	{
		switch (eventos->type)
		{
		case Event::MouseMoved://posicionamos el mouse
			sprite_mira.setPosition((Vector2f)Mouse::getPosition(*ventana));
			break;

		case Event::Closed:
			exit(1);
			break;
			

		case Event::MouseButtonPressed:
			for (int i = 0; i < 5; i++)
			{
				if (cowboys[i])
				{
					if (cowboys[i]->getSprite().getGlobalBounds().contains(mouse))
					{
						cowboys[i] = NULL;//"mato" al cowboy
						cowboysAbatidos = cowboysAbatidos + 1;
						cout<<"bien! le disparaste a un Cowboy"<<endl;
						cout << "puntos hasta ahora: " << (cowboysAbatidos - hostagesAbatidos)* 10 << endl;
						puertas_cowboy[i] = false;//libero la puerta
					}
				}
			}

			for (int j = 0; j < 5; j++)
			{
				if (hostages[j])
				{
					if (hostages[j]->getSprite().getGlobalBounds().contains(mouse))
					{
						hostages[j] = NULL;//"mato" al hostage
						hostagesAbatidos = hostagesAbatidos + 1;
						cout << "OH NO!, le disparaste a un hostage" << endl;
						vidas = vidas - 1;
						cout << "Perdiste una vida, tienes " << vidas << " vidas." << endl;
						puertas_cowboy[j] = false;//libero la puerta

					}
				}
			}
			break;
		}

	}
}

void juego::checkCowboys()
{
	for (int i = 0; i < 5; i++)
	{
		if (cowboys[i])
		{
			if (cowboys[i]->getSeconds() > 5)
			{
				cowboys[i] = NULL;
				puertas_cowboy[i] = false;
				cout << "OH NO! el Cowboy te disparo!" << endl;
				vidas = vidas - 1;
				cout << "Perdiste una vida, tienes "<<vidas<<" vidas."<< endl;
			}
		}
	}
}

void juego::checkHostages()
{
	for (int i = 0; i < 5; i++)
	{
		if (hostages[i])
		{
			if (hostages[i]->getSeconds() > 5)
			{
				hostages[i] = NULL;
				puertas_cowboy[i] = false;
				cout << "el hostage volvio a entrar" << endl;
			}
		}
	}
}

void juego::checkGameOver()//chequeo  mis vidas parea ver si es game over
{
	if (vidas == 0)
	{
		game_over = true;
	}
}