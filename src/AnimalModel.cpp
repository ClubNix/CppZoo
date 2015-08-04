#include "AnimalModel.h"
#include "Color.h"
#include <iostream>

extern sf::Font font_;

AnimalModel::AnimalModel(std::string path) : sprite_(path), text_("",font_,20){
	sprite_.setFrameRate(sf::milliseconds(200));
	text_.setColor(sf::Color::Blue);
	isTalking_ = false;
	currentDirection_ = Direction::Down;
	isSleeping_ = false;
	napDuration_ = sf::Time::Zero;
}

void AnimalModel::setPosition(sf::Vector2f position){
	sprite_.setPosition(position);
	text_.setPosition({position.x-30, position.y-20});
}

void AnimalModel::setSpriteAnimation(Direction animationName){
	sprite_.setAnimation(animationName);
}

void AnimalModel::setColor(sf::Color color){
	sprite_.setColor(color);
}

const AnimatedSprite<32,32> &AnimalModel::getSprite() const{
	return sprite_;
}

bool AnimalModel::isSleeping() const{
	return isSleeping_;
}

void AnimalModel::sleep(sf::Time napDuration){
	isSleeping_ = true;
	napDuration_ += napDuration;
}

void AnimalModel::wakeUp(){
	isSleeping_ = false;
}

void AnimalModel::setNapDuration(sf::Time napDuration){
	napDuration_ = napDuration;
}

sf::Time AnimalModel::getNapDuration(){
	return napDuration_;
}


void AnimalModel::setText(std::string text){
	text_.setString(text);
	isTalking_ = true;
}

bool AnimalModel::isTalking() const{
	return isTalking_;
}

void AnimalModel::finishTalking(){
	text_.setString("");
	isTalking_ = false;
}

Direction AnimalModel::getCurrentDirection(){
	return currentDirection_;
}

void AnimalModel::setCurrentDirection(Direction direction){
	currentDirection_ = direction;
}

const sf::Text &AnimalModel::getText() const{
	return text_;
}

void AnimalModel::updateSprite(sf::Time elapsedTime){
	sprite_.update(elapsedTime);
}
