#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "Animal.h"
#include "Zoo.h"
#include "MovingAnimal.h"

sf::Font font;
sf::FloatRect screenDimension;

void addAnimal(Zoo& zoo, std::string str){
	MovingAnimal animal("resources/animal/" + str + ".png");
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
	sf::Clock clock;
	std::random_device seed;
	std::uniform_int_distribution<int> dist(0,3);
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
		for(int i = 0; i < zoo.count(); i++){
		
			int randmv = dist(seed);

			if(randmv == (int)Direction::Up){
				zoo[i].setAnimation(Direction::Up);
				zoo[i].move(Direction::Up);
			}

			else if(randmv == (int)Direction::Down){
				zoo[i].setAnimation(Direction::Down);
				zoo[i].move(Direction::Down);
			}

			else if(randmv == (int)Direction::Right){
				zoo[i].setAnimation(Direction::Right);
				zoo[i].move(Direction::Right);
			}

			else if(randmv == (int)Direction::Left){
				zoo[i].setAnimation(Direction::Left);
				zoo[i].move(Direction::Left);
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
