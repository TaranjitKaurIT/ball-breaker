#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ball Breaking Game");

    Ball ball(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
    Paddle paddle(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50);

    std::vector<Brick> bricks;
    int rows = 5, cols = 10;
    float brickWidth = 60, brickHeight = 20;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            bricks.emplace_back((j + 1) * (brickWidth + 10), (i + 1) * (brickHeight + 10));
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ball.update();
        paddle.update();

        // Collision detection for ball and paddle
        if (ball.shape.getGlobalBounds().intersects(paddle.shape.getGlobalBounds())) {
            ball.velocity.y = -ball.velocity.y;
        }

        // Collision detection for ball and bricks
        for (auto& brick : bricks) {
            if (brick.isDestroyed)
                continue;

            if (ball.shape.getGlobalBounds().intersects(brick.shape.getGlobalBounds())) {
                ball.velocity.y = -ball.velocity.y;
                brick.isDestroyed = true;
            }
        }

        window.clear();

        window.draw(ball.shape);
        window.draw(paddle.shape);

        for (const auto& brick : bricks) {
            if (!brick.isDestroyed)
                window.draw(brick.shape);
        }

        window.display();
    }

    return 0;
}
