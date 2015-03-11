#include <iostream>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "AnimalControler.h"
#include "Zoo.h"
#include "MovingAnimalControler.h"
#include "Color.h"

sf::Font font;
sf::FloatRect screenDimension;

void addAnimalControler(Zoo& zoo, std::string str){
	AnimalControler *movingAnimalControler = new MovingAnimalControler("resources/animal/" + str + ".png");
	zoo << movingAnimalControler;
}

int main(){
	font.loadFromFile("resources/font/EptKazoo.ttf");
	screenDimension.width = 480;
	screenDimension.height = 312;
	sf::RenderWindow window(sf::VideoMode(screenDimension.width, screenDimension.height), "Zoo");
	window.setVerticalSyncEnabled(true);

	Zoo zoo("resources/map.png");
//	AnimalControler chat("resources/AnimalControler/cat.png");
//	zoo << chat;
	addAnimalControler(zoo, "cat");
	addAnimalControler(zoo, "dog");
	addAnimalControler(zoo, "fairy");
	zoo[0].setAnimalPosition(sf::Vector2f(screenDimension.width/2, screenDimension.height/2));
	zoo[1].setAnimalPosition(sf::Vector2f(screenDimension.width/2, screenDimension.height-32));
	zoo[0].sleep(sf::seconds(3));
	zoo[1].setAnimalColor(Color::Red);
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
		
		sf::Time elapsedTime = clock.restart();
		zoo.update(elapsedTime);
		window.clear();
		window.draw(zoo);
		window.display();
	}

	return 0;
}
