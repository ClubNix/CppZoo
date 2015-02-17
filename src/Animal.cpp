#include "Animal.h"

extern sf::Font font;

Animal::Animal(std::string path) : sprite_(path), text_("miaou",font,20){
	sprite_.setFrameRate(sf::milliseconds(200));
	text_.setColor(sf::Color::Blue);
}

void Animal::setPosition(sf::Vector2f position){
	sprite_.setPosition(position);
	text_.setPosition({position.x-10, position.y-20});
}

void Animal::setAnimation(std::string animationName){
	sprite_.setAnimation(animationName);
}

void Animal::update(sf::Time elapsedTime){
	sprite_.update(elapsedTime);
}

void Animal::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(sprite_, states);
	target.draw(text_,states);
}

