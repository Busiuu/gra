#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <cstdlib>
#include <iostream>
#include <vector>
#pragma once

// skrypt nie autorski, pobrany z oficialnej dokumentacji sfml 

class TileMap : public sf::Drawable, public sf::Transformable {
    public:

    bool load(const std::string& tileset, sf::Vector2u tileSize, int* tiles, unsigned int width, unsigned int height);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};