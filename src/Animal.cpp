#include "Animal.h"

extern sf::Font font;

Animal::Animal(std::string path) : sprite_(path), text_("",font,20){
	sprite_.setFrameRate(sf::milliseconds(200));
	text_.setColor(sf::Color::Blue);
	isSayingSomething_ = false;
}

void Animal::setPosition(sf::Vector2f position){
	sprite_.setPosition(position);
	text_.setPosition({position.x-10, position.y-20});
}

void Animal::setAnimation(std::string animationName){
	sprite_.setAnimation(animationName);
}

void Animal::operator<<(const char* text){
	std::string stringText(text);
	operator<<(stringText);
}


void Animal::operator<<(std::string& text){
	text_.setString(text);
	isSayingSomething_ = true;
	frameCountThatSomethingIsBeingSaid_ = 0;
}

void Animal::update(sf::Time elapsedTime){
	sprite_.update(elapsedTime);
	if(isSayingSomething_){
		frameCountThatSomethingIsBeingSaid_++;
	}
	if(frameCountThatSomethingIsBeingSaid_ > 30){
		text_.setString("");
		isSayingSomething_ = false;
		frameCountThatSomethingIsBeingSaid_ = 0;
	}
}

void Animal::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(sprite_, states);
	target.draw(text_,states);
}

