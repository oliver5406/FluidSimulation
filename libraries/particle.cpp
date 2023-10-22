#include "particle.h"
#include <cmath>

Particle::Particle(float x, float y, sf::Color color, float radius, sf::Vector2f initialVelocity)
    : shape(radius), m_particlePos(x, y), m_particleVel(initialVelocity) {
    shape.setPosition(m_particlePos);
    shape.setFillColor(color);
}

// void Particle::Start()


void Particle::Update(float deltaTime) 
{
    m_particlePos += m_particleVel * deltaTime + 0.5f * m_gravity * (float)std::pow(deltaTime, 2);
    m_particleVel += m_gravity * deltaTime;  // Update velocity due to gravity

    shape.setPosition(m_particlePos);
}

void Particle::Draw(sf::RenderWindow& window) 
{
    window.draw(shape);
}

void Particle::ResolveBoundaryCollisions(sf::RenderWindow& window)
{
    sf::Vector2u windowSize = window.getSize();
    unsigned int windowWidth = windowSize.x; // X-axis width
    unsigned int windowHeight = windowSize.y; // Y-axis height
    float radius = shape.getRadius();

    // std::cout << "PosY: " << m_particlePos.y << "\n";
    if (m_particlePos.y + radius/2 >= windowHeight || m_particlePos.y - radius <= 0.1)
    {
        m_particleVel.y = -m_particleVel.y * m_dampingCoefficient.y;
        m_particlePos.y = std::max(radius, std::min(static_cast<float>(windowHeight) - radius, m_particlePos.y));
    }

    if (m_particlePos.x + radius >= windowWidth || m_particlePos.x - radius <= 0.1)
    {
        m_particleVel.x = -m_particleVel.x * m_dampingCoefficient.x;
        m_particlePos.x = std::max(radius, std::min(static_cast<float>(windowWidth) - radius, m_particlePos.x));
    }
}