#pragma once

#include <SFML/Graphics.hpp>
class Cube : public sf::Shape
{
private:
	float _size;
	float _height;
	sf::VertexArray _vertices;
	sf::Texture* _texture;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		auto transform = sf::Transform();
		transform.translate(getPosition());
		states.transform.combine(transform);
		
		states.texture = _texture;
		target.draw(_vertices, states);
	}

	virtual std::size_t getPointCount() const { return _vertices.getVertexCount(); }
	virtual sf::Vector2f getPoint(std::size_t i) const { return (_vertices[i]).position; }

public:
	Cube(float size, float height, sf::Texture* texture)
	{
		_size = size;
		_height = height;
		_texture = texture;
		auto tex = texture->getSize();

		auto clrGrey = sf::Color(0xBBBBBBFF);
		auto clrDark = sf::Color(0x444444FF);
		auto clrLite = sf::Color(0xCCCCCCFF);

		_vertices = sf::VertexArray(sf::PrimitiveType::Quads, 3 * 4);
		_vertices[0] = sf::Vertex(sf::Vector2f(0 - _height, 0 - _height), clrLite, sf::Vector2f(0, 0));
		_vertices[1] = sf::Vertex(sf::Vector2f(1 - _height, 0 - _height), clrLite, sf::Vector2f(tex.x, 0));
		_vertices[2] = sf::Vertex(sf::Vector2f(1 - _height, 1 - _height), clrLite, sf::Vector2f(tex.x, tex.y)),
		_vertices[3] = sf::Vertex(sf::Vector2f(0 - _height, 1 - _height), clrLite, sf::Vector2f(0, tex.y));

		_vertices[4] = sf::Vertex(sf::Vector2f(1 - _height, 0 - _height), clrGrey, sf::Vector2f(tex.x, 0));
		_vertices[5] = sf::Vertex(sf::Vector2f(1, 0), clrDark, sf::Vector2f(tex.x, tex.y));
		_vertices[6] = sf::Vertex(sf::Vector2f(1, 1), clrDark, sf::Vector2f(0, tex.y));
		_vertices[7] = sf::Vertex(sf::Vector2f(1 - _height, 1 - _height), sf::Vector2f(0, 0));

		_vertices[8] = sf::Vertex(sf::Vector2f(0 - _height, 1 - _height), clrGrey, sf::Vector2f(0, 0));
		_vertices[9] = sf::Vertex(sf::Vector2f(1 - _height, 1 - _height), clrGrey, sf::Vector2f(tex.x, 0));
		_vertices[10] = sf::Vertex(sf::Vector2f(1, 1), clrDark, sf::Vector2f(tex.x, tex.y));
		_vertices[11] = sf::Vertex(sf::Vector2f(0, 1), clrDark, sf::Vector2f(0, tex.y));
	}
};
