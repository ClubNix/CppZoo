#include "AnimalControler.h"

	AnimalControler::AnimalControler(std::string path): model_(path), view_(model_.getText(), model_.getSprite()){
		userTickCounter_ = sf::Time::Zero;
		userTick_ = sf::milliseconds(500);
	}

	AnimalControler::~AnimalControler(){}

	void AnimalControler::setAnimalPosition(sf::Vector2f position){
		model_.setPosition(position);
		updateView();
	}

	void AnimalControler::operator<<(std::string text){
		model_.setText(text);
		frameCountThatSomethingIsBeingSaid_ = 0;
	}

	void AnimalControler::setAnimalColor(sf::Color color){
		model_.setColor(color);
	}

	void AnimalControler::sleep(sf::Time napDuration){
		model_.sleep(napDuration);
	}

	void AnimalControler::wakeAnimalUp(){
		model_.wakeUp();
	}

	void AnimalControler::updateView(){
		view_.update(model_.getText(), model_.getSprite());
	}

	void AnimalControler::update(sf::Time elapsedTime){
		model_.updateSprite(elapsedTime);

		if(model_.isSleeping()){
			model_.setNapDuration(model_.getNapDuration() - elapsedTime);
			model_.setText("zZz...");
			if(model_.getNapDuration() <= sf::Time::Zero){
				model_.setNapDuration(sf::Time::Zero);
				wakeAnimalUp();
				model_.setText("");
			}
		}
		
		if(model_.isTalking()){
			frameCountThatSomethingIsBeingSaid_ ++;
		}
		
		if(frameCountThatSomethingIsBeingSaid_ > 300){
			model_.finishTalking();
			frameCountThatSomethingIsBeingSaid_ = 0;
		}
		
		userTickCounter_ += elapsedTime;
		if(userTickCounter_ > userTick_){
			userFunction();
			userTickCounter_ -= userTick_;
		}
		updateView();
	}

	void AnimalControler::draw(sf::RenderTarget& target, sf::RenderStates states) const{
		view_.draw(target, states);
		if(model_.isTalking() || model_.isSleeping()){
			view_.drawTextBubble(target, states);
		}
		//printf("%d\n", model_.getSprite().getFrame());
	}


	void AnimalControler::userFunction(){
	}