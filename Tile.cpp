#include "Tile.h"


//Tile::~Tile() {
//	delete m_sprite;
//}

Tile::Tile(sf::Vector2f cord, sf::Sprite sprite)
: m_cord(cord), m_sprite(sprite), m_rect(sprite.getTextureRect()) 
{
	m_sprite.setPosition(cord);
}

sf::Vector2i Tile::get_cord() {
	return m_cord;
}

sf::Sprite Tile::get_sprite() {
	return m_sprite;
}

void Tile::setScale(sf::Vector2f scale) {
	m_sprite.scale(scale);
}

sf::Vector2i Tile::get_rect_size() {
	return m_rect.getSize();
}