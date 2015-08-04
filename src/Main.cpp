#include <iostream>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "AnimalControler.h"
#include "Zoo.h"
#include "MovingAnimalControler.h"
#include "Color.h"
#include "EventManager.h"

sf::Font font_;
sf::FloatRect screenDimension_;
sf::RenderWindow *window_;

void addAnimalControler(Zoo& zoo, std::string str){
	AnimalControler *movingAnimalControler = new MovingAnimalControler("resources/animal/" + str + ".png");
	zoo << movingAnimalControler;
}

void setup(){
	font_.loadFromFile("resources/font/EptKazoo.ttf");
	screenDimension_.width = 480;
	screenDimension_.height = 312;
	window_ = new sf::RenderWindow(sf::VideoMode(screenDimension_.width, screenDimension_.height), "Zoo");
	window_->setVerticalSyncEnabled(true);
}

void processInput(){
	sf::Event event;
	EventManager manager;

	while(window_->pollEvent(event)){
		manager.manageEvent(window_, event);
	}
}

void render(Zoo zoo){
	window_->clear();
	window_->draw(zoo);
	window_->display();
}

Zoo & populateZoo(Zoo &zoo){
	addAnimalControler(zoo, "cat");
	addAnimalControler(zoo, "dog");
	addAnimalControler(zoo, "fairy");
	zoo[0].setAnimalPosition(sf::Vector2f(screenDimension_.width/2, screenDimension_.height/2));
	zoo[1].setAnimalPosition(sf::Vector2f(screenDimension_.width/2, screenDimension_.height-32));
	zoo[0].sleep(sf::seconds(3));
	zoo[1].setAnimalColor(Color::Red);

	return zoo;
}

int main(){
	setup();
	EventManager eventManager();
	Zoo zoo("resources/map.png");
//	AnimalControler chat("resources/AnimalControler/cat.png");
//	zoo << chat;
	zoo = populateZoo(zoo);

	sf::Clock clock;

	while(window_->isOpen()){
		sf::Time elapsedTime = clock.restart();
		processInput();
		zoo.update(elapsedTime);
		render(zoo);
	}

	/* nb: so far the window can still be restored */
	delete window_;
	return 0;
}
