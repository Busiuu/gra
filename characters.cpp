#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <list>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Tiles.hpp"
#include "characters.hpp"

Postac::Postac(sf::Vector2f size, sf::Vector2f pos, std::string tekstura) : RectangleShape(size)
    {
        pozycja = pos;
        setPosition(pozycja);
        tekstura_.loadFromFile(tekstura);
        setTexture(&tekstura_);
    }

Postac::~Postac() {};


Bohater::Bohater(sf::Vector2f size, sf::Vector2f pos) : Postac(size, pos, "boh.png") {
         for(int i = 0; i < 8; i++){
            rect.emplace_back(sf::IntRect(i*127, 8, 127, 172));
        }
    };

Bohater::~Bohater() {};

bool Bohater::check(enum sf::Keyboard::Key key){
        sf::FloatRect rectangle_bounds = getGlobalBounds();
        if( rectangle_bounds.top < 32 && key == sf::Keyboard::Key::Up)
        {
            return false;
        }

        else if(rectangle_bounds.top + rectangle_bounds.height + 32 > 1024 && key == sf::Keyboard::Key::Down)
        {
            return false;
        }

        if(32 > rectangle_bounds.left && key == sf::Keyboard::Key::Left)
        {
            return false;
        }

        else if(rectangle_bounds.left + rectangle_bounds.width + 32 > 1024 && key == sf::Keyboard::Key::Right)
        {
            return false;
        }
        return true;
    }

void Bohater::animate(sf::Time elapsed){
            time_frame += elapsed;
            if (time_frame.asSeconds() > 0.2){
                if (frame >= 4){ frame = 1; };
                setTextureRect(rect[frame]);
                frame++;
                time_frame = time_frame.Zero;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                // move up...
                if (check(sf::Keyboard::Up))
                    setPosition(getPosition() + sf::Vector2f(0,-(abs(500*elapsed.asSeconds()))));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                // move down...
                if (check(sf::Keyboard::Down))
                    setPosition(getPosition() + sf::Vector2f(0,abs(500*elapsed.asSeconds())));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                // move up...
                if (check(sf::Keyboard::Left))
                    setPosition(getPosition() + sf::Vector2f(-(abs(500*elapsed.asSeconds())),0));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                // move down...
                if (check(sf::Keyboard::Right))
                    setPosition(getPosition() + sf::Vector2f(abs(500*elapsed.asSeconds()),0));
            }
        
    }

void Bohater::UstawCel(const sf::RenderWindow& window) {
			this->mouse_pos =sf::Mouse::getPosition(window);
	}

void Bohater::PodazajDoCelu(sf::Time el) {

			if (this->getPosition().y <= mouse_pos.y ) {
				this->move(0, 1000 * el.asSeconds());
			} else if (this->getPosition().y >= mouse_pos.y ) {
				this->move(0, -1000 * el.asSeconds());
			}

	}
