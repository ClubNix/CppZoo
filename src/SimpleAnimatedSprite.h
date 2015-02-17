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

public:
	SimpleAnimatedSprite(std::string fileName);
	const sf::IntRect getCurrentFrame() const;
	void setAnimation(std::string animationName);
	void update();
};

#endif /* __SimpleAnimatedSprite_H__ */

