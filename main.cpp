#include <SFML/Graphics.hpp>
#include <memory>

#include "Header.h"
#include "Map.h"
#include "Render.h"
#include "Tile.h"
#pragma once
std::shared_ptr<sf::RenderWindow> window(std::make_shared<sf::RenderWindow>(sf::VideoMode(1366, 768), "SFML works!"));


Map m_map;
Render m_render(window);

int main()
{
    const int FPS = 60;
    window.get()->setFramerateLimit(FPS);
    sf::Image image;
    image.loadFromFile("images/block.png");
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite *sprite = new sf::Sprite;
    sprite->setTexture(texture);
    sprite->setPosition({ 50, 50 });
    
    for (int i = 0;i < 50;i++) {
        m_map.add_tile({i * tile_size_x, 0}, sprite);
    
        m_map.add_tile({0, i * tile_size_y}, sprite);
    }

   
    

    while (window.get()->isOpen())
    {
        sf::Event event;
        while (window.get()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.get()->close();
        }
        m_render.update(m_map.get_to_render({ 0, 0 }, {1366, 768}));
    }

    return 0;
}


