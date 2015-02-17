#ifndef __Animal_H__
#define __Animal_H__

#include "SimpleAnimatedSprite.h"
#include <string>
#include <SFML/Graphics.hpp>

class Animal : public sf::Drawable{
	SimpleAnimatedSprite<32,32> sprite_;
	sf::Text text_;
	bool isSayingSomething_;
	unsigned frameCountThatSomethingIsBeingSaid_;
	
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Animal(std::string path);
	void setPosition(sf::Vector2f position);
	void setAnimation(std::string animationName);
	void update(sf::Time elapsedTime);
	void operator<<(std::string& text);
	void operator<<(const char* text);
};

#endif /* __Animal_H__ */

