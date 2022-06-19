#include <iostream>
#include <vector> 
#include <ctime>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "dung_gener.hpp"
#include "dung_gener.cpp"
#include "pokoje.hpp"
#include "pokoje.cpp"
#include "Tiles.hpp"
#include "characters.hpp"
#include "characters.cpp"

using namespace std;

int main() {
    srand (time(NULL));
    // create the window
    sf::RenderWindow window(sf::VideoMode(1024,1024), "Rouge-like");
    engine::Generator silnik;
    Bohater bohater(sf::Vector2f(127,172), sf::Vector2f(512,512)); 
    silnik.init();
    sf::Clock clock;
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Time elapsed = clock.restart();
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        // draw everything here...
        window.draw(silnik.map);
        // window.draw(bohater);
        // end the current frame
        window.display();
    }
};