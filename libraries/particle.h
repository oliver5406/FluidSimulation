#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Particle {
public:

    Particle();
    Particle(float x, float y, sf::Color color, float radius, sf::Vector2f initialVelocity);

    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    void ResolveBoundaryCollisions(sf::RenderWindow& window);

private:
    sf::CircleShape shape;
    sf::Vector2f m_particlePos;
    sf::Vector2f m_particleVel;
    const sf::Vector2f m_dampingCoefficient = sf::Vector2f(0.8, 0.8);
    const sf::Vector2f m_gravity = sf::Vector2f(0, 2*9.81);
};
