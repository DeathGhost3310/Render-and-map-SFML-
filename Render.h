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
	~Render();
	void update(std::vector<Tile> tiles_to_render);
	
private:
	std::vector<Tile> make_frame(std::vector<Tile> tiles_to_render);
	void draw_frame(std::vector<Tile> frame);

	sf::Vector2f m_rect;
	std::shared_ptr<sf::RenderWindow> m_window;
	sf::Vector2i r_cord_start_pos = sf::Vector2i(0, 0);
	sf::Vector2i r_cord_end_pos;
	unsigned int m_width;
	unsigned int m_height;
};

