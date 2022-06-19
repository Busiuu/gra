#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "dung_gener.hpp"
#include "pokoje.hpp"
#include "Tiles.hpp"
 
sf::Vector2i engine::Generator::startPos(){
            int x = std::rand() % 2 + 3;
            int y = std::rand() % 2 + 3;
            std::cout << "startPos" << x << " " << y << std::endl;
            return sf::Vector2i(x, y);
};

sf::Vector2i engine::Generator::bossPos(){
            int x = std::rand() % 8;
            int y;
            if (x<1 || x>6)
            y = std::rand() % 8;
            else{
                if (int i = std::rand() % 2; i < 1)
                    y = i;
                else 
                    y = i + 6;
            }
            std::cout << "bossPos" << x << " " << y << std::endl;
            return sf::Vector2i(x, y);
};

sf::Vector2i engine::Generator::shopPos(){
            int x = std::rand() % 6 + 1;
            int y;
            if (x<1 || x>4)
            y = std::rand() % 6 + 1;
            else{
                if (int i = std::rand() % 2; i < 1)
                    y = i + 1;
                else 
                    y = i + 5;
            }
            std::cout << "shopPos" << x << " " << y << std::endl;
            return sf::Vector2i(x, y);
};

sf::Vector2i engine::Generator::itemPos(){
            int x = std::rand() % 4 + 2;
            int y;
            if (x<1 || x>2)
            y = std::rand() % 4 + 2;
            else{
                if (int i = std::rand() % 2; i < 1)
                    y = i + 2;
                else 
                    y = i + 4;
            }
            std::cout << "itemPos" << x << " " << y << std::endl;
            return sf::Vector2i(x, y);
};

std::vector<int> engine::Generator::zakres_check(int liczba, int a, int b){
            std::vector<int> temp;
            if (liczba > 0 ) {
                if (a > b) {
                    for(int i = a; i >= b; i--) {
                        temp.push_back(i);
                    }; 
                } else {
                    for(int i = a; i <= b; i++){
                        temp.push_back(i);
                    }; 
                } 
            } else {
                temp.push_back(a);
            }
            return temp;
};

void engine::Generator::Gen(sf::Vector2i start, sf::Vector2i end, engine::Room::Pokoj_ rooms ){
            std::vector<int> zakres_x = zakres_check(abs(start.x - end.x), start.x, end.x);
            std::vector<int> zakres_y = zakres_check(abs(start.y - end.y), start.y, end.y);
            int steps_x = zakres_x.size() - 1;
            int steps_y = zakres_y.size() - 1;
            int x_i = 0;
            int y_i = 0;
            do{
                if (steps_x > 0 && steps_y  > 0){
                    if (int i = rand() % 2; i == 0){
                        x_i++;
                        pokoje[zakres_x[x_i]][zakres_y[y_i]] = 1;
                        steps_x--;
                    }else{
                        y_i++;
                        pokoje[zakres_x[x_i]][zakres_y[y_i]]  = 1;
                        steps_y--;
                    }
                } else if (steps_x > 0 && steps_y <= 0){
                    x_i++;
                    pokoje[zakres_x[x_i]][zakres_y[y_i]]  = 1;
                    steps_x--;
                } else {
                    y_i++;
                    pokoje[zakres_x[x_i]][zakres_y[y_i]]  = 1;
                    steps_y--;
                }
            } while(((steps_x > 0) || (steps_y > 0 )));

            switch(rooms){
                case engine::Room::Pokoj_::Boss:
                    pokoje[zakres_x[x_i]][zakres_y[y_i]]  = 9;
                    break;
                case engine::Room::Pokoj_::Item:
                    pokoje[zakres_x[x_i]][zakres_y[y_i]]  = 7;
                    break;
                case engine::Room::Pokoj_::Shop:
                pokoje[zakres_x[x_i]][zakres_y[y_i]]  = 5;
                    break;
                default:
                    break;
            }
            
            
}



void engine::Generator::drawable(){
            for (int i = 0; i < 8; ++i){
                for(int j = 0; j < 8; ++j){
                    pokoje[i][j] = 0;
                }
            }
            startPos_ = startPos();
            bossPos_ = bossPos();
            shopPos_ = shopPos();
            itemPos_ = itemPos();
            pokoje[startPos_.x][startPos_.y] = 2;
            Gen(startPos_, bossPos_, engine::Room::Pokoj_::Boss );
            Gen(startPos_, shopPos_, engine::Room::Pokoj_::Shop );
            Gen(startPos_, itemPos_, engine::Room::Pokoj_::Item );
            
            if (!map.load("tiles.png", sf::Vector2u(64, 64), levels, 16, 16))
                std::cout << "ERROR" << std::endl;
            

};
