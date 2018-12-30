#include <SFML/Graphics.hpp>
#include "display/Display.hpp"
#define WIN_W 800
#define WIN_H 600

int main ()
{
	sf::RenderWindow window (sf::VideoMode(WIN_W, WIN_H), "Jaunter");//, sf::Style::Fullscreen);

	auto display = Display(window);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}
		
		display.Render();
	}
}
