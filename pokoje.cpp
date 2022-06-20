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

engine::Room::~Room(){};

engine::Empty::Empty(sf::Vector2f pos, sf::Vector2f size)  : engine::Room::Room(size, pos){};

engine::Empty::~Empty(){};

engine::Start::Start(sf::Vector2f pos, sf::Vector2f size)  : engine::Room::Room(size, pos){};

engine::Start::~Start(){
    active = false;
};

engine::Hall::Hall(sf::Vector2f pos, sf::Vector2f size)  : engine::Room::Room(size, pos){};

engine::Hall::~Hall(){};

engine::Item_room::Item_room(sf::Vector2f pos, sf::Vector2f size)  : engine::Room::Room(size, pos){
        active = false;
};

engine::Item_room::~Item_room(){};

engine::Shop::Shop(sf::Vector2f pos, sf::Vector2f size)  : engine::Room::Room(size, pos){
    active = false;
};

engine::Shop::~Shop(){};

engine::Boss::Boss(sf::Vector2f pos, sf::Vector2f size)  : engine::Room::Room(size, pos){
    active = false;
};

engine::Boss::~Boss(){};

std::vector<std::vector<int> >  engine::Empty::getLevels(){
    return level_.at(rand() % layers);
};

std::vector<std::vector<int> >  engine::Start::getLevels(){
    return level_.at(rand() % layers);
};

std::vector<std::vector<int> >  engine::Hall::getLevels(){
    return level_.at(rand() % layers);
};

std::vector<std::vector<int> >  engine::Item_room::getLevels(){
    return level_.at(rand() % layers);
};

std::vector<std::vector<int> >  engine::Shop::getLevels(){
    return level_.at(rand() % layers);
};

std::vector<std::vector<int> >  engine::Boss::getLevels(){
    return level_.at(rand() % layers);
};
