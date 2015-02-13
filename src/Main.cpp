#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 312), "Zoo");
	sf::Texture backgroundTexture;
	sf::Sprite background;
	
	backgroundTexture.loadFromFile("resources/map.png");
	background.setTexture(backgroundTexture);
	background.setOrigin(0.f,0.f);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}
		
		window.clear();
		window.draw(background);
		window.display();
	}

	return 0;
}
