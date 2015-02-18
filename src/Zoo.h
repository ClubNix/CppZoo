#ifndef __Zoo_H__
#define __Zoo_H__

#include <SFML/Graphics.hpp>
#include <string>

class Zoo : public sf::Sprite{
	sf::Texture texture_;

public:
	Zoo(std::string fileName);
};

#endif /* __Zoo_H__ */

