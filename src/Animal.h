#ifndef __Animal_H__
#define __Animal_H__

#include "SimpleAnimatedSprite.h"
#include <string>
#include <SFML/Graphics.hpp>

/**
 * An animal class.
 * An Animal animate a sprite sheet and
 * add several method (like being able to speak)
 */
class Animal : public sf::Drawable{
	SimpleAnimatedSprite<32,32> sprite_;           //!< Sprite of the animal (containing logic for animation)
	sf::Text text_;                                //!< Drawable object for displaying text
	bool isSayingSomething_;                       //!< true if the Animal is saying something
	unsigned frameCountThatSomethingIsBeingSaid_;  //!< timer to count the number of frame a text is being said
	
private:
	/**
	 * drawing function.
	 * draw the animal and it's text
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	/**
	 * Constructor for Animal
	 * \param path path to a sprite sheet
	 */
	Animal(std::string path);

	/**
	 * set the position of the sprite on screen
	 * \param position position to place the sprite
	 */
	void setPosition(sf::Vector2f position);
	
	/**
	 * select a set of frame to play.
	 * currently, a sprite has 4 different animation dependent of the direction the sprite is looking
	 * \param animationName a direction for the animation ("up", "down", "left" or "right")
	 */
	void setAnimation(std::string animationName);

	/**
	 * processing loop of the sprite
	 * \param elapsedTime time elapsed since last frame
	 */
	void update(sf::Time elapsedTime);

	/**
	 * method to make the sprite talk
	 * \param text whatever the sprite must say
	 */
	void operator<<(std::string& text);

	/**
	 * overload for C string
	 * \param text whatever the sprite must say
	 */
	void operator<<(const char* text);
};

#endif /* __Animal_H__ */
