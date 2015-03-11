#ifndef __Animal_H__
#define __Animal_H__

#include "AnimatedSprite.h"
#include "Direction.h"
#include <string>
#include <SFML/Graphics.hpp>

/**
 * An animal model class.
 * An Animal has a sprite sheet and several states,
 * such as talking or sleeping
 */
class AnimalModel {
	AnimatedSprite<32,32> sprite_;                 //!< Sprite of the animal (containing logic for animation)
	sf::Text text_;                                //!< Drawable object for displaying text
	bool isTalking_;     		                   //!< true if the Animal is saying something
	Direction currentDirection_;				   //!< direction the animal is facing
	bool isSleeping_;                              //!< true if the Animal is sleeping
	sf::Time napDuration_;                         //!< duration of a sleeping state

public:
	/**
	 * Constructor for Animal
	 * \param path path to a sprite sheet
	 */
	AnimalModel(std::string path);

	/**
	 * updates the sprite
	 * \param elapsedTime time elapsed since last frame
	 */
	void updateSprite(sf::Time elapsedTime);

	/**
	 * get the animal's text
	 * \return the animal's text
	 */
	const sf::Text &getText() const;

	/**
	 * get the animal's sprite
	 * \return the animal
	 */
	const AnimatedSprite<32,32> &getSprite() const;

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
	void setSpriteAnimation(Direction animationName);

	/**
	 * method to make the sprite talk
	 * \param text whatever the sprite must say
	 */
	void setText(std::string text);

	/**
	 * sets the sprite's color
	 * \param color color to be set
	 */
	void setColor(sf::Color color);
	
	/**
	 * get sleeping state of the animal
	 * \return true if the animal is sleeping
	 */
	bool isSleeping() const;

	/**
	 * make the animal sleep for a certain duration. If the animal is already sleeping, he will sleep longer.
	 * \param napDuration the duration of the nap
	 */
	void sleep(sf::Time napDuration);

	/**
	 * change the animal's state to awoken
	 */
	void wakeUp();
	
	/**
	 * get the animal's speech state
	 * \return wether the animal is talking or not
	 */
	bool isTalking() const;

	/**
	 * get the animal's current nap's duration
	 * \return the animal's current nap's duration
	 */
	sf::Time getNapDuration();

	/**
	 * sets the animal's nap's duration
	 * \param the nap's duration
	 */
	void setNapDuration(sf::Time napDuration);
	
	/**
	 * makes the animal talk
	 */
	void talk();
	
	/**
	 * changes the animal's speech state to having finished talking
	 */
	void finishTalking();
	
	/**
	 * get the animal's current direction
	 * \return the current direction
	 */
	Direction getCurrentDirection();
	
	/**
	 * sets the animal's current direction
	 * \param direction direction to be set
	 */
	void setCurrentDirection(Direction direction);
};

#endif /* __Animal_H__ */

