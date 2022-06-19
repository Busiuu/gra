#include "pokoje.hpp"
#include "Tiles.hpp"
#pragma once

namespace engine {

    class Generator{
        public:
        enum Pokoj_ {Boss, Item, Shop};
        private:
        sf::Vector2i startPos();

        sf::Vector2i bossPos();

        sf::Vector2i shopPos();

        sf::Vector2i itemPos();

        std::vector<int> zakres_check(int liczba, int a, int b);

        void Gen(sf::Vector2i start, sf::Vector2i end, engine::Room::Pokoj_ rooms );

        void mapa();

       
        
        public: 
        void rysuj_bg(int a, int b);
        void init();
        int pokoje[8][8];
        TileMap map;
        private:
        std::vector<std::vector<std::vector<int> > > mapa_;
        sf::Vector2i startPos_;
        sf::Vector2i bossPos_;
        sf::Vector2i shopPos_;
        sf::Vector2i itemPos_;

    };
};