#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

#pragma once

class Tile;

class Map
{
public:
	Map();
	~Map();
	std::shared_ptr<Tile> get_tile(sf::Vector2i cord);
	std::shared_ptr<Tile> get_wall(sf::Vector2i cord);
	void add_tile(sf::Vector2i cord, sf::Sprite *sprite);
	void delete_tile(sf::Vector2i);
	int get_size();
	std::vector<Tile> get_to_render(sf::Vector2i render_start_pos,sf::Vector2i render_end_pos);
private:
	std::shared_ptr<Tile> get_vector_value(sf::Vector2i cord, const std::vector<std::shared_ptr<Tile>> vec);
	std::vector<std::shared_ptr<Tile>> m_tiles;
	std::vector<std::shared_ptr<Tile>> m_walls;
};

