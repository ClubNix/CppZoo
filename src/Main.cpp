#include <iostream>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "Animal.h"
#include "Zoo.h"

sf::Font font;
sf::FloatRect screenDimension;

int main(){
	font.loadFromFile("resources/font/EptKazoo.ttf");
	screenDimension.width = 480;
	screenDimension.height = 312;
	sf::RenderWindow window(sf::VideoMode(screenDimension.width, screenDimension.height), "Zoo");
	window.setVerticalSyncEnabled(true);

	Zoo zoo("resources/map.png");	
	Animal cat("resources/animal/cat.png");
	cat.setPosition(sf::Vector2f(screenDimension.width/2, screenDimension.height/2));

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
			cat.setAnimation(Direction::Up);
			cat.move(Direction::Up);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			cat.setAnimation(Direction::Down);
			cat.move(Direction::Down);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			cat.setAnimation(Direction::Right);
			cat.move(Direction::Right);
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
			cat.setAnimation(Direction::Left);
			cat.move(Direction::Left);
		}

		sf::Time elapsedTime = clock.restart();
		cat.update(elapsedTime);
		window.clear();
		window.draw(zoo);
		window.draw(cat);
		window.display();
	}

	return 0;
}
