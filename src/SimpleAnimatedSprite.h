#ifndef __SimpleAnimatedSprite_H__
#define __SimpleAnimatedSprite_H__

#include <stdexcept>
#include <string>
#include <SFML/Graphics.hpp>
#include <unordered_map>

class SimpleAnimatedSprite : public sf::Sprite{
	using Animation = typename std::vector<sf::IntRect>;
	sf::Texture texture_;
	std::unordered_map<std::string, Animation> frameList_;
	unsigned currentFrame_;
	std::string currentAnimation_;

private:
	void cutSheet();
//	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	SimpleAnimatedSprite(std::string fileName);
	void update();
	const sf::IntRect getCurrentFrame() const;
};

#endif /* __SimpleAnimatedSprite_H__ */

