#ifndef __SimpleAnimatedSprite_H__
#define __SimpleAnimatedSprite_H__

#include <stdexcept>
#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>

template<unsigned WIDTH, unsigned HEIGHT>
class SimpleAnimatedSprite : public sf::Sprite{
	using Animation = typename std::vector<sf::IntRect>;
	sf::Texture texture_;
	std::unordered_map<std::string, Animation> frameList_;
	unsigned currentFrame_;
	unsigned maxFrame_;
	std::string currentAnimation_;
	sf::Time frameRate_; // time before next frame
	sf::Time frameTime_; // time elapsed between two frame update

private:
	// two times sprite at position x=32 for smooth animation
	void cutSheet(){
		Animation downAnimationList;
		downAnimationList.push_back({1*WIDTH, 0*HEIGHT, WIDTH, HEIGHT});
		downAnimationList.push_back({2*WIDTH, 0*HEIGHT, WIDTH, HEIGHT});
		downAnimationList.push_back({1*WIDTH, 0*HEIGHT, WIDTH, HEIGHT});
		downAnimationList.push_back({0*WIDTH, 0*HEIGHT, WIDTH, HEIGHT});
		frameList_["down"] = downAnimationList;

		Animation leftAnimationList;
		leftAnimationList.push_back({1*WIDTH, 1*HEIGHT, WIDTH, HEIGHT});
		leftAnimationList.push_back({2*WIDTH, 1*HEIGHT, WIDTH, HEIGHT});
		leftAnimationList.push_back({1*WIDTH, 1*HEIGHT, WIDTH, HEIGHT});
		leftAnimationList.push_back({0*WIDTH, 1*HEIGHT, WIDTH, HEIGHT});
		frameList_["left"] = leftAnimationList;

		Animation rightAnimationList;
		rightAnimationList.push_back({1*WIDTH, 2*HEIGHT, WIDTH, HEIGHT});
		rightAnimationList.push_back({2*WIDTH, 2*HEIGHT, WIDTH, HEIGHT});
		rightAnimationList.push_back({1*WIDTH, 2*HEIGHT, WIDTH, HEIGHT});
		rightAnimationList.push_back({0*WIDTH, 2*HEIGHT, WIDTH, HEIGHT});
		frameList_["right"] = rightAnimationList;

		Animation upAnimationList;
		upAnimationList.push_back({1*WIDTH, 3*HEIGHT, WIDTH, HEIGHT});
		upAnimationList.push_back({2*WIDTH, 3*HEIGHT, WIDTH, HEIGHT});
		upAnimationList.push_back({1*WIDTH, 3*HEIGHT, WIDTH, HEIGHT});
		upAnimationList.push_back({0*WIDTH, 3*HEIGHT, WIDTH, HEIGHT});
		frameList_["up"] = upAnimationList;
	}


public:
	SimpleAnimatedSprite(std::string fileName){
		if (!texture_.loadFromFile(fileName)){
			throw std::runtime_error("file not found");
		}
		cutSheet();
		setTexture(texture_);
		currentFrame_ = 0;
		currentAnimation_ = "down";
		maxFrame_ = 4;
		frameRate_ = sf::milliseconds(150);
		frameTime_ = sf::Time::Zero;
	}
	
	const sf::IntRect getCurrentFrame() const{
		const sf::IntRect currentFrame = frameList_.at(currentAnimation_).at(currentFrame_);
		return currentFrame;
	}
	
	void setAnimation(std::string animationName){
		if(frameList_.count(animationName) > 0){
			currentAnimation_ = animationName;
		}
	}
	
	void setFrameRate(sf::Time frameRate){
		frameRate_ = frameRate;
	}

	void update(sf::Time elapsedTime){
		setTextureRect(getCurrentFrame());
		frameTime_ += elapsedTime;
		// next frame when total elapsed time exceed the frame rate
		if(frameTime_ > frameRate_){
			currentFrame_++;
			currentFrame_ %= maxFrame_;
			frameTime_ -= frameRate_;
		}
	}
};

#endif /* __SimpleAnimatedSprite_H__ */

