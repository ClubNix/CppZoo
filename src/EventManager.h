#ifndef __EventManager_H__
#define __EventManager_H__

#include <SFML/Graphics.hpp>

class EventManager
{
public:
	EventManager();
	~EventManager();

public:
	void manageEvent(sf::RenderWindow *window, sf::Event event);
	
};
#endif /* __EventManager_H__ */
