#include "Render.h"
#include "Tile.h"
#include "Map.h"
#include "Header.h"

Render::Render(std::shared_ptr<sf::RenderWindow> window)
	:m_window(window),
	m_width(window.get()->getPosition().x), m_height(window.get()->getPosition().y)
{
	
}

std::vector<Tile> Render::make_frame(std::vector<Tile> tiles_to_render) {
	std::vector<Tile> frame;
	for (auto tile : tiles_to_render) {
		sf::Vector2f scaling_factor = { 1, 1 };
		if (r_cord_end_pos.x - tile.get_cord().x < tile_size_x) {
			scaling_factor.x = m_width / tile.get_cord().x;
			
			tile.setScale(scaling_factor);
			frame.push_back(tile);
		}
		if (r_cord_end_pos.y - tile.get_cord().y < tile_size_y) {
			scaling_factor.y = m_height / tile.get_cord().y;

			tile.setScale(scaling_factor);
			frame.push_back(tile);
		}
	}

	return frame;
}

void Render::draw_frame(std::vector<Tile> frame) {
	for (auto tile : frame) {
		m_window.get()->draw(tile.get_sprite());
	}
}

void Render::update(std::vector<Tile> tiles_to_render) {
	m_window.get()->clear();
	
	auto frame = make_frame(tiles_to_render);
	draw_frame(frame);

	m_window.get()->display();
}