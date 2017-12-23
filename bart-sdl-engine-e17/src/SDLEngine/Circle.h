#pragma once

#include "Includes.h"
#include "Vector2D.h"

class Circle
{
public:

	Circle(float x, float y, float radius);
	Circle(const Vector2D* const center, float radius);
	~Circle() {};

	bool Contains(float x, float y) const;
	bool Contains(const Vector2D* const point) const;
	float GetX() const { return x; }
	float GetY() const { return y; }
	float GetRadiusSq() const { return radius*radius; }
	float GetRadius() const { return radius; }
	void SetPosition(const Vector2D* const vect);
	void SetPosition(float x, float y);
	void MoveBy(const Vector2D* const vect);
	void MoveBy(float x, float y);
	bool CollidesWith(const Circle* const circle) const;


private:

	float x;
	float y;
	float radius;

};

