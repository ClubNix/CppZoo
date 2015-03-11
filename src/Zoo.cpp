#include "Zoo.h"

Zoo::Zoo(std::string fileName){
	if (!texture_.loadFromFile(fileName)){
		throw std::runtime_error("file not found");
	}
	background_.setTexture(texture_);
	background_.setOrigin(0.f,0.f);	
}

void Zoo::update(sf::Time elapsedTime){
	for(AnimalControler *animalControler : animalControlerList_){
		animalControler->update(elapsedTime);
	}
}

void Zoo::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(background_, states);
	for(AnimalControler *animalControler : animalControlerList_){
		animalControler->draw(target, states);
	}
}

void Zoo::operator<<(AnimalControler *animalControler){
	animalControlerList_.push_back(animalControler);
}

AnimalControler& Zoo::operator[](int position){
	return *animalControlerList_.at(position);
}

int Zoo::count(){
	return animalControlerList_.size();
}