#include <SFML/Graphics.hpp>
#include <memory>

#include "Header.h"
#include "Map.h"
#include "Render.h"
#include "Tile.h"
#pragma once
std::shared_ptr<sf::RenderWindow> window(std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML works!"));
sf::Sprite sprite;

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
    sprite.setTexture(texture);
    sprite.setPosition({ 50, 50 });

    
    
    //sf::Sprite *ptr_sprite = new sf::Sprite(sprite);
    
    for (int i = 0;i < 50;i++) {
        m_map.add_tile(sf::Vector2f(i * tile_size_x, 0), sprite);
    
        m_map.add_tile(sf::Vector2f(0, i * tile_size_y), sprite);
    }
    //m_map.add_tile({ 50, 50 }, sprite);
    //m_map.add_tile({ 50, 100 }, sprite);
    //m_map.add_tile({ 50, 150 }, sprite);
    //m_map.add_tile({ 50, 200 }, sprite);
    //m_map.add_tile({ 50, 250 }, sprite);

    
    m_render.set_map(m_map.get_to_render({ 0, 0 }, { 1366, 768 }));
    while (window.get()->isOpen())
    {
        sf::Event event;
        while (window.get()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.get()->close();
        }
       
        m_render.update();
    }

    return 0;
}


