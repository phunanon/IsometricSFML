#pragma once
#include "IsoEngine.hpp"


class Display
{
private:
	IsoEngine* _engine;
	std::vector<IsoSubj> drawables;
	sf::VertexArray floor;
	sf::RectangleShape player;
	sf::Texture _texBrick;
public:
	Display(sf::RenderWindow&);
	void Render();
};
