#pragma once

#include "Includes.h"

struct Vector2D
{
	Vector2D()
		: x(0), y(0) {}
	Vector2D(float x, float y)
		: x(x), y(y) { }
	

	float x, y;
};


Vector2D Add(const Vector2D* const vector1, const Vector2D* const vector2);
Vector2D Substract(const Vector2D* const vector1, const Vector2D* const vector2);
Vector2D Scale(const Vector2D* const vector1, float scale);
void MoveBy(const Vector2D* const by, Vector2D* const toMove);
float GetPolarAngleDegree(const Vector2D* const vector1);
float AngleBetweenDeltas(const Vector2D* const vector1, const Vector2D* const vector2);
float Lenght(const Vector2D* const vector1);
float LenghtSquare(const Vector2D* const vector1);
void ScaleBy(Vector2D* const vector1, float scale);
bool Normalize(Vector2D* const vector1);
Vector2D GetVectorByAngleDegree(float angle);
bool Equals(const Vector2D* const vector1, const Vector2D* const vector2);
void MoveToward(Vector2D* origin, const Vector2D* const destination, const float speed);