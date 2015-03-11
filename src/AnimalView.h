#ifndef __AnimalView_H__
#define __AnimalView_H__

#include "AnimatedSprite.h"
#include <SFML/Graphics.hpp>

/**
 * An Animal view allows to display an animal's state
 */
class AnimalView : public sf::Drawable {
	sf::Text text_;							   //!< animal's text
	AnimatedSprite<32,32> sprite_;			   //!< animal's sprite

public:
	AnimalView(sf::Text text, AnimatedSprite<32, 32> sprite);
	~AnimalView();

	/**
	 * update the view's information
	 * \param text Animal's text
	 * \param sprite Animal's sprite
	 */
	void update(sf::Text text, AnimatedSprite<32,32> sprite);

	/**
	 * drawing function.
	 * draw the animal and it's text
	 */
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	/**
	 * draw the text bubble
	 */
	void drawTextBubble(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif /* __AnimalView_H__ */