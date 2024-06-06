#pragma once
#include <SFML/Graphics.hpp>

class Brick {
public:
    sf::RectangleShape shape;
    bool isDestroyed{ false };

    Brick(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({ 60.f, 20.f });
        shape.setFillColor(sf::Color::Yellow);
        shape.setOrigin(30.f, 10.f);
    }
};
