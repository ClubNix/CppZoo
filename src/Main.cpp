#include <iostream>
#include <SFML/Graphics.hpp>

#include "AnimatedSprite.h"
#include "Animal.h"

sf::Font font;

int main(){
	font.loadFromFile("resources/font/EptKazoo.ttf");
	sf::Vector2i screenDimensions(480, 312);
	sf::RenderWindow window(sf::VideoMode(480, 312), "Zoo");
	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Texture texture;
	
	window.setVerticalSyncEnabled(true);
	
	backgroundTexture.loadFromFile("resources/map.png");
	background.setTexture(backgroundTexture);
	background.setOrigin(0.f,0.f);
	
	Animal fairy("resources/animal/cat.png");
	fairy.setPosition(sf::Vector2f(screenDimensions / 2));
//	fairy.setFrameRate(sf::milliseconds(200));
	sf::Clock clock;
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
				
				case sf::Event::KeyPressed:
					switch(event.key.code){
						case sf::Keyboard::Key::Left:
							fairy.setAnimation("left");
							fairy << "miaou";
							break;
							
						case sf::Keyboard::Key::Up:
							fairy.setAnimation("up");
							fairy << "chat";
							break;
							
						case sf::Keyboard::Key::Right:
							fairy.setAnimation("right");
							fairy << "ZzZz. . .";
							break;
							
						case sf::Keyboard::Key::Down:
							fairy.setAnimation("down");
							fairy << "oh, un chat!";
							break;
							
						default:
							break;
					}
					break;
					
				default:
					break;
			}
		}

		sf::Time elapsedTime = clock.restart();
		fairy.update(elapsedTime);
		window.clear();
		window.draw(background);
		window.draw(fairy);
		window.display();
	}

	return 0;
}
