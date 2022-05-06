#include <SFML/Graphics.hpp>
#include "Afichmation.h"

using namespace sf;

int main(int argc, char *argv[]){
	RenderWindow *w = new RenderWindow(VideoMode(640,480),"Ejemplo de SFML");
	w->setFramerateLimit(60);
	Texture textureBackground;
	textureBackground.loadFromFile("assets/mundo_fondo.jpg");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setScale((float)(w->getSize().x) / textureBackground.getSize().x, (float)(w->getSize().y) / textureBackground.getSize().y); //escalamos el fondo
	int floor = 380;//este integer determina el piso
	
	Afichmation anim("assets/spritesheet.png", true, 104, 125);
	anim.Add("idle", {0, 1, 2, 1, 0}, 8, true);
	anim.Add("run", {3, 4, 5, 6, 7, 6, 5, 4}, 8, true);
	anim.Add("jump", {12,13,14,15,14,13,12}, 8, true);
	anim.Play("idle");
	
	anim.setScale(Vector2f(1.f, 1.f));
	anim.move(200,1);
	
	while(w->isOpen()) {
		Event e;
		while(w->pollEvent(e)) {
	
			switch (e.type) {
				case Event::KeyPressed://procesamos las teclas marcadas por el usuariom el input
					if (Keyboard::isKeyPressed(Keyboard::Space))//barra espaciadora para saltar
					{
						anim.Play("jump");
						anim.setPosition(anim.getPosition().x, anim.getPosition().y - 40);
						
					}
					else if (Keyboard::isKeyPressed(Keyboard::Right))//correr a la derecha
					{
						anim.Play("run");
						anim.FlipX(true);
						anim.setPosition(anim.getPosition().x + 2, anim.getPosition().y);
						
						
					}
					else if (Keyboard::isKeyPressed(Keyboard::Left))//correr a la izquierda
					{
						anim.Play("run");
						anim.FlipX(false);
						anim.setPosition(anim.getPosition().x - 2, anim.getPosition().y);
						
					}
			
				break;
				
			
			}

			if(e.type == Event::Closed)
				w->close();	
			

		}
		if (anim.getPosition().y < floor) {
			anim.setPosition(anim.getPosition().x, anim.getPosition().y + 4);
		}
		if (anim.getPosition().y > floor)
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

