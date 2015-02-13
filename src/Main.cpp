#include <iostream>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"

int main(){
	sf::Vector2i screenDimensions(480, 312);
	sf::RenderWindow window(sf::VideoMode(480, 312), "Zoo");
	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Texture texture;
	
	window.setFramerateLimit(60);
	
	backgroundTexture.loadFromFile("resources/map.png");
	background.setTexture(backgroundTexture);
	background.setOrigin(0.f,0.f);
		
	if (!texture.loadFromFile("resources/animal/fairy.png")){
		std::cerr << "Failed to load spritesheet!" << std::endl;
		return 1;
	}
	
	Animation walkingAnimationDown;
	walkingAnimationDown.setSpriteSheet(texture);
	walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimationDown.addFrame(sf::IntRect(64, 0, 32, 32));
	walkingAnimationDown.addFrame(sf::IntRect(32, 0, 32, 32));
	walkingAnimationDown.addFrame(sf::IntRect( 0, 0, 32, 32));

	Animation walkingAnimationLeft;
	walkingAnimationLeft.setSpriteSheet(texture);
	walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
	walkingAnimationLeft.addFrame(sf::IntRect(64, 32, 32, 32));
	walkingAnimationLeft.addFrame(sf::IntRect(32, 32, 32, 32));
	walkingAnimationLeft.addFrame(sf::IntRect( 0, 32, 32, 32));

	Animation walkingAnimationRight;
	walkingAnimationRight.setSpriteSheet(texture);
	walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
	walkingAnimationRight.addFrame(sf::IntRect(64, 64, 32, 32));
	walkingAnimationRight.addFrame(sf::IntRect(32, 64, 32, 32));
	walkingAnimationRight.addFrame(sf::IntRect( 0, 64, 32, 32));

	Animation walkingAnimationUp;
	walkingAnimationUp.setSpriteSheet(texture);
	walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
	walkingAnimationUp.addFrame(sf::IntRect(64, 96, 32, 32));
	walkingAnimationUp.addFrame(sf::IntRect(32, 96, 32, 32));
	walkingAnimationUp.addFrame(sf::IntRect( 0, 96, 32, 32));
	
	Animation* currentAnimation = &walkingAnimationDown;
	
	AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
	animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));

	sf::Clock frameClock;
	
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		
		sf::Time frameTime = frameClock.restart();
		animatedSprite.play(*currentAnimation);
		animatedSprite.update(frameTime);
		
		window.clear();
		window.draw(background);
		window.draw(animatedSprite);
		window.display();
	}

	return 0;
}
