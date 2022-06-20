#pragma once

namespace engine{

        class Room : public sf::RectangleShape {
        public:
        enum Pokoj_ {Boss, Item, Shop, Hall, Start};
        Room(sf::Vector2f size = sf::Vector2f(128, 128), sf::Vector2f pos = sf::Vector2f(0, 0), Pokoj_ rooms = engine::Room::Pokoj_::Hall,  sf::Color color = sf::Color::Black);
        ~Room ();
        virtual std::vector<std::vector<int> >  getLevels()=0;
        protected:
        sf::RectangleShape rectangle;
        bool active = true;
    };

        class Empty : public engine::Room {
        public:
        Empty(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(128, 128));
        ~Empty();
        virtual std::vector<std::vector<int> >  getLevels();
        protected:
        const int layers = 1;
        std::vector<std::vector<std::vector<int> > > level_ = {
            { 
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0}
            }
        };
        };

        class Start : public engine::Room {
        public:
        Start(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(128, 128));
        ~Start();
        virtual std::vector<std::vector<int> >  getLevels();
        protected:
        const int layers = 4;
        std::vector<std::vector<std::vector<int> > >  level_= {{

            { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 2, 1, 7, 8, 18},
            { 15, 4, 1, 6, 2, 5, 3, 18},
            { 15, 5, 2, 2, 5, 8, 1, 18},
            { 15, 4, 8, 1, 7, 4, 5, 18},
            { 15, 2, 6, 5, 1, 3, 6, 18},
            { 15, 3, 4, 8, 6, 7, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
        } , {
                 { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 1, 7, 8, 18},
            { 15, 7, 3, 6, 1, 4, 3, 18},
            { 15, 5, 2, 8, 20, 8, 1, 18},
            { 15, 6, 1, 7, 4, 6, 5, 18},
            { 15, 2, 4, 3, 1, 8, 6, 18},
            { 15, 4, 4, 1, 6, 8, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            } , {
                 { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 1, 7, 8, 18},
            { 15, 7, 9, 6, 4, 4, 3, 18},
            { 15, 5, 2, 8, 1, 8, 1, 18},
            { 15, 6, 1, 20, 6, 6, 5, 18},
            { 15, 2, 4, 2, 1, 4, 6, 18},
            { 15, 4, 4, 1, 6, 8, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            } , { 
                 { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 1, 7, 3, 18},
            { 15, 4, 8, 7, 2, 4, 2, 18},
            { 15, 7, 2, 1, 6, 8, 1, 18},
            { 15, 4, 1, 3, 7, 4, 5, 18},
            { 15, 1, 2, 2, 1, 5, 6, 18},
            { 15, 8, 4, 7, 6, 8, 1, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }
        };
        };

         class Boss : public engine::Room {
        public:
        Boss(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(128, 128));
        ~Boss();
        virtual std::vector<std::vector<int> >  getLevels();
        protected:
        const int layers = 2;
        std::vector<std::vector<std::vector<int> > >  level_ = {{
            { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 5, 7, 8, 18},
            { 15, 4, 8, 7, 4, 6, 3, 18},
            { 15, 4, 2, 2, 1, 8, 1, 18},
            { 15, 4, 1, 1, 8, 4, 5, 18},
            { 15, 1, 6, 3, 1, 3, 6, 18},
            { 15, 4, 4, 8, 6, 7, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }, {
                 { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 1, 7, 8, 18},
            { 15, 7, 3, 6, 1, 4, 3, 18},
            { 15, 5, 2, 8, 2, 8, 1, 18},
            { 15, 6, 1, 7, 4, 6, 5, 18},
            { 15, 2, 4, 3, 1, 8, 6, 18},
            { 15, 4, 4, 1, 6, 8, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }
        };
        };

        class Item_room : public engine::Room {
        public:
        Item_room (sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(128, 128));
        ~Item_room ();
        virtual std::vector<std::vector<int> >  getLevels();
        protected:
        const int layers = 2;
        std::vector<std::vector<std::vector<int> > >  level_ = {{
            { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 5, 7, 8, 18},
            { 15, 4, 8, 1, 4, 6, 3, 18},
            { 15, 4, 2, 20, 1, 8, 1, 18},
            { 15, 4, 1, 5, 2, 4, 3, 18},
            { 15, 1, 7, 3, 1, 3, 7, 18},
            { 15, 4, 4, 8, 6, 7, 6, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }, {
                 { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 2, 6, 3, 1, 7, 4, 18},
            { 15, 7, 3, 6, 1, 3, 1, 18},
            { 15, 5, 2, 8, 2, 8, 1, 18},
            { 15, 6, 1, 20, 4, 6, 5, 18},
            { 15, 2, 3, 3, 1, 8, 6, 18},
            { 15, 4, 8, 1, 6, 8, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }
        };
        };


        class Shop : public engine::Room {
        public:
        Shop(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(128, 128));
        ~Shop();
        virtual std::vector<std::vector<int> >  getLevels();
        protected:
        const int layers = 2;
        std::vector<std::vector<std::vector<int> > >  level_ = {{
            { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 5, 7, 8, 18},
            { 15, 4, 8, 1, 4, 6, 3, 18},
            { 15, 4, 2, 5, 1, 8, 1, 18},
            { 15, 4, 20, 5, 2, 20, 3, 18},
            { 15, 1, 7, 3, 1, 3, 7, 18},
            { 15, 4, 4, 8, 6, 7, 6, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }, {
                 { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 2, 6, 1, 1, 8, 4, 18},
            { 15, 8, 3, 6, 2, 4, 1, 18},
            { 15, 3, 2, 8, 2, 8, 1, 18},
            { 15, 6, 20, 7, 4, 20, 5, 18},
            { 15, 1, 3, 3, 1, 6, 6, 18},
            { 15, 4, 8, 1, 6, 8, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }
        };
        };


        class Hall : public engine::Room {
        public:
        Hall(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(128, 128));
        ~Hall();
        virtual std::vector<std::vector<int> >  getLevels();
        protected:
        const int layers = 3;
        std::vector<std::vector<std::vector<int> > >  level_ = {{
            { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 1, 7, 8, 18},
            { 15, 4, 8, 6, 2, 4, 3, 18},
            { 15, 5, 2, 2, 1, 8, 1, 18},
            { 15, 4, 1, 1, 7, 4, 5, 18},
            { 15, 2, 6, 2, 1, 3, 6, 18},
            { 15, 4, 4, 8, 6, 8, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }, {
                 { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 1, 7, 8, 18},
            { 15, 7, 9, 6, 4, 4, 3, 18},
            { 15, 5, 2, 8, 1, 8, 1, 18},
            { 15, 6, 1, 3, 6, 6, 5, 18},
            { 15, 2, 4, 2, 1, 4, 6, 18},
            { 15, 4, 4, 1, 6, 8, 5, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }, { 
                 { 14, 10, 12, 11, 10, 12, 11, 13},
            { 15, 3, 6, 3, 1, 7, 3, 18},
            { 15, 4, 8, 7, 2, 4, 2, 18},
            { 15, 7, 2, 1, 6, 8, 1, 18},
            { 15, 4, 1, 3, 7, 4, 5, 18},
            { 15, 1, 2, 2, 1, 5, 6, 18},
            { 15, 8, 4, 7, 6, 8, 1, 18},
            { 16, 19, 19, 19, 19, 19, 19, 17}
            }
        };
        };

}