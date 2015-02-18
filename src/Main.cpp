#include <iostream>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "Animal.h"

sf::Font font;

int main(){
	font.loadFromFile("resources/font/EptKazoo.ttf");
	sf::Vector2i screenDimensions(480, 312);
	sf::RenderWindow window(sf::VideoMode(480, 312), "Zoo");
	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Texture texture;
	
	window.setVerticalSyncEnabled(true);
	
	backgroundTexture.loadFromFile("resources/map.png");
	background.setTexture(backgroundTexture);
	background.setOrigin(0.f,0.f);
	
	Animal cat("resources/animal/cat.png");
	cat.setPosition(sf::Vector2f(screenDimensions / 2));
//	cat.setFrameRate(sf::milliseconds(200));
	sf::Clock clock;
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
			cat.setAnimation("up");
			cat.move(Animal::UP);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			cat.setAnimation("down");
			cat.move(Animal::DOWN);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			cat.setAnimation("right");
			cat.move(Animal::RIGHT);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
			cat.setAnimation("left");
			cat.move(Animal::LEFT);
		}

		sf::Time elapsedTime = clock.restart();
		cat.update(elapsedTime);
		window.clear();
		window.draw(background);
		window.draw(cat);
		window.display();
	}

	return 0;
}
