#ifndef __AnimalControler_H__
#define __AnimalControler_H__

#include "AnimalModel.h"
#include "AnimalView.h"

/**
 * An animal controler.
 * An Animal controler animates an animal
 * and makes it alive (speech, sleep,...)
 */
class AnimalControler
{
	unsigned frameCountThatSomethingIsBeingSaid_;  //!< timer to count the number of frame a text is being said
	sf::Time userTick_;                            //!< minimal time between execution of two user function
	sf::Time userTickCounter_;                     //!< time elapsed between two call of userTick function
	
protected:
	AnimalModel model_;							   //!< animal's model
	AnimalView view_;							   //!< animal's view

public:
	AnimalControler(std::string path);
	~AnimalControler();

public:
	
	/**
	 * updates the Animal's view's informations
	 */
	void updateView();

	/**
	 * processes the Animal's sprite's loop
	 * \param elapsedTime time elapsed since the last frame
	 */
	void update(sf::Time elapsedTime);

	/**
	 * set the Animal's position
	 * \param position the Animal's position
	 */
	void setAnimalPosition(sf::Vector2f position);

	/**
	 * method to make the sprite talk
	 * \param text whatever the sprite must say
	 */
	void operator<<(std::string text);
	
	/**
	 * sets the Animal's color
	 * \param color color to be set
	 */
	void setAnimalColor(sf::Color color);

	/**
	 * makes the animal sleep for a certain duration
	 * \param napDuration the duration of the nap
	 */
	void sleep(sf::Time napDuration);

	/**
	 * awakens the Animal
	 */
	void wakeAnimalUp();
	
	/**
	 * execute a function every userTick_ second.
	 * it's where lib user can do something
	 */
	virtual void userFunction();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif /* __AnimalControler_H__ */