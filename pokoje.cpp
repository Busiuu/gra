#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "pokoje.hpp"

engine::Room::Room(sf::Vector2f size, sf::Vector2f pos, Pokoj_ rooms,  sf::Color color)  : sf::RectangleShape(size){
            setPosition(pos);
            setFillColor(color);
};


void engine::Room::Room_gen(){
            setFillColor(sf::Color::White);
            active = true;
};

sf::RectangleShape engine::Room::drawing(){
    return rectangle;
}

engine::Room::~Room(){};