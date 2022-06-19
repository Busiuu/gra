#pragma once

namespace engine{

        class Room : public sf::RectangleShape {
        public:
        enum Pokoj_ {Boss, Item, Shop, Hall, Start};
        Room(sf::Vector2f size = sf::Vector2f(100, 100), sf::Vector2f pos = sf::Vector2f(0, 0), Pokoj_ rooms = engine::Room::Pokoj_::Hall,  sf::Color color = sf::Color::Black);
        void Room_gen(); 
        ~Room ();
        sf::RectangleShape drawing();
        sf::RectangleShape rectangle;
        protected:
        sf::Texture tekstura_;
        bool active = false;
    };

}