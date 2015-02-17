#include <iostream>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "SimpleAnimatedSprite.h"

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
	
	SimpleAnimatedSprite fairy("resources/animal/fairy.png");
	fairy.setPosition(sf::Vector2f(screenDimensions / 2));
//	sf::Clock frameClock;
	
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
				
				case sf::Event::KeyPressed:
				case sf::Event::KeyReleased:
					switch(event.key.code){
						case sf::Keyboard::Key::Left:
							fairy.setAnimation("left");
							break;
							
						case sf::Keyboard::Key::Up:
							fairy.setAnimation("up");
							break;
							
						case sf::Keyboard::Key::Right:
							fairy.setAnimation("right");
							break;
							
						case sf::Keyboard::Key::Down:
							fairy.setAnimation("down");
							break;
							
						default:
							break;
					}
					
				default:
					break;
			}
		}
		
//		sf::Time frameTime = frameClock.restart();
//		animatedSprite.play(*currentAnimation);
//		animatedSprite.update(frameTime);
		fairy.update();
		window.clear();
		window.draw(background);
//		window.draw(animatedSprite);
		window.draw(fairy);
		window.display();
	}

	return 0;
}
