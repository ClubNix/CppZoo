#include "AnimatedSprite.h"

//AnimatedSprite::AnimatedSprite(std::string fileName){
//	if (!texture_.loadFromFile(fileName)){
//		throw std::runtime_error("file not found");
//	}
//	cutSheet();
//	setTexture(texture_);
//	currentFrame_ = 0;
//	currentAnimation_ = "down";
//	maxFrame_ = 4;
//	frameRate_ = sf::milliseconds(150);
//	frameTime_ = sf::Time::Zero;
//}

//void AnimatedSprite::cutSheet(){
//	Animation downAnimationList;
//	downAnimationList.push_back({32, 0, 32, 32});
//	downAnimationList.push_back({64, 0, 32, 32});
//	downAnimationList.push_back({32, 0, 32, 32});
//	downAnimationList.push_back({ 0, 0, 32, 32});
//	frameList_["down"] = downAnimationList;

//	Animation leftAnimationList;
//	leftAnimationList.push_back({32, 32, 32, 32});
//	leftAnimationList.push_back({64, 32, 32, 32});
//	leftAnimationList.push_back({32, 32, 32, 32});
//	leftAnimationList.push_back({ 0, 32, 32, 32});
//	frameList_["left"] = leftAnimationList;

//	Animation rightAnimationList;
//	rightAnimationList.push_back({32, 64, 32, 32});
//	rightAnimationList.push_back({64, 64, 32, 32});
//	rightAnimationList.push_back({32, 64, 32, 32});
//	rightAnimationList.push_back({ 0, 64, 32, 32});
//	frameList_["right"] = rightAnimationList;

//	Animation upAnimationList;
//	upAnimationList.push_back({32, 96, 32, 32});
//	upAnimationList.push_back({64, 96, 32, 32});
//	upAnimationList.push_back({32, 96, 32, 32});
//	upAnimationList.push_back({ 0, 96, 32, 32});
//	frameList_["up"] = upAnimationList;
//}

//const sf::IntRect AnimatedSprite::getCurrentFrame() const{
//	const sf::IntRect currentFrame = frameList_.at(currentAnimation_).at(currentFrame_);
//	return currentFrame;
//}

//void AnimatedSprite::setAnimation(std::string animationName){
//	if(frameList_.count(animationName) > 0){
//		currentAnimation_ = animationName;
//	}
//}

//void AnimatedSprite::setFrameRate(sf::Time frameRate){
//	frameRate_ = frameRate;
//}

//void AnimatedSprite::update(sf::Time elapsedTime){
//	setTextureRect(getCurrentFrame());
//	frameTime_ += elapsedTime;
//	// next frame when total elapsed time exceed the frame rate
//	if(frameTime_ > frameRate_){
//		currentFrame_++;
//		currentFrame_ %= maxFrame_;
//		frameTime_ -= frameRate_;
//	}
//}

