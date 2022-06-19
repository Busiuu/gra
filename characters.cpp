#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
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
        
    };

Bohater::~Bohater() {};

bool Bohater::check(enum sf::Keyboard::Key key){
        sf::FloatRect rectangle_bounds = getGlobalBounds();
        if( 32 < top_b && key == sf::Keyboard::Key::Up)
        {
            return false;
        }

        else if(rectangle_bounds.height - 32 > bottom_b && key == sf::Keyboard::Key::Down)
        {
            return false;
        }

        if(32 < left_b && key == sf::Keyboard::Key::Left)
        {
            return false;
        }

        else if(rectangle_bounds.width - 32>right_b && key == sf::Keyboard::Key::Right)
        {
            return false;
        }
        return true;
    }

void Bohater::animate(sf::Time elapsed){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                // move up...
                if (check(sf::Keyboard::Up))
                    setPosition(getPosition() + sf::Vector2f(0,-(abs(1000*elapsed.asSeconds()))));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                // move down...
                if (check(sf::Keyboard::Down))
                    setPosition(getPosition() + sf::Vector2f(0,abs(1000*elapsed.asSeconds())));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                // move up...
                if (check(sf::Keyboard::Left))
                    setPosition(getPosition() + sf::Vector2f(0,-(abs(1000*elapsed.asSeconds()))));
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                // move down...
                if (check(sf::Keyboard::Right))
                    setPosition(getPosition() + sf::Vector2f(0,abs(1000*elapsed.asSeconds())));
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
