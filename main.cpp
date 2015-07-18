#include <SFML/Graphics.hpp>


void initWindow(int windowSize) {
    sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "{Window Title}");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            window.display();
        }
    }
};

int main() {
    initWindow(200);

    return 0;
};
