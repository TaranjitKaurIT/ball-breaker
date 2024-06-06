#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
public:
    sf::RectangleShape shape;
    const float paddleWidth{ 80.f }, paddleHeight{ 20.f };
    const float paddleVelocity{ 8.f };
    sf::Vector2f velocity{ paddleVelocity, 0.f };

    Paddle(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({ paddleWidth, paddleHeight });
        shape.setFillColor(sf::Color::Green);
        shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
    }

    void update() {
        shape.move(velocity);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0) velocity.x = -paddleVelocity;
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < 800) velocity.x = paddleVelocity;
        else velocity.x = 0;
    }

    float x() const { return shape.getPosition().x; }
    float y() const { return shape.getPosition().y; }
    float left() const { return x() - shape.getSize().x / 2.f; }
    float right() const { return x() + shape.getSize().x / 2.f; }
    float top() const { return y() - shape.getSize().y / 2.f; }
    float bottom() const { return y() + shape.getSize().y / 2.f; }
};
