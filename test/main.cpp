#include <SFML/Graphics.hpp>
#include <cmath>
#include "../libraries/particle.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Particle Example");

    int numParticles = 12;
    float particleSpacing = 1;
    float radius = 10.0;
    std::vector<Particle*> particles;

    int particlesPerRow = std::sqrt(numParticles);
    int particlesPerCol = (numParticles - 1) / particlesPerRow + 1;
    float spacing = radius * 2 + particleSpacing;
    
    for (int i = 0; i < numParticles; i++)
    {
        float x = 400 + (i % particlesPerRow - particlesPerRow / (float)2 + (float)0.5) * spacing;
        float y = 300 + (i / particlesPerRow - particlesPerCol / (float)2 + (float)0.5) * spacing;
        particles.push_back(new Particle(x, y, sf::Color::Red, radius, sf::Vector2f(0, 10)));
    }

    // Particle p(400.0, 300.0, sf::Color::Red, 10.0, sf::Vector2f(0, 10));

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        float deltaTime = clock.restart().asSeconds();

        for (Particle* p : particles) {
            int count = 0;
            p->Update(deltaTime);
            p->ResolveBoundaryCollisions(window);
            // if (count != 1)
            // {
            //     p->CalculateDensity(particles);
            // }
            count += 1;
        }

        window.clear();

        for (Particle* p : particles) {
            p->Draw(window);
        }   
        
        window.display();
    }

    for (Particle* p : particles) {
        delete p;
    }
    return 0;
}
