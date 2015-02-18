#ifndef __Zoo_H__
#define __Zoo_H__

#include <SFML/Graphics.hpp>
#include <string>

class Zoo : public sf::Drawable{
	sf::Texture texture_;
	sf::Sprite background_;
	
private:
	/**
	 * drawing function.
	 * draw the Zoo
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
public:
	Zoo(std::string fileName);
};

#endif /* __Zoo_H__ */

