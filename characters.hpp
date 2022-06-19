#pragma once

class Postac : public sf::RectangleShape {
    public:
    Postac(sf::Vector2f size, sf::Vector2f pos, std::string tekstura);
    ~Postac();
    protected:
    sf::Texture tekstura_;
    sf::Vector2i mouse_pos;
    sf::Vector2f pozycja;
    int zycie;
    sf::IntRect rect;
    float top_b = 0;
    float bottom_b = 0;
    float left_b = 0;
    float right_b = 0;
};

class Bohater : public Postac {
    public:
    Bohater(sf::Vector2f size, sf::Vector2f pos);
    ~Bohater();

    bool check(enum sf::Keyboard::Key key);

    void animate(sf::Time elapsed);
        
    void UstawCel(const sf::RenderWindow& window);

    void PodazajDoCelu(sf::Time el);
};