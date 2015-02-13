////////////////////////////////////////////////////////////
//
// Copyright (C) 2014 Maximilian Wagenbach (aka. Foaly) (foaly.f@web.de)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
// you must not claim that you wrote the original software.
// If you use this software in a product, an acknowledgment
// in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
// and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(sf::Time frameTime, bool paused, bool looped) :
	animation_(NULL), frameTime_(frameTime), currentFrame_(0), isPaused_(paused), isLooped_(looped), texture_(NULL)
{

}

void AnimatedSprite::setAnimation(const Animation& animation)
{
	animation_ = &animation;
	texture_ = animation_->getSpriteSheet();
	currentFrame_ = 0;
	setFrame(currentFrame_);
}

void AnimatedSprite::setFrameTime(sf::Time time)
{
	frameTime_ = time;
}

void AnimatedSprite::play()
{
	isPaused_ = false;
}

void AnimatedSprite::play(const Animation& animation)
{
	if (getAnimation() != &animation)
		setAnimation(animation);
	play();
}

void AnimatedSprite::pause()
{
	isPaused_ = true;
}

void AnimatedSprite::stop()
{
	isPaused_ = true;
	currentFrame_ = 0;
	setFrame(currentFrame_);
}

void AnimatedSprite::setLooped(bool looped)
{
	isLooped_ = looped;
}

void AnimatedSprite::setColor(const sf::Color& color)
{
	// Update the vertices' color
	vertices_[0].color = color;
	vertices_[1].color = color;
	vertices_[2].color = color;
	vertices_[3].color = color;
}

const Animation* AnimatedSprite::getAnimation() const
{
	return animation_;
}

sf::FloatRect AnimatedSprite::getLocalBounds() const
{
	sf::IntRect rect = animation_->getFrame(currentFrame_);

	float width = static_cast<float>(std::abs(rect.width));
	float height = static_cast<float>(std::abs(rect.height));

	return sf::FloatRect(0.f, 0.f, width, height);
}

sf::FloatRect AnimatedSprite::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

bool AnimatedSprite::isLooped() const
{
	return isLooped_;
}

bool AnimatedSprite::isPlaying() const
{
	return !isPaused_;
}

sf::Time AnimatedSprite::getFrameTime() const
{
	return frameTime_;
}

void AnimatedSprite::setFrame(std::size_t newFrame, bool resetTime)
{
	if (animation_)
	{
		//calculate new vertex positions and texture coordiantes
		sf::IntRect rect = animation_->getFrame(newFrame);

		vertices_[0].position = sf::Vector2f(0.f, 0.f);
		vertices_[1].position = sf::Vector2f(0.f, static_cast<float>(rect.height));
		vertices_[2].position = sf::Vector2f(static_cast<float>(rect.width), static_cast<float>(rect.height));
		vertices_[3].position = sf::Vector2f(static_cast<float>(rect.width), 0.f);

		float left = static_cast<float>(rect.left) + 0.0001f;
		float right = left + static_cast<float>(rect.width);
		float top = static_cast<float>(rect.top);
		float bottom = top + static_cast<float>(rect.height);

		vertices_[0].texCoords = sf::Vector2f(left, top);
		vertices_[1].texCoords = sf::Vector2f(left, bottom);
		vertices_[2].texCoords = sf::Vector2f(right, bottom);
		vertices_[3].texCoords = sf::Vector2f(right, top);
	}

	if (resetTime)
		currentTime_ = sf::Time::Zero;
}

void AnimatedSprite::update(sf::Time deltaTime)
{
	// if not paused and we have a valid animation
	if (!isPaused_ && animation_)
	{
		// add delta time
		currentTime_ += deltaTime;

		// if current time is bigger then the frame time advance one frame
		if (currentTime_ >= frameTime_)
		{
			// reset time, but keep the remainder
			currentTime_ = sf::microseconds(currentTime_.asMicroseconds() % frameTime_.asMicroseconds());

			// get next Frame index
			if (currentFrame_ + 1 < animation_->getSize())
				currentFrame_++;
			else
			{
				// animation has ended
				currentFrame_ = 0; // reset to start

				if (!isLooped_)
				{
					isPaused_ = true;
				}

			}

			// set the current frame, not reseting the time
			setFrame(currentFrame_, false);
		}
	}
}

void AnimatedSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (animation_ && texture_)
	{
		states.transform *= getTransform();
		states.texture = texture_;
		target.draw(vertices_, 4, sf::Quads, states);
	}
}
