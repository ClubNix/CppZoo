#ifndef __MovingAnimalControler_H__
#define __MovingAnimalControler_H__

#include <random>
#include "Direction.h"

extern sf::FloatRect screenDimension;

/**
 * A moving animal controler allows an animal to move
 */
class MovingAnimalControler : public AnimalControler{
	std::mt19937_64 randGenerator;
	std::uniform_int_distribution<int> distribution;
	
private:
	Direction randDirection(){
		return (Direction)distribution(randGenerator);
	}
	
public:
	
	MovingAnimalControler(std::string path) : AnimalControler(path), randGenerator((unsigned long)this), distribution(0,3){}
	
	virtual void userFunction(){
		move(randDirection());
	}

	/**
	 * change the position of the sprite according to a direction.
	 * \param direction a direction of the movinf (LEFT, UP, RIGHT, DOWN)
	 */
	void move(Direction direction){
		if(not model_.isSleeping()){
			sf::Vector2f position = model_.getSprite().getPosition();
			if(model_.getCurrentDirection() == direction){
				switch(direction){
					case Direction::Left:
						position.x = position.x - model_.getSprite().getTextureRect().width;
						break;
					case Direction::Up:
						position.y = position.y - model_.getSprite().getTextureRect().height;
						break;
					case Direction::Right:
						position.x = position.x + model_.getSprite().getTextureRect().width;
						break;
					case Direction::Down:
						position.y = position.y + model_.getSprite().getTextureRect().height;
						break;
					default: break;
				}
			}
			model_.setCurrentDirection(direction);
		
			sf::IntRect currentFrame = model_.getSprite().getCurrentFrame();
			sf::Vector2f topLeftPointOfFrame(position);
			sf::Vector2f bottomRightPointOfFrame(position + sf::Vector2f(currentFrame.width, currentFrame.height));
		
			if(screenDimension.contains(topLeftPointOfFrame) and screenDimension.contains(bottomRightPointOfFrame)){
				model_.setPosition(position);
			}
			model_.setSpriteAnimation(direction);
		}
	}
};

#endif /* __MovingAnimalControler_H__ */