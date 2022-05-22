#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800,480), "My window");
    
    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(sf::Vector2f(0.0, 0.0));
    circle.setFillColor(sf::Color(0, 250, 0));
    
    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(sf::Vector2f(500.0, 400.0));
    rectangle.setFillColor(sf::Color(0, 0, 250));
    
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(sf::Vector2f(300.0, 160.0));
    
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
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);
        
        // end the current frame
        window.display();
    }
    
    return 0;
}