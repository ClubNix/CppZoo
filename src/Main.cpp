#include <iostream>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "Animal.h"
#include "Zoo.h"
#include "MovingAnimal.h"
#include "Color.h"

sf::Font font;
sf::FloatRect screenDimension;

const sf::Color Color::Black(sf::Color::Black);
const sf::Color Color::White(sf::Color::White);
const sf::Color Color::Red(sf::Color::Red);
const sf::Color Color::Green(sf::Color::Green);
const sf::Color Color::Blue(sf::Color::Blue);
const sf::Color Color::Yellow(sf::Color::Yellow);
const sf::Color Color::Magenta(sf::Color::Magenta);
const sf::Color Color::Cyan(sf::Color::Cyan);
const sf::Color Color::Transparent(sf::Color::Transparent);

void addAnimal(Zoo& zoo, std::string str){
	Animal *animal = (new MovingAnimal("resources/animal/" + str + ".png"));
	zoo << animal;
}

int main(){
	font.loadFromFile("resources/font/EptKazoo.ttf");
	screenDimension.width = 480;
	screenDimension.height = 312;
	sf::RenderWindow window(sf::VideoMode(screenDimension.width, screenDimension.height), "Zoo");
	window.setVerticalSyncEnabled(true);

	Zoo zoo("resources/map.png");
//	Animal chat("resources/animal/cat.png");
//	zoo << chat;
	addAnimal(zoo, "cat");
	addAnimal(zoo, "dog");
	addAnimal(zoo, "fairy");
	zoo[0].setPosition(sf::Vector2f(screenDimension.width/2, screenDimension.height/2));
	zoo[1].setPosition(sf::Vector2f(screenDimension.width/2, screenDimension.height-32));
	zoo[0].sleep(sf::seconds(3));
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
