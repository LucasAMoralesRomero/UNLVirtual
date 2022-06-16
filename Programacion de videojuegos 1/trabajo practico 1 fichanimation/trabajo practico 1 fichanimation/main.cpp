#include <SFML/Graphics.hpp>
#include "Afichmation.h"
#include <iostream>
#include <cstdlib>

using namespace sf;

int main(int argc, char* argv[]) {
	RenderWindow* w = new RenderWindow(VideoMode(640, 480), "Ejemplo de SFML");
	w->setFramerateLimit(60);//se indica el limite de frames
	Texture textureBackground;
	textureBackground.loadFromFile("assets/mundo_fondo.jpg");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setScale((float)(w->getSize().x) / textureBackground.getSize().x, (float)(w->getSize().y) / textureBackground.getSize().y); //escalamos el fondo
	int floor = 380;//este integer determina el piso
	bool jumping = false;//booleano que indica si estoy saltando
	int bloques[] = { 1,2,3,4,5,6,7,8,9,10 }; // se crea array para los numero de los bloques
	int auxiliar = 0;//a almacena el numero aleatorio creado
	int time = 60;//integer que almacenael tiempo

	for (int b = 0; b < 10; b++) {//muestro el arreglo anes para ver que esa cargado con el preset
		cout << bloques[b] << endl;
	}
	for (int i = 0; i < 10; i++) {//lleno el arreglo con valores random
		auxiliar = rand() % 1000;
		bloques[i] = auxiliar;
	}
	for (int b = 0; b < 10; b++) {//vuelvo a mostrar el arreglo para ver que esta cambiado
		cout << bloques[b] << endl;
	}
	//ordenamos el arreglo bloques y lo guardamos en el areglo bloquesOrdenados
	for (int i = 0; i < 10; i++) {//lo necesito para recorrerlos todos
		for (int j = 0; j < 9; j++) {//lo necesito para observar el siguiente
			if (bloques[j] > bloques[j + 1]) {//Si el valor actual es mayor que el valor siguiente
				//lo que tengo en el valor actual lo recuerdo en la variable auxiliar
				auxiliar = bloques[j];
				//lo que tengo en la posición siguiente lo coloco en la posición de lectura actual
				bloques[j] = bloques[j + 1];
				//y lo que tenía en la posición actual (que sobreescribí antes) lo tenía salvado en el auxiliar
				//y de ese modo provoco un intercambio
				bloques[j + 1] = auxiliar;
			}
		}
	}
	for (int b = 0; b < 10; b++) {//vemos si el array esta ordenado
		cout << bloques[b] << endl;
	}
	
	Afichmation anim("assets/spritesheet.png", true, 104, 125);
	anim.Add("idle", {0, 1, 2, 1, 0}, 8, true);
	anim.Add("run", {3, 4, 5, 6, 7, 6, 5, 4, 3}, 8, true);
	anim.Add("jump", {12,13,14,14,13,12}, 8, true);
	anim.Play("idle");
	
	anim.setScale(Vector2f(0.75f, 0.75f));//seteo escala de mario a 0.75
	anim.move(200,1);
	
	while(w->isOpen()) {
		Event e;
		while(w->pollEvent(e)) {
	
			switch (e.type) {
			case Event::KeyPressed://procesamos las teclas marcadas por el usuariom el input
				if (Keyboard::isKeyPressed(Keyboard::Space))//barra espaciadora para saltar
				{
					//solamente salto si no estoy saltando
					if (!jumping) {
						jumping = true;
						anim.Play("jump");
						anim.setPosition(anim.getPosition().x, anim.getPosition().y - 120);
					}


				}
				else if (Keyboard::isKeyPressed(Keyboard::Right))//correr a la derecha a 5 puntos x ciclo
				{
					anim.Play("run");
					anim.FlipX(true);
					anim.setPosition(anim.getPosition().x + 5, anim.getPosition().y);


				}
				else if (Keyboard::isKeyPressed(Keyboard::Left))//correr a la izquierda
				{
					anim.Play("run");
					anim.FlipX(false);
					anim.setPosition(anim.getPosition().x - 5, anim.getPosition().y);

				}
				break;
			default:
				if (anim.getPosition().y > floor || anim.getPosition().y == floor)
					{
						jumping = false;
						anim.Play("idle"); //animacion que se reproduce por default si no pulsamos ninguna tecla
					}
				break;
				
			
			}

			if(e.type == Event::Closed)
				w->close();	
			

		}
		if (anim.getPosition().y < floor) {
			anim.setPosition(anim.getPosition().x, anim.getPosition().y + 4);
		}
		else if (anim.getPosition().y > floor)
		{
			anim.setPosition(anim.getPosition().x, (float)floor);
		}
		
		anim.Update();
		//w->clear(Color(255,255,0,0));
		w->draw(spriteBackground);
		w->draw(anim);
		w->display();
	}
	return 0;
}

