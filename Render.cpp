#include "Render.h"
#include "Tile.h"
#include "Map.h"
#include "Header.h"

Render::Render(std::shared_ptr<sf::RenderWindow> window)
	:m_window(window),
	m_width(window.get()->getPosition().x), m_height(window.get()->getPosition().y), 
	r_cord_end_pos({ window.get()->getPosition().x, window.get()->getPosition().y})
{
	
}

void Render::make_frame() {
	
	for (std::shared_ptr<Tile> tile : frame) {
		sf::Vector2f scaling_factor = { 1, 1 };
		if (r_cord_end_pos.x - tile.get()->get_cord().x < tile_size_x) {
			scaling_factor.x = m_width / tile.get()->get_cord().x;
			
			tile.get()->setScale(scaling_factor);
			
		}
		if (r_cord_end_pos.y - tile.get()->get_cord().y < tile_size_y) {
			scaling_factor.y = m_height / tile.get()->get_cord().y;

			tile.get()->setScale(scaling_factor);
			
		}

		tile.get()->get_sprite().setPosition(sf::Vector2f(tile.get()->get_cord()));
		
	}
	
}

void Render::draw_frame() {
	for (std::shared_ptr<Tile> tile : frame) {
		tile.get()->get_sprite().setPosition(sf::Vector2f( tile.get()->get_cord().x, tile.get()->get_cord().y));
		m_window.get()->draw(tile.get()->get_sprite());
	}
}

void Render::update() {
	m_window.get()->clear();
	
	
	draw_frame();

	m_window.get()->display();
}

sf::Vector2i Render::get_start_pos() {
	return r_cord_start_pos;
}

sf::Vector2i Render::get_end_pos() {
	return r_cord_end_pos;
}

void Render::set_map(std::vector<std::shared_ptr<Tile>> tiles_to_render) {
	frame = tiles_to_render;
}