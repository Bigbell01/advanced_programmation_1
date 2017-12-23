#include "Circle.h"

Circle::Circle(float x, float y, float radius = 1)
	:x(x), y(y), radius(abs(radius))
{
}

Circle::Circle(const Vector2D* const center, float radius = 1)
	:x(center->x), y(center->y), radius(abs(radius))
{
}

bool Circle::Contains(float x, float y) const
{
	return (((x - this->x) * (x - this->x) + (y - this->y) * (y - this->y)) <= (this->radius * this->radius));
}

bool Circle::Contains(const Vector2D * const point) const
{
	return (((point->x - this->x) * (point->x - this->x) + (point->y - this->y) * (point->y - this->y)) <= (this->radius * this->radius)) ;
}

void Circle::SetPosition(const Vector2D * const vect)
{
	this->x = vect->x;
	this->y = vect->y;
}

void Circle::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Circle::MoveBy(const Vector2D * const vect)
{
	this->x += vect->x;
	this->y += vect->y;
}

void Circle::MoveBy(float x, float y)
{
	this->x += x;
	this->y += y;
}

bool Circle::CollidesWith(const Circle * const circle) const
{
	return (((circle->x - this->x)*(circle->x - this->x) + 
			 (circle->y - this->y)*(circle->y - this->y)) <= 
			 (this->radius+circle->radius)*(this->radius + circle->radius));
}
