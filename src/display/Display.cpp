#include "Display.hpp"

Display::Display(sf::RenderWindow &window)
{
	//Load engine
	_engine = new IsoEngine(window);
	//Load textures
	_texBrick.loadFromFile("../res/brick.png");
	
	uint32_t diameter = 64;
	floor = _engine->CreateTileFloor(diameter);

	//Make and add player
	auto player = std::make_shared<sf::RectangleShape>(sf::Vector2f(10, 20));
	player->setFillColor(sf::Color::Red);
	player->setPosition(sf::Vector2f(10, 10));

	drawables.push_back(IsoSubj(player, true));

	//Make random cubes
	for (auto i = 0; i < 1000; ++i) {
		auto cube = std::make_shared<Cube>(32, (rand()%2+1)/2.0, &_texBrick);
		cube->setPosition(rand() % diameter, rand() % diameter);
		drawables.push_back(IsoSubj(cube, false));
	}
}

void Display::Render ()
{
	_engine->Render(32, floor, drawables);
}
