#include "AnimalView.h"

AnimalView::AnimalView(sf::Text text, AnimatedSprite<32,32> sprite): text_(text), sprite_(sprite){
}

AnimalView::~AnimalView(){}

void AnimalView::update(sf::Text text, AnimatedSprite<32,32> sprite){
	text_ = text;
	sprite_ = sprite;
	// sprite_.setPositixon(sprite.getPosition());
}

void AnimalView::drawTextBubble(sf::RenderTarget& target, sf::RenderStates states) const{
	//calculate position of text bubble
	float textWidth = text_.getGlobalBounds().width;
	float textHeight = text_.getGlobalBounds().height;
	sf::CircleShape textBubble(textWidth/2);
	textBubble.setOrigin(textWidth/2, textWidth/2);
	sf::Vector2f textBubblePosition = text_.getPosition();
	textBubblePosition.x += textWidth/2;
	textBubblePosition.y += 0.9*textHeight; // have a better rendering
	textBubble.setPosition(textBubblePosition);
	
	//kikoo bubble
	textBubble.setFillColor(sf::Color(225,200,250));
	textBubble.setOutlineThickness(1.5);
	textBubble.setOutlineColor(sf::Color(125,100,150));
	textBubble.setScale(1.6,1.6*textHeight/textWidth);
	
	target.draw(textBubble,states);
	target.draw(text_,states);
}

void AnimalView::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(sprite_, states);
}