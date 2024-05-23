#ifndef RENDER_H
#define RENDER_H


#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Tile;
#pragma once
class Render
{
public:
	Render(std::shared_ptr<sf::RenderWindow> window);
	//~Render();
	void update();
	void set_map(std::vector<std::shared_ptr<Tile>> tiles_to_render);
	sf::Vector2i get_start_pos();
	sf::Vector2i get_end_pos();
private:
	void make_frame();
	void draw_frame();
	std::vector<std::shared_ptr<Tile>> frame;
	sf::Vector2f m_rect;
	std::shared_ptr<sf::RenderWindow> m_window;
	sf::Vector2i r_cord_start_pos = sf::Vector2i(0, 0);
	sf::Vector2i r_cord_end_pos;
	unsigned int m_width;
	unsigned int m_height;
};

#endif