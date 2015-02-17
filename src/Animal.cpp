#include "Animal.h"

Animal::Animal(std::string path) : animal_(path){
	animal_.setFrameRate(sf::milliseconds(200));
}

void Animal::setPosition(sf::Vector2f position){
	animal_.setPosition(position);
}

void Animal::setAnimation(std::string animationName){
	animal_.setAnimation(animationName);
}

void Animal::update(sf::Time elapsedTime){
	animal_.update(elapsedTime);
}

void Animal::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(animal_, states);
}

