#include "EventManager.h"

EventManager::EventManager(){}

EventManager::~EventManager(){}

void EventManager::manageEvent(sf::RenderWindow *window, sf::Event event){
	switch(event.type){
		case sf::Event::Closed:
			window->close();
			break;
		default:
			break;
	}
}
