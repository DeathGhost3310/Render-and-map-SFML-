#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

#pragma once

class Tile
{
public:
	Tile(sf::Vector2f cord, sf::Sprite sprite);
	/*~Tile();*/
	sf::Vector2i get_cord();
	sf::Sprite get_sprite();
	void setScale(sf::Vector2f scale);
	sf::Vector2i get_rect_size();
private:
	sf::Vector2i m_cord;
	sf::Sprite m_sprite;
	sf::IntRect m_rect;
};

#endif