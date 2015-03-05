#ifndef __AnimatedSprite_H__
#define __AnimatedSprite_H__

#include <stdexcept>
#include <string>
#include <utility>
#include <SFML/Graphics.hpp>
#include "Direction.h"

template<int WIDTH, int HEIGHT>
class AnimatedSprite : public sf::Sprite{
	using Animation = typename std::vector<sf::IntRect>;   //!< simple name for an animation set
	sf::Texture texture_;                                  //!< reference to the spritesheet
	Animation frameList_[int(Direction::Size)];            //!< all available animation set (for different direction)
	int currentFrame_;                                     //!< current frame being displayed
	Direction currentAnimation_;                           //!< direction of the sprite
	sf::Time frameRate_;                                   //!< time before next frame
	sf::Time frameTime_;                                   //!< time elapsed between two frame update

private:
	/**
	 * create the list of frame for sprite sheet looking like resources/animal/cat.png
	 */
	void cutSheet(){
		for(int j = 0; j < int(Direction::Size); j++){
			Animation animationList;
			// two times sprite at position x=1*WIDTH for smooth looping
			for(auto i : {0,1,2,1}){
				animationList.push_back({i*WIDTH, j*HEIGHT, WIDTH, HEIGHT});
			}
			frameList_[j] = animationList;
		}
	}


public:
	/**
	 * Copy constructor
	 * \param sprite an sprite to copy
	 */
	AnimatedSprite(const AnimatedSprite& sprite) : texture_(sprite.texture_){
		cutSheet();
		setTexture(texture_);
		currentFrame_ = 0;
		currentAnimation_ = Direction::Down;
		frameRate_ = sf::milliseconds(150);
		frameTime_ = sf::Time::Zero;
		setTextureRect(getCurrentFrame());
	}
	
	/**
	 * Constructor for AnimatedSprite
	 * throw a runtime exception if the resources file is not found
	 * \param fileName path to sprite sheet
	 */
	AnimatedSprite(std::string fileName){
		if(!texture_.loadFromFile(fileName)){
			throw std::runtime_error("file not found");
		}
		cutSheet();
		setTexture(texture_);
		currentFrame_ = 0;
		currentAnimation_ = Direction::Down;
		frameRate_ = sf::milliseconds(150);
		frameTime_ = sf::Time::Zero;
		setTextureRect(getCurrentFrame());
	}
	
	/**
	 * get the frame that will be drawn
	 * \return current frame of of the sprite
	 */
	const sf::IntRect getCurrentFrame() const{
		const sf::IntRect currentFrame = frameList_[int(currentAnimation_)].at(currentFrame_);
		return currentFrame;
	}
	
	/**
	 * set a frame list for an animation
	 * \param animationName direction of the sprite
	 */
	void setAnimation(Direction animationName){
		currentAnimation_ = animationName;
	}
	
	/**
	 * speed of the animation
	 * \param frameRate minimum time between a change of frame
	 */
	void setFrameRate(sf::Time frameRate){
		frameRate_ = frameRate;
	}

	/**
	 * process sprite logic.
	 * change the current displayed frame in respect with the sprite internal framerate
	 * \param elapsedTime time elapsed since last frame
	 */
	void update(sf::Time elapsedTime){
		setTextureRect(getCurrentFrame());
		frameTime_ += elapsedTime;
		// next frame when total elapsed time exceed the frame rate
		if(frameTime_ > frameRate_){
			currentFrame_++;
			currentFrame_ %= frameList_[int(currentAnimation_)].size();
			frameTime_ -= frameRate_;
		}
	}
};

#endif /* __AnimatedSprite_H__ */

