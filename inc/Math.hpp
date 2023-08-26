#ifndef MATH_HPP
#define MATH_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <cmath>
#include <cstdlib>


namespace math
{

extern const float PI;
extern unsigned int seed;

template <class T>
inline T max(T a, T b)
{
	return a > b ? a : b;
}

template <class T>
inline T min(T a, T b)
{
	return a < b ? a : b;
}

template <class T>
inline T clamp(T value, T max, T min)
{
	return value < max ? max : (value > min ? value : min);
}


inline int random(int begin, int end)
{
	return std::rand() % (end - begin + 1) + begin;
}

inline float random(float begin, float end)
{
	return static_cast<float>(std::rand()) / RAND_MAX * (end - begin) + begin;
}

void set_seed(unsigned int seed);

// 2D helpers

inline float to_rad(float degres)
{
	return degres * PI / 180;
}


inline float to_deg(float radians)
{
	return radians / PI * 180;
}


inline void translate(sf::Vector2f& offset, float angle, float speed)
{
	offset.x = offset.x + speed * std::cos(angle);
	offset.y = offset.y - speed * std::sin(angle);
}


inline float distance(float x1, float y1, float x2 = 0.f, float y2 = 0.f)
{
	// Formula para calcular a distancia entre dois pontos:
	// sqrt( (x1 - x2)² + (y1 - y2)² )
	return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}


inline float distance(const sf::Vector2f& p1, const sf::Vector2f& p2 = sf::Vector2f(0.f, 0.f))
{
	return distance(p1.x, p1.y, p2.x, p2.y);
}


float angle(const sf::Vector2f& p1, const sf::Vector2f& p2);

sf::Color random_color(sf::Uint8 min_r=0, sf::Uint8 min_g=0, sf::Uint8 min_b=0, sf::Uint8 max_r=255, sf::Uint8 max_g=255, sf::Uint8 max_b=255);

}

#endif // MATH_HPP
