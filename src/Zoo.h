#ifndef __Zoo_H__
#define __Zoo_H__

#include <SFML/Graphics.hpp>
#include <string>
#include "Animal.h"

class Zoo : public sf::Drawable{
	sf::Texture texture_;
	sf::Sprite background_;
	std::vector<Animal> animalList_;
	
private:
	/**
	 * drawing function.
	 * draw the Zoo
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
public:
	/**
	 * Constructor for Zoo, a container for animal
	 * \param fileName name of the background to use
	 */
	Zoo(std::string fileName);

	/**
	 * update all animal in zoo
	 * \param elapsedTime time elapsed since last frame
	 */
	void update(sf::Time elapsedTime);

	/**
	 * add an animal in zoo
	 * \param animal the animal to add
	 */
	void operator<<(Animal& animal);

	/**
	 * retrieve an animal from zoo
	 * \param position postion of animal in the zoo
	 * \return the animal
	 */
	Animal& operator[](int position);
	
	/**
	 * count number of animal in the zoo
	 * \return number of animal
	 */
	int getAnimalCount();
	
	/**
	 * give the number of animals
	 * \return size of the zoo
	 */
	int size();
};

#endif /* __Zoo_H__ */

