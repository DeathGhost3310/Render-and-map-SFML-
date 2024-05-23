#include "Map.h"
#include "Tile.h"

Map::Map() 
{

}

std::shared_ptr<Tile> Map::get_vector_value(sf::Vector2i cord,const std::vector<std::shared_ptr<Tile>> vec){
	for (int i = 0;i < vec.size() - 1;i++) {
		if (vec[i].get()->get_cord() == cord)
			return vec[i];
	}
}

std::shared_ptr<Tile> Map::get_tile(sf::Vector2i cord) {
	return get_vector_value(cord, m_tiles);
}

std::shared_ptr<Tile> Map::get_wall(sf::Vector2i cord) {
	return get_vector_value(cord, m_walls);
}

void Map::delete_tile(sf::Vector2i cord) {
	auto it = m_tiles.begin();
	for (auto cd : m_tiles)
	{	
		if (cd.get()->get_cord() == cord)
			m_tiles.erase(it);  return;
		it++;
	
	}
	
}

void Map::add_tile(sf::Vector2i cord, sf::Sprite *sprite) {
	m_tiles.push_back(std::make_shared<Tile>(Tile( cord, sprite )));
}

int Map::get_size() {
	return m_tiles.size() + m_walls.size();
}

std::vector<Tile> Map::get_to_render
(sf::Vector2i render_start_pos, sf::Vector2i render_end_pos)
{
	std::vector<Tile> tiles_to_render;
	for (auto tile : m_tiles) {
		if (tile.get()->get_cord().x >= render_start_pos.x
			&& tile.get()->get_cord().y >= render_start_pos.y
				&& tile.get()->get_cord().x < render_end_pos.x
				&& tile.get()->get_cord().y < render_end_pos.y) 
					tiles_to_render.push_back(*tile);
	}
	if (m_walls.size() > 0) {
		for (auto wall : m_walls) {
			if (wall.get()->get_cord().x > render_start_pos.x
				&& wall.get()->get_cord().y > render_start_pos.y
				&& wall.get()->get_cord().x < render_end_pos.x
				&& wall.get()->get_cord().y < render_end_pos.y)
				tiles_to_render.push_back(*wall);
		}
	}

	return tiles_to_render;
}