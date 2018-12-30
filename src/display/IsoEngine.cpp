#include "IsoEngine.hpp"

void IsoEngine::Render (
	float scale,
	sf::VertexArray &floor,
	std::vector<IsoSubj> &subjects
)
{
	sf::Transform viewMx;
	viewMx.scale(1, .5);
	viewMx.translate(_winSize.x / 2.0f, 0);
	viewMx.rotate(45);
	viewMx.scale(scale, scale);

	std::sort(subjects.begin(), subjects.end(), [](IsoSubj a, IsoSubj b) {
		auto aPos = a.shape->getPosition();
		auto aDepth = aPos.x + aPos.y;
		auto bPos = b.shape->getPosition();
		auto bDepth = bPos.x + bPos.y;
		return aDepth < bDepth;
	});

	_window->clear(sf::Color(255, 255, 255));
	_window->draw(floor, viewMx);
	for (auto &subject : subjects) {
		if (subject.is2d) {
			sf::Transform coordMx;
			coordMx.translate(viewMx.transformPoint(subject.shape->getPosition()));
			_window->draw(*(subject.shape), coordMx);
		} else
			_window->draw(*(subject.shape), viewMx);
	}

	_window->display();
}

sf::VertexArray IsoEngine::CreateTileFloor (uint16_t diameter)
{
	uint32_t vLen = pow(diameter, 2) * 4;
	auto floor = sf::VertexArray(sf::Quads, vLen);
	//Position tiles
	for (uint32_t v = 0, t = 0; v < vLen; v += 4, ++t) {
		auto origin = sf::Vector2f((float)(t % diameter), (float)(t / diameter));
		floor[v + 0] = sf::Vertex(origin, sf::Color(0,128,0));
		floor[v + 1] = sf::Vertex(origin + sf::Vector2f(1, 0), sf::Color(0,128,0));
		floor[v + 2] = sf::Vertex(origin + sf::Vector2f(1, 1), sf::Color(0,128,0));
		floor[v + 3] = sf::Vertex(origin + sf::Vector2f(0, 1), sf::Color(0,128,0));
	}
	//Color tiles
	uint16_t rowLen = diameter * 4;
	for (uint32_t t = 0; t < (vLen - rowLen) - 4; t += 4) {
		auto randCol = sf::Color(rand()%32, 100 + (rand()%128), 0);
		floor[t+2].color = randCol;
		floor[t+4+3].color = randCol;
		floor[t+rowLen+1].color = randCol;
		floor[t+rowLen+4].color = randCol;
	}

	return floor;
}
