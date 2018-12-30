#pragma once
#include <vector>
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "IsoShapes.hpp"

class IsoSubj
{
	public:
	bool is2d = false;
	std::shared_ptr<sf::Shape> shape;

	IsoSubj (std::shared_ptr<sf::Shape> shape, bool is2d) : shape(shape), is2d(is2d) {};
};

class IsoEngine
{
	private:
	sf::RenderWindow* _window;
	sf::Vector2f _winSize;
	
	public:
	IsoEngine (sf::RenderWindow &window) : _window(&window), _winSize(window.getSize()) {};
	
	void Render (
		float scale,
		sf::VertexArray &floor,
		std::vector<IsoSubj> &drawables
	);
	static sf::VertexArray CreateTileFloor (uint16_t diameter);
};
