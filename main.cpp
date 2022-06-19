#include <iostream> 
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "dung_gener.hpp"
#include "dung_gener.cpp"
#include "pokoje.hpp"
#include "pokoje.cpp"
#include "Tiles.hpp"

using namespace std;

int main() {
    srand (time(NULL));
    // create the window
    sf::RenderWindow window(sf::VideoMode(1024,1024), "Rouge-like");
    engine::Generator silnik;
    silnik.drawable();
    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // clear the window with black color
        window.clear(sf::Color::Black);
        
        // draw everything here...
        window.draw(silnik.map);
        // end the current frame
        window.display();
    }
};